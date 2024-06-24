# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
# import matplotlib.ticker as mticker
# import numpy as np

# # 更新的数据
# debris_data = {
#     'Debris 1': {'Longitude': 110.457984, 'Latitude': 27.682318, 'Altitude': 799.3, 'Time': 95.21},
#     'Debris 2': {'Longitude': 110.487945, 'Latitude': 27.664313, 'Altitude': 803.5, 'Time': 95.53},
#     'Debris 3': {'Longitude': 110.478963, 'Latitude': 27.679264, 'Altitude': 1705.3, 'Time': 97.46},
#     'Debris 4': {'Longitude': 110.490138, 'Latitude': 27.609531, 'Altitude': 7936.4, 'Time': 98.93}
# }

# # 监控设备数据保持不变
# monitoring_data = {
#     'Device A': {'Longitude': 110.241, 'Latitude': 27.204, 'Altitude': 824},
#     'Device B': {'Longitude': 110.783, 'Latitude': 27.456, 'Altitude': 727},
#     'Device C': {'Longitude': 110.762, 'Latitude': 27.785, 'Altitude': 742},
#     'Device D': {'Longitude': 110.251, 'Latitude': 28.025, 'Altitude': 850},
#     'Device E': {'Longitude': 110.524, 'Latitude': 27.617, 'Altitude': 786},
#     'Device F': {'Longitude': 110.467, 'Latitude': 28.081, 'Altitude': 678},
#     'Device G': {'Longitude': 110.047, 'Latitude': 27.521, 'Altitude': 575}
# }

# # 提取绘图数据
# longitudes_debris = [debris['Longitude'] for debris in debris_data.values()]
# latitudes_debris = [debris['Latitude'] for debris in debris_data.values()]
# altitudes_debris = [debris['Altitude'] for debris in debris_data.values()]
# times_debris = [debris['Time'] for debris in debris_data.values()]
# labels_debris = list(debris_data.keys())

# longitudes_devices = [device['Longitude'] for device in monitoring_data.values()]
# latitudes_devices = [device['Latitude'] for device in monitoring_data.values()]
# altitudes_devices = [device['Altitude'] for device in monitoring_data.values()]
# labels_devices = list(monitoring_data.keys())

# # 归一化时间用于颜色映射
# norm = plt.Normalize(min(times_debris), max(times_debris))
# colors = plt.cm.viridis(norm(times_debris))

# # 绘图
# fig = plt.figure(figsize=(14, 12))
# ax = fig.add_subplot(111, projection='3d')

# # 残骸的散点图
# scatter_debris = ax.scatter(longitudes_debris, latitudes_debris, altitudes_debris, c=colors, marker='o', s=120, edgecolors='w', linewidth=1.5, cmap='viridis', label='Debris')

# # 注释每个残骸点
# for i, label in enumerate(labels_debris):
#     ax.text(longitudes_debris[i], latitudes_debris[i], altitudes_debris[i], f'{label}', fontsize=11, fontweight='bold', color='blue', ha='right')

# # # 监控设备的散点图
# # scatter_devices = ax.scatter(longitudes_devices, latitudes_devices, altitudes_devices, c='red', marker='^', s=120, edgecolors='k', linewidth=1.5, label='Monitoring Devices')

# # # 注释每个设备点
# # for i, label in enumerate(labels_devices):
# #     ax.text(longitudes_devices[i], latitudes_devices[i], altitudes_devices[i], f'{label}', fontsize=11, fontweight='bold', color='black', ha='right')

# # 标签和标题增强样式
# ax.set_xlabel('Longitude', fontsize=14, fontweight='bold')
# ax.set_ylabel('Latitude', fontsize=14, fontweight='bold')
# ax.set_zlabel('Altitude (m)', fontsize=14, fontweight='bold')
# ax.set_title('Debris and Monitoring Devices Locations in 3D Space', fontsize=18, fontweight='bold')

