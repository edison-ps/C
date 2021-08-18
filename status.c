#include <stdio.h>
#include <dos.h>

void main ( )

{

 union REGS regs;

 regs.h.ah = 0x36;
 regs.h.dl = 0;
 intdos (&regs, &regs);
 printf ("\n\nTotal : %lu", ((long) regs.x.dx * (long) regs.x.ax) * (long) regs.x.cx);
 printf ("\nLivre : %lu", ((long) regs.x.bx * (long) regs.x.ax) * (long) regs.x.cx);
 printf ("\nOcupado : %lu", (((long) regs.x.dx - (long) regs.x.bx) * (long) regs.x.ax) * (long) regs.x.cx);

}