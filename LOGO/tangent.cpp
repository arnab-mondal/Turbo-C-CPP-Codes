#include <stdio.h>
#include <math.h>
#include <conio.h>
double x1=413,y1=177,x2=335,y2=255;
int main(void)
{
   double result;
   //double x1=355,y1=167,x2=301,y2=221;

   result = atan((y2-y1)/(x2-x1));
   result = 180 * result / 3.141;
   printf("The arc tangent is %lf\n", result);
   getch();
	return(0);
}

