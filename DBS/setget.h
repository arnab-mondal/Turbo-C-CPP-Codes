#include <stdio.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
int x1h,y1h,x2h,y2h;
char boxh[10][15][6];
char tableh[20];
double getbox();
void setbox(long double);
char val_key();
double copy_data();
void disph(int);
void verticalh();
void horizontalh();
void select();
void add()
{
   strcpy(tableh,"Table.txt");
	cout<<"Its working\n\n\n";
	long double c;
   c = getbox() + getbox();
   //cout<<"Select a cell to place the added value "<<c;
   setbox(c);
}
double getbox()
{
	int key=0;
   double long value=0;
	//while(key!=13 && value!=0)
   ungetch('c');
   while(key!=27)
   {
   	if(key==13 && value!=0)
      break;
   	key = val_key();
      value = copy_data();
      disph(value);
      cout<<" value = "<<value;//make this line inactive and see the change
      //value = 0;
   }
   //printf("\n\n vcalue = %lf",(float)value); //getch();
   return value;
}
char val_key()//for setting value of x2 and y2 as per the key prssed
{
   char key;
   key = getch();
   clrscr();
   if((key == 72 || key == 56) && x2h>0)//up
   {
		x2h = x2h - 1;
      x1h = x1h - 1;
   }
   else if ((key == 80 || key == 50))//down
   {
		x2h = x2h + 1;
      x1h = x1h + 1;
   }
   else if ((key == 75 || key == 52) && y2h>0)//left
   {
		y2h = y2h - 1;
      y1h = y1h - 1;
   }
   else if ((key == 77 || key == 54) )//right
   {
		y2h = y2h + 1;
      y1h = y1h + 1;
   }
   else if((key==71 || key == 55) && (y2h>0 && x2h>0))
   {
		x2h = x2h - 1; x1h = x1h - 1;
		y2h = y2h - 1; y1h = y1h - 1;
   }
   else if((key==73 || key == 57) && (x2h>0))
   {
		x2h = x2h - 1; x1h = x1h - 1;
		y2h = y2h + 1; y1h = y1h + 1;
   }
   else if((key==79 || key == 49) && (y2h>0))
   {
		x2h = x2h + 1; x1h = x1h + 1;
		y1h = y1h - 1; y2h = y2h - 1;
   }
   else if((key==81 || key == 51) )
   {
		x2h = x2h + 1; x1h = x1h + 1;
		y2h = y2h + 1; y1h = y1h + 1;
   }
   //else   other();
   if(x1h>9) x1h = 9;
   if(x1h<1) x1h = 1;
   if(y1h>12) y1h = 12;
   if(y1h<1) y1h = 1;
   clrscr();
   printf("\n\n x1 = %d y1 = %d x2 = %d y2 = %d",x1h,y1h,x2h,y2h);
   return key;
}
double copy_data()
{
   int i,j,k,l,i1,ex,ex1,ey1;
   char input[100],temp[100];
   fstream obj;
   for(i=0;i<10;i++)
   for(j=0;j<15;j++)
   {
		for(k=0;k<6;k++)
		boxh[i][j][k] = ' ';
      boxh[i][j][5] = '\0';
   }
	for(i=1;i<10;i++)
   for(j=1;j<13;j++)
   {
      obj.open(tableh,ios::in);
   	while(obj)
      {
      	k = x2h - x1h + i;
			l = y2h - y1h + j;
         obj>>ex>>ex1>>ey1>>input;
         for(i1=0;i1<strlen(input);i1++)
	  		if(input[i1]=='_')
			input[i1]=' ';
      	if(input[0]!='\0')
		   input[strlen(input)-1] = '\0';
			if(ex1==k && ey1==l && input[0]!='\0')
			{
				boxh[i][j][0] = input[0];
				boxh[i][j][1] = input[1];
				boxh[i][j][2] = input[2];
				boxh[i][j][3] = input[3];
				boxh[i][j][4] = input[4];
            if(i==x1h && y1h==j) strcpy(temp,input);
         }
		}
      obj.close();
   }
   /*if(_atold(temp)==0)
	{
   	cout<<"\nreturning zero";//getch();
   	return 0;
   }
   else
   {
      printf("\n\n vcalue = %lf",(float)_atold(temp)); //getch();
   	return _atold(temp);
   }*/
   if(_atold(temp)!=0)
   return _atold(temp);
   return 0;
}
void disph(int colour = 0)
{
	int i,j;
   printf("\t%-40s\n\n",tableh);
   for(j=0;j<80;j++)
   printf("-");
   printf("\n");
	for(i=0;i<10;i++)
   {
		if(i!=0)
      verticalh();
		for(j=0;j<13;j++)
      {
			if(i==0 && j!=0)
			horizontalh();
			if(i==x1h && j==y1h)
			{
            if(colour==0)
            {
					textcolor(RED);
		   		textbackground(CYAN);
            }
            else
            {
					textcolor(BLACK);
		   		textbackground(WHITE);
            }
			   cprintf("%5s",boxh[i][j]);
			   textcolor(WHITE);
			   textbackground(BLACK);
			   printf("|");
			}
			else
			printf("%5s|",boxh[i][j]);
      }
      printf("\n");
      for(j=0;j<80;j++)
      printf("-");
      printf("\n");
   }
}
void setbox(long double c)
{
	fstream obj;
   obj.open(tableh,ios::app);
   int key=0;
   cout<<"\n\nSelect a cell to place this value ";
   while(key!=13)
   {
   	key = val_key();
      disph(-1);
      cout<<"\nSelect Row = "<<x2h<<"\tCol = "<<y2h<<"\n\n\tfor Value = "<<c;
   }
   obj<<1<<" "<<x2h<<" "<<y2h<<" "<<c<<"_\n";
}
void horizontalh()
{
	int i,j;// = x2 - x1;
	for(i=1;i<13;i++)
   {
		j = y2h - y1h;
		gcvt(j+i+1,5,boxh[0][i]);
   }
}
void verticalh()
{
	int i,j;
   for(i=1;i<10;i++)
   {
		j = x2h - x1h;
      gcvt(j+i+1,5,boxh[i][0]);
   }
}
/*void select()
{
	int key = 0;
	while(key!=13)
   {
   	if(key == 141)//up
      else if(key == 145)//down
      else if(key == 115)//left
      else if(key == 116)//right

}*/
/*void main()
{
	strcpy(table2,"Table.txt");
	add();
   clrscr();
   copy_data();
   disp(-1);
   getch();
}*/
/*
here for demonstration purpose main() is initiating the function call
but in actual case this should be done from external file.
Sequence of function call
-> select the operation to be performed
               |
               |---> getbox() helps in selecting the box and getting
               |          |   the value of valid cell
               |			  |
               |          |-----> val-key() for changing x1,y1,x2,y2
               |          |
               |          |
               |          |-----> copy-data() according to x2,y2
               |          |                    box[][][] is set
               |          |
               |           -----> disp(int) for all sorts of display operation
               |                            colour = 0 if not usable cell selected
               |                            else otherwise
               |
                ---> setbox() gets the processed value (in c) and stores it
                              to "Table.txt". During its operation val-key is
                              used along with disp() as it was used earlier
                              for getbox(), in the same sequence

To Entirely change the contents of "Table.txt" execute "Try.cpp"
REMEMBER once if try is executed all the contents will be lost
*/
