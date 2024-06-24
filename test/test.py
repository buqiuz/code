import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.metrics import silhouette_score

# 加载鸢尾花数据集
data = load_iris()
X = data.data
y = data.target

# 实现k均值算法
def k_means(X, k, initial_centroids=None, max_iter=100):
    if initial_centroids is None:
        indices = np.random.choice(X.shape[0], k, replace=False)
        centroids = X[indices]
    else:
        centroids = initial_centroids

    for _ in range(max_iter):
        # 分配簇
        distances = np.sqrt(((X - centroids[:, np.newaxis])**2).sum(axis=2))
        closest_cluster = np.argmin(distances, axis=0)

        # 更新中心点
        new_centroids = np.array([X[closest_cluster == k].mean(axis=0) for k in range(centroids.shape[0])])
        if np.all(centroids == new_centroids):
            break
        centroids = new_centroids

    return centroids, closest_cluster
