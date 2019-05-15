#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iostream>
//ip address 10.140.137.215
//raspberry pass
//pi username
// scp -r ~/Desktop/Engr101/MainProject/Cpp/* pi@10.140.137.215:~/AVC/
//SSh ssh pi@10.140.137.215    
// Compiler g++ -o camera Camera.cpp -le101
// sudo ./camera
int main ()
{
 int  err;
 printf(" Hello\n");
 err = init(0);
 int countrun = 0;
 int red[320][240];
 int blue[320][240];
 int green[320][240];
 int gray [320][240];
 int countc = 0;
 int countr = 0;
 int totred = 0;
 int totgray = 0;
 int totgreen = 0;
 int totblue = 0;
 open_screen_stream();
 while(countrun <100)
 {
	countc = 0; countr = 0; totred = 0; totgray = 0; totgreen = 0; totblue = 0;
	take_picture();
	update_screen();
	while(countr<240)
		{
			countc=0;
			while(countc<320)
			{
					
					/* Next update this pixel for all arrays. */
					red[countr][countc]=(int)get_pixel(countr,countc,0);
					green[countr][countc]=(int)get_pixel(countr,countc,1);
					blue[countr][countc]=(int)get_pixel(countr,countc,2);
					gray[countr][countc]=(int)get_pixel(countr,countc,3);
					totred = totred + (int)get_pixel(countr,countc,0);
					totgreen = totgreen + (int)get_pixel(countr,countc,1);
					totblue = totblue + (int)get_pixel( countr,countc,2);
					totgray = totgray + (int)get_pixel( countr,countc,3);
					countc++;
				}
				countr++;
			}
			//Open file in write mode
			std::ofstream outfile;
			outfile.open("test.txt");
			//Write to file
			outfile << totred << std::endl;
			outfile << totgreen << std::endl;
			outfile << totblue << std::endl;
			outfile << totgray << std::endl;
			//Close file
			outfile.close();
			printf("	\n");
			printf("Total red %d\n", totred);
			printf("Total gray %d\n", totred);
			printf("Total blue %d\n", totblue);
			printf("Total green %d\n", totgreen);
			printf("count run %d\n", countrun);
		}	
		close_screen_stream();
		printf("Again\n");
		return 0;
}
