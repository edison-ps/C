/* S115200.C */

/****************************************************
 * comunica‡Æo direta com a porta serial atrav‚s da *
 * programa‡Æo do UART                              *
 ***************************************************/

#define COM0   0x03f8   /* para COM1. COM2 usar 0x02f8  */
#define TAXA  115200L   /* bps                          */
#define PARIDADE    0   /* 0=Nenhuma, 1=impar, 2=par    */
#define STOP        1   /* 1 stop bit                   */
#define BITS_DADOS  8   /* 8 bits de dados              */
#define TRUE        1

void inicializa (unsigned int,long,int,int,int);

main()
{
   int status;
   unsigned char ch;

   /* inicializa UART */
   inicializa(COM0,TAXA,PARIDADE,STOP,BITS_DADOS);

   while(TRUE) {
      if(kbhit()) {          /* se tecla pressionada   */
         ch=getch();         /* le char                */
         outportb(COM0,ch);   /* envia char             */
      }

      status=inport(COM0+5);

      if((status & 1)){      /* dados disponiveis ?    */
         ch=inportb(COM0);
         if(ch == '\r') {    /* se carriage return     */
              putch('\r');   /* imprime CR + LF        */
              putch('\n');
         } else              /* se outro caractere     */
              putch(ch);     /* imprime caractere      */
      }
   }
}


/* inicializa() */

/****************************************************  
 * inicializa porta serial com os parƒmetros        *  
 * enviados como argumentos                         *
 ***************************************************/

void inicializa (porta,bps,p, stop, bits_dados)
unsigned int porta; /* 0x03f8 se com1 e 0x02f8 se com2 */
long bps;  /* bits por segundo - taxa de transmissÆo   */
int p;       /* paridade - 0=Nenhuma, 1=impar, 2=par   */
int stop;    /* 1 ou 2 stop bits                       */
int bits_dados; /* 7 ou 8 bits de dados                */
{
   union{
      unsigned int nr;
      unsigned char hilo[2];
   } divisor;

   unsigned char byte_de_param;


   /* Calcula valor a ser enviado para registradores    */
   /* de taxa de transmissÆo -                          */
   divisor.nr= (unsigned int)(1843200L/(bps*16L));


   /* Liga bit do registrador de controle das caract.   */
   /* que permite acesso aos registradores de taxa de   */
   /* transmissÆo                                       */
   outportb(porta+3,0x80);

   /* Byte menos significativo para porta               */
   outportb(porta,divisor.hilo[0]);

   /* Byte mais  significativo para porta               */
   outportb(porta+1,divisor.hilo[1]);

   /* Formata byte de parƒmetros                        */
   byte_de_param = bits_dados-5;   
   byte_de_param |= (stop - 1)<<2;

   if (p){
      byte_de_param |= 0x08;   /* liga bit de paridade  */
      byte_de_param |= p&0x10; /* paridade par ou impar */
   }

   /* Envia byte de parƒmetros para registrador de       */
   /* controle de linha                                  */
   outportb(porta+3,byte_de_param);
}
