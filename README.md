# OptimalController_AA
In this repository you will find all the code I used to design a preliminary optimal controller for an active air brake system (Active Aero) for Clemson's Rocket Engineering Club (CRE). 

Note: the drag coefficient is purely heuristic and based on estimations. This controller can not be used as is. A CFD simulation to approximate the coefficient of drag is strongly encouraged.


Structure of the folder:

Single files:
- Main_DynProg.m: This is the main script to compute the optimal controller. It makes use of the rocket dynamics in "RocketDynamics_DynProg" and uses the drag description from the folder "Drag" as well as several helper and plotting functions. Here, all limits for discretization (Time, velocity, height) can be chosen.
- RocketDynamics_DynProg.m: The dynamics of our rocket as evaluated when calculating the optimal controller. This needs to be a little less sophisticated to reduce computing time. It makes use of several functions from other folders such as "Environment", "Drag", "Helper".
- RocketSimAA.slx: Simulink model of our rocket with the controller. Used to validate its functionality.
- Optimal Controller for an air brake system of an amateur rocket.pdf: my project report, all of my findings during the project.

Folders:
- Drag: all functions concerned with estimating the drag coefficient of the rocket.
- DynamicProgramming: Helperfunctions for the dynamic programming to determine the optimal controller. Concerned with calculating costs, discretizing the region and interpolate the final controller between points
- Environment: All things temperature, density, gravity, getting the mach number
- Helper: test functions for different functionalities. Most importantly maybe is a function, which cancels the ode calculation in the dynamic programming once the rocket reaches its apogee
- Plotting: to plot several things for visualization
- Results: some plots I used in my report
- Rocket: the data of a (fictional) rocket, for which the controller is designed -> needs to be changed to the real rocket
- SoftwareInTheLoop: Folder I used to create the simulink validation. Not of particular use for the moment.



TO DO:
If we want to use this concept, we will have to 
- get a good estimation for the rockets (and especially the AA fins) drag behavior: how does C_D change with velocity and AA orientation (basically a matrix with values)
- put in the final real data for the rocket (geometry, motor, weight, etc)
- optional: we could add a probabilistic scheme to account for weather and wind, also the simulation could be extended to be more realistic (not sure if this helps much, but it could make the system more robust)
