function [value, isterminal, direction] = ApoReached(T, Y)
value      = (Y(2) <= 0); %velocity less than 0 -> we fall back down
isterminal = 1;   % Stop the integration
direction  = 0;