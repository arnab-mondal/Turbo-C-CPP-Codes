#include <stdio.h>
#include <string.h>
#include <conio.h>
char box[10][15][6];
char table[20];
int x1,y1,x2,y2;
//x1,y1 for array block selection
//x2,y2 for actual row and column
void init();
void disp();
char valkey();
void setval();
void main()
{
	int key;
   init();
   ungetch('c');
   while(key!=27)
   {
   	key = valkey();
      disp();
      if(key==13) setval();
   }
   //disp();
   //getch();
}
void init()
{
	int i,j,k;
   for(i=0;i<10;i++)
   for(j=0;j<15;j++)
   {
   	for(k=0;k<6;k++)
   	box[i][j][k] = ' ';
      box[i][j][5] = '\0';
   }
   strcpy(table,"Table.txt");
}
void disp()
{
	int i,j;
   printf("\t%-40s\n\n",table);
   for(j=0;j<80;j++)
   printf("-");
	for(i=0;i<10;i++)
   {
   	for(j=0;j<13;j++)
      {
      	if(i==x1 && j==y1)
         {
         	textcolor(BLACK);
            textbackground(WHITE);
            cprintf("%5s",box[i][j]);
            textcolor(WHITE);
            textbackground(BLACK);
            printf("|");
         }
         else
      	printf("%5s|",box[i][j]);
      }
      printf("\n");
      for(j=0;j<80;j++)
      printf("-");
      printf("\n");
   }
}
char valkey()//for setting value of x2 and y2 as per the key prssed
{
   char key;
   key = getch();
   clrscr();
   if((key == 72 || key == 56) && x2>0)//up
   {
   	x2 = x2 - 1;
      x1 = x1 - 1;
   }
   else if ((key == 80 || key == 50))//down
   {
   	x2 = x2 + 1;
      x1 = x1 + 1;
   }
   else if ((key == 75 || key == 52) && y2>0)//left
   {
   	y2 = y2 - 1;
      y1 = y1 - 1;
   }
   else if ((key == 77 || key == 54) )//right
   {
   	y2 = y2 + 1;
      y1 = y1 + 1;
   }
   else if((key==71 || key == 55) && (y2>0 && x2>0))
   {
		x2 = x2 - 1; x1 = x1 - 1;
		y2 = y2 - 1; y1 = y1 - 1;
   }
   else if((key==73 || key == 57) && (y2>0))
   {
		x2 = x2 - 1; x1 = x1 - 1;
		y2 = y2 + 1; y1 = y1 + 1;
   }
   else if((key==79 || key == 49) && (x2>0))
   {
		x2 = x2 + 1; x1 = x1 + 1;
		y2 = y2 - 1; y2 = y2 - 1;
   }
   else if((key==81 || key == 51) )
   {
		x2 = x2 + 1; x1 = x1 + 1;
		y2 = y2 + 1; y1 = y1 + 1;
   }
   if(x1>10) x1 = 9;
   if(x1<0) x1 = 0;
   if(y1>12) y1 = 12;
   if(y1<0) y1 = 0;
   clrscr();
   printf("\n\n x1 = %d y1 = %d x2 = %d y2 = %d",x1,y1,x2,y2);
   return key;
}
void setval()
{
   char input[100];
	printf("\n\n\t Enter a value to be stored at \n\t=> ");
   gets(input);
   box[x1][y1][0]=input[0];
   box[x1][y1][1]=input[1];
   box[x1][y1][2]=input[2];
   if(input[3]!='\0' || input[4]!='\0')
   box[x1][y1][3]=box[x1][y1][4]='.';
   else
   {
   	box[x1][y1][3]=input[3];
   	box[x1][y1][4]=input[4];
   }
   clrscr();
   disp();
}
