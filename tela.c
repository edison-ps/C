 #define LIMPA "\x1b[2J"
 #define C_ESQ "\x1b[D"
 #define C_DIR "\x1b[C"
 #define C_SOBE "\x1b[A"
 #define C_DESCE "\x1b[B"
 #define SETA_ESQ 75
 #define SETA_DIR 77
 #define SETA_SOBE 72
 #define SETA_DESCE 80
 #define DUPLO_H 205
 #define DUPLO_V 186
 #define CSE 0xC9
 #define CSD 0xBB
 #define CIE 0xC8
 #define CID 0xBC

 void main ()

 {
  int Tecla, Aux = 0;
  printf (LIMPA);
  while ((Tecla = getch ()) == 0) {
		Tecla = getch ();
		switch (Tecla) {

			   case SETA_ESQ:
					if (Aux == SETA_SOBE) {
					   putch (CSD);
					   printf (C_ESQ);
					}
					else
					   if (Aux == SETA_DESCE) {
					      putch (CID);
					      printf (C_ESQ);
					}
					printf (C_ESQ);
					putch (DUPLO_H);
					break;

			   case SETA_DIR:
					if (Aux == SETA_SOBE) {
					   putch (CSE);
					   printf (C_ESQ);
					}
					else
					   if (Aux == SETA_DESCE) {
					      putch (CIE);
					      printf (C_ESQ);
					}
					printf (C_DIR);
					putch (DUPLO_H);
					break;

			   case SETA_SOBE:
					if (Aux == SETA_DIR) {
					   putch (CID);
					   printf (C_ESQ);
					}
					else
					   if (Aux == SETA_ESQ) {
					      putch (CIE);
					      printf (C_ESQ);
					}
					printf (C_SOBE);
					putch (DUPLO_V);
					break;

			   case SETA_DESCE:
					if (Aux == SETA_DIR) {
					   putch (CSD);
					   printf (C_ESQ);
					}
					else
					   if (Aux == SETA_ESQ) {
					      putch (CSE);
					      printf (C_ESQ);
					}
					printf (C_DESCE);
					putch (DUPLO_V);
					break;
		}
		printf (C_ESQ);
		Aux = Tecla;

  }

 }