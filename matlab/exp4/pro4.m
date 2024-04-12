% 定义年利率
rates = [1.75, 2.3, 2.85, 3]/100; % 分别对应一年期、二年期、三年期、五年期的年利率

% 存款期限
total_years = 33;

% 初始本金
principal = 1; % 假设初始本金为1（为了简化计算，实际金额可以按比例放大）

% 计算每种策略的终值
final_values = zeros(1, 4); % 初始化数组，用于存储每种方案的终值
for i = 1:4
    switch i
        case 1 % 一年期，循环存33次
            years = 1;
        case 2 % 二年期，循环存16.5次，实际为16次
            years = 2;
        case 3 % 三年期，循环存11次
            years = 3;
        case 4 % 五年期，循环存6.6次，实际为6次加剩余年份
            years = 5;
    end
    cycles = floor(total_years / years); % 完整周期数
    remaining_years = total_years - cycles * years; % 剩余年份
    % 计算周期内的复利增长
    for j = 1:cycles
        principal = principal * (1 + rates(i));
    end
    % 计算剩余年份的增长，按最优利率计算
    if remaining_years > 0
        best_remaining_rate = max(rates(1:min(remaining_years,4))); % 假设剩余年份最优利率为剩余年限内的最高利率
        principal = principal * (1 + best_remaining_rate)^remaining_years;
    end
    final_values(i) = principal;
    principal = 1; % 重置本金为下一个方案计算
end

% 输出每种方案的终值
disp('终值（本金+利息）分别为：');% Define the objective function Y
objFun = @(k) -(1 + 0.0175)^k(1) * (1 + 0.023)^k(2) * (1 + 0.0285)^k(3) * (1 + 0.03)^k(4);

% Define the linear constraints A*k = b
A = [1, 2, 3, 5];
b = 33;

% Define the bounds for k
lb = [0, 0, 0, 0];  % Lower bounds
ub = [33, 16, 11, 6];  % Upper bounds

% Set the options to display the iterative output
options = optimoptions('fmincon','Display','iter','Algorithm','sqp');

% Initial guess (feasible w.r.t. the linear constraint)
k0 = [1, 1, 1, 6];

% Call fmincon to maximize the objective function
[k_opt, Y_max_neg] = fmincon(objFun, k0, A, b, [], [], lb, ub, [], options);

% Since we minimized the negative of Y to get the maximum, we take the negative of the output
Y_max = -Y_max_neg;

% Display the results
disp(['Optimal k values: ', num2str(k_opt)]);
disp(['Maximum Y value: ', num2str(Y_max)]);

disp(final_values);

% 找出最大终值及其对应的存款方案
[max_value, best_strategy] = max(final_values);
strategies = ["一年期", "二年期", "三年期", "五年期"];
fprintf('最优的存款方案为：%s，33年后的终值为：%f\n', strategies(best_strategy), max_value);
