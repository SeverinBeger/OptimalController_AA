function T = Trafo(theta)
 %Transformation from the rocket coordinate system to the world system
 %(x,y)
 %Theta defines the angle between the rocket axis and the ground, defined
 %positive anticlockwise
 T = [cos(theta), sin(theta);
     -sin(theta),cos(theta)];
end