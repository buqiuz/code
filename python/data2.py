import numpy as np
from scipy.optimize import differential_evolution

# 定义一个目标函数，我们要找到这个函数的最小值
def objective_function(x):
    return np.sum(x**2)

# 设置差分进化算法的参数
bounds = [(-10, 10), (-10, 10),(100,1000)]  # 每个维度的上下界
# 这里我们优化一个二元函数，所以有两个参数

# 使用差分进化算法求解
result = differential_evolution(objective_function, bounds)

# 输出结果
z = np.floor(result.x)
print("Optimization result:")
print("Minimum value:", result.fun)
print("Parameters:", z)

import itertools
import pandas as pd
import numpy as np
from scipy.optimize import least_squares

# 函数：计算音爆发生的位置和时间
def calculate_sound_blast(times):
    coords = np.array([
        [110.241 * 97304, 27.204 * 111263, 824],
        [110.780 * 97304, 27.456 * 111263, 727],
        [110.712 * 97304, 27.785 * 111263, 742],
        [110.524 * 97304, 27.617 * 111263, 786]
    ])
    v = 340

    # 定义一个目标函数，我们要找到这个函数的最小值
    def objective_function(vars):
        x, y, z, t = vars
        return np.sum((np.sqrt((x - coords[:, 0])**2 + (y - coords[:, 1])**2 + (z - coords[:, 2])**2) - v * (times - t))**2)

    # 设置差分进化算法的参数
    bounds = [(9730400, 11676480), (25*111263, 29*111263),(0,20000),(0,280)]  # 每个维度的上下界
    # 这里我们优化一个二元函数，所以有两个参数

    # 使用差分进化算法求解
    result = differential_evolution(objective_function, bounds)
    
    x, y, z, t = result.x

    x_km, y_km = x / 97304, y / 111263
    return x_km, y_km, z, t

# times = [100.767, 112.220, 188.020, 118.443]
# results=calculate_sound_blast(times)
# print(results)


# 原始数据
data = {
    'A': [100.767, 164.229, 214.850, 270.065],
    'B': [92.453, 112.220, 169.362, 196.583],
    'C': [75.560, 110.696, 156.936, 188.020],
    'E': [78.600, 86.216,  118.443, 126.669]
}

# 生成所有排列组合
data['A']=list(data['A'])
permutations_B = list(itertools.permutations(data['B']))
permutations_C = list(itertools.permutations(data['C']))
permutations_D = list(itertools.permutations(data['E']))

# 创建一个DataFrame来存储结果
results1 = []
results2 = []
results3 = []
results4 = []

# 对于每个设备，生成所有排列组合并存储在列表中
cnt=0
for perm_B in permutations_B:
    for perm_C in permutations_C:
        for perm_D in permutations_D: 
            # 将每个排列组合合并为一个列表
            cnt=cnt+1
            print(cnt)
            combined_times = np.array([data['A'][2], perm_B[2], perm_C[2], perm_D[2]])
            # 计算音爆发生的位置和时间
            longitude, latitude, altitude, time = calculate_sound_blast(combined_times)
            # 将结果存储在列表中
            results2.append({
                'longitude': longitude,
                'latitude': latitude,
                'altitude': altitude,
                'time': time
            })
# 将results2列表转换为DataFrame对象
results_df = pd.DataFrame(results2)

# 保存到CSV文件
results_df.to_csv('data1_2.csv', index=False)