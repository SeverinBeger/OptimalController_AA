function x_new = rk3(x,dx)
global Ts;

%erster Faktor
    k1 = dx;

    %zweiter Faktor
    x_k2 = x + Ts/2 * k1;
    k2 = RocketDynamics2(0,x_k2);
    
    %dritter Faktor
    x_k3 = x - Ts * k1 + 2 * Ts *k2;
    k3 = RocketDynamics2(0,x_k3);
    
    %Berechnung der neuen q's und dq's
    x_new = x + Ts * (1/6 * k1 + 4/6 * k2 + 1/6 *k3);