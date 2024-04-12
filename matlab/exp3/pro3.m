a_values = [0.2, 0.4, 0.6];

% 绘制不同 a 值对应的相图
for i = 1:length(a_values)
    rossler(a_values(i));
end