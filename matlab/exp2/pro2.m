x = linspace(-5, 5, 100);
y = linspace(-5, 5, 100);

[X, Y] = meshgrid(x, y);
Z = Y.^2 - 3*X.*Y + X.^2;

surf(X, Y, Z);
xlabel('x');
ylabel('y');
zlabel('z');
title('z = y^2 - 3xy + x^2');

colormap('jet');
colorbar;
