function v_bounds = GetVBounds(x_lower,x_upper,h)
%interpolate velocities to get bounds

%% lower bound
if(h > x_lower(end,1))
    v_low = 0;
else
    [h_low,idx_low1] = min((x_lower(:,1)-h).^2);
    if(abs(h_low) <= 1e-3)
        v_low = x_lower(idx_low1,2);
    else
    %get the right indexes of the velocity array for an interpolation
    if(idx_low1 == 1)
        idx_low2 = idx_low1+1;
    elseif(idx_low1 == size(x_lower,1))
        idx_low2 = idx_low1-1;
    else
        del1 = x_lower(idx_low1+1,1)-h;
        del2 = x_lower(idx_low1-1,1)-h;
        if(del1 < del2)
            idx_low2 = idx_low1+1;
        else
            idx_low2 = idx_low1-1;
        end
    end

    high = max([idx_low1,idx_low2]);
    low = min([idx_low1,idx_low2]);

    %interpolate
    v_low = x_lower(low,2) + (x_lower(low,2)-x_lower(high,2))*(h - x_lower(low,1))/(x_lower(high,1) - x_lower(low,1));
    end
end

if(abs(v_low)< 1e-3)
    v_low = 0;
end
%% upper bound

    [h_high,idx_high1] = min((x_upper(:,1)-h).^2);
    if(abs(h_high) <= 1e-3)
        v_high= x_upper(idx_high1,2);
    else
    %get the right indexes of the velocity array for an interpolation
    if(idx_high1 == 1)
        idx_high2 = idx_high1+1;
    elseif(idx_high1 == size(x_upper,1))
        idx_high2 = idx_high1-1;
    else
        del1 = x_upper(idx_high1+1,1)-h;
        del2 = x_upper(idx_high1-1,1)-h;
        if(del1 < del2)
            idx_high2 = idx_high1+1;
        else
            idx_high2 = idx_high1-1;
        end
    end

    high = max([idx_high1,idx_high2]);
    low = min([idx_high1,idx_high2]);

    %interpolate
    v_high = x_upper(low,2) + (x_upper(low,2)-x_upper(high,2))*(h - x_upper(low,1))/(x_upper(high,1) - x_upper(low,1));
    end
    if(abs(v_high)< 1e-3)
    v_high = 0;
    end
    %% return the found bounds
    v_bounds = [v_low,v_high];
end