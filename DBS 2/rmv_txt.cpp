#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <dir.h>
void main()
{
	struct ffblk ffblk;
   int done;
   done = findfirst("*.txt",&ffblk,0);
   while(!done)
   {
   	remove(ffblk.ff_name);
      done = findnext(&ffblk);
   }
}