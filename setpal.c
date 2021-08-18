#include <stdio.h>
#include <dos.h>

void setpal (char);

void setpal (char pal)

{

  union REGS regs;

  regs.h.ah = 0x0b;
  regs.h.bh = 1;
  regs.h.bl = pal;
  int86 (0x10, &regs, &regs);

}

void main (int argc, char**argv)

{

 setpal (atoi (argv [1]));

}