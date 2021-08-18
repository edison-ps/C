#include <stdio.h>
#include <dos.h>

void setmodo (char);

void setmodo (char modo)

{

  union REGS regs;

  regs.h.ah = 0;
  regs.h.al = modo;
  int86 (0x10, &regs, &regs);

}

void main (int argc, char**argv)

{

 setmodo (atoi (argv [1]));

}