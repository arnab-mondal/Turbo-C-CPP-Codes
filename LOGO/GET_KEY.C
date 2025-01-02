#include <stdio.h>
#include <conio.h>
void main()
{
	int key = getch();
	while(key!=13)
	{
		printf("%d",key);
		key = getch();
		clrscr();
	}
	getch();
}
