#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <fstream.h>
#include <stdlib.h>

void menu();
int file();
int operations();
int help();
void abt();
void hlp();
void display2();
void numbering();
void clear();
int x1,x2,y2,y1;
char str_x2[7],str_y2[7];
int get_key();
char input[100];
char table[16];
void main()
{
   int key = 13;
   x2 = 1;x1 = 8;
   y2 = 1;y1 = 6;
   clrscr();
   textcolor(WHITE);
   textbackground(BLACK);
   x1 = 8;
   y1 = 6;
   display2();
   ungetch('c');
   ungetch('c');
   while(1)
   {
		//input[0]='\0';
		key = get_key();
		gotoxy(2,23);
		cprintf("                                                       ");
		clear();
		numbering();
		gotoxy(x1,y1);
		//textbackground(WHITE);
		//textcolor(BLACK);
		//cprintf("%s",input);
		//cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
		gotoxy(x1,y1);
		//cprintf("%d %d",x1,x2);
		gotoxy(x1,y1);
		textbackground(BLACK);
		textcolor(WHITE);
		//cprintf("%d %d",x2,y2);
		if(getch()==27)
		exit(0);
   }
}

void numbering()
{
	//for horizontal numbering
	int i;
	for(i=0;i<10;i++)
	{
		gotoxy(i*7 + 8,4);
		cprintf("      ");
		gotoxy(i*7 + 8,4);
		cprintf("%d",x2 - (x1/7)  + i + 1);
	}
	//for vertical numbering
	for(i=0;i<8;i++)
	{
		gotoxy(2,i*2 + 6);
		cprintf("     ");
		gotoxy(2,i*2 + 6);
		cprintf("%d",y2 - (y1/2) + i + 3);
	}
}
void display2()
{
	int i;
	clrscr();
	menu();
	gotoxy(1,3);
	printf("%c",(char)218);
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
	numbering();
}

int get_key()
{
   int key,i;
   key = getch();
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
   else if(key == 59)
   {
	clrscr();
	menu();
	display2();
	gotoxy(x1,y1);
	cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
	file();
   }
   else if(key == 60)
   {
	clrscr();
	menu();
	display2();
	gotoxy(x1,y1);
	cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
	operations();
   }
   else if(key == 61)
   {
	clrscr();
	menu();
	display2();
	gotoxy(x1,y1);
	cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
	help();
   }
   else if(key==13)
   {
		gotoxy(2,23);
		printf("Enter anything=> ");
		gets(input);
		for(i=0;i<strlen(input);i++)
		if(input[i]==' ')
		input[i]='_';
		if(!strlen(input))
		return 13;

		fstream obj;
		table[0]='\0';
		itoa(x2,str_x2,10);
		strcat(table,str_x2);
		itoa(y2,str_y2,10);
		strcat(table,"_");
		strcat(table,str_y2);
		strcat(table,".txt");
		obj.open(table,ios::out);
		obj<<input;
		obj.close();
		display2();
   }
   if (key==83)
   {
		table[0]='\0';
		itoa(x2,str_x2,10);
		strcat(table,str_x2);
		itoa(y2,str_y2,10);
		strcat(table,"_");
		strcat(table,str_y2);
		strcat(table,".txt");
		remove(table);
		return 83;
   }
   if(y1>20) y1 = 20;
   if(y1<6) y1 = 6;
   if(x1>71) x1 = 71;
   if(x1<8) x1= 8;
   return key;
}

void menu()
{
	int i;
	textcolor(BLACK);
	textbackground(WHITE);
	gotoxy(80,1);
	cprintf(" ");
	for(i=1;i<=79;i++)
	{
		gotoxy(i,1);
		cprintf(" ");
		gotoxy(i,25);
		cprintf(" ");
	}
	gotoxy(2,1);
	textcolor(RED);
	cprintf("%c ",(char)240);
	cprintf("F1 ");
	gotoxy(7,1);
	printf("File");
	gotoxy(14,1);
	cprintf(" F2 ");
	gotoxy(18,1);
	printf("Operations");
	gotoxy(29,1);
	cprintf(" F3 ");
	gotoxy(33,1);
	printf("Help");
	textcolor(WHITE);
	textbackground(BLACK);
}

