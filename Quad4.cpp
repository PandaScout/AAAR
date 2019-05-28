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
	select_IO(0, 0);
	open_screen_stream();
	take_picture();
	sleep1(0, 40000);
	update_screen();
	x = 0;
	y = 0;
	totred = 0;
	totgreen = 0;
	totblue = 0;
	totint = 0;
	redness = 0;
	greenness = 0;
	blueness = 0;
		
	for(x = 0; x < 240; x++)
	{
		for(y = 0; y < 320; y++) 
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

	
	//Need to look at my code for red ruby
	while(reddness < x) { //x is a set value gain from the camera
		rightspeed = 59;
		leftspeed = 47;
	}
	sleep(1000);
	while(reddness< y){
		rightSpeed=31;
		leftSpeed=59;
	}
	sleep(1000);
	while(greenness < Z){
		
	
	//Code to test quadrant 4. need values for X and Y from the real test.
	}
}


