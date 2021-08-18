#include <stdio.h>
#include "primo.h"

void main ()

{

  int Num;
  printf ("\nDigite um Numero: ");
  scanf ("%d", &Num);
  if (!primo (Num))
	 printf ("\nO numero nao e primo");
  else
	 printf ("\nO numero e primo");

}