int file()
{
	int i,j,n=7,m=21,x=0;
	char key;
	gotoxy(6,1);
	textcolor(WHITE);
	textbackground(GREEN);
	cprintf(" File ");
	textcolor(BLACK);
	textbackground(WHITE);
	for(i=3;i<=n+1;i++)
	{
		for(j=7;j<=m+1;j++)
		{
			gotoxy(j,i);
			printf("%c",(char)176);
		}
		printf("\n");
	}
	for(i=2;i<=n;i++)
	{
		for(j=6;j<=m;j++)
		{
			gotoxy(j,i);
			cprintf(" ");
		}
		printf("\n");
	}
	gotoxy(6,2);
	printf("%c",(char)218);
	for(i=7;i<=m-2;i++)
	{
		gotoxy(i,2);
		printf("%c",(char)196);
	}
	gotoxy(m-1,2);
	printf("%c",(char)191);
	for(i=3;i<=n-1;i++)
	{
		gotoxy(m-1,i);
		printf("%c",(char)179);
	}
	gotoxy(m-1,n);
	printf("%c",(char)217);
	for(i=3;i<=n-1;i++)
	{
		gotoxy(6,i);
		printf("%c",(char)179);

	}
	gotoxy(6,n);
	printf("%c",(char)192);
	for(i=7;i<=m-2;i++)
	{
		gotoxy(i,n);
		printf("%c",(char)196);
	}
	if(x == 0)
	{
		gotoxy(7,3);
		textcolor(WHITE);
		textbackground(GREEN);
		cprintf(" Open ctrl+O ");
		gotoxy(7,4);
		printf(" Save ctrl+s");
		gotoxy(7,5);
		printf(" Save as...  ");
		gotoxy(7,6);
		printf(" Exit        ");
		textcolor(WHITE);
		textbackground(BLACK);
	}
	while(key != 13)
	{
		fflush(stdin);
		key = getch();
		if(key == 80 && x>=0 && x<4)
		x=x+1;
		else if(key == 72 && x<=4 && x>0)
		x=x-1;
		x=x%4;
		if(x == 0)
		{
			gotoxy(7,3);
			textcolor(WHITE);
			textbackground(GREEN);
			cprintf(" Open ctrl+O ");
			gotoxy(7,4);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Save ctrl+s ");
			gotoxy(7,5);
			cprintf(" Save as...  ");
			gotoxy(7,6);
			cprintf(" Exit        ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 1)
		{
			gotoxy(7,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Open ctrl+O ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(7,4);
			cprintf(" Save ctrl+s ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(7,5);
			cprintf(" Save as...  ");
			gotoxy(7,6);
			cprintf(" Exit        ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 2)
		{
			gotoxy(7,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Open ctrl+O ");
			gotoxy(7,4);
			cprintf(" Save ctrl+s ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(7,5);
			cprintf(" Save as...  ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(7,6);
			cprintf(" Exit        ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 3)
		{
			gotoxy(7,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Open ctrl+O ");
			gotoxy(7,4);
			cprintf(" Save ctrl+s ");
			gotoxy(7,5);
			cprintf(" Save as...  ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(7,6);
			cprintf(" Exit        ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 0 && key == 13)
		return 101;
		if(x == 1 && key == 13)
		return 102;
		if(x == 2 && key == 13)
		return 103;
		if(x == 3 && key == 13)
		exit(0);
		if(key == 60 || key == 77)
		{
			clrscr();
			menu();
			display2();
			gotoxy(x1,y1);
			cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
			operations();
			break;
		}
		if(key == 61 || key == 75)
		{
			clrscr();
			menu();
			display2();
			gotoxy(x1,y1);
			cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
			help();
			break;
		}
		if(key == 27)
		{
			clrscr();
			display2();
			return 0;
		}
	}
	textcolor(WHITE);
	textbackground(BLACK);
	return 0;
}

int operations()
{
	int i,j,n=8,m=35,x=0;
	char key;
	gotoxy(17,1);
	textcolor(WHITE);
	textbackground(GREEN);
	cprintf(" Operations ");
	textcolor(BLACK);
	textbackground(WHITE);
	for(i=3;i<=n+1;i++)
	{
		for(j=18;j<=m+1;j++)
		{
			gotoxy(j,i);
			printf("%c",(char)176);
		}
		printf("\n");
	}
	for(i=2;i<=n;i++)
	{
		for(j=17;j<=m;j++)
		{
			gotoxy(j,i);
			cprintf(" ");
		}
		printf("\n");
	}
	gotoxy(17,2);
	printf("%c",(char)218);
	for(i=3;i<=n-1;i++)
	{
		gotoxy(17,i);
		printf("%c",(char)179);
		printf("\n");
	}
	gotoxy(17,n);
	printf("%c",(char)192);
	for(i=18;i<=m-2;i++)
	{
		gotoxy(i,n);
		printf("%c",(char)196);
	}
	for(i=18;i<=m-2;i++)
	{
		gotoxy(i,2);
		printf("%c",(char)196);
	}
	gotoxy(m-1,2);
	printf("%c",(char)191);
	gotoxy(m-1,n);
	printf("%c",(char)217);
	for(i=3;i<=n-1;i++)
	{
		gotoxy(m-1,i);
		printf("%c",(char)179);
		printf("\n");
	}
	if(x == 0)
	{
		gotoxy(18,3);
		textcolor(WHITE);
		textbackground(GREEN);
		cprintf(" Addition       ");
		textcolor(BLACK);
		textbackground(WHITE);
		gotoxy(18,4);
		cprintf(" Substraction   ");
		gotoxy(18,5);
		cprintf(" Multiplication ");
		gotoxy(18,6);
		cprintf(" Division    ");
		gotoxy(18,7);
		cprintf(" Primary Key    ");
		textcolor(WHITE);
		textbackground(BLACK);
	}
	while(key != 13)
	{
		fflush(stdin);
		key = getch();
		if(key == 80 && x>=0 && x<5)
		x=x+1;
		else if(key == 72 && x<=4 && x>0)
		x=x-1;
		if(key == 59 || key == 75)
		{
			clrscr();
			menu();
			display2();
			gotoxy(x1,y1);
			cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
			file();
			break;
		}
		if(key == 61 || key == 77)
		{
			clrscr();
			menu();
			display2();
			gotoxy(x1,y1);
			cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
			help();
			break;
		}
		if(key == 27)
		{
			clrscr();
			display2();
			return 0;
		}
		x=x%5;
		if(x == 0)
		{
			gotoxy(18,3);
			textcolor(WHITE);
			textbackground(GREEN);
			cprintf(" Addition       ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(18,4);
			cprintf(" Substraction   ");
			gotoxy(18,5);
			cprintf(" Multiplication ");
			gotoxy(18,6);
			cprintf(" Division       ");
			gotoxy(18,7);
			cprintf(" Primary Key    ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 1)
		{
			gotoxy(18,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Addition       ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(18,4);
			cprintf(" Substraction   ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(18,5);
			cprintf(" Multiplication ");
			gotoxy(18,6);
			cprintf(" Division       ");
			gotoxy(18,7);
			cprintf(" Primary Key    ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 2)
		{
			gotoxy(18,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Addition       ");
			gotoxy(18,4);
			cprintf(" Substraction   ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(18,5);
			cprintf(" Multiplication ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(18,6);
			cprintf(" Division       ");
			gotoxy(18,7);
			cprintf(" Primary Key    ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 3)
		{
			gotoxy(18,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Addition       ");
			gotoxy(18,4);
			cprintf(" Substraction   ");
			gotoxy(18,5);
			cprintf(" Multiplication ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(18,6);
			cprintf(" Division       ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(18,7);
			cprintf(" Primary Key    ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 4)
		{
			gotoxy(18,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Addition       ");
			gotoxy(18,4);
			cprintf(" Substraction   ");
			gotoxy(18,5);
			cprintf(" Multiplication ");
			gotoxy(18,6);
			cprintf(" Division       ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(18,7);
			cprintf(" Primary Key    ");
			textcolor(WHITE);
			textbackground(BLACK);
		}

	}
	return 0;
}

int help()
{
	int i,j,n=6,m=42,x=0;
	char key;
	gotoxy(32,1);
	textcolor(WHITE);
	textbackground(GREEN);
	cprintf(" Help ");
		textcolor(BLACK);
	textbackground(WHITE);
	for(i=3;i<=n+1;i++)
	{
		for(j=33;j<=m+1;j++)
		{
			gotoxy(j,i);
			printf("%c",(char)176);
		}
		printf("\n");
	}
	for(i=2;i<=n;i++)
	{
		for(j=32;j<=m;j++)
		{
			gotoxy(j,i);
			cprintf(" ");
		}
		printf("\n");
	}
	gotoxy(m-10,2);
	printf("%c",(char)218);
	for(i=3;i<=n-1;i++)
	{
		gotoxy(m-10,i);
		printf("%c",(char)179);
		printf("\n");
	}
	gotoxy(m-10,n);
	printf("%c",(char)192);
	for(i=m-9;i<=m-2;i++)
	{
		gotoxy(i,n);
		printf("%c",(char)196);
	}
	gotoxy(m-1,n);
	printf("%c",(char)217);
	for(i=m-9;i<=m-2;i++)
	{
		gotoxy(i,2);
		printf("%c",(char)196);
	}
	gotoxy(m-1,2);
	printf("%c",(char)191);
	for(i=3;i<=n-1;i++)
	{
		gotoxy(m-1,i);
		printf("%c",(char)179);
		printf("\n");
	}
	if(x == 0)
	{
		gotoxy(33,3);
		textcolor(WHITE);
		textbackground(GREEN);
		cprintf("  About ");
		gotoxy(33,4);
		printf("  Help  ");
		gotoxy(33,5);
		printf("  Exit  ");
		textcolor(WHITE);
		textbackground(BLACK);
	}
	while(key != 13)
	{
		fflush(stdin);
		key = getch();
		if(key == 80 && x>=0 && x<3)
		x=x+1;
		else if(key == 72 && x<=3 && x>0)
		x=x-1;
		if(key == 59 || key == 77)
		{
			clrscr();
			menu();
			display2();
			gotoxy(x1,y1);
			cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
			file();
			break;
		}
		if(key == 60 || key == 75)
		{
			clrscr();
			menu();
			display2();
			gotoxy(x1,y1);
			cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
			operations();
			break;
		}
		if(key == 27)
		{
			clrscr();
			display2();
			return 0;
		}
		x=x%3;
		if(x == 0)
		{
			gotoxy(33,3);
			textcolor(WHITE);
			textbackground(GREEN);
			cprintf("  About ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(33,4);
			cprintf("  Help  ");
			gotoxy(33,5);
			cprintf("  Exit  ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 1)
		{
			gotoxy(33,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf("  About ");
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(33,4);
			cprintf("  Help  ");
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(33,5);
			cprintf("  Exit  ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 2)
		{
			gotoxy(33,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf("  About ");
			gotoxy(33,4);
			cprintf("  Help  ");
			gotoxy(33,5);
			textcolor(WHITE);
			textbackground(GREEN);
			cprintf("  Exit  ");
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 2 && key == 13)
		{
			exit(0);
		}
		if(x == 0 && key == 13)
		{
			clrscr();
			menu();
			display2();
			abt();
		}
		if(x == 1 && key == 13)
		{
			clrscr();
			menu();
			display2();
			hlp();
		}
	}

	return 0;
}

void abt()
{
	clrscr();
	gotoxy(2,3);
	printf("This is the about file");
	getch();
	ungetch(13);
	return;
}

void hlp()
{
	clrscr();
	gotoxy(2,3);
	printf("This is the help file");
	getch();
	ungetch(13);
	return;
}
void clear()
{
	int i,j,k,l;
	gotoxy(3,4);
	textcolor(CYAN + BLINK);
	cprintf("DBS");
	textcolor(WHITE);
	for(k=6;k<=20;k=k+2)
	{
		for(i=8;i<=71;i=i+7)
		{
			j = i/7; l = k/2;
			//gotoxy(2,23);
			//cprintf("                                                  ");
			gotoxy(i,k);
			cprintf("      ");
			fstream obj;
			table[0]='\0';
			itoa(x2 - (x1/7)  + j,str_x2,10);
			strcat(table,str_x2);
			itoa(y2 - (y1/2) + l,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);
			strcat(table,".txt");
			obj.open(table,ios::in);
			if(obj)
			{
				obj>>input;
				//if(x2== x2 - (x1/7) + j && y2 == y2 - (y1/2) + l)
				if(x1 == i && y1 == k)
				{
					gotoxy(2,23);
					cprintf("Val %d, %d => %s",x2 - (x1/7) + j,y2 - (y1/2) + l,input);
				}
				input[6] = '\0';
				/*if(x1==i && y1==k)
				{
					textcolor(BLACK);
					textbackground(WHITE);
					gotoxy(i,k);
					printf("%s",input);
					textcolor(WHITE);
					textbackground(BLACK);
					continue;
				}*/
				gotoxy(i,k);
				printf("%s",input);
			}
			obj.close();
		}
	}
}