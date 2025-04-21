#!/bin/bash

# 显示脚本说明
echo "=========================================================="
echo "主机配置、MPICH安装与测试脚本"
echo "功能: 自动设置主机名、配置hosts文件、生成SSH密钥、安装MPICH并进行集群测试"
echo "=========================================================="

# 获取三台主机的IP地址
echo "请输入三台主机的IP地址:"
read -p "ecs-hw-0001 的IP地址: " ip1
read -p "ecs-hw-0002 的IP地址: " ip2
read -p "ecs-hw-0003 的IP地址: " ip3
read -p "当前主机的IP地址 (从上面三个IP中选择): " current_ip
read -p "远程主机的用户名: " remote_user

# 检查IP地址格式
validate_ip() {
    if [[ ! $1 =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
        echo "错误: '$1' 不是有效的IP地址格式"
        exit 1
    fi
}

validate_ip $ip1
validate_ip $ip2
validate_ip $ip3
validate_ip $current_ip

# 确定当前主机ID和主机名
if [ "$current_ip" == "$ip1" ]; then
    host_id="0001"
elif [ "$current_ip" == "$ip2" ]; then
    host_id="0002"
elif [ "$current_ip" == "$ip3" ]; then
    host_id="0003"
else
    echo "错误: 当前IP不在提供的三个IP地址中"
    exit 1
fi

hostname="ecs-hw-$host_id"

# 设置主机名
echo "正在设置主机名为 $hostname..."
sudo hostnamectl set-hostname $hostname

# 创建新的hosts文件内容
hosts_content="127.0.0.1   localhost
# 以下是原hosts文件内容的注释版本
# $(cat /etc/hosts | grep -v '^#' | grep -v '^$' | sed 's/^/# /')

# 集群主机配置
$ip1  ecs-hw-0001
$ip2  ecs-hw-0002
$ip3  ecs-hw-0003"

# 备份原hosts文件
echo "正在备份和修改hosts文件..."
sudo cp /etc/hosts /etc/hosts.bak.$(date +%Y%m%d%H%M%S)

# 写入新的hosts内容
echo "$hosts_content" | sudo tee /etc/hosts > /dev/null

echo "hosts文件已更新"

# 生成SSH密钥
echo "正在生成SSH密钥..."
# 检查是否已存在密钥，如果存在则不覆盖
if [ ! -f ~/.ssh/id_rsa ]; then
    ssh-keygen -t rsa -b 4096 -f ~/.ssh/id_rsa -N ""
else
    echo "SSH密钥已存在，跳过生成步骤"
fi

# 复制SSH密钥到其他主机
echo "正在复制SSH密钥到其他主机..."
for i in 1 2 3; do
    target_host="ecs-hw-000$i"
    if [ "$target_host" != "$hostname" ]; then
        echo "正在复制密钥到 $target_host..."
        # 使用StrictHostKeyChecking=no避免首次连接时的确认提示
        ssh-copy-id -o StrictHostKeyChecking=no $remote_user@$target_host
    fi
done

# 安装MPICH
echo "=========================================================="
echo "开始安装MPICH..."
echo "=========================================================="

# 更新软件包列表
echo "更新软件包列表..."
sudo apt-get update

# 安装MPICH和相关开发库
echo "安装MPICH和相关依赖..."
sudo apt-get install -y mpich mpich-doc libmpich-dev build-essential

# 验证MPICH安装
echo "验证MPICH安装..."
mpirun --version
mpicc --version

# 创建测试目录
echo "创建测试目录..."
mkdir -p ~/mpich_test
cd ~/mpich_test

# 创建一个简单的MPI测试程序
echo "创建MPI测试程序..."
cat > mpi_hello.c << 'EOF'
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int world_size, world_rank;
    char hostname[256];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // 获取主机名
    gethostname(hostname, sizeof(hostname));
    
    printf("Hello world from processor %s, rank %d out of %d processors\n", 
           hostname, world_rank, world_size);

    MPI_Finalize();
    return 0;
}
EOF

# 编译MPI程序
echo "编译MPI测试程序..."
mpicc -o mpi_hello mpi_hello.c

# 创建主机文件
echo "创建主机文件..."
cat > hostfile << EOF
ecs-hw-0001
ecs-hw-0002
ecs-hw-0003
EOF

# 在本地测试MPI程序
echo "在本地测试MPI程序..."
mpirun -n 2 ./mpi_hello

# 在集群上测试MPI程序
echo "=========================================================="
echo "在集群上测试MPI程序..."
echo "=========================================================="
mpirun -hostfile hostfile -n 6 ./mpi_hello

# 创建一个更复杂的MPI测试程序 - 计算π
echo "创建MPI π计算程序..."
cat > mpi_pi.c << 'EOF'
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_POINTS 1000000

int main(int argc, char** argv) {
    int world_size, world_rank;
    char hostname[256];
    double pi_estimate, pi_sum = 0.0;
    int points_in_circle = 0;
    int points_per_proc;
    
    // 初始化MPI环境
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    // 获取主机名
    gethostname(hostname, sizeof(hostname));
    
    // 设置随机数种子
    srand(time(NULL) + world_rank);
    
    // 每个进程计算的点数
    points_per_proc = NUM_POINTS / world_size;
    
    // 蒙特卡洛方法计算π
    for (int i = 0; i < points_per_proc; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x*x + y*y <= 1.0) {
            points_in_circle++;
        }
    }
    
    // 计算当前进程的π估计值
    pi_estimate = 4.0 * points_in_circle / points_per_proc;
    
    // 收集所有进程的结果
    MPI_Reduce(&pi_estimate, &pi_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    
    // 主进程计算最终结果并输出
    if (world_rank == 0) {
        pi_sum = pi_sum / world_size;
        printf("从 %d 个进程估算的π值约为: %f\n", world_size, pi_sum);
        printf("与实际π值的差异: %f\n", pi_sum - 3.14159265358979323846);
    }
    
    printf("进程 %d 在主机 %s 上完成计算\n", world_rank, hostname);
    
    MPI_Finalize();
    return 0;
}
EOF

# 编译π计算程序
echo "编译MPI π计算程序..."
mpicc -o mpi_pi mpi_pi.c

# 在集群上运行π计算程序
echo "在集群上运行π计算程序..."
mpirun -hostfile hostfile -n 6 ./mpi_pi

echo "=========================================================="
echo "配置与测试完成!"
echo "主机名: $hostname"
echo "hosts文件已更新"
echo "SSH密钥已生成并复制到其他主机"
echo "MPICH已安装并完成集群测试"
echo "测试程序位于: ~/mpich_test/"
echo "=========================================================="