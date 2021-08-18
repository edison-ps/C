#include <stdio.h>
#include <dos.h>

union REGS regs;

void setmodo (char);

void setmodo (char modo)

{

  regs.h.ah = 0;
  regs.h.al = modo;
  int86 (0x10, &regs, &regs);

}

void main (int argc, char**argv)

{

 FILE *fptr;

 unsigned char far *video = (unsigned char far *) 0xb8000000;

 int ch,
	  i = 0;

 setmodo (4);

 fptr = fopen (argv [1], "rb");


 while ((ch = getc (fptr)) != EOF) {

		 if (i > 6) {

			 *video = (unsigned char) ch;
			 video++;

		 }
		 i++;

 }

 fclose (fptr);
 getch ();
 setmodo (3);

}