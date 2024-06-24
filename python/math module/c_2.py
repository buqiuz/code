import numpy as np
from scipy.optimize import minimize

# 给定的数据
data = {
    'A': [110.241, 27.204, 824, [100.767, 164.229, 214.850, 270.065]],
    'B': [110.783, 27.456, 727, [92.453, 112.220, 169.362, 196.583]],
    'C': [110.762, 27.785, 742, [75.560, 110.696, 156.936, 188.020]],
    'D': [110.251, 28.025, 850, [94.653, 141.409, 196.517, 258.985]],
    'E': [110.524, 27.617, 786, [78.600, 86.216, 118.443, 126.669]],
    'F': [110.467, 28.081, 678, [67.274, 166.270, 175.482, 266.871]],
    'G': [110.047, 27.521, 575, [103.738, 163.024, 206.789, 210.306]]
}

# 转换为numpy数组
stations = np.array([[110.241, 27.204, 824],
                     [110.783, 27.456, 727],
                     [110.762, 27.785, 742],
                     [110.251, 28.025, 850],
                     [110.524, 27.617, 786],
                     [110.467, 28.081, 678],
                     [110.047, 27.521, 575]])
arrival_times = np.array([[100.767, 164.229, 214.850, 270.065],
                          [92.453, 112.220, 169.362, 196.583],
                          [75.560, 110.696, 156.936, 188.020],
                          [94.653, 141.409, 196.517, 258.985],
                          [78.600, 86.216, 118.443, 126.669],
                          [67.274, 166.270, 175.482, 266.871],
                          [103.738, 163.024, 206.789, 210.306]])

# 定义震动波速度
v = 340  # m/s

# 定义目标函数
def objective(params, stations, arrival_times, v):
    residuals = []
    num_stations, num_blasts = arrival_times.shape
    num_sources = 4  # 残骸数量
    for i in range(num_sources):
        x_i, y_i, z_i, t_i = params[4*i:4*i+4]
        for j in range(num_stations):
            t_ij = arrival_times[j, i]
            x_j, y_j, z_j = stations[j]
            d_ij = np.sqrt((x_i - x_j)**2 + (y_i - y_j)**2 + (z_i - z_j)**2)
            t_ij_pred = t_i + d_ij / v
            residuals.append(t_ij - t_ij_pred)
    return np.sum(np.square(residuals))

# 初始猜测
initial_guess = []
for i in range(4):
    initial_guess.extend([110.5, 27.5, 700, 100])  # 初始位置和时间猜测

# 最小化目标函数
result = minimize(objective, initial_guess, args=(stations, arrival_times, v), method='L-BFGS-B')

# 获取结果
positions_times = result.x
print("残骸位置和时间：")
for i in range(4):
    x_i, y_i, z_i, t_i = positions_times[4*i:4*i+4]
    print(f"残骸{i+1}: 位置=({x_i}, {y_i}, {z_i}), 音爆时间={t_i} s")
