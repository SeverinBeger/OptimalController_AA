%% Calculate an optimal Controller for the AA braking system
%This script makes use of the dynamic programming approach
clc; close all; clear all;
addpath(genpath(pwd)); %add all folders

global Ts; %Time step global!!
Ts = 0.01;

step_lim = 50; %maximum iterations on the angle finding algorithm
ratio_lim = 0.005; %limit on how far we can be off from the intended height

%% Set Discretization Parameters 
h_no = 21;
v_no = 21;

%% Get Bounds of the System
metric = 0;
plotting = 1;

DetermineBounds_DynProg;

x_max = [h_table(end,end);v_vec(1);pi/2];
v_limits = zeros(v_no,h_no,2);
for(j=1:v_no)
    for(i=1:h_no)
        v_limits(j,i,:) = GetVBounds(x_lower,x_upper,h_table(j,i));
    end
end
drawnow();
fprintf("\n")

%% Get possible transitions

disp("Discretized the system. Starting to calculate all possible transitions.")

%Initialize Cost Matrix and Controller Matrix

Controller = NaN(v_no-1,h_no); %we save the angles in here
CostMat = Inf(v_no,h_no); %we save the costs in here
FROM_TO = NaN(v_no-1,h_no,2);

new_level_list = Inf(h_no,3); %list with reachable states of the next level
    %[vidx,hidx,cost]
new_level_counter = 0;

    for i=1:h_no
        x_cur = [h_table(v_no,i),v_vec(v_no)];
        cost = CalcEndpointCost(x_cur,x_ep,h_table);
        CostMat(v_no,i) = cost;
%         new_level_counter = new_level_counter + 1;
%         new_level_list(new_level_counter,:) = [v_no,i,cost];
    end
 

    
    
%go over all possible velocities, over all possible heights (h_table) and
%all possible AA Fin angles

Opt    = odeset('Events', @VelocityReached); 
    %to stop simulation, once the rocket reached its velocity target
t = 0:Ts:30; %should never go up to 30 seconds
ep = 0;
counter = 0;

 
%get a transition for each point, if possible
for i=v_no-1:-1:1
    
    level_list = Inf(h_no,3);
    
    for(l=1:h_no)
        level_list(l,:) = [i+1,l,CostMat(i+1,l)];
    end
    
    level_list = sortrows(level_list,3);
    level_counter = h_no; %new_level_counter;
    %sort list after cost in ascending order -> lowest at top

%     new_level_list = Inf(h_no,3); %list with new found states of the next level
%     new_level_counter = 0;
    
    str = num2str(level_counter) + " states to evaluate for velocity level " + num2str(i);
    disp(str);
    
    
    for j=1:h_no
        
        h0 = h_table(i,j);
        v0 = v_vec(i);
        delta_h = h_table(i+1,2)-h_table(i+1,1);
        x_cur = [h0,v0];
        
        success = 0;
        str = "[v,h] = [" + num2str(i) + ", " + num2str(j) + "]";
        disp(str);
        
        
        %Calculate limits of the current step
                phi_min = 0;
                phi_max = pi/2;
                x_goal = [x_ep(1),v_vec(i+1)];
                %get first simulation
                    %upper means: high angle -> more braking, flies lower
                    %lower means: low angle -> less braking, flies higher
                X0 = [x_cur,phi_max,x_goal];
                [~,Xnew] = ode45(@RocketDynamics_DynProg, t, X0, Opt);
                Xnew_upper = Xnew(end,:);
                
                X0 = [x_cur,phi_min,x_goal];
                [~,Xnew] = ode45(@RocketDynamics_DynProg, t, X0, Opt);
                Xnew_lower = Xnew(end,:);
        
        for p=1:level_counter 
            %go over list and see which state can be reached
            %first state, which can be reached is automatically the lowest cost
            %option

            h_idx = level_list(p,2);
            v_idx = level_list(p,1); 

            h1 = h_table(v_idx,h_idx);
            v1 = v_vec(v_idx);

            h_vec = h_table(i,:);
            
            x_goal = [h1,v1];
              
                %avoid certain configurations
                if(h1 < h0 || v1 > v0) %state definitely not reachable
                    continue;
                end   

                x_new = x_goal;
