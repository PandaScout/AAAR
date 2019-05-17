#include "E101.h"
//left motor might be...reverse=30, stationary=48, 50= forward
//right motor would be opposite
 
class robot{	

public:
void setMotors();

	
	
	
private:
int leftMotor = 1;
int rightMotor = 5;
int rightSpeed = 48;
int leftSpeed = 48;

};

void robot::setMotors(){

set_motors(rightMotor,rightSpeed);
set_motors(leftMotor,leftSpeed);
hardware_exchange();
}



//old

#include "E101.h"
 
double motors{

double vel=0;
double Fmax=1;
double Rmax=-1;
	
	double accel(){
		if(vel>=0 && vel<1){vel+=0.2;}
		else if(vel<0 && vel<-1){vel-=0.2;} 
		return(vel);
	}
	double deccel(){
		if(vel>0 && vel<=1){vel-=0.2;}
		else if(vel<0 && vel<=-1){vel+=0.2;}
	return(vel);
	}
int set_motors(num_mot,vel);
int hardware_exchange();
}
