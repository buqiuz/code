# # import matplotlib.pyplot as plt
# # from mpl_toolkits.mplot3d import Axes3D
# # import matplotlib.ticker as mticker
# # import numpy as np

# # # Data
# # debris_data = {
# #     'Debris 1': {'Longitude': 110.457995, 'Latitude': 27.681618, 'Altitude': 798.4, 'Time': 95.30},
# #     'Debris 2': {'Longitude': 110.488570, 'Latitude': 27.656313, 'Altitude': 777.6, 'Time': 95.53},
# #     'Debris 3': {'Longitude': 110.479030, 'Latitude': 27.679734, 'Altitude': 1685.8, 'Time': 97.38},
# #     'Debris 4': {'Longitude': 110.490165, 'Latitude': 27.609234, 'Altitude': 8768.6, 'Time': 99.21}
# # }

# # # Extract data for plotting
# # longitudes = [debris['Longitude'] for debris in debris_data.values()]
# # latitudes = [debris['Latitude'] for debris in debris_data.values()]
# # altitudes = [debris['Altitude'] for debris in debris_data.values()]
# # times = [debris['Time'] for debris in debris_data.values()]
# # labels = list(debris_data.keys())

# # # Normalize time for color mapping
# # norm = plt.Normalize(min(times), max(times))
# # colors = plt.cm.viridis(norm(times))

# # # Plotting
# # fig = plt.figure(figsize=(10, 8))
# # ax = fig.add_subplot(111, projection='3d')

# # # Scatter plot with enhanced styling
# # scatter = ax.scatter(longitudes, latitudes, altitudes, c=colors, marker='o', s=100, edgecolors='w', linewidth=1, cmap='viridis')

# # # Annotate each point with the debris label
# # for i, label in enumerate(labels):
# #     ax.text(longitudes[i], latitudes[i], altitudes[i], f'{label}\nTime: {times[i]}s', fontsize=10, fontweight='bold')

# # # Labels and title with enhanced styling
# # ax.set_xlabel('Longitude', fontsize=12, fontweight='bold')
# # ax.set_ylabel('Latitude', fontsize=12, fontweight='bold')
# # ax.set_zlabel('Altitude (m)', fontsize=12, fontweight='bold')
# # ax.set_title('Debris Locations in 3D Space', fontsize=15, fontweight='bold')

# # # Set formatter to avoid scientific notation
# # ax.xaxis.set_major_formatter(mticker.FormatStrFormatter('%.6f'))

# # # Set grid and background color
# # ax.grid(True, linestyle='--', linewidth=0.5)
# # ax.set_facecolor('lightgrey')

# # # Add a color bar to show the time scale
# # cbar = plt.colorbar(scatter, ax=ax, pad=0.1)
# # cbar.set_label('Time (s)', fontsize=12, fontweight='bold')

# # # Show plot
# # plt.show()


# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
# import matplotlib.ticker as mticker
# import numpy as np

# # Data for debris
# debris_data = {
#     'Debris 1': {'Longitude': 110.457995, 'Latitude': 27.681618, 'Altitude': 798.4, 'Time': 95.30},
#     'Debris 2': {'Longitude': 110.488570, 'Latitude': 27.656313, 'Altitude': 777.6, 'Time': 95.53},
#     'Debris 3': {'Longitude': 110.479030, 'Latitude': 27.679734, 'Altitude': 1685.8, 'Time': 97.38},
#     'Debris 4': {'Longitude': 110.490165, 'Latitude': 27.609234, 'Altitude': 8768.6, 'Time': 99.21}
# }

# # Data for monitoring devices
# monitoring_data = {
#     'Device A': {'Longitude': 110.241, 'Latitude': 27.204, 'Altitude': 824},
#     'Device B': {'Longitude': 110.783, 'Latitude': 27.456, 'Altitude': 727},
#     'Device C': {'Longitude': 110.762, 'Latitude': 27.785, 'Altitude': 742},
#     'Device D': {'Longitude': 110.251, 'Latitude': 28.025, 'Altitude': 850},
#     'Device E': {'Longitude': 110.524, 'Latitude': 27.617, 'Altitude': 786},
#     'Device F': {'Longitude': 110.467, 'Latitude': 28.081, 'Altitude': 678},
#     'Device G': {'Longitude': 110.047, 'Latitude': 27.521, 'Altitude': 575}
# }

# # Extract data for plotting
# longitudes_debris = [debris['Longitude'] for debris in debris_data.values()]
# latitudes_debris = [debris['Latitude'] for debris in debris_data.values()]
# altitudes_debris = [debris['Altitude'] for debris in debris_data.values()]
# times_debris = [debris['Time'] for debris in debris_data.values()]
# labels_debris = list(debris_data.keys())

# longitudes_devices = [device['Longitude'] for device in monitoring_data.values()]
# latitudes_devices = [device['Latitude'] for device in monitoring_data.values()]
# altitudes_devices = [device['Altitude'] for device in monitoring_data.values()]
# labels_devices = list(monitoring_data.keys())

# # Normalize time for color mapping
# norm = plt.Normalize(min(times_debris), max(times_debris))
# colors = plt.cm.viridis(norm(times_debris))

# # Plotting
# fig = plt.figure(figsize=(12, 10))
# ax = fig.add_subplot(111, projection='3d')

# # Scatter plot for debris
# scatter_debris = ax.scatter(longitudes_debris, latitudes_debris, altitudes_debris, c=colors, marker='o', s=100, edgecolors='w', linewidth=1, cmap='viridis', label='Debris')

# # Annotate each debris point
# for i, label in enumerate(labels_debris):
#     ax.text(longitudes_debris[i], latitudes_debris[i], altitudes_debris[i], f'{label}\nTime: {times_debris[i]}s', fontsize=10, fontweight='bold')

