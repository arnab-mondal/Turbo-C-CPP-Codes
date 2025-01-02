#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <fstream.h>
#include <process.h>
#include <dos.h>
int x1,x2,y1,y2;
//char str1[10];
//char str2[10];
char valkey();
void showxy();
void initxy();
void main()
{
	char key=0,fname[10];
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
	//setbkcolor(0);
   initxy();
   fstream obj;
   obj.open("NONAME.txt",ios::out);
   obj<<"\n";
   ungetch('c');
   while(key!=27)
   {
	  key = 0;
	  while(key!=13)
	  {
		delay(10);
		key = valkey();
		cleardevice();
		showxy();
		//outtextxy(x1,y1,"+");
		//outtextxy(x2,y2,"+");
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

		line(x1,y1,x2,y2);
	  }
	  obj<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	  x1 = x2;
	  y1 = y2;
	  //clrscr();
	  //printf(" x1 = %d \t y1 = %d\n",x1,y1);
	  //printf(" x2 = %d \t y2 = %d",x2,y2);
	  key = getch();
   }
   obj.close();
   cleardevice();
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
   //cleardevice();
   //printf(" x1 = %d \t y1 = %d\n",x1,y1);
   //printf(" x2 = %d \t y2 = %d",x2,y2);
   //cleardevice();
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
	//printf(" %s %s ",str1,num);
	tmpx = x1; tmpy = y1;
	//outtextxy(x1,y1,&str1);
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
	//printf(" %s %s ",str1,num);
	//outtextxy(x2,y2,&str2);
	tmpx = x2; tmpy = y2;
	if(y2>471) tmpy = y2 - 7;
	if(x2>568) tmpx = x2 - 71;
	outtextxy(tmpx,tmpy,str2);
}
void initxy()
{
	char key=0;
	//cleardevice();
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
		//outtext("+");
		showxy();
	}
}