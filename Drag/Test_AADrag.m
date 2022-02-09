%% Test AA Drag Coefficient

testangle = 0:0.05:pi/2;
CD_test = zeros(length(testangle),1);

for i=1:32
CD_test(i) = CD_AAcalc(testangle(i)); 
end

figure
plot(testangle,CD_test,'LineWidth',1);
xlabel("angle $\varphi$", 'Interpreter','latex','FontSize',16)
ylabel("Drag Coefficient $C_{D-AA}$", 'Interpreter','latex','FontSize',16);
title("Test of the Drag Coefficient Function",'FontSize',20)
grid on