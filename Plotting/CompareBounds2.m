function CompareBounds2(t_lower,x_lower,t_upper,x_upper,v_vec,h_table,metric)
ft2m = 0.3048; %feet to meters
% datalength_lower = size(t_lower,1);
% datalength_upper = size(t_upper,1);

h_lower = x_lower(:,1);
v_hlower = x_lower(:,2);

h_upper = x_upper(:,1);
v_hupper = x_upper(:,2);

h_lim = size(h_table,2);
v_lim = length(v_vec);
%% Plot
figure
if(metric)
    plot(v_hlower,h_lower,'LineWidth',3);
    hold on
    plot(v_hupper,h_upper,'LineWidth',3);
    
    legend("Lower Bound", "Upper Bound",'AutoUpdate','off','FontSize',14);
    for(i=1:h_lim)%h limits
        plot(v_vec(:),h_table(:,i),'k','LineWidth',0.3);
    end
    for(i=1:v_lim) %vertical - v-limits
        plot([v_vec(i),v_vec(i)],[h_table(i,1),h_table(i,end)],'k','LineWidth',0.3);
    end
    xlabel("Velocity in vertical direction - [m/s]",'FontSize',14);
    ylabel("Height h - [m]",'FontSize',14);
    xlim([0,x_upper(1,2)*1.1]);
else
    plot(v_hlower/ft2m,h_lower/ft2m,'LineWidth',3);
    hold on
    plot(v_hupper/ft2m,h_upper/ft2m,'LineWidth',3);
    
    legend("Lower Bound", "Upper Bound",'AutoUpdate','off','FontSize',14);
    for(i=1:h_lim)%h limits
        plot(v_vec(:)./ft2m,h_table(:,i)./ft2m,'k','LineWidth',0.3);
    end
    for(i=1:v_lim) %vertical - v-limits
        plot([v_vec(i)/ft2m,v_vec(i)/ft2m],[h_table(i,1)./ft2m,h_table(i,end)./ft2m],'k','LineWidth',0.3);
    end
    xlabel("Velocity in vertical direction - [ft/s]",'FontSize',14);
    ylabel("Height h - [ft]",'FontSize',14);
    xlim([0,x_upper(1,2)/ft2m*1.1]);
end
hold off
title("The bounds of the controller",'FontSize',20);
grid on