#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <fstream.h>
void deep_search(int,int,char[]);
void search(int *,int*,char[]);
void main()
{
	int x2,y2;
	search(&x2,&y2,"hello");
   getch();
}
void search(int *a,int *b,char sub[])
{
	int j,k,ex,ex1,ey1;
   char temp[100],key;
   //printf("%s",sub);
   fstream obj;
   obj.open("Table.txt",ios::in);
   while(obj)
   {
   	obj>>ex>>ex1>>ey1>>temp;
      deep_search(ex1,ey1,sub);
   }
   obj.close();
}
void deep_search(int x1,int y1,char sub[])
{
   char temp[100];
   int ex,ex1,ey1;
	fstream obj;
   obj.open("Table.txt",ios::in);
   while(obj)
   {
   	obj>>ex>>ex1>>ey1>>temp;
      /*if(x1==ex1 && y1==ey1 && temp[0]!='\0')
      {
      	strcpy(sub,temp);
      }*/
   }
   obj.close();
   if(strstr(temp,sub))
   {
   	printf(" %d %d",x1,y1);
   }
}
