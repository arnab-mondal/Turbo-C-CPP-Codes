/*the menubar() is to be broken into functions and only the task bar is
working and not the menu bar*/
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void pattern();
menubar();   //draws the upper most bar
arrow();     //the arrows on the bar
void main()
{
		char key;
		int graphdriver=DETECT,graphmode;
		initgraph(&graphdriver,&graphmode,"C:\\TC\\BGI");
		clrscr();
		ungetch(key);
		menubar();
		while(1)
		{
			key=getch();
			if(key == 79 || key == 111)
			{
				clrscr();
				menubar();
				arrow();
			}
		}

}
menubar()                       //the menu
{
		int poly_red[6],poly_green[6];
		char key;
		int x=0,y=0;
		setfillstyle(1,BLACK);
		bar(1,1,800,800);
		setfillstyle(1,DARKGRAY);
		bar(1,1,800,22);            //the home block
		setcolor(WHITE);
		line(1,22,800,22);
		poly_red[0]=21;
		poly_red[1]=1;
		poly_red[2]=1;
		poly_red[3]=21;             //  drawing the red triangle
		poly_red[4]=41;
		poly_red[5]=21;
		setfillstyle(1,RED);
		setcolor(RED);
		fillpoly(3,poly_red);
		setfillstyle(1,1);
		bar(250,30,530,75);
		setcolor(WHITE);
		line(250,75,530,75);
		line(250,30,250,75);
		line(250,30,530,30);
		line(530,30,530,75);
		setfillstyle(1,WHITE);
		bar(255,35,525,70);
		setfillstyle(1,GREEN);
		bar(255,35,255+70,70);
		bar(255+73,35,255+144,70);
		bar(255+147,35,525,70);
		settextstyle(1,0,2);
		outtextxy(260,44,"HOME");
		outtextxy(330,44,"INSERT");
		outtextxy(405,44,"OPERATIONS");
		if(key == 79 || key == 111)
		{
		setfillstyle(1,DARKGRAY);
		bar(1,1,800,22);            //the bar block
		setcolor(WHITE);
		line(1,22,800,22);
		poly_green[0]=1;
		poly_green[1]=1;
		poly_green[2]=40;           //drawing the green inverted triangle
		poly_green[3]=1;
		poly_green[4]=20;
		poly_green[5]=21;
		setcolor(GREEN);
		setfillstyle(1,GREEN);
		fillpoly(3,poly_green);     //the inverted triangle is drawn
		setfillstyle(1,LIGHTGRAY);
		bar(1,22,105,130);          //the home block
		pattern();
		setfillstyle(1,RED);
		bar(7,35,98,64);
		settextstyle(12,0,1);
		outtextxy(25,52,"_");
		outtextxy(25,50,"NEW");
		setfillstyle(1,7);
		outtextxy(25,77,"_");
		outtextxy(25,75,"SAVE");
		outtextxy(25,102,"_");
		outtextxy(25,100,"EXIT");
		while(key != 13)
		{
			fflush(stdin);
			key = getch();
			if(key == 80 && x>=0 && x<3)
				x=x+1;
			else if(key == 72 && x<=3 && x>0)
				x=x-1;
			x=x%3;
			if(x == 0)
			{
				setfillstyle(1,7);
				bar(5,22,105,130);           //the main bar
				pattern();
				setfillstyle(1,RED);           //colour changes to darkgray
				bar(7,35,98,64);            //new is selected
				settextstyle(12,0,1);
				outtextxy(25,52,"_");
				outtextxy(25,50,"NEW");
				setfillstyle(1,LIGHTGRAY);           //colour changes to gray
				outtextxy(25,77,"_");
				outtextxy(25,75,"SAVE");
				outtextxy(25,102,"_");
				outtextxy(25,100,"EXIT");
			}
			if(x == 1)
			{
				setfillstyle(1,LIGHTGRAY);
				bar(5,22,105,130);            //the main bar
				pattern();
				settextstyle(12,0,1);
				outtextxy(25,52,"_");
				outtextxy(25,50,"NEW");
				setfillstyle(1,RED);            //the open is selected
				bar(7,64,98,93);
				outtextxy(25,77,"_");
				outtextxy(25,75,"SAVE");
				setfillstyle(1,LIGHTGRAY);    //the light gray is again selected
				outtextxy(25,102,"_");
				outtextxy(25,100,"EXIT");
			}
			if(x == 2)
			{
				setfillstyle(1,7);
				bar(5,22,105,130);            //the main bar
				pattern();
				settextstyle(12,0,1);
				outtextxy(25,52,"_");
				outtextxy(25,50,"NEW");
				outtextxy(25,77,"_");
				outtextxy(25,75,"SAVE");
				setfillstyle(1,RED);            //the save block is selected
				bar(7,93,98,122);
				outtextxy(25,102,"_");
				outtextxy(25,100,"EXIT");
			}
			if(x == 0 && key == 13)
				return 1;
			if(x == 1 && key == 13)
				return 1;
			if(x == 2 && key == 13)
				exit(0);
			if(key == 27)          //if esc pressed the home closes
			{
				setfillstyle(1,BLACK);
				bar(1,22,10005,1030);
				menubar();
				break;
			}
	   }
   }
		while(key != 13)
		{
			fflush(stdin);
			key=getch();
			if(key == 77 && y>=0 && y<3)
				y=y+1;
			else if(key == 75 && y<=3 && y>0)
				y=y-1;
			y=y%3;
			if(y == 0)
			{
				setfillstyle(1,WHITE);
				bar(255,35,525,70);
				setfillstyle(1,	DARKGRAY);
				bar(255,35,255+70,70);
				setfillstyle(1,GREEN);
				bar(255+73,35,255+144,70);
				bar(255+147,35,525,70);
				settextstyle(1,0,2);
				outtextxy(260,44,"HOME");
				outtextxy(330,44,"INSERT");
				outtextxy(405,44,"OPERATIONS");
			}
			if(y == 1)
			{
				setfillstyle(1,WHITE);
				bar(255,35,525,70);
				setfillstyle(1,GREEN);
				bar(255,35,255+70,70);
				setfillstyle(1,DARKGRAY);
				bar(255+73,35,255+144,70);
				setfillstyle(1,GREEN);
				bar(255+147,35,525,70);
				settextstyle(1,0,2);
				outtextxy(260,44,"HOME");
				outtextxy(330,44,"INSERT");
				outtextxy(405,44,"OPERATIONS");
			}
			if(y == 2)
			{
				setfillstyle(1,WHITE);
				bar(255,35,525,70);
				setfillstyle(1,GREEN);
				bar(255,35,255+70,70);
				bar(255+73,35,255+144,70);
				setfillstyle(1,DARKGRAY);
				bar(255+147,35,525,70);
				settextstyle(1,0,2);
				outtextxy(260,44,"HOME");
				outtextxy(330,44,"INSERT");
				outtextxy(405,44,"OPERATIONS");
			}
			if(y == 0 && key == 13)
			exit(0);
			if(y == 1 && key == 13)
			exit(0);
			if(y == 1 && key == 13)
			exit(0);
		}
}
arrow()                          //if the key 'o' or 'O' is pressed
{
		int poly_green[6];
		int x=0;
		char key;

	   while(1)
		{
				fflush(stdin);
				key=getch();
				if(key == 79 || key == 111)
				{
					clrscr();
					menubar();
					arrow();
				}
		}

}
void pattern()
{
		setcolor(WHITE);
		line(4,24,99,24);
		line(4,24,4,126);
		line(4,126,99,126);
		line(99,126,99,24);
		setcolor(BLACK);
		line(5,25,100,25);          //horizontal line 1st
		line(5,25,5,125);           //vertical line 1st
		line(5,125,100,125);        //horizontal line 2nd
		line(100,125,100,25);       //vertical line 2nd
}
