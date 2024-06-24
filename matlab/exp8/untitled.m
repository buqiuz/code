% 销售数据
apple_sales = [7500, 10800, 13900, 15000, 20800, 24000, 18900];
xiaomi_sales = [14900, 23000, 21000, 21600, 21800, 19800, 20600];
other_sales = [6107, 6655, 5542, 9141, 11860, 12460, 14600];

% 时间点
t = linspace(0, 6, 7);

% 初始参数
params = [0.3, 0.3, 0.3, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 30000, 30000, 30000];

% 定义Lotka-Volterra竞争模型函数


% 优化目标函数，现在包含t作为参数

% 使用MATLAB优化工具箱进行参数优化
options = optimoptions('fmincon', 'Algorithm', 'sqp');
lb = [0.01 0.01 0.01 0.001 0.001 0.001 0.001 0.001 0.001 10000 10000 10000];
ub = [1 1 1 0.1 0.1 0.1 0.1 0.1 0.1 50000 50000 50000];
[optimized_params, ~] = fmincon(@(p) objective(p, t), params, [], [], [], [], lb, ub, [], options);

% 解优化后的模型
[~, Y_opt] = ode45(@(t, Y) lotkaVolterraCompete(t, Y, optimized_params), t, [apple_sales(1), xiaomi_sales(1), other_sales(1)]);

% 绘制结果
figure;
hold on;
plot(t, apple_sales, 'ro-');
plot(t, xiaomi_sales, 'go-');
plot(t, other_sales, 'bo-');
plot(t, Y_opt(:,1), 'r--');
plot(t, Y_opt(:,2), 'g--');
plot(t, Y_opt(:,3), 'b--');
legend('Apple Sales Data', 'Xiaomi Sales Data', 'Other Sales Data', 'Model Apple', 'Model Xiaomi', 'Model Other');
xlabel('Time');
ylabel('Sales');
title('Optimized Lotka-Volterra Competition Model vs Sales Data');
hold off;
