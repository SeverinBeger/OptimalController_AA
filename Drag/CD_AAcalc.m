function CD = CD_AAcalc(phi)


%inspiration:
    %https://www.researchgate.net/publication/278049906_Experimental_Investigation_on_the_Performance_of_NACA_4412_Aerofoil_with_Curved_Leading_Edge_Planform/figures?lo=1
    %https://www.grc.nasa.gov/www/k-12/rocket/shaped.html
rng('shuffle');
%correct angle


if(phi > pi)
    disp("Angle phi of the active aero fins is wrong. Too big.");
    disp(phi*180/pi);
    CD = 1.28;
    return;
elseif(-phi > pi)
    disp("Angle phi of the active aero fins is wrong. Too Small.");
    disp(phi*180/pi);
    CD = 0.045;
    return;
elseif(phi>pi/2)
    phi = pi/2;
elseif(phi < 0)
    phi = 0;
end

CD_min = 0.045; %typical airfoil
CD_max = 1.28;  %typical flat plate perpendicular

phi_lim = 16; %16 degrees till stalling

if(phi *180/pi <= phi_lim)
    CD = CD_min + 10*CD_min * exp(1+phi *180/pi / phi_lim)/(exp(2)); % exponential rise
    
else
    CD_base = 11*CD_min;
    CD =  CD_base + ((phi*180/pi)-phi_lim)/(90-phi_lim)*(CD_max-CD_base);
    %add random perturbation
    pert = rand(); %between 0 and 1

    CD = CD + sign(pert-0.5) * CD./20 * pert; %randomly perturbe around 5 degrees 
    
end

