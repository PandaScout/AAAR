
#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iostream>
using namespace std; 
//ip address 10.140.137.215
//raspberry pass
//pi username
// scp -r ~/Desktop/Engr101/MainProject/Cpp/* pi@10.140.137.215:~/AVC/
//SSh ssh pi@10.140.137.215    
// Compiler g++ -o camera Camera.cpp -le101
// sudo ./camera


//gatestuff
void getGate(){
char ip[15]="130.195.6.196";
connect_to_server(ip, 1024);
char message[15]="Please";
send_to_server(message);
char password[24];
receive_from_server(password);
send_to_server(password);
}

double motors(){
	double vel=0;
	double Fmax=1;
	double Rmax=-1;
	double accel= if(vel>=0 && vel<1){vel+=0.2;}else if(vel<0 && vel<-1){vel-=0.2;} 
	double deccel= if(vel>0 && vel<=1){vel-=0.2;}else if(vel<0 && vel<=-1){vel+=0.2;}
	return(vel);
	}
int main (){
cout<<motors()<<endl;
}
