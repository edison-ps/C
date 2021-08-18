#include <stdio.h>
#include <dos.h>

void main (int argc, char **argv)

{

 union REGS regs;

 regs.h.ah = 0x56;
 regs.x.dx = (unsigned int) *(argv + 1);
 regs.x.di = (unsigned int) *(argv + 2);
 intdos (&regs, &regs);


}