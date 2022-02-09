function plot_phi_single(phi,t)

% figure
plot(t,phi*180/pi,'LineWidth',1)
grid on
xlabel("time t in seconds")
ylabel("Angle \phi in degree")
title("Fin Angle")
end