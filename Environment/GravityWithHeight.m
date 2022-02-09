function g = GravityWithHeight(h)
R_E = 6378136; %radius of the earth in meter
g_0 = 9.798; %m/s^2, gravity acceleration parameter
    
g = R_E^2 / (R_E+h)^2 * g_0;
end