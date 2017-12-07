#include "PID.h"
#include <iostream>

using namespace std;

/*
* Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
}

double PID::Control() {
    double steer =  - Kp * p_error 
                    - Kd * d_error 
                    - Ki * i_error;
    
    // limit to [-1,1]
    steer = min(steer, 1.0);
    steer = max(steer, -1.0);
    return steer;
}


double PID::TotalError() {
    return 0; 
}

