function cost = CalcEndpointCost(x,x_d,h_table)
%Calculate the costs of the endpoint
w_ep = 100;
cost = w_ep * (x(1)- x_d(1))^2/((h_table(end,end)-x_d(1))*(x_d(1)-h_table(end,1))); %final value problem -> difference between actual height and desired height

end