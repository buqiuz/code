function rossler(a)
    % 定义参数和微分方程组
    b = 2;
    c = 4;
    dxdt = @(t, x) -x(2) - x(3);
    dydt = @(t, x) x(1) + a * x(2);
    dzdt = @(t, x) b + x(3) * (x(1) - c);
    
    % 设置时间范围
    tspan = [0 70];
    
    % 设置初始条件
    x0 = [0; 0.1; 0.1];
    
    % 使用 ODE45 求解微分方程
    [t, x] = ode45(@(t, x) [dxdt(t, x); dydt(t, x); dzdt(t, x)], tspan, x0);
    
    % 绘制相图
    figure;
    plot3(x(:,1), x(:,2), x(:,3));
    xlabel('x');
    ylabel('y');
    zlabel('z');
    title(['Rossler Equation, a = ', num2str(a)]);
    grid on;
end

% 设置不同的 a 值

