function g = population(x,t)

%UNTITLED2 此处显示有关此函数的摘要

% 此处显示详细说明

g = x(1)./(1+(x(1)/3.9-1)*exp(-x(2)*t));

end