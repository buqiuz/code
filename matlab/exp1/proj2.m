% 水仙花数
n=100;
while n<1000
    a1=floor(n/100);
    a2=floor(mod(n,100)/10);
    a3=mod(n,10);
    if a1^3 + a2^3 +a3^3 ==n
        disp(n);
    end
    n=n+1;
    
end

