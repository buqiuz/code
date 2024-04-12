syms x y;
e1 = x + y^2 - 13;
e2 = log(2*x + y) - x^2 + 2;

% 寻找数值解
[x0, y0] = vpasolve([e1 == 0, e2 == 0], [x, y]);

% 显示数值解
disp(['x = ' char(sol_x)]);
disp(['y = ' char(sol_y)]);
