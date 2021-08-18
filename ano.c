main ()

{

   int Ano;

   printf ("\nDigite o Ano : ");
   scanf ("%d", &Ano);
   printf ("\n\nO Ano e' %d",(!(Ano % 4) && (Ano % 100)) || (!(Ano % 400)));

}

