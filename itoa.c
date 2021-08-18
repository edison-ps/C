#include <stdio.h>

void invert (char *);

int itoa (char *, int);

void invert (char *S1)

{
  char Temp;
  int Sub = 0,
      Sub1 = strlen (S1) - 1;

  while (Sub <= Sub1) {

	Temp = *(S1 + Sub);
	*(S1 + Sub) = *(S1 + Sub1);
	*(S1 + Sub1) = Temp;
	Sub++;
	Sub1--;

  }

}

int itoa (char *S1, int Valor)

{

  char Neg = 'N';
  int Sub = 0;

  if (Valor < 0) {
     Valor *= -1;
     Neg = 'S';

  }

  while (Valor) {

	*S1 = Valor % 10 + '0';
	Valor /= 10;
	S1++;
	Sub++;
  }

  if (Neg == 'S') {
     *S1 = '-';
     S1++;
     Sub++;
  }

  *S1 = '\0';
  S1 -= Sub;
  invert (S1);

}

void main ()

{

  char S1 [10];
  int Valor;

  printf ("\nDigite um numero inteiro: ");
  scanf ("%d", &Valor);
  itoa (S1, Valor);
  printf ("\nO string convertido e -> %s", S1);

}