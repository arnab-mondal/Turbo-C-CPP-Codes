#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>
char fname[10];
int x1,y1,x2,y2;
void redraw();
void main()
{
	redraw();
   getch();
}
void redraw()
{
	fstream obj;
   obj.open("first.txt",ios::in);
   while(obj)
   {
   	obj>>x1;
      obj>>y1;
      obj>>x2;
      obj>>y2;
      printf("%d %d %d %d\n",x1,y1,x2,y2);
   }
   obj.close();
}
