function [value, isterminal, direction] = VelocityReached(T, Y)
value      = ((Y(2)-Y(5)) <= 0 || Y(3)<0 || Y(3) > pi/2); %velocity less than desired velocity
isterminal = 1;   % Stop the integration
direction  = 0;