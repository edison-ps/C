/* estrela.c */
/* desenha uma estrela em movimento */
#define COL_MAX 320
#define LIN_MAX 200
#define BRANCO 3
#define PRETO 0
#include <dos.h>
main()
{
   int x=10,y=10,dx=4,dy=4;
   unsigned int i;
   set_modo(4);
   while(kbhit()==0) {     /* movimento ate uma tecla */
      desenha_estrela(y,x,PRETO); /* apaga estrela antiga */
      x+=dx; y+=dy;        /* move coordenadas  */
      if(x<10 || x>COL_MAX-20) dx *= -1; /* se no angulo */
      if(y<10 || y>LIN_MAX-20) dy *= -1; /* troca dire‡ao */
      desenha_estrela(y,x,BRANCO);   /* desenha estrela */
   }
/*   set_modo(3);*/
}


/* desenha_estrela() */
/* desenha estrela, raio 16 pixels. */
desenha_estrela(int lin,int col, unsigned char cor)
{
   unsigned int mask;
   int x,y,modelo;
   static unsigned int estrela[20]=  /* desenho da estrela */
   /*

     bits 12345678901234567890
     ----|--------------------
       F |00000000010000000000
       E |00000000111000000000
       D |00000001111100000000
       C |00000011111110000000
     -------------------------
       B |11111111111111111110
       A |01111111111111111100
       9 |00111111111111111000
       8 |00011111111111110000
     -------------------------
       7 |00111111111111111000
       6 |01111111111111111100
       5 |11111111111111111110
       4 |00000011111110000000
     -------------------------
       3 |00000001111100000000
       2 |00000000111000000000
       1 |00000000010000000000
       0 |00000000000000000000
     -------------------------
*/


	    {
	     0x0820,0x0c60,0x0ee0,0x0fe0,
	     0x0fe0,0x0fe0,0x1ff0,0x3ff8,
	     0x7ffc,0xfffe,0x7ffc,0x3ff8,
	     0x1ff0,0x0fe0,0x0fe0,0x0fe0,
	     0x0ee0,0x0c60,0x0820,0x0000,
	    };

   for(y=0;y<20;y++) {
      modelo=estrela[y];       /* modelo destas linhas */
      mask=0x8000;             /* um bit a esquerda    */
      for(x=0; x<16; x++) {    /* cada das 16 colunas  */
	 if(mask & modelo)        /* se parte do modelo   */
	    imprpt(lin+x,col+y,cor); /* desenha ponto   */
	 mask >>= 1;              /* move mask a direita  */
      }
   }
}
#define SETMODO 0x00
set_modo(char modo)
{
     union REGS regs;
     regs.h.ah= SETMODO;
     regs.h.al= modo;
     int86(0x10,&regs,&regs);
}

/**************   Imprime um ponto na tela *****************
 * Utiliza mem¢ria de v¡deo do adaptador CGA. Assume modo 4.
 * A fun‡Æo recebe o n£mero da linha e o n£mero da coluna
 * onde queremos o ponto, como tamb‚m a cor (0 a 3).
 **********************************************************/
#define MAX_BYTES    40
#define BANCO_IMPAR  0x2000 - 40
#define MEM_VID 0xB8000000L
imprpt(int lin, int col, unsigned char cor)
{
	int desloc, posicao, k, mask=0xff3f;
	unsigned char ch;
	unsigned char far *farp = (unsigned char far *)MEM_VID;

	desloc = lin * MAX_BYTES + (col>>2);

	if( lin & 1)             /* Se a linha ‚ ¡mpar */
	   desloc += BANCO_IMPAR;

	posicao = col & 3;

	cor = cor << 6;

	for(k=0; k < posicao; k++)
	{
		cor  = cor  >> 2;
		mask = mask >> 2;
	}

	ch = *(farp + desloc) & (char) mask;
	*(farp + desloc) = ch | cor;
}


