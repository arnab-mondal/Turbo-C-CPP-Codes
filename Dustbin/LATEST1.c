//*		instruction are given at the end of the program			*/
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
void exiting();   //exiting from the output screen
void blocks();    //displaying the boxes
void pattern();   //designs on the home block
void task_bar();  //the tasks to be performed
void green_triangle();  //the home block
void menubar();   //draws the upper most bar
void main()
{
		char key;
		int graphdriver=DETECT,graphmode;
		initgraph(&graphdriver,&graphmode,"C:\\TC\\TC\\BGI");
		clrscr();
		ungetch(key);
		menubar();
		while(1)
		{
			fflush(stdin);
			key=getch();
			if(key == 79 || key == 111)     //press o
			{
				clrscr();
				green_triangle();
			}
			if(key == 9)                    //press tab
			{
				clrscr();
				task_bar();
			}
			if(key == 120 || key == 88)     //press x
			{
				clrscr();
				exiting();
			}
		}
}
void blocks()
{
	int i,j,k;
	char a[]="A";char b[]="B";char c[]="C";char d[]="D";char e[]="E";char f[]="F";char g[]="G";char h[]="H";char ii[]="I";char jj[]="J";char kk[]="K";char l[]="L";char m[]="M";char n[]="N";char o[]="O";char pp[]="P";char qq[]="Q";char r[]="R";char s[]="S";char t[]="T";char u[]="U";char v[]="V";char w[]="W";char x[]="X";char y[]="Y";char z[]="Z";
	char p[20];
	setfillstyle(1,WHITE);
	bar(1,83,1000,102);
	bar(1,83,17,1000);
	setfillstyle(1,DARKGRAY);
	bar(3,85,10000,100);
	bar(2,85,18,1000);
	for(i=0,j=0;i<=12,j<=1000;i++)  //printing the vertical numbers
	{
		itoa(i+1,p,10);
		setcolor(BLACK);
		settextstyle(0,0,1);
		outtextxy(4,110+j,p);
		j=j+24;
	}
	setcolor(RED);
	settextstyle(1,0,1);
	outtextxy(35,80,a);
	outtextxy(35+54,80,b);
	outtextxy(35+108,80,c);
	outtextxy(35+162,80,d);
	outtextxy(35+216,80,e);
	outtextxy(35+270,80,f);
	outtextxy(35+324,80,g);
	outtextxy(35+54+314,80,h);
	outtextxy(35+108+314,80,ii);
	outtextxy(35+162+314,80,jj);
	outtextxy(35+206+314,80,kk);
	outtextxy(35+260+314,80,l);
	outtextxy(35+260+314+54,80,m);
	outtextxy(35+54+260+314+80+54,80,n);
	outtextxy(35+108+260+314+80+54,80,o);
	outtextxy(35+162+108+260+314+80+54,80,pp);
	outtextxy(35+206+108+260+314+80+54,80,qq);
	outtextxy(35+260+108+260+314+80+54,80,r);
	outtextxy(35+314+108+260+314+80+54,80,s);
	outtextxy(35+54+314+108+260+314+80+54,80,t);
	outtextxy(35+108+314+108+260+314+80+54,80,u);
	outtextxy(35+162+314+108+260+314+80+54,80,v);
	outtextxy(35+206+314+108+260+314+80+54,80,w);
	outtextxy(35+260+314+108+260+314+80+54,80,x);
	outtextxy(35+206+314+108+260+314+80+54+54,80,y);
	outtextxy(35+260+314+108+260+314+80+54+54,80,z);
	for(j=0;j<=1000;)
	{
		for(i=0;i<=1000;)
		{
			setcolor(WHITE);
			rectangle(20+i,103+j,70+i,125+j);
			i=i+50;
		}
		j=j+22;
	}
}
void menubar()                       //the menu
{
		int poly_red[6];
		char key;
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
		outtextxy(330,44,"INSERT");            //the task bar
		outtextxy(405,44,"OPERATIONS");
		setcolor(BLACK);
		rectangle(1,2,640,20);
		setfillstyle(1,LIGHTGRAY);
		bar(620,2,640,20);
		rectangle(619,2,640,20);
		rectangle(620,1,639,21);
		setcolor(BLACK);                       //printing the 'X'
		settextstyle(1,0,1);
		outtextxy(625,1,"X");
		if(key == 120 || key == 88)     //press x
		{
			clrscr();
			exiting();
		}
		blocks();
}
void green_triangle()               //press 'o' or 'O'
{
		int x=0;
		int poly_green[6];
		char key;
		menubar();
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
		bar(7,35,98,64);
		setcolor(RED);
		setlinestyle(1,1,1);
		rectangle(7,35,98,64);
		rectangle(8,36,97,65);
		setlinestyle(0,0,0);
		setcolor(BLACK);
		settextstyle(12,0,1);
		outtextxy(25,52,"_");
		outtextxy(25,50,"NEW");
		setfillstyle(1,7);
		outtextxy(25,77,"_");
		outtextxy(25,75,"SAVE");
		outtextxy(25,102,"_");
		outtextxy(25,100,"EXIT");
		setcolor(BLACK);
		rectangle(1,2,640,20);
		setfillstyle(1,LIGHTGRAY);
		bar(620,2,640,20);
		rectangle(619,2,640,20);
		rectangle(620,1,639,21);
		setcolor(BLACK);
		settextstyle(1,0,1);
		outtextxy(625,1,"X");
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
				setfillstyle(1,RED);         //colour changes to darkgray
				bar(7,35,98,64);             //new is selected
				settextstyle(12,0,1);
				outtextxy(25,52,"_");
				outtextxy(25,50,"NEW");
				setfillstyle(1,LIGHTGRAY);    //colour changes to gray
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
				exit(0);
			if(x == 1 && key == 13)
				exit(0);
			if(x == 2 && key == 13)
				exit(0);
			if(key == 27)          //if esc pressed the home closes
			{
				setfillstyle(1,BLACK);
				bar(1,22,10005,1030);
				menubar();
				break;
			}
			if(key == 9)
			{
				task_bar();
			}
			if(key == 79 || key == 111)
			{
				green_triangle();
			}
			if(key == 120 || key == 88)     //press x
			{
				clrscr();
				exiting();
			}
		}//end of while(key!=13)
}//end of green_triangle()
void task_bar()
{
	  char key;
	  int y=0;
	  menubar();
	  setfillstyle(1,WHITE);
	  bar(255,35,525,70);
	  setfillstyle(1,GREEN);
	  bar(255,35,255+70,70);
	  bar(255+73,35,255+144,70);
	  bar(255+147,35,525,70);
	  setcolor(BLUE);
	  settextstyle(1,0,2);
	  setlinestyle(1,1,1);
	  rectangle(257,37,255+68,68);
	  setcolor(WHITE);
	  outtextxy(260,44,"HOME");
	  outtextxy(330,44,"INSERT");
	  outtextxy(405,44,"OPERATIONS");
	  setlinestyle(0,0,0);
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
			if(key == 79 || key == 111)     //press o
			{
				clrscr();
				green_triangle();
			}
			if(key == 120 || key == 88)     //press x
			{
				clrscr();
				exiting();
			}
		}//end of while(key!=13)
}//end of task_bar()
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
void exiting()
{
		menubar();
		setcolor(WHITE);
		rectangle(1,2,640,20);
		setfillstyle(1,BLACK);
		bar(620,2,640,20);
		rectangle(619,2,640,20);
		rectangle(620,1,639,21);
		setcolor(RED);
		settextstyle(1,0,1);
		outtextxy(625,1,"X");
		setfillstyle(1,RED);
		bar(165,200,415,315);
		setfillstyle(1,WHITE);
		bar(170,210,410,310);
		setfillstyle(1,DARKGRAY);
		bar(180,220,400,300);
		settextstyle(1,0,4);
		setcolor(RED);
		outtextxy(200,240,"EXITING.....");
		delay(2500);
		exit(0);
}
/*once the key 'o' is pressed the home option is displayed
  to close it press 'esc'
  to exit from the screen press 'x'
  to operate the task bar press 'tab' and then press the r8 key
*/