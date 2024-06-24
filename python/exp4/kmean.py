import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn import datasets
from sklearn.metrics import silhouette_score

# 加载数据集
iris = datasets.load_iris()
X = iris.data

# 用于记录不同k值和初始中心点下的聚类结果
results = {}

# 不同的k值
k_values = [2, 3, 4]
# 选择三组不同的初始中心点种子
seeds = [0, 42, 99]

for k in k_values:
    for seed in seeds:
        kmeans = KMeans(n_clusters=k, random_state=seed)
        clusters = kmeans.fit_predict(X)
        
        # 计算轮廓系数
        silhouette_avg = silhouette_score(X, clusters)
        
        results[(k, seed)] = silhouette_avg

        # 可视化聚类结果
        plt.figure(figsize=(12, 4))
        plt.scatter(X[:, 0], X[:, 1], c=clusters, cmap='viridis', marker='o', edgecolor='k', s=50)
        plt.title(f'k={k}, seed={seed}, silhouette={silhouette_avg:.2f}')
        centers = kmeans.cluster_centers_
        plt.scatter(centers[:, 0], centers[:, 1], c='red', s=200, alpha=0.75)
        plt.xlabel('Sepal length')
        plt.ylabel('Sepal width')
        plt.show()

# 输出轮廓系数以比较聚类质量
for (k, seed), silhouette in results.items():
    print(f"k={k}, seed={seed}, silhouette score={silhouette:.2f}")
