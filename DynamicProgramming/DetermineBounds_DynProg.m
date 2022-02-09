%% Determine Bounds Script
% This script finds two trajectories for a lower and an upper bound
global Ts;
addpath([pwd, '/Drag']); %adds in the folder with necessary functions etc
addpath([pwd, '/Plotting']); %adds in the folder with necessary functions etc
addpath([pwd, '/Environment']); %adds in the folder with necessary functions etc
addpath([pwd, '/Rocket']); %adds in the folder with necessary functions etc
addpath([pwd, '/Helper']); %adds in the folder with necessary functions etc
addpath([pwd, '/DynamicProgramming']); %adds in the folder with necessary functions etc

%% initial values (in metric units!)
h0 = 1000; %starting height in m
v0 = 280; %initial absolute velocity in rocket heading direction in m/s
omega0 = 0; %angle between rocket and world coordinate system, rad
phi0 = 0; %deflecion of the AA system, rad

Conversions;

h_d = 10000 *ft2m; %final height in m
v_d = 0;
x_ep = [h_d,v_d];

w_V0 = Trafo(omega0) * [0;v0];

%initial state for ode45 solver
X0 = [h0;v0;phi0;h_d;v_d]; 

%% Get Bounds
global delT;
delT = 0.01;
t = 0:delT:60; %0.1s time step, 30 seconds

Opt    = odeset('Events', @VelocityReached); %to stop simulation, once the rocket "falls down" again

% Lower bound:
h_final = h_d; %to start new search set to h_d
X0(3) = 0;
v0_lower = 228; % normal search with v0;
while(abs(h_final-0.95*h_d) > 10)
     X0(2) = v0_lower;
     [T, Y] = ode45(@RocketDynamics_DynProg, t, X0, Opt);

    h_final = Y(end,1);
    if(abs(h_final-0.95*h_d) > 10)
        v0_lower = v0_lower*(1- (h_final-0.95*h_d)/abs(0.95*h_d));
        h_last = h_final;
    end

end
t_lower = T;
x_lower = Y;

% Upper bound:
h_final = 0; % to start new search set to 0;
X0(3) = pi/2; %fully extended AA
v0_upper = 500; % normal search v0
while(abs(h_final-1.05*h_d) > 10)
    X0(2) = v0_upper;

    [T, Y] = ode45(@RocketDynamics_DynProg, t, X0, Opt);
    h_final = Y(end,1);
    
    if(abs(h_final-1.05*h_d) > 10)
        v0_upper = v0_upper*(1 - (h_final-1.05*h_d)/abs(1.05*h_d));
    end

end
t_upper = T;
x_upper = Y;


%% discretize the area

[v_vec,h_limit,h_table] = DiscretizeRegion(x_lower,x_upper,h0,h_no,v_no);

%% Plot
if plotting
% PlotRocketStuff(T,Y);
CompareBounds2(t_lower,x_lower,t_upper,x_upper,v_vec,h_table,metric);
end


disp("Bounds of the system:");
if(metric)
    str = "Starting height: " + num2str(h0) + " m";
    disp(str);
    
    str = "Minimum velocity: " + num2str(norm(x_lower(1,2))) + " m/s - Maximum velcocity: " + num2str(norm(x_upper(1,2))) + " m/s";
    disp(str);

    str = "Final height low: " + num2str(x_lower(end,1)) + " m - Final height high: " + num2str(x_upper(end,1)) + " m";
    disp(str);

    str = "Desired height: " + num2str(h_d) + " m - Desired vertical speed: " + num2str(v_d) + " m/s";
    disp(str);
else
    str = "Starting height: " + num2str(h0/ft2m) + " ft";
    disp(str);
    
    str = "Minimum velocity: " + num2str(norm(x_lower(1,2))/ft2m) + " ft/s - Maximum velcocity: " + num2str(norm(x_upper(1,2))/ft2m) + " ft/s";
    disp(str);

    str = "Final height low: " + num2str(x_lower(end,1)/ft2m) + " ft - Final height high: " + num2str(x_upper(end,1)/ft2m) + " ft";
    disp(str);

    str = "Desired height: " + num2str(h_d/ft2m) + " ft - Desired vertical speed: " + num2str(v_d/ft2m) + " ft/s";
    disp(str);
end