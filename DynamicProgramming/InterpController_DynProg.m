function controller_interp = InterpController_DynProg(Controller)
%phi max is the maximum turnrate per second

[v,h] = size(Controller);
controller_interp = zeros(v,h);
controller_interp(1,:) = pi/2; % first value will alway by full brakeing if max velocity

for i= 2:v
    
    idx = find(~isnan(Controller(i,:)));
    
    if(isempty(idx))
        controller_interp(i,:) = 0:pi/2 /(h-1):pi/2;
        continue;
    end
    
    if(idx(1) ~= 1)
        idx = [1, idx];
        Controller(i,1) = 0;
    end
    
    if(idx(end) ~= h)
        idx = [idx,h];
        Controller(i,end) = pi/2;
    end
        
    if(length(idx) == h)
        controller_interp(i,:) = Controller(i,:);
        continue;
    end 
    
    for p = 1:length(idx)-1
        steps = idx(p+1)-idx(p);
        if( steps > 1)
            startval = Controller(i,idx(p));
            endval = Controller(i,idx(p+1));
            if(startval == endval)
            controller_interp(i,idx(p):idx(p+1)) = startval*ones(1,steps+1);
            else
            controller_interp(i,idx(p):idx(p+1)) = startval:(endval-startval)/(steps):endval;
            end
        end
    end
end
            