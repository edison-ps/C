#include <stdio.h>
#include <dos.h>

#define BI 0x2000 - 40
#define VIDEO 0xb8000000

union REGS regs;




void setmodo (char);

void putpt (int, int, unsigned char);

void rect (int, int, int, int, unsigned char);

void setmodo (char modo)

{

  regs.h.ah = 0;
  regs.h.al = modo;
  int86 (0x10, &regs, &regs);

}

void putpt (int l, int c, unsigned char cor)

{
  unsigned int far *p = (unsigned int far *) VIDEO;
  unsigned mask = 0xff3f, pos, d, i;

  d = l * 40 + (c >> 2);

  if (l & 1)

	  d += BI;

  pos = c & 3;

  cor <<= 6;

  for (i = 0; i < pos; i++) {

		cor >>= 2;
		mask >>= 2;

  }

  *(p + d) &= (unsigned char) mask;
  *(p + d) |= cor;

}

void rect (int li, int lf, int ci, int cf, unsigned char cor)

{
  int l, c;

  for (l = li; l <= lf; l++)

		for (c = ci; c <= cf; c++)

			 putpt (l, c, cor);

}


void main ()

{

 int i;
 setmodo (4);
 for (i = 50; i >= 10; i -= 10)

	  rect (100 - i, 100 + i, 160 - i, 160 + i, (i/ 10) % 4);
}