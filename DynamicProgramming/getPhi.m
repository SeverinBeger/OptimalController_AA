function [phi_min_new,phi_max_new] = getPhi(phi_min,phi_max,ratio_upper,ratio_lower,dir_up,dir_low)

% factor_up = (1-ratio_upper);
% factor_low = (1-ratio_lower);
% 
% tr_max_new = factor_up*tr_max;
% tr_min_new = factor_low*tr_min;

% if(ratio_upper > ratio_lower)
%     tr_max_new = tr_max;
%     tr_min_new = factor*tr_min
% elseif(ratio_upper < ratio_lower)
%     tr_max_new = factor*tr_max;
%     tr_min_new = tr_min;
% else

phi_max_new = phi_max - dir_up * ratio_upper* pi/2;
phi_min_new = phi_min - dir_low* ratio_lower *  pi/2;

if(phi_min_new < 0)
    phi_min_new = 0;
elseif(phi_min_new > pi/2)
    phi_min_new = pi/2;
end

if(phi_max_new < 0)
    phi_max_new = 0;
elseif(phi_max_new > pi/2)
    phi_max_new = pi/2;
end

end