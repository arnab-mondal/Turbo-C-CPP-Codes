#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void main()
{
	int x1,y1,x2,y2;
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	errorcode = graphresult();

	if (errorcode != grOk)
	{
	   printf("Graphics error: %s\n", grapherrormsg(errorcode));
	   printf("Press any key to halt:");
	   getch();
	   exit(1);
	}
	x1 = 0;
	y1 = 0;
	x2 = 630;
	y2 = 500;
	line(x1,y1,x2,y2);
	getch();
}