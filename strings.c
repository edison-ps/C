int strlen (char []);

void strcpy (char [], char []);

void strcat (char [], char []);

int strcmp (char [], char []);

int strlen (char S1 [])

{

  int Ind = 0;
  while (S1 [Ind])

	Ind++;

  return Ind;

}

void strcpy (char S1 [], char S2 [])

{
  int Ind = 0;
  while (S1 [Ind] = S2 [Ind])

	Ind++;

}

void strcat (char S1 [], char  S2 [])

{

  int Ind;
  Ind = strlen (S1);
  strcpy (&S1 [Ind], S2);

}

int strcmp (char S1 [], char S2 [])

{

  int Ind = 0;
  while (S1 [Ind] == S2 [Ind] && S1 [Ind] && S2 [Ind])

		Ind++;

  return S1 [Ind] - S2 [Ind];


}

void main ()


{

 char S1 [30], S2 [30];
 printf ("\nDigite a 1a. string: ");
 gets (S1);
 printf ("\nDigite a 2a. string: ");
 gets (S2);
 printf ("\n\n%s = %d", S1, strlen(S1));
 printf ("\nSTRCMP = %d", strcmp (S1, S2));
 strcat (S1, S2);
 printf ("\nSTRCAT = %s", S1);
 strcpy (S1, S2);
 printf ("\nSTRCPY = %s", S1);

}