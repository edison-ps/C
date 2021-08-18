#include <stdio.h>

void invert (char *);

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

void main ()

{

  char S1 [30];

  printf ("\nDigite uma string: ");
  gets (S1);
  invert (S1);
  printf ("\n\n%s",S1);

}