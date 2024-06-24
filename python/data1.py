import itertools
import pandas as pd

# 原始数据
data = {
    'A': [100.767, 164.229, 214.850, 270.065],
    'B': [92.453, 112.220, 169.362, 196.583],
    'C': [75.560, 110.696, 156.936, 188.020],
    'D': [94.653, 141.409, 196.517, 258.985]
}

# 生成 [100.767, 164.229, 214.850, 270.065] 的所有排列组合
permutations_A = list(itertools.permutations(data['A']))
permutations_B = list(itertools.permutations(data['B']))
permutations_C = list(itertools.permutations(data['C']))
permutations_D = list(itertools.permutations(data['D']))

# 创建一个DataFrame来存储结果
results = []

# 对于每个设备，生成所有排列组合并存储在列表中
for perm_A in permutations_A:
    for perm_B in permutations_B:
        for perm_C in permutations_C:
            for perm_D in permutations_D:
                results.append({
                    'A': perm_A,
                    'B': perm_B,
                    'C': perm_C,
                    'D': perm_D
                })

# 转换为DataFrame
results_df = pd.DataFrame(results)

# 打印或保存结果
print(results_df)

# 保存到CSV文件
results_df.to_csv('sound_explosion_data_permutations.csv', index=False)
