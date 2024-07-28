# linux技巧

## 1.快捷键

### 1.1 ctrl+c

- 强制结束当前命令
- 当命令写错了,不想一直删除,可以ctrl+c

### 1.2 ctrl+d

- 退出当前命令

## 2.包管理器

### 2.1 yum

>Yellow Dog Updater,Modfied

```sh
yum [-y][install | update | remove ] [package]
```

- `-y`:自动确认
- `install`:安装
- `update`:更新,可简写`up`
- `remove`:卸载,可简写`rm`
- `package`:包名

```sh
yum list [all | installed | updates | available]
```

- `all`:列出所有包
- `installed`:列出已安装的包
- `updates`:列出可更新的包
- `available`:列出可安装的包

```sh
yum [search | info] [package]
```

- `search`:搜索包
- `info`:查看包信息

### 2.2 yum源

- 位于`/etc/yum.repos.d/`
- 可以通过`yum repolist`查看当前yum源
- 可以通过`yum-config-manager --add-repo [url]`添加新的yum源
- 一般操作过后要`yum clean all` 清除缓存然后`yum makecache`生成缓存

## 3.systemctl

>system control

```sh
systemctl [start | stop | restart | enable | disable | status] [service]
```

- `restart`:重启
- `enable`:开机自启
- `disable`:开机不自启
- `status`:查看状态

## 4.软链接ln

>link

```sh
ln -s [source] [target]
```

- `-s`:创建软链接
- `source`:源文件
- `target`:目标文件
- 软链接相当于windows的快捷方式

## 5.ip地址和主机名

### 5.1 ifconfig

>network interface configuration
>interface configuration

```sh
ifconfig [eth0] [up | down]
```

- 127.0.0.1, 这个ip地址用于指代本机
- 0.0.0.0, 这个ip地址用于指代所有ip,也代指本机

### 5.2 hostname

>hostname

```sh
hostname [hostname]
```

- `hostname`:查看主机名
- `hostname [hostname]`:设置主机名(瞬态)

### 5.3 hostnamectl

>hostname control

```sh
hostnamectl set-hostname [hostname] [--static | --transient | --pretty]
```

- `--static`:静态主机名
- `--transient`:瞬态主机名
- `--pretty`:漂亮主机名

一旦修改了静态主机名，/etc/hostname 将被自动更新。然而，`/etc/hosts`不会更新以保存所做的修改，所以你每次在修改主机名后一定要手动更新`/etc/hosts`，之后再重启`reboot`CentOS。以确保新主机名与系统中的本地主机名解析一致。这有助于防止网络应用程序和服务在解析主机名时出现问题。

`/etc/hosts`是私人的地址映射,由域名向ip映射,dns服务商则是公开的映射服务器.
`/etc/hosts`文件中,可以添加自定义的域名和ip映射,这样就可以通过域名访问本机.但是没啥用.

>idea:
>假如没有在dns服务商解析域名,可以自己在hosts文件中添加域名映射,然后就可以通过自定义的映射名来访问远程的服务器了.如在windows的`C:\Windows\System32\drivers\etc`下添加远程服务器的ip地址和映射名,然后就可以通过映射名来访问远程服务器了.

### 5.4 固定vm虚拟机的ip

>具体方法参考网络答案

## 6.网络

### 6.1 ping

>ping

```sh
ping [-c num] ip
```

- `ping [ip]`:测试网络连通性
- `-c`:指定ping的次数

### 6.2 wget

>"World Wide Web"和"Get"的结合

```sh
wget [-b] [url]
```

- `-b`:后台下载
- `ctrl+c`停止下载后,下载一半的文件也会存在,需要手动删除.

### 6.3 curl

>"Client URL",是"Client for URLs"的缩写
>其中"URL"是"Uniform Resource Locator"的缩写,"统一资源定位符",俗称网址

```sh
curl [-O] [url]
```

- `-O`:下载文件并保存到本地
- `curl url`:直接显示网页内容
- `curl -O url`:下载文件并保存到本地

### 6.4 端口

