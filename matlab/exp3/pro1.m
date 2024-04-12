syms y(x);
eqn = diff(y,x) == y+2*x; % 定义微分方程
cond = y(0) == 1; % 设置初始条件 y(0) = 1
ySol(x) = dsolve(eqn, cond) % 求解微分方程

% 绘制解析解
x = linspace(0,1,1000); % 时间范围
plot(x, y);
xlabel('x');
ylabel('y');
title('Analytical Solution of ODE');
