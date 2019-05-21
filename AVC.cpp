#include "E101.h"

//left motor might be...reverse=31, stationary=48, 59= forward
//right motor would be opposite
//camera angle is 180 turns for values between 31 & 59 

class robot{	

public:
void setMotors();
void fMax();
void rMax();
void Stop();
void getGate();
void cameraDown();
void cameraUp();

	
private:
int leftMotor = 1;
int rightMotor = 5;
int rightSpeed;
int leftSpeed;
int camMotor = 3;
int camAngle;


};
void robot::getGate(){

char ip[15]="130.195.6.196";
connect_to_server(ip, 1024);
char message[15]="Please";
send_to_server(message);
char password[24];
receive_from_server(password);
send_to_server(password);
}

void robot::cameraDown(){

camAngle=35;
set_motors(camMotor,camAngle);
hardware_exchange();
}

void robot::cameraUp(){

camAngle=48;
set_motors(camMotor,camAngle);
hardware_exchange();
}

void robot::fMax(){

rightSpeed= 59;
leftSpeed=31;
}

void robot::rMax(){

rightSpeed=31;
leftSpeed=59;
}

void robot::Stop(){

rightSpeed=48;
leftSpeed=48;
}

void robot::setMotors(){

set_motors(rightMotor,rightSpeed);
set_motors(leftMotor,leftSpeed);
hardware_exchange();
}
