#include <stdio.h>

void linha (int, char);

void linha1 (char, int);

void linha2 (int);

void linha3 (char);

void linha4 (void);

void linha (int Num, char Ch)

{

  for ( ; Num; Num--)

	  printf ("%c", Ch);

}

void linha1 (char Ch, int Num)

{

  linha (Num, Ch);

}

void linha2 (int Num)

{

  linha (Num, '*');

}

void linha3 (char Ch)

{

  linha (20, Ch);

}

void linha4 (void)

{

  linha (20, '*');

}


void main ()

{

  int Num;
  char Ch;
  printf ("\n\nDigite numero de repeticoes: ");
  scanf ("%d", &Num);
  printf ("\nDigite o caracter desejado: ");
  Ch = getche ();
  printf ("\n\n Linha  ");
  linha (Num, Ch);
  printf ("\n Linha - 01 ");
  linha1 (Ch, Num);
  printf ("\n Linha - 02 ");
  linha2 (Num);
  printf ("\n Linha - 03 ");
  linha3 (Ch);
  printf ("\n Linha - 04 ");
  linha4 ();

}