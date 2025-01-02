#include <stdio.h>
#include <conio.h>
int dbsmenu(int key)
{
	int i;
   textcolor(LIGHTRED);
   textbackground(LIGHTGRAY);
   for(i=1;i<=80;i++)
   {
   	cprintf(" ");
   }
   gotoxy(2,1);
   cprintf("%c ",(int)240);
   cprintf()
   textcolor(WHITE);
   textbackground(BLACK);
}
void main()
{
	dbsmenu(0);
   getch();
}
