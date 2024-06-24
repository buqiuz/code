% 实际销售数据
data = [7500, 10800, 13900, 15000, 20800, 24000, 18900;
        16900, 23000, 21000, 21600, 21800, 19800, 20600;
        6107, 6655, 5542, 9141, 11860, 12460, 14600]';

% 时间点，对应数据月份
t_data = 1:size(data, 1);

% 初始条件和时间跨度
x0 = data(1, :);  % 使用第一个数据点作为初始条件
tspan_fit = linspace(min(t_data), max(t_data), 100);

initial_params = [0.1, 0.1, 0.1, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 1e5, 1e5, 1e5];
% 目标函数

% 初始参数估计


% 执行拟合
options = optimoptions('lsqcurvefit', 'Display', 'iter');
params_fit = lsqcurvefit(@model_fun, initial_params, t_data, data, [], [], options);

% 输出拟合参数
disp('拟合的参数:');
disp('增长率 r:');
disp(params_fit(1:3));
disp('竞争系数 s:');
disp(reshape(params_fit(4:12), 3, 3));
disp('市场容量 N:');
disp(params_fit(13:15));
