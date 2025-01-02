#include<stdio.h>
#include<conio.h>
#include<dos.h>

void dbsmenu();

void menu(); // Displays the main menu

int file(); // Displays the drop down file menu

int operations(); // Displays the drop down operations menu

int help(); // Displays the drop down help menu

void abt();

void hlp();

void dbsmenu()
{
	char key;
	clrscr();
	textcolor(WHITE);
	textbackground(BLACK);
	menu();
	while(1)
	{
		fflush(stdin);
		key = getch();
		if(key == 59)
		{
			clrscr();
			menu();
			file();
		}
		if(key == 60)
		{
			clrscr();
			menu();
			operations();
		}
		if(key == 61)
		{
			clrscr();
			menu();
			help();
		}
		if(key == 27)
		{
			exit(0);
		}
	}
}

void menu()
{
	int i;
	textcolor(BLACK);
	textbackground(WHITE);
	for(i=1;i<=80;i++)
	{
		gotoxy(i,1);
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
		if(key == 60)
		{
			clrscr();
			menu();
			operations();
			break;
		}
		if(key == 61)
		{
			clrscr();
			menu();
			help();
			break;
		}
		if(key == 59)
		{
			clrscr();
			menu();
			file();
			break;
		}
	}
	textcolor(WHITE);
	textbackground(BLACK);
	return 0;
}

int operations()
{
	int i,j,n=6,m=35,x=0;
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
		cprintf(" Arithmetic    %c",(char)16);
		textcolor(BLACK);
		textbackground(WHITE);
		gotoxy(18,4);
		cprintf(" Trigonometric %c",(char)16);
		gotoxy(18,5);
		cprintf(" Statistics    %c",(char)16);
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
		if(key == 59)
		{
			clrscr();
			menu();
			file();
			break;
		}
		if(key == 61)
		{
			clrscr();
			menu();
			help();
			break;
		}
		x=x%3;
		if(x == 0)
		{
			gotoxy(18,3);
			textcolor(WHITE);
			textbackground(GREEN);
			cprintf(" Arithmetic    %c",(char)16);
			gotoxy(18,4);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Trigonometric %c",(char)16);
			gotoxy(18,5);
			cprintf(" Statistics    %c",(char)16);
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 1)
		{
			gotoxy(18,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Arithmetic    %c",(char)16);
			gotoxy(18,4);
			textcolor(WHITE);
			textbackground(GREEN);
			cprintf(" Trigonometric %c",(char)16);
			textcolor(BLACK);
			textbackground(WHITE);
			gotoxy(18,5);
			cprintf(" Statistics    %c",(char)16);
			textcolor(WHITE);
			textbackground(BLACK);
		}
		if(x == 2)
		{
			gotoxy(18,3);
			textcolor(BLACK);
			textbackground(WHITE);
			cprintf(" Arithmetic    %c",(char)16);
			gotoxy(18,4);
			cprintf(" Trigonometric %c",(char)16);
			textcolor(WHITE);
			textbackground(GREEN);
			gotoxy(18,5);
			cprintf(" Statistics    %c",(char)16);
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
		if(key == 59)
		{
			clrscr();
			menu();
			file();
			break;
		}
		if(key == 60)
		{
			clrscr();
			menu();
			operations();
			break;
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
			abt();
		}
		if(x == 1 && key == 13)
		{
			clrscr();
			menu();
			hlp();
		}
	}

	return 0;
}

void abt()
{
	gotoxy(2,3);
	printf("This is the about file");
	getch();
	main();
}

void hlp()
{
	gotoxy(2,3);
	printf("This is the help file");
	getch();
	main();
}