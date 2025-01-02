#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <process.h>
//#include "dbsmenu.h"
#include <fstream.h>
#include <stdlib.h>
#include <string.h>


int x1,x2,y2,y1;
char table[20];
char input[100];
void display();
void copydata();
int get_key();
//x1=13,y1=8
void main()
{
	int key = 100;
	fstream obj;
	strcpy(table,"table.txt");
	obj.open(table,ios::out);
	obj<<"\n";
	obj.close();
	x2 = 1;x1 = 8;
	y2 = 1;y1 = 6;
	clrscr();
	textcolor(WHITE);
   x1 = 8;
   y1 = 4;
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
void copydata()
{
	fstream obj;
	int i,j,k,l,i1,ex,ex1,ey1;
	for(i=0;i<10;i++)
	for(j=0;j<8;j++)
	{
		obj.open(table,ios::in);
		while(obj)
		{
			k = x2 - x1/7 + i + 1;
			l = y2 - y1/2 + j + 1;
			obj>>ex>>ex1>>ey1>>input;
			//gotoxy(2,23);
			//printf("i=%d j=%d k=%d l=%d x1=%d y1=%d x2=%d y2=%d ex=%d ex1=%d ey1=%d %s",i,j,k,l,x1,y1,x2,y2,ex,ex1,ey1,input);
			for(i1=0;i1<strlen(input) && i1!=5 ;i1++)
			if(input[i1]=='_')
			input[i1]=' ';
			if(input[0]!='\0')
			input[strlen(input)-1] = '\0';

			if(ex1==k && ey1==l && input[0]!='\0')
			{
				//printf("%s",input);
				gotoxy(x1,y1);
				printf("%s",input);
			}
		}
		obj.close();
	}
	obj.close();
	//getch();
}
/*void copydata()
{
	fstream obj;
	for(i=0;i<10;i++)
	for(j=0;j<8;j++)
	{
		obj.open(table,ios::in);
		while(obj)
		{
			k = x2 - x1/7 + i;
			l = y2 - y1/7 + j;
			obj>>ex>>ex1>>ey1>>input;
			for(i1=0;i1<strlen(input) && i1!=5;i++)
			if(input[i1]=='_')
			input[i1]=' ';
			if(input[0]!='\0')
			input[strlen(input)-1]='\0';
			input[5]='\0';
			if(ex1==k && ey1==1 && input[0]!='\0')
			{
				gotoxy();
*/
/*int select(int x1,int y1)
{
   int i = x1,j = y1;
   textcolor(WHITE);
   for(;j<y1+6;j++)
   gotoxy(x1,y1);
   return 0;
}*/