#### 6.4.1 前要

- 计算机之间可以通过ip进行访问
- 若要访问具体的某个程序,则需要具体到某个端口
- ip用于锁定计算机,端口用于锁定具体进程

>端口范围:0-65535
>其中0-1023为系统占用端口
>1024-49151为用户端口
>49152-65535为动态端口
>其中80端口为http协议的默认端口,443端口为https协议的默认端口

#### 6.4.2 nmap

>network exploration tool and security scanner
>非自带,需要`yum install nmap`

```sh
nmap [ip]
```

#### 6.4.3 netstat

>network statistics

```sh
netstat [-a | -n | -p] [port]
```

- `-a`:显示所有连接和监听端口
- `-n`:以数字形式显示地址和端口号
- `-p`:显示进程id和名称

## 7.进程

### 7.1 ps

>process status

```sh
ps aux
```

- `a`:显示现行终端机下的所有程序，包括其他用户的程序
- `u`:以用户为主的格式来显示进程状态
- `x`:显示没有控制终端的进程

```sh
ps -ef
```

- `-e`:显示所有进程
- `-f`:全格式显示

>ps aux和ps -ef的区别在于显示的格式不同,ps aux显示的格式更详

### 7.2 kill

>kill

```sh
kill [-9] [pid]
```

- `-9`:强制杀掉进程
- `killall [进程名]`:杀掉所有指定进程

## 8.查看系统信息

### 8.1 top

>top

```sh
top
```

- `top`:实时显示进程状态
- `q`:退出
- `E`:切换顶部内存显示单位
- `e`:切换进程内存显示单位
- `f`:选择需要显示的内容
- `M`:按照内存排序
- `P`:按照cpu排序
- `c`:显示进程的完整命令行
- `t`:切换顶部cpu显示
- `m`:切换顶部内存显示

### 8.2 df

>disk free

```sh
df [-h]
```

- `-h`:以人类可读的方式显示

### 8.3 free

>free

```sh
free [-h]
```

- `-h`:以人类可读的方式显示

### 8.4 iostat

>io statistics

```sh
iostat [-x] 
```

- `-x`:显示详细的io信息

### 8.5 sar

>sar

```sh
sar -n DEV [interval] [count]
```

- `-n DEV`:显示网络信息
- `interval`:间隔时间
- `count`:次数

## 9.环境变量

>环境变量是操作系统中的变量,用于存储一些系统信息,如用户名,主机名,当前路径等

- 系统环境变量在`/etc/profile`文件中
- 用户环境变量在`~/.bashrc`文件中
- 环境变量可以通过`echo $变量名`查看
- 环境变量可以通过`export 变量名=变量值`设置(临时设置)
- 可以直接修改`/etc/profile`文件和`~/.bashrc`文件来永久设置环境变量

>修改过后要用`source`使其生效

## 10.上传和下载

>可以通过rz,sz来上传下载

- `rz`:上传文件到linux
- `sz`:下载文件到本地

>需要`yum install lrzsz`

## 11.解压和压缩

### 11.1 tar

>tar:简单封装,文件大小并不会减少多少
>gz:使用gzip压缩,文件大小会减少很多

```sh
tar [-z -c -x -v -f -C]
```

- `-z`:使用gzip压缩
- `-c`:创建压缩包
- `-x`:解压
- `-v`:显示详细信息
- `-f`:指定压缩包名
- `-C`:指定解压路径
- 压缩文件:`tar -cvf [压缩包名] [文件名]`
- 压缩文件:`tar -zcvf [压缩包名] [文件名]`
- 解压文件:`tar -xvf [压缩包名] -C [解压路径]`
- 解压文件:`tar -zxvf [压缩包名] -C [解压路径]`

>若要用`z`,一般放第一个
>`f`必须要放最后一个,指定文件

### 11.2 zip

```sh
zip [-r] [压缩包名] [文件名]
```

- `-r`:递归压缩

### 11.3 unzip

```sh
unzip [压缩包名] -d [解压路径]
```

>如果有同名,会自动覆盖