# # Scatter plot for monitoring devices
# scatter_devices = ax.scatter(longitudes_devices, latitudes_devices, altitudes_devices, c='red', marker='^', s=100, edgecolors='k', linewidth=1, label='Monitoring Devices')

# # Annotate each device point
# for i, label in enumerate(labels_devices):
#     ax.text(longitudes_devices[i], latitudes_devices[i], altitudes_devices[i], f'{label}', fontsize=10, fontweight='bold')

# # Labels and title with enhanced styling
# ax.set_xlabel('Longitude', fontsize=12, fontweight='bold')
# ax.set_ylabel('Latitude', fontsize=12, fontweight='bold')
# ax.set_zlabel('Altitude (m)', fontsize=12, fontweight='bold')
# ax.set_title('Debris and Monitoring Devices Locations in 3D Space', fontsize=15, fontweight='bold')

# # Set formatter to avoid scientific notation
# ax.xaxis.set_major_formatter(mticker.FormatStrFormatter('%.6f'))

# # Set grid and background color
# ax.grid(True, linestyle='--', linewidth=0.5)
# ax.set_facecolor('lightgrey')

# # Add a color bar to show the time scale for debris
# cbar = plt.colorbar(scatter_debris, ax=ax, pad=0.1)
# cbar.set_label('Time (s)', fontsize=12, fontweight='bold')

# # Add legend
# ax.legend(loc='upper left', fontsize=12)

# # Show plot
# plt.show()


import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.ticker as mticker
import numpy as np

# Data for debris
debris_data = {
    'Debris 1': {'Longitude': 110.457995, 'Latitude': 27.681618, 'Altitude': 798.4, 'Time': 95.30},
    'Debris 2': {'Longitude': 110.488570, 'Latitude': 27.656313, 'Altitude': 777.6, 'Time': 95.53},
    'Debris 3': {'Longitude': 110.479030, 'Latitude': 27.679734, 'Altitude': 1685.8, 'Time': 97.38},
    'Debris 4': {'Longitude': 110.490165, 'Latitude': 27.609234, 'Altitude': 8768.6, 'Time': 99.21}
}

# Data for monitoring devices
monitoring_data = {
    'Device A': {'Longitude': 110.241, 'Latitude': 27.204, 'Altitude': 824},
    'Device B': {'Longitude': 110.783, 'Latitude': 27.456, 'Altitude': 727},
    'Device C': {'Longitude': 110.762, 'Latitude': 27.785, 'Altitude': 742},
    'Device D': {'Longitude': 110.251, 'Latitude': 28.025, 'Altitude': 850},
    'Device E': {'Longitude': 110.524, 'Latitude': 27.617, 'Altitude': 786},
    'Device F': {'Longitude': 110.467, 'Latitude': 28.081, 'Altitude': 678},
    'Device G': {'Longitude': 110.047, 'Latitude': 27.521, 'Altitude': 575}
}

# Extract data for plotting
longitudes_debris = [debris['Longitude'] for debris in debris_data.values()]
latitudes_debris = [debris['Latitude'] for debris in debris_data.values()]
altitudes_debris = [debris['Altitude'] for debris in debris_data.values()]
times_debris = [debris['Time'] for debris in debris_data.values()]
labels_debris = list(debris_data.keys())

longitudes_devices = [device['Longitude'] for device in monitoring_data.values()]
latitudes_devices = [device['Latitude'] for device in monitoring_data.values()]
altitudes_devices = [device['Altitude'] for device in monitoring_data.values()]
labels_devices = list(monitoring_data.keys())

# Normalize time for color mapping
norm = plt.Normalize(min(times_debris), max(times_debris))
colors = plt.cm.viridis(norm(times_debris))

# Plotting
fig = plt.figure(figsize=(12, 10))
ax = fig.add_subplot(111, projection='3d')

# Scatter plot for debris
scatter_debris = ax.scatter(longitudes_debris, latitudes_debris, altitudes_debris, c=colors, marker='o', s=100, edgecolors='w', linewidth=1, cmap='viridis', label='Debris')

# Annotate each debris point
for i, label in enumerate(labels_debris):
    ax.text(longitudes_debris[i], latitudes_debris[i], altitudes_debris[i], f'{label}', fontsize=10, fontweight='bold')

# Scatter plot for monitoring devices
scatter_devices = ax.scatter(longitudes_devices, latitudes_devices, altitudes_devices, c='red', marker='^', s=100, edgecolors='k', linewidth=1, label='Monitoring Devices')

# Annotate each device point
for i, label in enumerate(labels_devices):
    ax.text(longitudes_devices[i], latitudes_devices[i], altitudes_devices[i], f'{label}', fontsize=10, fontweight='bold')

# Labels and title with enhanced styling
ax.set_xlabel('Longitude', fontsize=12, fontweight='bold')
ax.set_ylabel('Latitude', fontsize=12, fontweight='bold')
ax.set_zlabel('Altitude (m)', fontsize=12, fontweight='bold')
ax.set_title('Debris and Monitoring Devices Locations in 3D Space', fontsize=15, fontweight='bold')

# Set formatter to avoid scientific notation
ax.xaxis.set_major_formatter(mticker.FormatStrFormatter('%.6f'))

# Set grid and background color
ax.grid(True, linestyle='--', linewidth=0.5)
ax.set_facecolor('lightgrey')

# Add a color bar to show the time scale for debris
cbar = plt.colorbar(scatter_debris, ax=ax, pad=0.1)
cbar.set_label('Time (s)', fontsize=12, fontweight='bold')

# Add legend
ax.legend(loc='upper left', fontsize=12)

# Show plot
plt.show()
