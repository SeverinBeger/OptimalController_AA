function T = TempWithHeight(h)

    initial_temp = 23+273; %ground Temp in C
    temp_increase = -9.8/1000; %degree per meter
    T = h*temp_increase + initial_temp;
end