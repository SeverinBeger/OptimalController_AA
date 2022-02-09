function [tr_min_new,tr_max_new] = getTurnrates(tr_min,tr_max,ratio_upper,ratio_lower,dir_up,dir_low,phi_turnrate)

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

tr_max_new = tr_max - dir_up * ratio_upper * phi_turnrate*10;
tr_min_new = tr_min - dir_low* ratio_lower * phi_turnrate*10;
end