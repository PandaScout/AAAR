#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iostream>
//ip address 10.140.84.246
//raspberry pass
//pi username
// scp -r ~/Desktop/Engr101/MainProject/Cpp/* pi@10.140.137.215:~/AVC/
//SSh ssh pi@10.140.137.215    
// Compiler g++ -o camera Camera.cpp -le101
// sudo ./camerarobot


//Robot
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

camAngle=30;
set_motors(camMotor,camAngle);
hardware_exchange();
}

void robot::cameraUp(){

camAngle=65;
set_motors(camMotor,camAngle);
hardware_exchange();
}

void robot::fMax(){

rightSpeed=31;
leftSpeed=59;
}

void robot::rMax(){

rightSpeed= 59;
leftSpeed=31;

}

void robot::Stop(){

rightSpeed=47;
leftSpeed=48;
}

void robot::setMotors(){

set_motors(rightMotor,rightSpeed);
set_motors(leftMotor,leftSpeed);
hardware_exchange();
}

int main(){
	robot bob;
	init(0);
	bob.fMax();
	bob.setMotors();
	sleep1(6000);
	bob.Stop();
	bob.setMotors();
	bob.cameraDown();
	bob.cameraUp();
	return 0;
}
