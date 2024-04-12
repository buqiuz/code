% 定义方程组
equations = @(x) [
    x(1) + x(2)^2 - 13
    log(2*x(1) + x(2)) - x(1)^x(2) + 2
];

% 初始值1
x1 = 1;
y1 = 3;

% 初始值2
x2 = 2;
y2 = 4;

% 求解方程组
solution_1 = fsolve(equations, [x1, y1]);
solution_2 = fsolve(equations, [x2, y2]);

% 定义输出格式为long g
format long g;

% 显示结果
disp('Solution 1:');
disp(solution_1);
disp('Solution 2:');
disp(solution_2);

% 验证初始值1
verification_1 = equations(solution_1);
disp('Verification for solution 1:');
disp(verification_1);

% 验证初始值2
verification_2 = equations(solution_2);
disp('Verification for solution 2:');
disp(verification_2);

