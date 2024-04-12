% 定义微分方程
f = @(x, y) y - 2 * x / y;

% 设置初始条件和参数
x0 = 0;
y0 = 1;
h = 0.1;
xf = 1;

% 计算迭代次数
k = (xf - x0) / h;

% 初始化 x 和 y（向前欧拉法）
x_forward = zeros(1, k+1);
y_forward = zeros(1, k+1);
x_forward(1) = x0;
y_forward(1) = y0;

% 向前欧拉法
for n = 1:k
    x_forward(n+1) = x_forward(n) + h; % 计算下一个 x 的值
    y_forward(n+1) = y_forward(n) + h * f(x_forward(n), y_forward(n)); % 使用向前欧拉法更新下一个 y 的值
end

% 初始化 x 和 y（改进的欧拉法）
x_improved = zeros(1, k+1);
y_improved = zeros(1, k+1);
x_improved(1) = x0;
y_improved(1) = y0;

% 改进的欧拉法
for n = 1:k
    x_improved(n+1) = x_improved(n) + h; % 计算下一个 x 的值
    y_temp = y_improved(n) + h * f(x_improved(n), y_improved(n)); % 计算临时的 y 值
    y_improved(n+1) = y_improved(n) + h * (f(x_improved(n), y_improved(n)) + f(x_improved(n+1), y_temp)) / 2; % 使用改进的欧拉法更新下一个 y 的值
end

% 绘制结果
plot(x_forward, y_forward, 'b.-', x_improved, y_improved, 'r.-');
legend('Forward Euler', 'Improved Euler');
xlabel('x');
ylabel('y');
title('Comparison of Forward Euler and Improved Euler Methods');
