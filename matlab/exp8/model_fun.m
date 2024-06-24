function F = model_fun(params, t_data)
    r = params(1:3);
    s = reshape(params(4:12), 3, 3);
    N = params(13:15);
    
    lotka_volterra_compete = @(t, Y) [
        r(1)*Y(1)*(1 - Y(1)/N(1) - s(1,2)*Y(2)/N(2) - s(1,3)*Y(3)/N(3));
        r(2)*Y(2)*(1 - Y(2)/N(2) - s(2,1)*Y(1)/N(1) - s(2,3)*Y(3)/N(3));
        r(3)*Y(3)*(1 - Y(3)/N(3) - s(3,1)*Y(1)/N(1) - s(3,2)*Y(2)/N(2))
    ];

    [t, Y] = ode45(lotka_volterra_compete, tspan_fit, x0);
    F = interp1(t, Y, t_data);  % 插值到实际的数据时间点
end
