/*			after compiling it..press o...then press c and then esc      */
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<process.h>
void close();//closes the box by pressing 'o'
void pattern();
menubar();   //draws the upper most bar
arrow();     //the arrows on the bar
void main()
{
		char key;
		int graphdriver=DETECT,graphmode;
		initgraph(&graphdriver,&graphmode,"C:\\tc\\BGI");
		clrscr();
		ungetch(key);
		menubar();
		while(1)
		{
			fflush(stdin);
			key=getch();
			if(key == 179 || key == 111)
			{
				clrscr();
				arrow();
			}


		}
		getch();
}
menubar()                       //the menu
{
		int poly_red[6];
		char key;
		int y=0;
		setfillstyle(1,BLACK);
		bar(1,1,800,800);
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

}
arrow()                          //if the key 'o' or 'O' is pressed
{
		int poly_green[6];
		int x=0;
		char key;
		setfillstyle(1,BLACK);
		bar(1,1,800,800);
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
				fflush(stdin);
				setfillstyle(1,LIGHTGRAY);
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
				fflush(stdin);
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
				fflush(stdin);
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
				exit(0);
			if(x == 1 && key == 13)
				exit(0);          //for the time being exiting from the screen
			if(x == 2 && key == 13)
				exit(0);

		   /*	if(key == 27)          //if esc pressed the home closes
			{
				setfillstyle(1,BLACK);
				bar(1,22,10005,1030);
				menubar();
				break;
			}*/
			if(key == 99 || key == 67)      //press c
			{
				clrscr();
				setfillstyle(1,BLACK);
				bar(1,1,800,800);
				menubar();
				close();
			}
			if(key == 27)            //press esc
			{
				exit(0);
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

void close()
{
		setfillstyle(1,BLACK);
		bar(5,24,60,130);
}