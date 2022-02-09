function [T_fin,X]= simulateRocket(X0,t,Opt)
        if(X0(3) < 0)
            X0(3) = 0;
            X0(6) = 0;
        elseif(X0(3) > pi/2)
            X0(3) = pi/2;
            X0(6) = 0;
        end

        Y_new =  [];
        T_new = [];
        
        [T, Y] = ode45(@RocketDynamics3, t, X0, Opt);
        if(Y(end,2)-Y(end,5)>1e-3) %velocity not reached -> this means, the integration was stopped due to a faulty angle
            X_new = Y(end,:);
            if(X_new(3) < 0)
                X_new(3) = 0;
            elseif(X_new(2) > pi/2)
                X_new(3) = pi/2;
            end
            
            X_new(6) = 0; %turn off turnrate
            [T_new, Y_new] = ode45(@RocketDynamics3, t, X_new, Opt);
        end

        X = [Y;Y_new];
        T_fin = [T;T_new];
end
                