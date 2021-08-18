#include <stdio.h>
#include <dos.h>

void setback (char);

void setback (char back)

{

  union REGS regs;

  regs.h.ah = 0x0b;
  regs.h.bh = 0;
  regs.h.bl = back;
  int86 (0x10, &regs, &regs);

}

void main (int argc, char**argv)

{

 setback (atoi (argv [1]));

}