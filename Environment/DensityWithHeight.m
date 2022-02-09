function rho = DensityWithHeight(h)

    rho_0 = 1.225; %kg/m^3, density at sea level
    H_0 = 7249000; %m, scale height below 10km, earth radius
    h_0 = 0; %starting height
    
    rho = rho_0 * exp(- (h-h_0)/H_0);
end