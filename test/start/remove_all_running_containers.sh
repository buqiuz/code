#!/bin/bash

# 获取所有正在运行的容器ID
running_containers=$(docker ps -q)

# 检查是否有正在运行的容器
if [ -n "$running_containers" ]; then
  echo "Stopping all running containers..."
  docker stop $running_containers

  echo "Removing all stopped containers..."
  docker rm $running_containers

  echo "All running containers have been stopped and removed."
else
  echo "No running containers to stop and remove."
fi
