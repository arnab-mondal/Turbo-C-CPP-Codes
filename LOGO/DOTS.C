#include <stdio.h>
#include <bios.h>
#include <conio.h>
#include <graphics.h>
int x1,x2,y1,y2;
void init();
void main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	gotoxy(1,1);
	printf(" Hit Enter to Stop This!!");
	init();
	getch();
}
void init()
{
	int key,val=1;
	char *str;
	//strcpy(str,".");
	x1 = y1 = 200;
	outtextxy(x1,y1,".");
	while(key!=13)
	{
		//cleardevice();
		setcolor(val+1);
		outtextxy(x1,y1,".");
		if(key==72)
		y1 = y1 - 5;
		else if(key==80)
		y1 = y1 + 5;
		else if(key==75)
		x1 = x1 - 5;
		else if(key==77)
		x1 = x1 + 5;
		else if(key==71)
		{
			x1 = x1 - 5;
			y1 = y1 - 5;
		}
		else if(key==73)
		{
			x1 = x1 + 5;
			y1 = y1 - 5;
		}
		else if(key==79)
		{
			x1 = x1 - 5;
			y1 = y1 + 5;
		}
		else if(key==81)
		{
			x1 = x1 + 5;
			y1 = y1 + 5;
		}
		key = getch();
		val = val + 1;
		val = val%14;
	}
}