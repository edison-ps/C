#include <stdio.h>

int atoi (char *);

int atoi (char *S1)

{

  char Neg = 'N',
       Aux [10] = "         ";
  int Sub = 0,
      Sub1 = 1,
      Valor = 0;

  while (*S1 == ' ' || *S1 == '-' || (*S1 >= '0' && *S1 <= '9')) {

	if (*S1 == '-')
	   Neg = 'S';
	else
	   if (*S1 >= '0' && *S1 <= '9') {
	      Aux [Sub] = *S1;
	      Sub++;
	   }

	*S1++;

  }

  if (Aux [0] == ' ')
     return 0;

  Sub--;
  while (Sub >= 0) {

	Valor += (Aux [Sub] - '0') * Sub1;
	Sub--;
	Sub1 *= 10;

  }

  if (Neg == 'S')
     return -Valor;
  else
     return Valor;

}

void main ()

{

  char S1 [10];

  printf ("\nDigite um numero inteiro: ");
  gets (S1);
  printf ("\nEste e o valor convertido -> %d", atoi (S1));

}