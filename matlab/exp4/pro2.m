% 目标函数的系数
f = -[193, 191, 187, 186, 180, 185]; % 乘以-1是因为intlinprog默认是求最小值

% 不等式约束条件
A = [
     0,  0,  0,  0, -1, -1;
     0,  0, -1,  0, -1,  0;
     1,  1,  0,  0,  0,  0;
     0,  1,  0,  0,  0,  1;
     0,  0,  0,  1,  0,  1
];
b = [-1; -1; 1; 1; 1];

% 等式约束条件
Aeq = [1, 1, 1, 1, 1, 1];
beq = 3;

% 变量的界限
lb = zeros(6,1);
ub = ones(6,1);

% 变量的类型，这里都是整数
intcon = 1:6;

% 求解0-1整数规划
[x, fval, exitflag, output] = intlinprog(f, intcon, A, b, Aeq, beq, lb, ub);

x'
% 将目标函数的值乘以-1以得到最大值
maximized_z = -fval
