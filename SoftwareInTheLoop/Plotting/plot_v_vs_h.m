function plot_v_vs_h(h,v,x_lower,x_upper,metric)

    h_lower = x_lower(:,1);
    v_hlower = x_lower(:,2);

    h_upper = x_upper(:,1);
    v_hupper = x_upper(:,2);


if(~metric)
    ft2m = 0.3048; %feet to meters
    v = v.*(1/ft2m);
    h=h.*(1/ft2m);
    [max_v,idx] = max(v);
    
    h_lower = h_lower./ft2m;
    v_hlower = v_hlower./ft2m;

    h_upper = h_upper./ft2m;
    v_hupper = v_hupper./ft2m;
%     str2 = ['Maximum velocity at ', num2str(max_v),' ft/s'];
    str1 = "velocity v in feet/s";
    str2 = "height h in feet";
else
    [max_v,idx] = max(v);
%     str2 = ['Maximum velocity at ', num2str(max_v),' m/s'];
    str1 = "velocity v in meter/s";
    str2 = "height h in meter";
end
% figure
plot(v,h,'LineWidth',1)
hold on
plot(v_hlower,h_lower,'LineWidth',1);
hold on
plot(v_hupper,h_upper,'LineWidth',1);
grid on
xlabel(str1,'FontSize',14)
ylabel(str2,'FontSize',14)
title("Height over Velocity",'FontSize',20)
legend('Rocketpath','Lower Bound','Upper Bound','FontSize',14);
hold on
% plot(t(idx),max_v,'rx','LineWidth',1);
% disp(str2);
end