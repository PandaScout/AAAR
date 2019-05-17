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
}
