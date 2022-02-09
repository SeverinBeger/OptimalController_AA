function cost = CalcTransitionCost(x,x_max,h_vec,ep,step,maxsteps)
%x = [h, v, phi]
%x indicates, if it is an endpoint

%desired values
ft2m = 0.3048; %feet to meters
h_d = 10000 *ft2m; %final height in m
v_d = 0;

endpointcost = 0;
transitioncost = 0;



if(ep)
    endpointcost = (x(1)-h_d)^2/((h_vec(end,end)-h_d)*(h_d-h_vec(end,1))); % + (x(2)-v_d)^2;
end

w_ep = 100;

%% Transition Costs
% Term 1 - Punish combinations of high angles and high velocities
term1 = (x(2)*x(3))^2/ ((x_max(2)*x_max(3))^2);
w1 = 1;

% Term 2 - Punish high angles (high input usage)

term2 = x(3)^2 /x_max(3)^2;
w2 = (maxsteps-step)/maxsteps; %to be easy on floating on the first steps but activate brakes later
% w2 = 1;

% Term3 - Punish offset from middle of feasible set
h_low = h_vec(1);
h_high = h_vec(end);
delh = (h_high-h_low);
h_mid = h_low + 1/2 * delh;
if(delh > 0)
    term3 = (x(1)-h_mid)^2/(delh/2)^2;
else
    term3 = 0;
end
w3 = 3;


 transitioncost =  w1* term1 + w2*term2 + w3*term3; 
 
%first term: punishes combination of big angles and high velocities
%second term punishes high angles of the AA system (keep it low, to reduce
%load)
%third term: punish offset from middle of feasible set

cost = w_ep * endpointcost + transitioncost;

end

%Old
% transitioncost = x(2)*x(2) / (x_max(2)^2) + x(3)^2 /x_max(3)^2;
%                 (x(2)*abs(x(3)))^2/(x_max(2)^2) + ...