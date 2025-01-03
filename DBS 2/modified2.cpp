//instructions are given below
//at the end of code
#include <stdio.h>
#include <dir.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <fstream.h>
#include <stdlib.h>

void menu();
int file();
void add();
int operations();
int help();
void abt();
void hlp();
void display2();
void numbering();
void clear();
void mul();
void minus();
void div();
int x1,x2,y2,y1;
char str_x2[7],str_y2[7];
int get_key();
float put_box(long double);
char input[100];
char table[16];
char msg[79];
char fname[20];
char args[50];
void main()
{
   int key = 13;
   int i;
   struct ffblk ffblk;
   x2 = 1;x1 = 8;
   y2 = 1;y1 = 6;
   clrscr();
   textcolor(WHITE);
   textbackground(BLACK);
   x1 = 8;
   y1 = 6;
   display2();
   ungetch('c');//to intiate display and avoiding key
   ungetch('c');
   while(1)
   {
		//input[0]='\0';
		key = get_key();//revceive what key has been pressed
		gotoxy(2,23);//goto the position where val and entering option is displayed has to be cleared
		cprintf("                                                       ");
		clear();//load data according to x1,y1
		numbering();//numbering vertical and horizontal
		gotoxy(x1,y1);//goto selected cell
		//textbackground(WHITE);
		//textcolor(BLACK);
		//cprintf("%s",input);
		//cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
		//gotoxy(x1,y1);
		//cprintf("%d %d",x1,x2);
		//gotoxy(x1,y1);
		//textbackground(BLACK);
		//textcolor(WHITE);
		//getch();
		//cprintf("%d %d",x2,y2);
		if(key==27)
		{
         gotoxy(2,23);
         printf("                                                                                    ");
			gotoxy(2,23);
			printf("1: Save & Quit   2: Quit  (1/2)=> ");
			i = getch();
			if(i=='1')
			{
            gotoxy(2,23);
	         printf("                                                                                    ");
				gotoxy(2,23);
				printf("Enter file name => ");
				gets(fname);
				strcpy(args,"save.exe ");
				strcat(args,fname);
				if(system(args))
				{
               gotoxy(2,23);
		         printf("                                                                                    ");
					gotoxy(2,23);
					printf("SAVE.EXE not found!! Saving could not be done...");
					gotoxy(x1,y1);
				}
			}
         gotoxy(2,23);
         printf("                                                                                    ");
			gotoxy(2,23);
			printf("Clearing all cell files..                          ");
			key = findfirst("*.txt",&ffblk,0);
			while(!key)
			{
				//gotoxy(2,23);
				//cprintf("                                                      ");
				//gotoxy(2,23);
				//printf(" %s",ffblk.ff_name);
            remove(ffblk.ff_name);
				key = findnext(&ffblk);
			}
			exit(0);
		}
		else if(key==3 || key == 24)//3 = Ctrl + C, 24 = Ctrl + x
		{
			//Copy & Cut
			fstream obj; // first copy has been defined
			table[0]='\0';//generating source file name
			itoa(x2,str_x2,10);
			strcat(table,str_x2);
			itoa(y2,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);
			strcat(table,".txt");
			obj.open(table,ios::in);//opening source file in read mode
			if(obj)
			{
				obj>>input;//if source file exist OR if cell contains any value
            gotoxy(2,23);
		      printf("                                                                                    ");
				gotoxy(2,23);//copy contents to input[]
				//printf("%s",input);
				obj.close();
				fstream obj2;//create/overwrite clipboard file
				obj2.open("clipbrd",ios::out);
				obj2<<input;//save input[]'s value in clipboard file
				obj2.close();
			}
			if(key==24)//if Ctrl + X has been pressed
			{
				remove(table);//then delete the corresponding cell file
				gotoxy(2,23);// and reset display
				cprintf("                                                       ");
				clear();
				gotoxy(x1,y1);
			}
		}
		else if(key==22)//Ctrl + V has been pressed
		{
			fstream obj;//read contents of clipboard file
			obj.open("clipbrd",ios::in);// and stored into input[]
			if(obj)
			{
				obj>>input;
				obj.close();
				fstream obj2;
				table[0]='\0';//generate file name...
				itoa(x2,str_x2,10);
				strcat(table,str_x2);
				itoa(y2,str_y2,10);
				strcat(table,"_");
				strcat(table,str_y2);
				strcat(table,".txt");
				obj2.open(table,ios::out);
				obj2<<input;//...and place input[]'s contents into it
				obj2.close();
				//display2();
				gotoxy(2,23);
				cprintf("                                                       ");
				clear();
				gotoxy(x1,y1);
			}
			//obj2.close();
		}
		//else if (key == 19)
		//system("save.exe");
		else if(key==13)
		{
         gotoxy(2,23);
         printf("                                                                                    ");
			gotoxy(2,23);
			printf("Enter anything=> ");
			gets(input);
			for(i=0;i<strlen(input);i++)
			if(input[i]==' ')
			input[i]='_';
			//if(!strlen(input))
			//continue;

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
			//display2();
			gotoxy(2,23);
			cprintf("                                                       ");
			clear();
			gotoxy(x1,y1);
		}
   }
}

