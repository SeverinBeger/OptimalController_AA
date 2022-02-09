function mu = dynVisc(T)
%Sutherland's Law
mu0 = 1.716*1e-5;
T0 = 273; %Kelvin
S_mu= 111;
%mu = 0.1456 * 1e-5 * sqrt(T)/(1+110/T);
mu = mu0 * (T/T0).^(3/2) * (T0+S_mu)./(T+S_mu);

end