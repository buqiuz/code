% 定义模型方程
function dYdt = competition_model(t, Y, params)
    r = params(1:3);
    s = reshape(params(4:12), 3, 3);
    N = params(13:15);
    
    dYdt = zeros(3,1);
    for i = 1:3
        dYdt(i) = r(i)*Y(i)*(1 - Y(i)/N(i) - sum(s(i,:)'.*Y./N));
    end
end

