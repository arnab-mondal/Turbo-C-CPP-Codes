#include <stdio.h>
#include <conio.h>
#include <fstream.h>
void main(int argc,char *argv[])
{
	fstream obj;
   int count = 0;
   char fname[16],input[1000];
   obj.open(argv[1],ios::in);
   while(obj)
   {
   	count = count + 1;
   	obj>>fname>>input;
      fstream obj2;
      obj2.open(fname,ios::out);
      obj2<<input;
      obj2.close();
   }
   obj.close();
   gotoxy(2,23);
   printf("                                                                   ");
   gotoxy(2,23);
   if(count!=0)
   printf("Almost %d files loaded",count);
   else
   printf("ERROR : No such filename exists");
   getch();
}