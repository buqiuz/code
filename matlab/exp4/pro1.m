% Objective function coefficients (note the negation for maximization)
f = [-2, -9, -10, -7, -1, -3, -4, -2, -8, -4, -2, -5];

% Equality constraints
Aeq = [
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0;
    0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0;
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1;
    1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0;
    0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0;
    0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0;
    0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1
];

beq = [9; 5; 7; 3; 8; 4; 6];

% Lower bounds
lb = zeros(12, 1);

% No upper bounds, hence an empty matrix
ub = [];

% Since the `linprog` function minimizes by default and we need to maximize,
% we can simply multiply the objective function by -1 and then negate the result.

% Solve the linear programming problem
options = optimoptions('linprog','Algorithm','dual-simplex');
[x, fval, exitflag, output] = linprog(f, [], [], Aeq, beq, lb, ub, options);

% Display the results
x = reshape(x, 4, 3)'
maximized_z = -fval
