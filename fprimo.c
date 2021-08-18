int primo (int X)

{

  int I;
  for (I = 2; I <= X/2; I++)
	  if (!(X % I)) return 0;

  return 1;
}