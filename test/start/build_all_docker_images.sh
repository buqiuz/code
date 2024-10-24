#!/bin/bash

# 设置项目的根目录
PROJECT_ROOT=/blog

# 构建 blog-backend 镜像
echo "Building blog-backend Docker image..."
cd $PROJECT_ROOT/backend
docker build -t blog-backend .

# 构建 blog-ht 镜像
echo "Building blog-ht Docker image..."
cd $PROJECT_ROOT/blog-ht
docker build -t blog-ht .

# 构建 blog-qt 镜像
echo "Building blog-qt Docker image..."
cd $PROJECT_ROOT/blog-qt
docker build -t blog-qt .

echo "All Docker images have been built successfully."
