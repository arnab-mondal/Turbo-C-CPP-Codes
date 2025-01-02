#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int x1,y1,x2,y2;
int count;
void main()
{
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
	count = 0;
	setpix();
}
void setpix()
{
	char key;
	if (count!=0)
	{
		x2 = x1;
		y2 = y1;
	}
	key = getch();
	while(key!=13)
	{
		if(key == 72)//up
		y=y-1;
		else if (key == 80)//down
		y=y+1;
		else if (key == 75)//left
		x = x+1;
		else if (key == 77)//right
