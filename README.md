# Udacity SDCND Project 9: PID Control
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)



The goal of this project was to use a simple PID control to drive a car around a track in the [term 2 simulator](https://github.com/udacity/self-driving-car-sim/releases). A PID controller is a simple feedback loop mechanism that doesn't only use the difference between the desired and the current state (P for proportional) but also integral (I) and derivative (D) terms. That allows for a simple but powerful control loop that is widely used.

In this project we were controlling the cte (cross track error) that describes the derivation of a vehicle from the middle of the lane. The simulator provides the current cte and the PID controller uses it to control the steering angle that is passed back to the simulator.

![PID](https://github.com/stefancyliax/CarND-PID-Control-Project/raw/master/pic/PID.png)


Additionally I added another PID instance to control the speed of the vehicle.


[![Project track](https://github.com/stefancyliax/CarND-PID-Control-Project/raw/master/pic/PID.gif)](https://youtu.be/AE_pA-dvYC8)

## Reflection

The PID coefficient were chosen as shown below.

| Coefficient             | P    | I       | D |
|-------------------------|------|---------|---|
| CTE -> Steering Angle   | 0.13 | 0.0001  | 5 |
| Speed -> Throttle Value | -0.2 | -0.0001 | 0 |

The P term is the proportional term. The larger the derivation from the middle of the lane, the larger the P term gets. It's the main mean of steering the vehicle around the track. It only has to be big enough to get the vehicle to drive around the sharp corners after the bridge. Therefore a low value of 0.13 was chosen after some testing.

The I term is the integral term. It depends on the sum of all previous errors. If there is a residual control error (bias) in the system, the I term sums these errors and gets larger. Therefore it is able to counteract biases in the system. For controlling the vehicle around the track the I term is not important and a relatively small coefficient was chosen.

The D term is the derivative term. It depends on the how the error value is changing. If the error value is getting smaller, the D term counteracts the control and therefore smooths out the control. It is an effective measure to prevent overshooting and oscillation. For the project it was increased to 5 until the vehicle was driving relatively smooth. 