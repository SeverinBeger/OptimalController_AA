function h_ratio = gethratio(x_cur,x_goal,x_new)
h_ratio = abs(x_goal(1)-x_new(1))/(x_goal(1)-x_cur(1));
end