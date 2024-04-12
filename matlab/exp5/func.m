function [allocation, maxSatisfaction] = func(C, P)
    % C 是物品数量的向量
    % P 是偏好矩阵
    
    % 定义问题的大小
    [numPeople, numItems] = size(P);
    
    % 决策变量的数量
    numVars = numPeople * numItems;
    
    % 目标函数系数
    f = -P(:); % 将P转化为列向量，并取负值（因为MATLAB默认进行最小化）
    
    % 约束条件
    % A*x <= b
    A = [];
    b = [];
    
    % 物品数量约束
    for j = 1:numItems
        Arow = zeros(1, numVars);
        Arow((j-1)*numPeople+1:j*numPeople) = 1;
        A = [A; Arow];
        b = [b; C(j)];
    end
    
    % 二进制变量
    intcon = 1:numVars;
    
    % 变量界限
    lb = zeros(numVars, 1);
    ub = ones(numVars, 1);
    
    % 求解
    options = optimoptions('intlinprog', 'Display', 'off');
    [x, fval] = intlinprog(f, intcon, A, b, [], [], lb, ub, options);
    
    % 输出结果
    allocation = reshape(x, numPeople, numItems);
    maxSatisfaction = -fval; % 因为目标函数取了负值
end
