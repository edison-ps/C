#include <stdio.h>

void impch (unsigned char, int, int);

void impch (unsigned char ch, int v, int h)

{

  unsigned char far *p = (unsigned char far *) 0xf000fa6e;
  unsigned char t = 0x80;
  int x,y;

  p += (ch * 8);

  for (x = 0; x < 8; x++) {

/*	  for ( ; v; v--) {*/

		  for (y = 0; y < 8; y++) {

			  if (*p & t)

				 for ( ; h; h--) {

					 printf ("%c", ch);

				 }

			  else

				 for ( ; h; h--) {

					  printf (" ");

				  }

			  t >>= 1;
		 }

/*	  }*/
	  p++;
	  t = 0x80;
	  printf ("\n");

  }


}

void main ()

{
  int i;

  for (i = 0; i < 128; i++) {

	  printf ("\n\n");
	  if (i == 7 || i == 26) i++;
	  impch (( unsigned char) i, 1, 1);
  }

}