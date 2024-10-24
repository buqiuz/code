import numpy as np

def simplex(c, A, b):
    """
    c: 系数矩阵的目标函数 (1 x n)
    A: 约束矩阵 (m x n)
    b: 约束常数 (m x 1)
    """
    m, n = A.shape

    # 构造初始单纯形表
    tableau = np.hstack((A, np.eye(m), b.reshape(-1, 1)))
    c = np.hstack((c, np.zeros(m + 1)))
    tableau = np.vstack((tableau, c))

    # 执行迭代直到找到最优解
    while True:
        # 检查目标函数的系数 (即最后一行)
        zj_cj = tableau[-1, :-1]

        # 如果目标函数的所有系数 <= 0，则当前解为最优解，停止
        if np.all(zj_cj <= 0):
            break

        # 找到进入基的变量 (最大正系数)
        entering = np.argmax(zj_cj)

        # 计算离开基的变量
        ratios = []
        for i in range(m):
            if tableau[i, entering] > 0:
                ratios.append(tableau[i, -1] / tableau[i, entering])
            else:
                ratios.append(np.inf)
        
        # 如果所有比值为无穷大，则问题无界，停止
        if all(r == np.inf for r in ratios):
            raise ValueError("问题无界")

        # 找到离开基的变量 (比值最小)
        leaving = np.argmin(ratios)

        # 进行枢轴操作
        pivot = tableau[leaving, entering]
        tableau[leaving, :] /= pivot

        for i in range(m + 1):
            if i != leaving:
                tableau[i, :] -= tableau[i, entering] * tableau[leaving, :]

    # 返回最优解和最大值
    solution = np.zeros(n)
    for i in range(m):
        if np.argmax(tableau[i, :n]) < n:
            solution[np.argmax(tableau[i, :n])] = tableau[i, -1]
    
    return solution, tableau[-1, -1]

# 示例用法
c = np.array([-3, -5])   # 目标函数
A = np.array([[1, 0], [0, 2], [3, 2]])   # 约束系数
b = np.array([4, 12, 18])  # 约束常数

solution, max_value = simplex(c, A, b)
print("最优解:", solution)
print("最大值:", max_value)
