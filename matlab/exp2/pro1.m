%% 同一个坐标系下
x = linspace(-4,4,1000);

% 计算 y1、y2、y3、y4
y1 = exp(x);
y2 = 1 + x;
y3 = 1 + x + 0.5 * x.^2;
y4 = 1 + x + 0.5 * x.^2 + 1/6 * x.^3;

% 绘制曲线
plot(x, y1, 'r', x, y2, 'g', x, y3, 'b', x, y4, 'm');
hold on; % 保持绘图区域

% 添加标注
legend('y = exp(x)', 'y = 1 + x', 'y = 1 + x + 0.5 * x^2', 'y = 1 + x + 0.5 * x^2 + 1/6 * x^3', 'Location', 'northwest');
title('Four Curves');
xlabel('x');
ylabel('y');

grid on; % 显示网格


%% 用subplot画出
x = linspace(-10, 10, 1000);

% 计算四个曲线的数据
y1 = exp(x);
y2 = 1 + x;
y3 = 1 + x + 0.5 * x.^2;
y4 = 1 + x + 0.5 * x.^2 + 1/6 * x.^3;

% 创建包含四个子图的图形
figure;

% 第一个子图
subplot(2, 2, 1);
plot(x, y1, 'b');
title('y = exp(x)');
xlabel('x');
ylabel('y');
grid on;

% 第二个子图
subplot(2, 2, 2);
plot(x, y2, 'r');
title('y = 1 + x');
xlabel('x');
ylabel('y');
grid on;

% 第三个子图
subplot(2, 2, 3);
plot(x, y3, 'g');
title('y = 1 + x + 0.5*x^2');
xlabel('x');
ylabel('y');
grid on;

% 第四个子图
subplot(2, 2, 4);
plot(x, y4, 'm');
title('y = 1 + x + 0.5*x^2 + 1/6*x^3');
xlabel('x');
ylabel('y');
grid on;

