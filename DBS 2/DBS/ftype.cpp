#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <fstream.h>
#include <stdlib.h>
void store()
{
	fstream obj;
   obj.open("Table.txt",ios::app);
   int ch;
   for(int i=0;i<10;i++)
   {
   	printf(" # %d ",i+1);
   	scanf("%d",&ch);
      obj<<i+1<<" "<<ch<<"\n";
   }
   obj.close();
}
void check(int j)
{
	fstream obj;
   obj.open("Table.txt",ios::in);
   int value,i,ch;
	while(obj)
   {
   	obj>>i>>ch;
      if(ch==j)value = i;
   }
   obj.close();
   printf("%d %d \n",value,j);
}
void retrieve()
{
	fstream obj;
   obj.open("Table.txt",ios::in);
   int ch,i;
   while(obj)
   {
   	obj>>i>>ch;
      check(ch);
      //printf("%d %d\n",i,ch);

   }
   obj.close();
}
void main()
{
	fstream obj;
   obj.open("Table.txt",ios::out);
   obj<<"\n";
   obj.close();
	store();
   retrieve();
   getch();
}

