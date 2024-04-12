
%下面是.m文件的程序，该文件需要以appollo命名
function dx=appollo(t,x)

mu=1/82.45;
fai=1-mu;
r1=sqrt((x(1)+mu)^2+x(3)^2);
r2=sqrt((x(1)-fai)^2+x(3)^2);
dx=[x(2)
2*x(4)+x(1)-fai*(x(1)+mu)/r1^3-mu*(x(1)-fai)/r2^3
x(4)
-2*x(2)+x(3)-fai*x(3)/r1^3-mu*x(3)/r2^3];
%以上格式不可改变，表示为列向量

