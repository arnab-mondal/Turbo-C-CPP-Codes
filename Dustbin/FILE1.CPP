#include <stdio.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>
int x1,y1,x2,y2;
void main()
{
	int key=100;
	x2 = 1;x1 = 8;
	y2 = 1;y1 = 6;
	clrscr();
	//while(1)
	ungetch('c');
   ungetch('c');
   while(1)
   {
		//getch();
		key=get_key();
		display();
		//gotoxy(x1,y1);
		//printf("%d %d",x1,y1);
		getch();
	}
}
void display()
{
	int i;
	clrscr();
	//menu();
	gotoxy(1,3);
	printf("%c",(char)218);
	gotoxy(3,4);
	textcolor(CYAN);
	cprintf("DBS");
	textcolor(WHITE);
	for(i=2;i<=79;i++)
	{
		if(i%7 == 0)
		{
			gotoxy(i,3);
			printf("%c",(char)194);
			gotoxy(i,21);
			printf("%c",(char)193);
			gotoxy(i,20);
			printf("%c",(char)179);
			gotoxy(i,5);
			printf("%c",(char)197);
			gotoxy(i,4);
			printf("%c",(char)179);
			gotoxy(i,7);
			printf("%c",(char)197);
			gotoxy(i,6);
			printf("%c",(char)179);
			gotoxy(i,17);
			printf("%c",(char)197);
			gotoxy(i,16);
			printf("%c",(char)179);
			gotoxy(i,19);
			printf("%c",(char)197);
			gotoxy(i,18);
			printf("%c",(char)179);
			gotoxy(i,9);
			printf("%c",(char)197);
			gotoxy(i,8);
			printf("%c",(char)179);
			gotoxy(i,11);
			printf("%c",(char)197);
			gotoxy(i,10);
			printf("%c",(char)179);
			gotoxy(i,13);
			printf("%c",(char)197);
			gotoxy(i,12);
			printf("%c",(char)179);
			gotoxy(i,15);
			printf("%c",(char)197);
			gotoxy(i,14);
			printf("%c",(char)179);
		}
		else
		{
			gotoxy(i,3);
			printf("%c",(char)196);
			gotoxy(i,21);
			printf("%c",(char)196);
			gotoxy(i,5);
			printf("%c",(char)196);
			gotoxy(i,7);
			printf("%c",(char)196);
			gotoxy(i,17);
			printf("%c",(char)196);
			gotoxy(i,19);
			printf("%c",(char)196);
			gotoxy(i,9);
			printf("%c",(char)196);
			gotoxy(i,11);
			printf("%c",(char)196);
			gotoxy(i,13);
			printf("%c",(char)196);
			gotoxy(i,15);
			printf("%c",(char)196);
		}
	}
	gotoxy(1,21);
	printf("%c",(char)192);
	for(i=4;i<=20;i++)
	{
		if(i%2==0)
		{
			gotoxy(1,i);
			printf("%c",(char)179);
		}
		else
		{
			gotoxy(1,i);
			printf("%c",(char)195);
		}
	}

	//for horizontal numbering
	for(i=0;i<10;i++)
	{
		gotoxy(i*7 + 8,4);
		cprintf("%d",x2 - (x1)/7 + i + 1);
	}
	//for vertical numbering
	for(i=0 ;i<8 ;i++)
	{
		gotoxy(2,i*2 + 6);
		cprintf("%d",y2 - y1/2 + i + 3);
	}
	//copydata();
}
int get_key()
{
   int key;
   int i;
   fstream obj;
   key = getch();
   if(key==27)
   {
		exit(0);
   }
   if(key == 75 && x2 > 1)//&& x1>13)//left
   {
	x2 = x2 - 1;
	x1 = x1 - 7;
   }
   else if(key == 77)// && x1<69)//right
   {
	x1 = x1 + 7;
	x2 = x2 + 1;
   }
   else if(key==80)// && y1<19)//down
   {
	y1 = y1 + 2;
	y2 = y2 + 1;
   }
   else if(key==72 && y2 > 1)// && y1>7)//up
   {
	y1 = y1 - 2;
	y2 = y2 - 1;
   }
   else if(key==13)
   {
		gotoxy(2,23);
		printf("Enter a value => ");
		gets(input);
		for(i=0;i<strlen(input);i++)
		if(input[i]==' ')
		input[i]='_';
		i=strlen(input);
		input[i]='_';
		input[i+1]='\0';
		obj.open(table,ios::app);
		obj<<1<<" "<<x2<<" "<<y2<<" "<<input<<"\n";
		obj.close();
		getch();
   }
   //select(x1,y1);
   //gotoxy(x1,y1);
   //printf("%d %d",x1,y1);
   if(y1>20) y1 = 20;
   if(y1<6) y1 = 6;
   if(x1>71) x1 = 71;
   if(x1<8) x1= 8;
   return key;
}
