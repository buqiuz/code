% 定义 x 的范围
x = linspace(0, 6, 1000);

% 计算函数值
y = x.^4 - 4*x.^3 + 3*x + 5;

% 绘制函数图形
plot(x, y);
xlabel('x');
ylabel('y');
title('Plot of y = x^4 - 4x^3 + 3x + 5');

% 在 [0,6] 范围内找到最小值点
x_range = linspace(0, 6, 1000);
y_range = x_range.^4 - 4*x_range.^3 + 3*x_range + 5;
[min_y, min_index] = min(y_range);
min_x = x_range(min_index);

% 标记最小值点
hold on;
plot(min_x, min_y, 'ro'); % 在最小值点处绘制红色圆点
text(min_x, min_y, ['min: (', num2str(min_x), ', ', num2str(min_y), ')']); % 添加文本标签
hold off;
