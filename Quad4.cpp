// C++ hopefuly
#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iostream>

//rotation of robot. right: 59, 59

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
	//Need to look at my code for red ruby
	while (red == true){
		if(redness < x) { //x is a set value gain from the camera
			rightspeed = 59;
			leftspeed = 47;
		}
		sleep(1000);
		if(redness < y){
			rightSpeed=31;
			leftSpeed=59; //robot::fMax
		}
		sleep(1000);
		if ( redness > z){
			red = false;
			green = true;
		}
	}
	
	
	//while(greenness < Z){
		
	
	//Code to test quadrant 4. need values for X and Y from the real test.
	}
	




