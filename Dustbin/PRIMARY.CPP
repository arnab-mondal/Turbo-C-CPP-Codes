#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <dir.h>
void main(int argc, char *argv[])
{
	struct ffblk ffblk;
	int done ;
   char input[1000];
   char temp[1000];
	fstream obj;
	obj.open("list.txt",ios::out);
	done =  findfirst("*_2.txt",&ffblk, 0);
	while(!done)
	{
   	fstream obj2;
      obj2.open(ffblk.ff_name,ios::in);
      obj2>>input;
   	obj.open("list.txt",ios::out);
      while(obj)
      {
      	obj>>temp;
         if(strcmp(temp,input))
         {
         	gotoxy(2,23);
            printf("Primary key not possible");
            obj2.close();
            obj.close();
            break;
         }
      }

		obj<<input;
		done = findnext(&ffblk);
      obj2.close();
	}
   obj.close();
}
