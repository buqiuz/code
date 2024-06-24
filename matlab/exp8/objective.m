function error = objective(params, t)
    [~, Y] = ode45(@(t, Y) lotkaVolterraCompete(t, Y, params), t, [apple_sales(1), xiaomi_sales(1), other_sales(1)]);
    error = sum((Y(:,1) - apple_sales).^2) + sum((Y(:,2) - xiaomi_sales).^2) + sum((Y(:,3) - other_sales).^2);
end
