#include <stdio.h>
#include <dos.h>

  union REGS regs;

void setmodo (char);

void putpt (int, int, unsigned char);

void setmodo (char modo)

{

  regs.h.ah = 0;
  regs.h.al = modo;
  int86 (0x10, &regs, &regs);

}

void putpt (int l, int c, unsigned char cor)

{

  regs.h.ah = 0x0c;
  regs.x.dx = l;
  regs.x.cx = c;
  regs.h.al = cor;
  regs.h.bh = 0;
  int86 (0x10, &regs, &regs);

}

void main ()

{

 int l, c;
 setmodo (4);
 for (l = 0; l < 200; l++)

	  for (c = 0; c < 320; c++)

			putpt (l, c, c /80);

}