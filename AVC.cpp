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
// scp -r ~/Desktop/AVC/* pi@10.140.84.246:~/AVC/
// ssh pi@10.140.84.246 
// cd AVC   
// g++ -o AVC AVC.cpp -le101
// sudo ./AVC
//edit = nano AVC.cpp

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
void Q2();

	
private:
int leftMotor = 1;
int rightMotor = 5;
int rightSpeed;
int leftSpeed;
int neutral= 48;
int camMotor = 3;
int camAngle;
float kp=0.02;


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

camAngle=28;
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
//Quadrant 2
void robot::Q2(){
//put this while loop around Q2 when you call it
	
	int countCol;
	
	int count=0;
	
	//array of pixels along 120 y axis to find black
	int black[320];
	
	//gets array possision of black pixels
	int blackCountpos;
	
	int lineStart;
	int lineCenter;
	int error;
	
	while(count<1500){
		
		
		take_picture();
		countCol = 0;
		blackCountpos=0;
		while(countCol<320){
			
			black[countCol] = (int)get_pixel(120,countCol,3);
			
			if(	black[countCol] < 100){
				black[countCol]=1;
			}
			else{ black[countCol]=0;}
			
			countCol++;
		}

		for(int col=0;col<320;col++){
			if(black[col] == 1){
				blackCountpos++;
			}
			if(blackCountpos == 1){
				lineStart = col; 
			}
		}
		//sees line. if it doesnt see line, does weird shit.
		//need to set up how error effects wheel speeds
		lineCenter = lineStart+blackCountpos/2;
		error = 160-lineCenter;
		printf("%.3f\n",error*kp);
		printf("%d\n",error);
		count++;
		
		set_motors(rightMotor,43-(error*kp));
		set_motors(leftMotor,53-(error*kp));
		hardware_exchange();
	}
		
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
	bob.cameraDown();
	bob.getGate();
	bob.Q2();
	bob.Stop();
	bob.setMotors();
	bob.cameraDown();
	bob.cameraUp();
	bob.cameraDown();
	return 0;
}

