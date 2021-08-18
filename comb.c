long fat (int);

long fat (int Num)

{
  return Num == 0 ? 1 : Num * fat ((Num - 1));

}


void main ()

{
  int n, r, nr;
  long nf, rf, nrf;
  unsigned long teste;
  n = r = 0;
  printf ("\nDigite o universo: ");
  scanf ("%d", &n);
  printf ("\nDigite o No. de elementos: ");
  scanf ("%d", &r);
  nr = n - r;
  nf = fat (n);
  rf = fat (r);
  nrf = fat (nr);
  printf ("\n%u",nf);
  printf ("\n%u",rf);
  printf ("\n%u",nrf);
  teste = (unsigned long)  nf / ((unsigned long) rf * (unsigned long) nrf);
  printf ("\nO No. de combinacoes e: %u\n", teste);

}
