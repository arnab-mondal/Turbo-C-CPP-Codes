#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
char beg[30];
char end[30];
void mfile()
{
   fstream obj;
   obj.open("Table.txt",ios::app);
   cout<<"Enter a string=>";
   gets(beg);
   printf("*\n\n%s\n*",beg);
   obj<<beg<<"\n";
   obj.close();
   printf("table ");
   system("type table.txt");
}
void update(void)
{
   fstream obj;
   obj.open("Temp.txt",ios::app);
   fstream obj1;
   obj1.open("Table.txt",ios::in);
   //fflush(stdin);
   //fflush(stdout);
   //gets(end);
   obj<<end<<"\n";
   //printf("*\n\n%s\n*",end);
   while(obj1)
   {
	  obj1>>beg;
	  //printf("%s",beg);
	  getch();
	  obj<<beg;
   }
   obj.close();
   obj1.close();
   remove("Table.txt");
   rename("Temp.txt","Table.txt");
}
/*void update()
{
	char ch;
	FILE *in, *out;
   int i;
   in = fopen("Table.txt","r");
   out = fopen("Temp.txt","w");
   fprintf(out,"%s",end);
   while(ch!=EOF)
   {
	ch = getc(in);
	putc(ch,out);
   }
   fclose(in);
   fclose(out);
}*/
void main()
{
	remove("Table.txt");
   fstream obj;
   obj.open("Table.txt",ios::out);
   obj.close();
   fstream obj1;
   obj.open("Temp.txt",ios::in);
   obj1.close();
   mfile();
   cout<<"Enter a string =>";
   gets(end);
   //cin>>end;
   update();
   system("dir");
   printf("table.txt = >\n");
   system("type Table.txt");
   getch();
}