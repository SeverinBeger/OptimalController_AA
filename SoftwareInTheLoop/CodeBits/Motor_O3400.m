%Motor Data O3400
t = [0, 0.04, 0.052, 0.101, 0.19, 0.38, 0.965, 2.176, 2.887,3.658, 4.17, 4.493, ...
    4.881, 5.483, 6.137, 6.322];
m = [11272, 11229.6, 11202.6, 11085.2, 10872.1, 10423.7, 9039.12, 6073.35, 4303.95,...
    2482.87,1511.85,1043.46, 609.199, 207.979, 12.3006, 0];
f = [0, 3959.81, 4432.62, 4515.37, 4420.8, 4391.25, 4444.44, 4698.58, 4592.2, 4225.77,...
    2854.61, 2559.1, 1619.38, 868.794, 248.227, 0];
cg = 619.5 * ones(1,length(t));

m_dot = [0];

for i=2:length(t)
    m_dot = [m_dot, (m(i)-m(i-1))/(t(i)-t(i-1))];
end

figure()
plot(t,m/1000)
grid on
hold on
plot(t,m_dot/1000)
xlabel("Time t")
legend("m", "$\dot{m}$",'Interpreter','latex','AutoUpdate','off');

plot(t,m_dot/1000,'kx')



figure()
plot(t,f)
grid on
xlabel("Time t")
ylabel("Force F in Newton")
