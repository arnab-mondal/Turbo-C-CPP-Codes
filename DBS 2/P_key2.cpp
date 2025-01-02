/*argv[1] = filename
argv[2] = value
argv[3] = x2
argv[4] = y2*/
#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <iostream.h>
void main(int argc, char *argv[])
{
   char input[1000];
   fstream obj;
   char ans;
   obj.open(argv[1],ios::app);
   gotoxy(2,23);
   while(obj)
   {
   	obj>>input;
      if(strcmp(input,argv[2]))
      {
      	printf("Unique Values Expected. Keep This value (y/n) => ");
         ans = getch();
         if(ans == 'n' || ans =='N')
         {
            strcpy(input,x2);
            strcat(input,"_");
            strcat(input,y2);
            strcat(input,".txt");
            remove(input);
            return;
         	//breeak;
         }
      }
   }
   obj<<argv[1];
   obj.close();
}
