% 定义问题参数
funds = 100000; % 初始资金
rates = [-0.15*ones(1, 4), -0.25, -0.40, -0.06*ones(1, 5)]; % 项目的负收益率

% 不等式约束矩阵和向量
A = [1 1 1 1 0 0 1 1 1 1 1; % 项目A每年投资和项目D投资的总和不能超过funds
     0 0 0 0 1 0 0 0 0 0 0; % 项目B在第三年投资，不能超过40000
     0 0 0 0 0 1 0 0 0 0 0; % 项目C在第二年投资，不能超过30000
    -1 0 0 0 0 0 0 0 0 0 0; % 项目A第一年的收益
     0 -1 0 0 0 0 0 0 0 0 0; % 项目A第二年的收益
     0 0 -1 0 0 0 -1 0 0 0 0; % 项目A第三年和项目D第一年的收益
     0 0 0 -1 0 0 0 -1 0 0 0; % 项目A第四年和项目D第二年的收益
     0 0 0 0 -1 0 0 0 -1 0 0; % 项目B第五年和项目D第三年的收益
     0 0 0 0 0 -1 0 0 0 -1 0]; % 项目C第五年和项目D第四年的收益
b = [funds; 40000; 30000; 0; 0; 0; 0; 0; 0];

% 等式约束矩阵和向量（如果有）

% 变量的下界和上界
lb = zeros(11, 1); % 所有投资都应该非负
ub = [funds; funds; funds; funds; 40000; 30000; funds; funds; funds; funds; funds]; % 项目B和C有上限

% 调用linprog函数
options = optimoptions('linprog','Algorithm','dual-simplex'); % 设置算法选项
[x, fval] = linprog(rates, A, b, [], [], lb, ub, options);

% 计算最大收益
max_return = -fval + funds;

% 打印结果
disp('投资策略:');
disp(x);
fprintf('最大收益: %.2f\n', max_return);
