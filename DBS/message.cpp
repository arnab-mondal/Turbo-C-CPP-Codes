#include <stdio.h>
#include <conio.h>
#include <string.h>
char input[100];
char *msg;
void msgbox(char *str,int mode)
{
	int i,j,n=10,m=65;
  	gotoxy(9,20);
   textcolor(RED );
   textbackground(LIGHTCYAN);
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
   	{
      	if(i==0 && j==0)
         cprintf("%c",(char)218);
         else if(i==n-1 && j==0)
         cprintf("%c",(char)192);
         else if(i==0 && j==m-1)
         cprintf("%c",(char)191);
         else if(i==n-1 && j==m-1)
         cprintf("%c",(char)217);
         else if(i==0 || i==n-1)
         cprintf("%c",(char)196);
         else if(j==0 || j==m-1)
         cprintf("%c",(char)179);
         //else if(i==0)
         //cprintf()
         else
      	cprintf(" ");
      }
      for(j=0;j<65;j++)
   	cprintf("\b");
      cprintf("\n");
   }
   gotoxy(12,20);
   if(mode==1)
   {
   	//clrscr();
      cprintf(" A T T E N T I O N : \n\n\n \b\b\b\b\b\b\b\b\b\b\b\b\b\b%s",str);
      gotoxy(35,35);
      n = 5;m=15;
      //	gotoxy(9,20);
   	//textcolor(RED	);
	   //textbackground(LIGHTCYAN);
	   for(i=0;i<n;i++)
	   {
      	for(j=0;j<m;j++)
	   	{
  	    		if(i==0 && j==0)
	         cprintf("%c",(char)218);
	         else if(i==n-1 && j==0)
	         cprintf("%c",(char)192);
	         else if(i==0 && j==m-1)
	         cprintf("%c",(char)191);
	         else if(i==n-1 && j==m-1)
	         cprintf("%c",(char)217);
	         else if(i==0 || i==n-1)
	         cprintf("%c",(char)196);
	         else if(j==0 || j==m-1)
		      cprintf("%c",(char)179);
	   	   //else if(i==0)
      	   //cprintf()
         	else
	      	cprintf(" ");
	      }
	      for(j=0;j<m;j++)
	   	cprintf("\b");
	      cprintf("\n");
   	}
   	gotoxy(38,37);
      cprintf("Hit ENTER");
      textcolor(WHITE);
      textbackground(BLACK);
      return;
   }
   input[0]=100;
   cprintf("%s",str);
   msg = cgets(input);
   strcpy(input,msg);
   textcolor(WHITE);
   textbackground(BLACK);
   //cprintf("\n\nOutput => %s",input);
}
void main()
{
	//msgbox("Enter a string\n\n \b\b\b\b\b\b\b\b\b\b\b\b\b\b => ",0);
   //getch();
   //clrscr();
   msgbox("Trial Msg",1);
   getch();
}
