
#include <stdio.h>

void main (int argc, char**argv)

{

 FILE *fptr;

 fptr = fopen (argv [1], "rb");
 fseek (fptr, 0l, 2);
 printf ("\n%lu",ftell (fptr));
 fclose (fptr);

}