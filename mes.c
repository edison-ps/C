struct month {

	   char nome [10];
	   char abr [4];
	   int dias;
	   int mes;

};

struct month data [12] =

	   {     {"Janeiro", "Jan", 31, 1},
			 {"Fevereiro", "Fev", 28, 2},
			 {"Marco", "Mar", 31, 3},
			 {"Abril", "Abr", 30, 4},
			 {"Maio", "Mai", 31, 5},
			 {"Junho", "Jun", 30, 6},
			 {"Julho", "Jul", 31, 7},
			 {"Agosto", "Ago", 31, 8},
			 {"Setembro", "Set", 30, 9},
			 {"Outubro", "Out", 31, 10},
			 {"Novembro", "Nov", 30, 11},
			 {"Dezembro", "Dez", 31, 12}

	   };

 void main ()

 {

  int mes, total, sub;

  printf ("\nDigite o mes: ");
  scanf ("%d", &mes);

  total = sub = 0;

  while (sub < mes) {

	 total += data [sub].mes;
	 sub++;

  }

