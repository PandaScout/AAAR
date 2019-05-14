#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>
#include <math.h>

int main ()
{
 int  err;
 printf(" Hello\n");
 err = init();
 int countrun = 0;
 int red[320][240];
 int blue[320][240];
 int green[320][240];
 int gray [320][240];
 double redness [320][240];
 int countc = 0;
 int countr = 0;
 int totred = 0;
 int totgray = 0;
 double imageredness = 0;
 double reddifference = 0;
 open_screen_stream();
 
 while(countrun <100)
 {
	countc = 0; countr = 0; totred = 0; totgray = 0; imageredness=0.0;
	reddifference = 0.0;
	select_IO(0, 0);
	take_picture();
	update_screen();
	while(countr<240)
		{
			countc=0;
			while(countc<320)
			{
					/* first get the difference between redness and old redness for this pixel and add up. */
					reddifference = reddifference + fabs((double)get_pixel(countr,countc,0)/(3.0*(double)get_pixel(countr,countc,3)) - redness[countr][countc]);
					
					/* Next updaate this pixel for all arrays. */
					red[countr][countc]=(int)get_pixel(countr,countc,0);
					green[countr][countc]=(int)get_pixel(countr,countc,1);
					blue[countr][countc]=(int)get_pixel(countr,countc,2);
					gray[countr][countc]=(int)get_pixel(countr,countc,3);
					totred = totred + (int)get_pixel(countr,countc,0);
					totgray = totgray + (int)get_pixel( countr,countc,3);
					countc++;
				}
				countr++;
			}
			imageredness = (double)totred/(3.0*(double)totgray);
			printf("	\n");
			printf("Total red %d\n", totred);
			printf("Total gray %d\n", totred);
			printf("count run %d\n", countrun);
		}	
		close_screen_stream();
		printf("Again\n");
		return 0;
	
