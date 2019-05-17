
#include "E101.h"
//left motor might be...reverse=31, stationary=48, 59= forward
//right motor would be opposite
//camera angle is 180 turns for values between 31 & 59 

class robot{	

public:
void setMotors();
void fMax();
void rMax();
	
	
	
private:
int leftMotor = 1;
int rightMotor = 5;
int rightSpeed = 48;
int leftSpeed = 48;

};

void robot::fMax(){
rightSpeed= 59;
leftSpeed=31;
}

void robot::rMax(){
rightSpeed=31;
leftSpeed=59;
}

void robot::setMotors(){

set_motors(rightMotor,rightSpeed);
set_motors(leftMotor,leftSpeed);
hardware_exchange();
}
