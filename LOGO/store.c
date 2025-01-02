#include <stdio.h>
#include <fstream.h>
#include <iostream.h>
#include <conio.h>
//#include <graphics.h>
int x1,x2,y1,y2;
//void showxy();
char valkey();
void initxy();
void main()
{
	char key=0,fname[10];
   fstream obj;
   obj.open("NONAME.txt",ios::out);
   obj<<"\n";
   while(key!=27)
   {
	  key = 0;
	  while(key!=13)
	  {
		//delay(10);
		key = valkey();
		//cleardevice();
		//showxy();
		//outtextxy(x1,y1,"+");
		//outtextxy(x2,y2,"+");
		/*putpixel(x1,y1,WHITE);
		putpixel(x1+1,y1+1,WHITE);
		putpixel(x1+1,y1-1,WHITE);
		putpixel(x1-1,y1+1,WHITE);
		putpixel(x1-1,y1-1,WHITE);
		putpixel(x2,y2,CYAN);
		putpixel(x2+1,y2+1,CYAN);
		putpixel(x2+1,y2-1,CYAN);
		putpixel(x2-1,y2+1,CYAN);
		putpixel(x2-1,y2-1,CYAN);

		line(x1,y1,x2,y2);*/
	  }
     obj<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
	  x1 = x2;
	  y1 = y2;
	  //clrscr();
	  printf(" x1 = %d \t y1 = %d\n",x1,y1);
	  printf(" x2 = %d \t y2 = %d",x2,y2);
	  key = getch();
   }
   obj.close();
   //cleardevice();
   clrscr();
   printf("\n\n Do you want to SAVE this document?\n\n\t\t If yes enter a name else click else hit 'n' => ");
   gets(fname);
   if((fname[0]=='n' || fname[0]=='N') && fname[1]=='\0')
   {
   	printf(" Quitting ALOGO!!\n\n Thank You");
   }
   else
   {
   	rename("NONAME.txt", fname);
   }
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
   printf(" x1 = %d \t y1 = %d\n",x1,y1);
   printf(" x2 = %d \t y2 = %d",x2,y2);
   //cleardevice();
   return key;
}
/*void store()
{
	fstream obj;
   obj.open("NONAME.txt",ios::app);
   obj<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
   obj.close();

*/
