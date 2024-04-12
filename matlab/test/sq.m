function ret = sq(a)

x0=a/2;
error=inf;
while error>10^-5
    x1=0.5*(x0+a/x0);
    error=abs(x1-x0);
    x0=x1;
    
end
ret=x1;
end

