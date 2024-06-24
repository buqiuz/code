function dydt = lotkaVolterraCompete(t, Y, params)
    r1 = params(1);
    r2 = params(2);
    r3 = params(3);
    s1 = params(4);
    s2 = params(5);
    s3 = params(6);
    s4 = params(7);
    s5 = params(8);
    s6 = params(9);
    N1 = params(10);
    N2 = params(11);
    N3 = params(12);

    dydt = zeros(3,1);
    dydt(1) = r1 * Y(1) * (1 - Y(1) / N1 - s1 * Y(2) / N2 - s3 * Y(3) / N3);
    dydt(2) = r2 * Y(2) * (1 - Y(2) / N2 - s2 * Y(1) / N1 - s4 * Y(3) / N3);
    dydt(3) = r3 * Y(3) * (1 - Y(3) / N3 - s5 * Y(1) / N1 - s6 * Y(2) / N2);
end