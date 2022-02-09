function M = GetMachNumber(v,h)
gamma = 1.4; %ratio of specific heats
    R = 286; % (m^2/s^2/K)
speed_of_sound = (gamma * R .* TempWithHeight(h)).^(1/2);

M = abs(v./speed_of_sound);
end