%                 h_ratio = abs(x_goal(1)-x_new(1))/(x_goal(1)-x_cur(1));
%                 v_ratio = abs(x_new(2)-x_goal(2))/(x_cur(2)-x_goal(2));


                h_ratio_up = gethratio(x_cur,x_goal,Xnew_upper(1:2));
                dir_up = sign(x_goal(1)-Xnew_upper(1));
                h_ratio_low = gethratio(x_cur,x_goal,Xnew_lower(1:2));
                dir_low = sign(x_goal(1)-Xnew_lower(1));    
                    %Xnew_lower(1): Max height we can reach
                    %Xnew_upper(1): Max height we can reach
                %sanity check
                if((x_goal(1) > Xnew_lower(1) || x_goal(1) < Xnew_upper(1)) && ...
                        (h_ratio_low > ratio_lim && h_ratio_up > ratio_lim) && ...
                        (abs(Xnew_lower(1)-x_goal(1)) > 1 || abs(Xnew_upper(1)-x_goal(1)) > 1)) %we are not in bounds or close to the goal
                    success = 0;
                    continue;
                end

                if(h_ratio_low < ratio_lim || h_ratio_up < ratio_lim)
                    
                    if(h_ratio_low < ratio_lim && h_ratio_up < ratio_lim)
                        cost_low =  CalcTransitionCost([X0(1:2),0],x_max,h_vec,0,i,v_no) + CostMat(v_idx,h_idx);
                        cost_up =  CalcTransitionCost([X0(1:2),pi/2],x_max,h_vec,0,i,v_no) + CostMat(v_idx,h_idx);
                        if(cost_up < cost_low)
                            x_new = Xnew_upper;
                        else
                            x_new = Xnew_lower;
                        end
                    elseif(h_ratio_low < h_ratio_up)
                        x_new = Xnew_lower;
                    else
                        x_new = Xnew_upper;
                    end
                    success = 1;
                end
                
                %if we are already within 1 m of the goal -> good enough
                if((abs(Xnew_lower(1)-x_goal(1)) < 1 || abs(Xnew_upper(1)-x_goal(1)) < 1))
                    if((abs(Xnew_lower(1)-x_goal(1)) < 1 &&  abs(Xnew_upper(1)-x_goal(1)) < 1))
%                     cost_low =  CalcTransitionCost(Xnew_lower,x_max,0) + CostMat(v_idx,h_idx);
%                     cost_up =  CalcTransitionCost(Xnew_upper,x_max,0) + CostMat(v_idx,h_idx);
%                         if(cost_up < cost_low)
%                             x_new = Xnew_upper;
%                         else
%                             x_new = Xnew_lower;
%                         end
                        x_mean = (Xnew_lower+Xnew_upper)./2;
                        
                        if(x_mean(1)-h_table(level_list(1,1),level_list(1,2)) <= 0) %lower than optimal height
                            x_new = [x_mean(1:2),0];
                        else
                            x_new = [x_mean(1:2),pi/2];
                        end
                    elseif(abs(Xnew_lower(1)-x_goal(1)) < 1)
                        x_new = Xnew_lower;
                    else
                        x_new = Xnew_upper;
                    end
                       
                    success = 1; 
                end
                
                
                
                steps = 0;
                while(success == 0) %adapt angle, until we find a suitable solution
                    steps = steps + 1;

                    %adapt angle
                    [phi_min,phi_max] = getPhi(phi_min,phi_max,h_ratio_up,h_ratio_low,dir_up,dir_low);


                    X0(3) = phi_max;
                    [~,Xnew] = ode45(@RocketDynamics_DynProg, t, X0, Opt);
                    Xnew_upper = Xnew(end,:);
                    h_ratio_up = gethratio(x_cur,x_goal,Xnew_upper(1:2));
                    dir_up = sign(x_goal(1)-Xnew_upper(1));


                    X0(3) = phi_min;
                    [~,Xnew] = ode45(@RocketDynamics_DynProg, t, X0, Opt);
                    Xnew_lower = Xnew(end,:);
                    h_ratio_low = gethratio(x_cur,x_goal,Xnew_lower(1:2));    
                    dir_low = sign(x_goal(1)-Xnew_lower(1));

                    if((h_ratio_low < ratio_lim || h_ratio_up < ratio_lim))
                        if(h_ratio_low < ratio_lim && h_ratio_up < ratio_lim)
                            cost_low =  CalcTransitionCost([X0(1:2),0],x_max,h_vec,0,i,v_no) + CostMat(v_idx,h_idx);
                            cost_up =  CalcTransitionCost([X0(1:2),pi/2],x_max,h_vec,0,i,v_no) + CostMat(v_idx,h_idx);
                            if(cost_up < cost_low)
                                x_new = Xnew_upper;
                            else
                                x_new = Xnew_lower;
                            end
                        elseif(h_ratio_low < h_ratio_up)
                            x_new = Xnew_lower;
                        else
                            x_new = Xnew_upper;
                        end
                        success = 1;
                        break;
                    end

                    if(steps >= step_lim)
                        break;
                    end
                end

                %add solution to matrix
                if(success)
                    h_idx_new = j;
                    v_idx_new = i;

                    phi_new = x_new(3);
                    h_vec = h_table(v_idx_new,:);
                    cost_new = CalcTransitionCost(X0(1:3),x_max,h_vec,0,i,v_no) + CostMat(v_idx,h_idx);

                    Controller(i,j) = phi_new;
                    CostMat(i,j) = cost_new;
                    FROM_TO(v_idx_new,h_idx_new,:) = [v_idx,h_idx];

%                     new_level_counter = new_level_counter + 1;
%                     new_level_list(new_level_counter,:) = [i,j,cost_new];


                    counter = counter + 1;
                    if(mod(counter,100)==0)
                        str = num2str(counter) + " transitions detected.";
                        disp(str);
                    end
                    
                    break;
                end
         end

    end
end



disp("Calculated all possible transitions");
str="A total of " + num2str(counter) +" transitions were found.";
disp(str);

%% Interpolate the Controller

Controller = InterpController_DynProg(Controller);

%% Plotting
plotTransition(FROM_TO,v_vec,h_table,metric);