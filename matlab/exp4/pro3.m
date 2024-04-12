% 定义目标函数，为了使用fmincon，需要定义为最小化，所以乘以-1
objFunc = @(x) -0.201*x(1)^4*x(2)^2*x(3)/(10^7);

% 定义非线性约束函数
nonlcon = @(x) deal([], [675 - x(1)^2*x(2); 0.419 - x(1)^2*x(3)^2/(10^7)]);

% 变量的初始猜测值
x0 = [1, 1, 1]; % 一个可能的起始点

% 变量的下界和上界
lb = [0, 0, 0];
ub = [36, 5, 125];

% 使用fmincon求解
options = optimoptions('fmincon', 'Display', 'iter', 'Algorithm', 'sqp');
[x, fval, exitflag, output] = fmincon(objFunc, x0, [], [], [], [], lb, ub, nonlcon, options);

% 输出结果
maximized_z = -fval % 取负值得到最大化目标函数的值
