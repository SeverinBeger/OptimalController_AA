function [v_vec,h_limit,h_table] = DiscretizeRegion2(x_lower,x_upper,h0,h_vals,v_vals)
%we check how many values we need and then interpolate from the bounds
%THIS VERSION HAS DIFFERRENT h LINEARIZATION

if(nargin < 5)
    v_vals = 50; %values to discretize in v direction
    h_vals = 50; %values to discretize in h direction
end

v_span = x_upper(1,2)-0;
h_span = x_upper(end,1)-h0;

%initialize vectors
h_vec = zeros(h_vals,1);
h_limit = zeros(v_vals,2); %upper and lower h value for each discretized velocity
h_table = zeros(v_vals,h_vals);

v_vec = zeros(v_vals,1);
v_limit = zeros(h_vals,2);



%discretize velocity v linearly

counter = v_vals;
for i=0:v_span/(v_vals-1):x_upper(1,2)
    v_vec(counter) = i;
    counter = counter - 1;
end

for i = 1:v_vals
    %first: find closest h_values to the discretized v
    v = v_vec(i);
    
    %lower bound
    if(x_lower(1,2) <  v) % highest lower velocity lower than interpolation value
        h_low = x_lower(1,1);
        
    else
        [delta_v_low,idx_low1] = min((x_lower(:,2)-v).^2);
        if(abs(delta_v_low) <= 1e-3)
            h_low = x_lower(idx_low1,1);
        else
        %get the right indexes of the velocity array for an interpolation
        if(idx_low1 == 1)
            idx_low2 = idx_low1+1;
        elseif(idx_low1 == size(x_lower,1))
            idx_low2 = idx_low1-1;
        else
            del1 = x_lower(idx_low1+1,2)-v;
            del2 = x_lower(idx_low1-1,2)-v;
            if(del1 < del2)
                idx_low2 = idx_low1+1;
            else
                idx_low2 = idx_low1-1;
            end
        end

        high = max([idx_low1,idx_low2]);
        low = min([idx_low1,idx_low2]);

        %interpolate
        h_low = x_lower(low,1) + (x_lower(high,1) - x_lower(low,1))*(v - x_lower(low,2))/(x_lower(high,2) - x_lower(low,2));
        end
    end
    
    %upper bound
    [v_high,idx_high1] = min((x_upper(:,2)-v).^2);
    if(abs(v_high) <= 1e-3)
        h_high = x_upper(idx_high1,1);
    else
        if(idx_high1 == 1)
            idx_high2 = idx_high1+1;
        elseif(idx_high1 == size(x_upper,1))
            idx_high2 = idx_high1-1;
        else
            del1 = x_upper(idx_high1+1,2)-v;
            del2 = x_upper(idx_high1-1,2)-v;
            if(del1 < del2)
                idx_high2 = idx_high1+1;
            else
                idx_high2 = idx_high1-1;
            end
        end
        high = max([idx_high1,idx_high2]);
        low = min([idx_high1,idx_high2]);
        %interpolate
        h_high = x_upper(low,1) + (x_upper(high,1) - x_upper(low,1))*(v - x_upper(low,2))/(x_upper(high,2) - x_upper(low,2));
        if(i == v_vals)
            h_low = 0;
            h_high = 0;
        end
    end
    
    %now, v bounds for this discretized h found
    %fill out the table
    h_limit(i,:) = [h_low,h_high];
end

    for i = 1:v_vals
        for j= 1:h_vals
            if(j==1)
                h_table(i,j) = h_limit(i,1);
            else
                h_table(i,j) = h_limit(i,1)+ (j-1)*(h_limit(i,2)-h_limit(i,1))/(h_vals-1);
            end
        end
    end


end %function ends
