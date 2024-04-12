x=10;
y=2;
ans1=x^y;
ans2=x+y;
% C+R  添加注释    C+T   取消注释
%% 连续两个百分号加空格可以将脚本分节
% 使用C+↑或C+↓可以在不同小节之间切换
% 使用C+Enter可以只运行当前小节
%% format 
% clc 清空命令行   claer 清空工作区
%% 2-7

y=round(3.1415926,6)
fix(3.1415)
floor(4.65)
mod(15,4)
%%
% 定义 x 范围
x = -4*pi:0.01:4*pi; % 从 -π/2 到 π/2 创建 1000 个均匀间隔的点

% 计算正切函数的值
y = tan(x);

% 绘制图形
plot(x, y);
title('Tangent Function');
xlabel('x');
ylabel('tan(x)');
grid on;
axis equal

