filename = 'D:\BaiduSyncdisk\作业\数学实验\数学实验（22计算机）第5周作业\表1.xls'; % Excel 文件路径
dataRange1 = 'C2:L2'; % 物品数量读取范围
dataRange2 = 'C3:L102'; % 债权人偏好读取范围
sheetName = 'Data'; % 工作表名称

C = readmatrix(filename, 'Range', dataRange1, 'Sheet', sheetName);
P = readmatrix(filename, 'Range', dataRange2, 'Sheet', sheetName);



% 调用函数
[allocation, maxSatisfaction] = func(C, P);

% 显示最大满意度
disp('最大满意度:');
disp(maxSatisfaction);

% 如果需要，还可以显示具体的分配方案
disp('分配方案:');
disp(allocation);