void numbering()
{
	//for horizontal numbering
	int i;
	for(i=0;i<10;i++)
	{
		gotoxy(i*7 + 8,4);
		cprintf("      ");//clearing location before placing a new value
		gotoxy(i*7 + 8,4);
		cprintf("%d",x2 - (x1/7)  + i + 1);//placing a new value
	}
	//for vertical numbering
	for(i=0;i<8;i++)
	{
		gotoxy(2,i*2 + 6);
		cprintf("     ");//same as earlier
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
  else if(key == 59)//activating File menu
   {
	clrscr();
	menu();
	display2();
	gotoxy(x1,y1);
	cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
	file();
   }
   else if(key == 60)//activate operations menu
   {
	clrscr();
	menu();
	display2();
	gotoxy(x1,y1);
	cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
	operations();
   }
   else if(key == 61)//activate help menu
   {
	clrscr();
	menu();
	display2();
	gotoxy(x1,y1);
	cprintf("%c%c%c%c%c%c",(char)219,(char)219,(char)219,(char)219,(char)219,(char)219);
	help();
   }
   /*else if(key==13)
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
   }*/
   else if (key==83)//deleting contents of a cell permanently
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
   else if(key==97)//TO BE MODIFIED //activating addtion operation
   add();//press 'a' to activate addition function
   else if(key==109)
   mul();//press 'm' to activate multiplication function
   else if(key=='s')
   minus();
   else if(key == 'd')
   div();
   else if (key == 19)//to save Press Ctrl + S
   {
		gotoxy(2,23);
		printf("Enter file name => ");
		gets(fname);
		//args[0]='\0';
		strcpy(args,"save.exe ");
		strcat(args,fname);
		//gotoxy(2,23);
		//printf("%s",args);
		if(system(args))
		{
			gotoxy(2,23);
			printf("SAVE.EXE not found!! Saving could not be done...");
			gotoxy(x1,y1);
		}
		//system(strcat("save.exe ",fname));
		//getch();
   }
   else if (key == 15)//to open Press Ctrl + O
   {
	  gotoxy(2,23);
	  printf("Enter file name => ");
	  gets(fname);
	  strcpy(args,"open.exe ");
	  strcat(args,fname);
	  if(system(args))
	  {
		gotoxy(2,23);
		printf("OPEN.EXE not found!! Cannot open %s",fname);
		gotoxy(x1,y1);
	  }
   }
   if(y1>20) y1 = 20;//limits are checked here
   if(y1<6) y1 = 6;
   if(x1>71) x1 = 71;
   if(x1<8) x1= 8;
   return key;//return what key has been pressed
}

void menu()//display menu
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
	gotoxy(1,25);
	cprintf("%s",msg);
	msg[0]='\0';
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

int file()//all file menu related operations
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
		//strcpy(msg,"Open a valid existing DBS file");
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
			//strcpy(msg,"Open a valid existing DBS file");
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

int operations()//all operation menu related jobs
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

int help()//all help menu related operations
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

void abt()//decides under about option what is to be displayed
{
	clrscr();
	gotoxy(2,3);
	printf("This is the about file");
	getch();
	ungetch(13);
	return;
}

void hlp()//under help option what is to be displayed
{
	clrscr();
	gotoxy(2,3);
	printf("This is the help file");
	getch();
	ungetch(13);
	return;
}
void clear()//loads data to screen
{
	int i,j,k,l,m;
	gotoxy(3,4);
	textcolor(CYAN);
	cprintf("DBS");
	textcolor(WHITE);
	for(k=6;k<=20;k=k+2)//row select, rows at lines 6,8,10,...,20
	{
		for(i=8;i<=71;i=i+7)
		{
			j = i/7; l = k/2;//pixels are converted into cell-reference
			//gotoxy(2,23);
			//cprintf("                                                  ");
			gotoxy(i,k);
			cprintf("      ");
			fstream obj;//creates a file stream for loading cell files
			table[0]='\0';//starting conversion of cell into file name
			itoa(x2 - (x1/7)  + j,str_x2,10);
			strcat(table,str_x2);
			itoa(y2 - (y1/2) + l,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);//process complete
			strcat(table,".txt");//adding desirable extension
			obj.open(table,ios::in);//opening file for retrieval if it exists
			if(obj)//if exists
			{
				obj>>input;//save it to input[] string
				for(m=0;m<strlen(input);m++)//replace all underscore into space
				if(input[m]=='_')
				input[m]=' ';
				//if(x2== x2 - (x1/7) + j && y2 == y2 - (y1/2) + l)
				if(x1 == i && y1 == k)//if it a selected cell
				{
					gotoxy(2,23);//goto end of screen and display
					cprintf("Val %d, %d => %s",x2 - (x1/7) + j,y2 - (y1/2) + l,input);
				}
				input[6] = '\0';//trim the line and make it of 6 characters to fit in the box
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
				gotoxy(i,k);//go and place input[] at the required position
				printf("%s",input);
			}
			obj.close();//close stream
		}
	}
}
void add()//addition function
{
	int key;
	float sum = 0;//for summing
	while(key!=27)//until Esc is hit input is taken
	{
		key = get_key();//input is detected
		//display2();
		gotoxy(2,23);
		cprintf("                                                       ");
		clear();
		gotoxy(x1,y1);
		if(key==13)//if enter is hit then cell is selected
		{		   //generate cell file name, retrieve data
			fstream obj;//convert data into long double
			table[0]='\0';//and add with the previous result
			itoa(x2,str_x2,10);
			strcat(table,str_x2);
			itoa(y2,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);
			strcat(table,".txt");
			obj.open(table,ios::in);
			if(obj)
			{
				obj>>input;
				if(_atold(input))
				sum = sum + _atold(input);
			}
			obj.close();
		}//after selection is over
	}//select a cell to put result
	gotoxy(1,25);
	cprintf("Select a cell to place this result %.3f or press Esc",sum);
	put_box(sum);
}
void mul()//multiplication function
{
	int key;
	float pro = 1;//for product
	while(key!=27)//until Esc is hit input is taken
	{
		key = get_key();//input is detected
		//display2();
		gotoxy(2,23);
		cprintf("                                                       ");
		clear();
		gotoxy(x1,y1);
		if(key==13)//if enter is hit then cell is selected
		{		   //generate cell file name, retrieve data
			fstream obj;//convert data into long double
			table[0]='\0';//and multiply with the previous result
			itoa(x2,str_x2,10);
			strcat(table,str_x2);
			itoa(y2,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);
			strcat(table,".txt");
			obj.open(table,ios::in);
			if(obj)
			{
				obj>>input;
				if(_atold(input))
				pro = pro * _atold(input);
			}
			obj.close();
		}//after selection is over
	}//select a cell to put result
	gotoxy(1,25);
	cprintf("Select a cell to place this result %.3f or press Esc",pro);
	put_box(pro);
}
void minus()//subtract function
{
	int key,count=0;
	float num[2];//for storing two numbers to subtract
	while(key!=27 && count != 2)//until Esc is hit input is taken or two numbers are taken
	{
		key = get_key();//input is detected
		//display2();
		gotoxy(2,23);
		cprintf("                                                       ");
		clear();
		gotoxy(x1,y1);
		if(key==13)//if enter is hit then cell is selected
		{		   //generate cell file name, retrieve data
			fstream obj;//convert data into long double
			table[0]='\0';//and multiply with the previous result
			itoa(x2,str_x2,10);
			strcat(table,str_x2);
			itoa(y2,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);
			strcat(table,".txt");
			obj.open(table,ios::in);
			if(obj)
			{
				obj>>input;
				if(_atold(input))
				{
					num[count] = _atold(input);
					count = count + 1;
				}
			}
			obj.close();
		}//after selection is over
	}//select a cell to put result
	gotoxy(1,25);
	cprintf("Select a cell to place this result %.3f or press Esc",(float)(num[0]-num[1]));
	if(key!=27)
	{
		put_box(num[0] - num[1]);
	}
}
void div()// function
{
	int key,count=0;
	float num[2];//for storing two numbers to subtract
	while(key!=27 && count != 2)//until Esc is hit input is taken or two numbers are taken
	{
		key = get_key();//input is detected
		//display2();
		gotoxy(2,23);
		cprintf("                                                       ");
		clear();
		gotoxy(x1,y1);
		if(key==13)//if enter is hit then cell is selected
		{		   //generate cell file name, retrieve data
			fstream obj;//convert data into long double
			table[0]='\0';//and multiply with the previous result
			itoa(x2,str_x2,10);
			strcat(table,str_x2);
			itoa(y2,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);
			strcat(table,".txt");
			obj.open(table,ios::in);
			if(obj)
			{
				obj>>input;
				if(_atold(input))
				{
					num[count] = _atold(input);
					count = count + 1;
				}
			}
			obj.close();
		}//after selection is over
	}//select a cell to put result
	gotoxy(1,25);
	cprintf("Select a cell to place this result %.3f or press Esc",(float)(num[0]/num[1]));
	if(key!=27)
	{
		put_box(num[0] / num[1]);
	}
}

float put_box(long double res)
{
	int key=0;
	while(key!=27)
	{
		key = get_key();
		//display2();
		gotoxy(2,23);
		cprintf("                                                       ");
		clear();
		gotoxy(x1,y1);
		if(key==13)
		{
			gotoxy(x1,y1);
			fstream obj;
			table[0]='\0';
			itoa(x2,str_x2,10);
			strcat(table,str_x2);
			itoa(y2,str_y2,10);
			strcat(table,"_");
			strcat(table,str_y2);
			strcat(table,".txt");
			obj.open(table,ios::out);
			obj<<res;
			obj.close();
			ungetch(27);
		}
	}
	return res;
}
/*
 * x1, y1 -> coordinates of selected cell w.r.t screen
 * x2, y2 -> coordinates of selected cell with absolute reference
 * table[] -> temporary variable to hold file name of the cell
 * str_x2[], str_y2[] -> for temporary use to generate file name
 * abt() -> this function will work when about under help menu will be selected
 * add() -> takes infinite number of valid inputs from the cell and keeps adding
 *          finally invokes put_box() to place it in proper cell.
 * clear() -> to clear all data from screen and reload all data from files
 * display2() -> this function draws all vertical and horizontal lines
 * file() -> all opeartions related to file menu are initiated and performed here
 * get_key() -> returns what key has been ben pressed
 *              general operation of several keys are defined here
 *              like the arrow keys, F1, F2, F3 etc.
 *              keys whose operations are method-specific are not defined here
 *              like Enter/Return, Esc, are not defined here
 * hlp()/help() -> this will be an interactive help file as similar to what we have seen TC
 * menu() -> the very first initiation for menu operation is done here
 * numbering() -> this is used for horizontal and vertical numbering.
 * opeartions() -> all mathematical operations are intiated here
 */
/*
	To Enter value into a particular cell select
	The cell and hit Enter. When Prompted Enter
	The value and once again hit Enter.

	To add anytime press a (small a) to activate
	Then goto the cell and press enter to select
	The numbers to be added. To stop enlisting numbers
	Hit Esc. To place in other Cell, goto to the
	The Cell and Hit enter. Optionally You can
	Hit Esc the second time and avoid storing vallue
	To another cell. Same is for Multiplication,
	Division and Substraction. In case of Division
	And substraction you can take only two numbers
	a -> addition
	s -> substraction
	m -> multiplication
	d -> division

	To Copy/Cut any cell's contents press Ctrl + C
	(Copy) or Ctrl + X (Cut). Goto to the destination
	Cell and hit Ctrl + V (Paste). This Copied value
	won't change until you copy/cut anything new

	To Save contents of entire cell anytime Press
	Ctrl + S and Ctrl + O to open
*/
/*
	Instead of a,d,s and m, proper menu options has
	to be made in use
	Satus bar has to be designed to make user
	understand this interface quckly and easily
	Refresh rate should be given first prority
*/
