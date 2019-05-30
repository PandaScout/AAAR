// C++ hopefuly
#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iostream>

//rotation of robot. right: 47, 59
//rotation of robot. left: 59,47
//forward at max speed. 31, 59

void robot::Q4(){
	//Code for camera will be here to find the redness, greenness and blueness.
	take_picture();
	x = 0;
	y = 0;
	totred = 0;
	totgreen = 0;
	totblue = 0;
	totint = 0;
	redness = 0;
	greenness = 0;
	blueness = 0;
	Boolean red = true;
	Boolean green = false;
	Boolean blue = false;
	Boolean end = false
	
		
	for(x = 0; x < 320; x++)
	{
		for(y = 0; y < 240; y++) 
		{
			totred = totred + (int)get_pixel(x, y,0);
			totgreen = totgreen + (int)get_pixel(x, y,1);
			totblue = totblue + (int)get_pixel(x, y,2);
			totint = totint + (int)get_pixel(x, y,3);
			redness = (float)totred/3.0*(float)totint;
			greenness = (float)totgreen/3.0*(float)totint;
			blueness = (float)totblue/3.0*(float)totint; 
		}
	}

	//Open file in write mode
			std::ofstream outfile;
			outfile.open("test.txt", std::ofstream::out | std::ofstream::app);

			//Write to file
			outfile << redness << "red" <<std::endl;
			outfile << greenness << "green"<< std::endl;
			outfile << blueness  << "blue" << std::endl;
			//Close file
			outfile.close();
			printf("	\n");
			printf("Total red %d\n", redness);
			printf("Total green %d\n", greenness);
			printf("Total blue %d\n", blueness);
			printf(" \n");
	
	while (red == true){
		if(greenness < 0.444 && blueness < 0.444) { //x is a set value gain from the camera
			rightspeed = 47;
			leftspeed = 59;  //Right turn
		}
		sleep(1000);
		else if (greenness > 0.544 && blueness > 0.544){
			rightspeed = 59;
			leftspeed = 47; //left turn
		}
		else {
			rightSpeed=31;
			leftSpeed=59; //robot::fMax
		}
		sleep(1000);
		if ( greenness < 0.444 && blueness < 0.444){ //Values will be figure out with testing
			red = false;
			green = true;
		}
	}
	while (green == true){
		if(redness < 0.444 && blueness < 0.444) { //x is a set value gain from the camera
			rightspeed = 47;
			leftspeed = 59;
		}
		sleep(1000);
		else if(redness > 0.544 && blueness > 0.544){
			rightSpeed=59;
			leftSpeed=47; 
		}
		else{
			rightSpeed=31;
			leftSpeed=59;
		}
		sleep(1000);
		if (redness > 0.444 && blueness > 0.444){
			green = false;
			blue = true;
		}
	}
	while (blue == true){
		if(redness < 0.444 && greenness < 0.444) { //x is a set value gain from the camera
			rightspeed = 59;
			leftspeed = 47;
		}
		sleep(1000);
		else if(redness > 0.544 && greenness > 0.544){
			rightSpeed=47;
			leftSpeed=59; 
		}
		else{
			rightSpeed=31;
			leftSpeed=59;
		} 
		sleep(1000);
		if (redness > 0.444 && greenness > 0.444){
			blue = false;
			end = true;
		}
	}
	while (end == true){ //Ajust later
		if(blueness > 0.444) { //x is a set value gain from the camera. This will look for blue as yellow is a mix of red and green
			rightspeed = 59;
			leftspeed = 47;
		}
		sleep(1000);
		else if(blueness < 0.544){
			rightSpeed=47;
			leftSpeed=59; 
		}
		else{
			rightSpeed=31;
			leftSpeed=59;
		}
		sleep(1000);
		if (redness > 1.5 && greenness < 0.4){
			blue = false;
			end = true;
			sleep(1000);
		}
	}
	stop();
	
	//while(greenness < Z){
		
	
	//Code to test quadrant 4. need values for X and Y from the real test.
	}
	




