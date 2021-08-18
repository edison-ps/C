#include <dos.h>
#define POS 142

long far *p = (long far *) 0x46c;
long h, m, s, r, t;
char far *v = (char far *) 0xb8000000;
void interrupt (*int_28h) ();

void interrupt minha_int_28h ()

{

 t = *p;
 h = t / 65543l;
 r = t % 65543l;
 m = r / 1092l;
 r = r % 1092l;
 s = r / 18l;
 *(v + POS) = h / 10 + '0';
 *(v + POS + 2) = h % 10 + '0';
 *(v + POS + 4) = ':';
 *(v + POS + 6) = m / 10 + '0';
 *(v + POS + 8) = m % 10 + '0';
 *(v + POS + 10) = ':';
 *(v + POS + 12) = s / 10 + '0';
 *(v + POS + 14) = s % 10 + '0';

}

void main ()

{
  int_28h = getvect (0x28);
  setvect (0x28, minha_int_28h);
  keep (0,_SS + (_SP / 16) - _psp + 10);

}