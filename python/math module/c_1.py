import numpy as np
from scipy.optimize import least_squares

# 数据
coords = np.array([
    [110.241 * 97304, 27.204 * 111263, 824],
    [110.780 * 97304, 27.456 * 111263, 727],
    [110.712 * 97304, 27.785 * 111263, 742],
    [110.251 * 97304, 27.825 * 111263, 850]
])
times = np.array([100.767, 112.220, 188.020, 258.985])
v = 340

# 目标函数
def residuals(vars):
    x, y, z, t = vars
    return np.sqrt((x - coords[:, 0])**2 + (y - coords[:, 1])**2 + (z - coords[:, 2])**2) - v * (times - t)

# 初始猜测
initial_guess = [coords[:, 0].mean(), coords[:, 1].mean(), coords[:, 2].mean(), times.mean()]

# 最小二乘法求解
result = least_squares(residuals, initial_guess)
x, y, z, t = result.x

# 结果
x_km, y_km = x / 97304, y / 111263
print(f"音爆发生的经度: {x_km}°, 纬度: {y_km}°, 高程: {z} m, 时间: {t} s")
