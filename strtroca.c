#include <stdio.h>

void strtroca (char *, char *);

void strtroca (char *S1, char *S2)

{

  char Ch;
  while (*S1 && *S2) {

		Ch = *S1;
		*S1 = *S2;
		*S2 = Ch;
		S1++;
		S2++;

  }
  if (*S1) {
	 strcpy (S2, S1);
	 *S1 = '\0';
  }
  else {
	 strcpy (S1, S2);
	 *S2 = '\0';
  }

}

void main ()

{

 static char S1 [30], S2 [30];
 printf ("\nDigite a 1a. String: ");
 gets (S1);
 printf ("\nDigite a 2a. String: ");
 gets (S2);
 strtroca (S1, S2);
 printf ("\n\n1a. String: %s", S1);
 printf ("\n\n2a. String: %s", S2);

}