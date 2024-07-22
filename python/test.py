import pandas as pd
import random

# 生成100行数据
data = {
    'ExamScoreId': list(range(4, 104)),
    'StudentId': [f'2022{random.randint(1000, 9999)}' for _ in range(100)],
    'CourseId': [102]*100,
    'Score': [random.randint(50, 100) for _ in range(100)],
    'Credit': [5]*100,
    'Coursename': ['高等数学']*100
}

df = pd.DataFrame(data)

# 生成SQL插入语句
insert_statements = []
for index, row in df.iterrows():
    insert_statement = f"INSERT INTO examscore (ExamScoreId, StudentId, CourseId, Score, Credit, Coursename) VALUES ({row['ExamScoreId']}, '{row['StudentId']}', {row['CourseId']}, {row['Score']}, {row['Credit']}, '{row['Coursename']}');"
    insert_statements.append(insert_statement)

# 将所有插入语句保存到一个SQL文件中
with open('insert_statements.sql', 'w', encoding='utf-8') as f:
    for statement in insert_statements:
        f.write(statement + '\n')

print("SQL insert statements generated and saved to insert_statements.sql")
