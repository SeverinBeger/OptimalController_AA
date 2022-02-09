function PlotRocketStuff(t,x)

datalength = size(x,1);

%% Height
figure
plot(t,x(:,2),'LineWidth',1);
xlabel("Time t");
ylabel("Height h in m");
grid on

%% Absolute Velocity
v = zeros(datalength,1);
for(i=1:datalength)
    v(i) = norm(x(i,3:4));
end

figure
plot(t,v,'LineWidth',1);
xlabel("Time t");
ylabel("Absolute velocity in m/s");
grid on

%% Angle of the rocket
figure
plot(t,x(:,5)*180/pi,'LineWidth',1);
xlabel("Time t");
ylabel("Angle of the rocket in degree");
grid on

