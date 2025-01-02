#include <iostream.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <fstream.h>
#include <process.h>
#include <dos.h>
int x1,x2,y1,y2;
char fname[15];
float rad2;
char valkey();
void showxy();
void initxy();
void redraw(int);
void menu();
void gencode();
void main()
{
	char key=0;
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
	cleardevice();
	menu();
   ungetch('c');
   while(key!=27)
   {
	  fstream obj;
	  obj.open(fname,ios::app);
	  key = 0;
	  while(key!=13)
	  {
		delay(10);
		key = valkey();
		cleardevice();
		showxy();
		putpixel(x1,y1,WHITE);
		putpixel(x1+1,y1+1,WHITE);
		putpixel(x1+1,y1-1,WHITE);
		putpixel(x1-1,y1+1,WHITE);
		putpixel(x1-1,y1-1,WHITE);
		putpixel(x2,y2,CYAN);
		putpixel(x2+1,y2+1,CYAN);
		putpixel(x2+1,y2-1,CYAN);
		putpixel(x2-1,y2+1,CYAN);
		putpixel(x2-1,y2-1,CYAN);
		redraw(0);
		line(x1,y1,x2,y2);
		gencode();
	  }
	  obj<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	  x1 = x2;
	  y1 = y2;
	  obj.close();
	  key = getch();
	  if(key=='p' || key=='P')
	  {
		while(valkey()!=13)
		{
			x1 = x2;
			y1 = y2;
			cleardevice();
			redraw(0);
			putpixel(x1,y1,4);
			putpixel(x1+1,y1+1,4);
			putpixel(x1+1,y1-1,4);
			putpixel(x1-1,y1+1,4);
			putpixel(x1-1,y1-1,4);
			showxy();
		}
	  }
   }
   cleardevice();
   fflush(stdin);
   printf("\n\n Do you want to SAVE this document?\n\n\t If yes enter a name else hit 'n' ");
   printf("\n\n\t\t Remember to ADD \".txt\" to your filename => ");
   gets(fname);
   if(((fname[0]=='n' || fname[0]=='N') && fname[1]=='\0') || fname[0]=='\0')
   {
	printf(" Quitting ALOGO!!\n\n Thank You");
   }
   else
   {
	if(rename("NONAME.txt", fname)!=0)
	printf("\n\n\t \'%s\' SUCCESSFULLY Saved",fname);
   }
   getch();
}
char valkey()//for setting value of x2 and y2 as per the key prssed
{
   char key;
   key = getch();
   if((key == 72 || key == 56) && y2>0)//up
   y2 = y2 - 1;
   else if ((key == 80 || key == 50) && y2<479)//down
   y2 = y2 + 1;
   else if ((key == 75 || key == 52) && x2>0)//left
   x2 = x2 - 1;
   else if ((key == 77 || key == 54) && x2<639)//right
   x2 = x2 + 1;
   else if((key==71 || key == 55) && (y2>0 && x2>0))
   {
		x2 = x2 - 1;
		y2 = y2 - 1;
   }
   else if((key==73 || key == 57) && (y2>0 && x2<639))
   {
		x2 = x2 + 1;
		y2 = y2 - 1;
   }
   else if((key==79 || key == 49) && (x2>0 && y2<479))
   {
		x2 = x2 - 1;
		y2 = y2 + 1;
   }
   else if((key==81 || key == 51) && (x2<639 && y2<479))
   {
		x2 = x2 + 1;
		y2 = y2 + 1;
   }
   clrscr();
   return key;
}
void showxy()//for showing co-ordinates at the two ends
{
	char str1[10];
	char str2[10];
	char num[3];
	int tmpx,tmpy;
	gcvt((float)x1,3,num);
	str1[0]='(';str1[1]='\0';
	strcat(str1,num);
	gcvt((float)y1,3,num);
	strcat(str1,",");
	strcat(str1,num);
	strcat(str1,")");
	tmpx = x1; tmpy = y1;
	if(y1>471) tmpy = y1 - 7;
	if(x1>568) tmpx = x1 - 70;
	outtextxy(tmpx,tmpy,str1);
	gcvt((float)x2,3,num);
	str2[0]='(';str2[1]='\0';
	strcat(str2,num);
	gcvt((float)y2,3,num);
	strcat(str2,",");
	strcat(str2,num);
	strcat(str2,")");
	tmpx = x2; tmpy = y2;
	if(y2>471) tmpy = y2 - 7;
	if(x2>568) tmpx = x2 - 71;
	outtextxy(tmpx,tmpy,str2);
}
void initxy()
{
	char key=0;
	fstream obj2;
	obj2.open("NONAME.txt",ios::out);
	obj2<<"\n";
	obj2.close();
	x2 = getmaxx() / 2;
	y2 = getmaxy() / 2;
	printf("\n\tSelect the initial starting point after this screen");
	printf("\n\t Use NUMPAD or ARROW KEYS for moving the tiny cursor");
	printf("\n\t  To escape after initial screen press ENTER followed by ESC");
	getch();
	ungetch('c');
	clrscr();
	while(key!=13)
	{
		key = valkey();
		cleardevice();
		x1 = x2;
		y1 = y2;
		moveto(x1,y1);
		putpixel(x1,y1,4);
		putpixel(x1+1,y1+1,4);
		putpixel(x1+1,y1-1,4);
		putpixel(x1-1,y1+1,4);
		putpixel(x1-1,y1-1,4);
		showxy();
	}
}
void redraw(int ip)
{
   int ex1,ex2,ey1,ey2;
   fstream obj1;
   obj1.open(fname,ios::in);
   while(obj1)
   {
	  obj1>>ex1;
	  obj1>>ey1;
	  obj1>>ex2;
	  obj1>>ey2;
	  line(ex1,ey1,ex2,ey2);
   }
   if(ip==1)
   {
		x1 = x2 = ex2;
		y1 = y2 = ey2;
   }
   obj1.close();
}
void menu()
{
	int ch;
	printf("\t\t\t WELCOME TO ALOGO\n\n");
	printf("\n 1. Create a NEW file");
	printf("\n\n 2. Open an EXISTING file");
	printf("\n\n 3. EXIT");
	printf("\n\n\n Enter your choice => ");
	scanf("%d",&ch);
	if(ch==1)
	{
		strcpy(fname,"NONAME.txt");
		initxy();
	}
	else if(ch==2)
	{
		system("dir /p *.txt");
		printf("\n\n\n\t Enter file name with extension name=> ");
		gets(fname);
		fstream tmp;
		tmp.open(fname,ios::in);
		if(tmp.fail())
		{
			printf("Cannot open file!!");
			getch();
			exit(1);
		}
		tmp.close();
		redraw(1);
	}
	else if(ch==3)
	{
		printf("\t\t Quitting ALOGO!!\n\n \t\t\t Thank You");
		getch();
		exit(0);
	}
}
void gencode()
{
	float len=0,rad = 0;
	len = pow((pow((x1-x2),2) + pow((y1-y2),2)),0.5);
	rad2 = rad;
	rad = atan2((y1-y2),(x1-x2));
	rad = (180 * rad / 3.1405);
	rad = 180 - rad;
	//rad2 = rad2 - rad;
	printf(" rt %3.0lf\n fd %4.0lf",rad2-rad,len);
	//rad2 = rad;
}