# # 设置格式化器以避免科学计数法
# ax.xaxis.set_major_formatter(mticker.FormatStrFormatter('%.6f'))

# # 设置网格和背景颜色
# ax.grid(True, linestyle='--', linewidth=0.7)
# ax.set_facecolor('whitesmoke')

# # 添加颜色条以显示残骸的时间刻度
# cbar = plt.colorbar(scatter_debris, ax=ax, pad=0.1)
# cbar.set_label('Time (s)', fontsize=14, fontweight='bold')

# # 添加图例
# ax.legend(loc='upper left', fontsize=14)

# # 显示图表
# plt.show()
import matplotlib.pyplot as plt

# 更新的数据
debris_data = {
    'Debris 1': {'Longitude': 110.457984, 'Latitude': 27.682318, 'Altitude': 799.3, 'Time': 95.21},
    'Debris 2': {'Longitude': 110.487945, 'Latitude': 27.664313, 'Altitude': 803.5, 'Time': 95.53},
    'Debris 3': {'Longitude': 110.478963, 'Latitude': 27.679264, 'Altitude': 1705.3, 'Time': 97.46},
    'Debris 4': {'Longitude': 110.490138, 'Latitude': 27.609531, 'Altitude': 7936.4, 'Time': 98.93}
}

# 监控设备数据
monitoring_data = {
    'Device A': {'Longitude': 110.241, 'Latitude': 27.204, 'Altitude': 824},
    'Device B': {'Longitude': 110.783, 'Latitude': 27.456, 'Altitude': 727},
    'Device C': {'Longitude': 110.762, 'Latitude': 27.785, 'Altitude': 742},
    'Device D': {'Longitude': 110.251, 'Latitude': 28.025, 'Altitude': 850},
    'Device E': {'Longitude': 110.524, 'Latitude': 27.617, 'Altitude': 786},
    'Device F': {'Longitude': 110.467, 'Latitude': 28.081, 'Altitude': 678},
    'Device G': {'Longitude': 110.047, 'Latitude': 27.521, 'Altitude': 575}
}

# 提取数据
longitudes_debris = [debris['Longitude'] for debris in debris_data.values()]
latitudes_debris = [debris['Latitude'] for debris in debris_data.values()]
labels_debris = list(debris_data.keys())

longitudes_devices = [device['Longitude'] for device in monitoring_data.values()]
latitudes_devices = [device['Latitude'] for device in monitoring_data.values()]
labels_devices = list(monitoring_data.keys())

# 绘制二维平面
plt.figure(figsize=(14, 10))

# 绘制残骸的点
plt.scatter(longitudes_debris, latitudes_debris, c='blue', marker='o', s=100, label='Debris', edgecolors='w', linewidth=1.5)

# 注释每个残骸点
for i, label in enumerate(labels_debris):
    plt.text(longitudes_debris[i], latitudes_debris[i], f'{label}', fontsize=11, fontweight='bold', color='blue', ha='right')

# 绘制监控设备的点
plt.scatter(longitudes_devices, latitudes_devices, c='red', marker='^', s=100, label='Monitoring Devices', edgecolors='k', linewidth=1.5)

# 注释每个设备点
for i, label in enumerate(labels_devices):
    plt.text(longitudes_devices[i], latitudes_devices[i], f'{label}', fontsize=11, fontweight='bold', color='black', ha='right')

# 设置标签和标题
plt.xlabel('Longitude', fontsize=14, fontweight='bold')
plt.ylabel('Latitude', fontsize=14, fontweight='bold')
plt.title('Debris and Monitoring Devices Locations in 2D Plane', fontsize=18, fontweight='bold')

# 添加网格和背景颜色
plt.grid(True, linestyle='--', linewidth=0.7)
plt.gca().set_facecolor('whitesmoke')

# 添加图例
plt.legend(loc='upper left', fontsize=14)

# 显示图表
plt.show()
