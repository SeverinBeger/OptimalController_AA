function S_NC = EstimateNCWettedArea(d,L)

    r_ogive = ((d/2)^2 + L^2)/d;
    r = @(x) sqrt(r_ogive^2-(x-L).^2) + (d/2-r_ogive);
    A = 0;
    step = 0.001;
    for i=0:step:L
        r_tmp = r(i);
        A = A + 2*pi*r_tmp * step;
    end
     S_NC = A;
end