%% Rocket Simulation
%This script is a quick & dirty simulation of a rocket model
%restoredefaultpath; %to delete all added paths and avoid unnecessary conflicts with data
% clc; close all; clear all;
% close all;
rocket_no = 3; %choose the rocket to test

% addpath([pwd, '/-CURocketMatlab/CodeBits']); %adds in the folder with necessary functions etc
% addpath([pwd, '/-CURocketMatlab/Plotting']); %adds in the folder with necessary functions etc
% addpath([pwd, '/-CURocketMatlab/Rockets', '/Rocket',num2str(rocket_no)]); %adds in the folder with necessary functions etc
addpath([pwd, '/CodeBits']); %adds in the folder with necessary functions etc
addpath([pwd, '/Plotting']); %adds in the folder with necessary functions etc
addpath([pwd, '/AnalyticDrag']); %adds in the folder with necessary functions etc
addpath([pwd, '/Rockets', '/Rocket',num2str(rocket_no)]); %adds in the folder with necessary functions etc
addpath([pwd, '/AA_Controller']); %adds in the folder with necessary functions etc

% load('Controller100_100.mat');
% load('h_table100_100.mat');
% load('v_vec100.mat');
% load('Bounds.mat');

load('ControllerSet_21_20_cost3.mat');
%% Simulation Parameters & Choices

T_s = 0.01; %sample time
flag_D = 1; %consider drag - 0: no, 1: yes with interpolation of data, 2: yes with analytical data
flag_analytical = 0; %if set, than drag is calculated analytical, else a RAS Aero File is loaded in
flag_AA = 1; %consider active aero - 0: no, 1: yes
flag_plotting = 1; %if you want to see plots in the end
metric =0; %if plotting is to be in metric units, 0 for imperial
h_lim = 1000; %height limits in meter
%% Variables
% Call several scripts

Conversions %for different types of conversions like feet to meter
Environment %loads environmental data like air density
Rocket_Data %loads the specific rocket data as specified in Rockets/Rocket+"rocket_no"


%% Run simulation

out = sim('RocketSimAA');
h = out.SimData.pos.Data(:,2);
t = out.SimData.pos.Time(:,1);
v = out.SimData.v.Data(:,1:2);
v_abs = sqrt(v(:,1).^2+v(:,2).^2);
a = out.SimData.a.Data(:,1:2);
a_abs = sqrt(a(:,1).^2+a(:,2).^2);
F_D = out.SimData.F_D.Data(:,1);
C_D = out.SimData.C_D.Data(:,1);
t2 = out.SimData.C_D.Time(:,1);
m = out.SimData.m.Data(:,1);
F_T = out.SimData.thrust.Data(:,1); %along rocket
t3 = out.SimData.thrust.Time(:,1);

phi_fins = out.SimData.phi.Data(:,1); %along rocket
t4 = out.SimData.phi.Time(:,1);
%% Postprocessing: Additional Calculations
speed_of_sound = (gamma * R .* (h .* temp_increase + initial_temp)).^(1/2);

mach_number = abs(v_abs./speed_of_sound);

flag_cmp = 0;
if(isfile('AA_Controller/hv_uncontrolled.mat') && flag_AA ~= 0)
    flag_cmp = 1;
    data = load('hv_uncontrolled.mat');
    h_prev = data.h;
    v_prev = data.v;
end
%% Plotting
if(flag_plotting)
figure()
subplot(3,1,1)
plot_apogee_single(h,t,metric); %1 indicates: metric scale, 0: imperial
subplot(3,1,2)
plot_v_single(v(:,2),t,metric);
subplot(3,1,3)
plot_a_single(a(:,2),t,metric);

figure()
subplot(2,1,1)
plot_FD_single(F_D,t,metric);
subplot(2,1,2)
plot_CD_single(C_D,t2);

figure()
subplot(2,1,1)
plot_CD_single(C_D,t2);
subplot(2,1,2)
plot_phi_single(phi_fins,t4);

figure()
subplot(2,1,1)
plot_thrust_single(F_T,t3,metric);
subplot(2,1,2)
plot_mass_single(m,t,metric)

figure()
plot_mach_single(mach_number, t)

figure()
    if(flag_cmp == 1)
        plot_v_vs_h_cmp(h,v(:,2),h_prev,v_prev(:,2),x_lower,x_upper,metric);
    else
        plot_v_vs_h(h,v(:,2),x_lower,x_upper,metric);
    end
end

