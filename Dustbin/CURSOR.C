#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
main()
{
	int gd=DETECT,gm;
	char key;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	ungetch(key);
	fflush(stdin);
	while(key!=13)
	{
		key=getch();
		setfillstyle(1,WHITE);
		bar(20,50,27,52);
		delay(400);
		setfillstyle(1,BLACK);
		bar(20,50,27,52);
		delay(400);
	}
	exit(0);

	getch();
}