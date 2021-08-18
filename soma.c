void main (int argc, char **argv)

{

  int soma = 0;

  for ( ; argc != 1; argc--) {

	  soma += atoi (*(argv + argc));

  }
  printf ("\n%d", soma);

}