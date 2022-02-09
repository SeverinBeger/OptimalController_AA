function xdot = RocketDynamics_DynProg(t,x)

%x = [h, v, phi,h_d,v_d,phi_rate]
%all distances and velocities are in the world frame
global Ts; %time step
%% get necessary rocket Data (scripts)
Conversions;
Rocket_Data;
Environment;

%% calculations
h = x(1);
v = x(2);
omega = 0; %angle between rocket and world coordinate frame
phi = x(3); %deflection angle of the AA system

% Dragcoefficient
[CD,~] = DragCoefficient(h,v,l,l_b,l_nc,d,d_b,S_B,rc_f, tc_f,S_F,LE,t_f,n_f,A_AAsmall,A_AAbig,n_finAA,phi);

%density
rho = DensityWithHeight(h); 
g = GravityWithHeight(h);

F_D = 1/2 * rho*CD*v^2 *A_r;

F_g = m_0*g;

%% Get Force Vectors in world coordinate System

w_T_r = Trafo(omega); %Transformation from rocket coordinates to  world coordinates

w_F_g = [0;-F_g];

w_F_D = w_T_r * [0;-F_D];

%% Get Acceleration in world coordinate system
w_a = 1/m_0 * (w_F_g + w_F_D);

%% get rotational velocity of rocket

% delta_omega = (g*cos(omega*delT))/v;

%% Set output vector

xdot= zeros(5,1);

xdot(1) = x(2);
xdot(2) = w_a(2);
xdot(3) = 0; %change of phi: turnrate
xdot(4) = 0; %final height doesn't change
xdot(5) = 0;%final velocity doesn't change
end