function plotTransition(FROM_TO,v_vec,h_table,metric)

[v,h,~] = size(FROM_TO);
cmap = lines(h);
figure()
hold on
ft2m = 0.3048; %feet to meters

for i=1:v
    for j =1:h
        idx_TO = FROM_TO(i,j,:);
        if(~isnan(idx_TO(1)) || ~isnan(idx_TO(2)))
        x_FROM = [h_table(i,j),v_vec(i)];
        x_TO = [h_table(idx_TO(1),idx_TO(2)),v_vec(idx_TO(1))];
        if(metric)
            plot([x_FROM(2),x_TO(2)],[x_FROM(1),x_TO(1)], 'Color', cmap((j), :));
            ax = gca;
            ax.FontSize = 14; 
            xlabel("Velocity v in m/s",'FontSize',16);
            ylabel("Height in m",'FontSize',16);
        else
            plot([x_FROM(2),x_TO(2)]./ft2m,[x_FROM(1),x_TO(1)]./ft2m, 'Color', cmap((j), :));
            ax = gca;
            ax.FontSize = 14; 
            xlabel("Velocity v in ft/s",'FontSize',16);
            ylabel("Height in ft",'FontSize',16);
        end
        end
    end
end

grid on


title("Optimal transitions",'FontSize',20);
