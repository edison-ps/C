/**************************
 * Informa‡oes sobre DBFs *
 **************************/
#include <stdio.h>
typedef struct
{
   unsigned char identifica_dbf; /* 0x03        -> sem campo memo
				    0x83        -> com campo memo
				    outro valor -> nao e arquivo dbf */
   char ultima_alteracao[3];     /* AA/MM/DD */
   long numero_de_registros;
   unsigned tamanho_cabecalho;
   unsigned tamanho_registro;
   char lixo[20];
} CABECALHO_DBF;

typedef struct
{
   char nome[11];
   char tipo;
   char lixo_1[4];
   char tamanho;
   char dec;
   char lixo[14];
} CAMPO_DBF;

char *mes[]={"Janeiro","Fevereiro","Marco","Abril","Maio","Junho",
	     "Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};

 main(int argc,char **argv)
 {
    CABECALHO_DBF cab;
    CAMPO_DBF *campo;
    FILE *fp;
    int i,j,num_de_campos,tam;
    char *registro;


    if(argc != 2)
    {
       printf("\nModo de uso: C:\>DBF_INFO nomearq.dbf");
       exit();
    }
    if((fp=fopen(argv[1],"rb"))==NULL)
    {
       printf("\nNao posso abrir o arquivo %s",argv[1]);
       exit();
    }

    fread(&cab,sizeof(CABECALHO_DBF),1,fp);

    printf("\n\n    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    printf  ("\n    ³         *****   INFORMACOES SOBRE ARQUIVOS DBF   *****              ³");
    printf  ("\n    ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    printf("\n\n\t    %s",
	   cab.identifica_dbf==0x03 ? "Arquivo DBF sem campo memo" :
	   cab.identifica_dbf==0x83 ? "Arquivo DBF com campo memo" :
				      "Nao e' arquivo DBF");
    printf("\n\t    Nome do arquivo..................:  %s",argv[1]);

    printf("\n\t    Ultima atualizacao...............:  %d de %s de 19%d",
		    cab.ultima_alteracao[2],
		    mes[cab.ultima_alteracao[1]-1],
		    cab.ultima_alteracao[0]);

    printf("\n\t    Numero de registros..............:  %6ld",cab.numero_de_registros);

    printf("\n\t    Tamanho do cabecalho.............:  %6u",cab.tamanho_cabecalho);

    printf("\n\t    Tamanho do registro..............:  %6u",cab.tamanho_registro);

    /***********************************************************************
     ***       CALCULO DO NUMERO DE CAMPOS
       O tamanho do cabe‡alho inclui:
	    sizeof(CABECALHO_DBF)=32 bytes com a descri‡Æo do arquivo
	    32 bytes para cada campo contendo sua descri‡Æo
	    1 byte contendo o caractere 0x0D indicando final de campos
	    1 byte contendo 0x1A se o arquivo nÆo contiver dados.
    ***********************************************************************/

    num_de_campos= (cab.tamanho_cabecalho - sizeof(CABECALHO_DBF) - 2)/32;
    printf("\n\t    Numero de campos.................:  %6u\n",num_de_campos);

    printf("\n\n\t\tNome          Tipo           Tamanho      Decimais");
    printf  ("\n\t   ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ   ");

    campo=(CAMPO_DBF *)malloc(sizeof(CAMPO_DBF)*num_de_campos);
    for (i=0;i<num_de_campos;i++)
    {
       fread(&campo[i],sizeof(CAMPO_DBF),1,fp);
       printf("\n\t\t%-16s%c",campo[i].nome,campo[i].tipo);
       tam = (campo[i].tipo=='C') ?
	    (campo[i].tamanho+campo[i].dec*256): campo[i].tamanho;
       printf("%17d",tam);
       if(campo[i].tipo=='N') printf("%12d",campo[i].dec);
    }
    printf  ("\n\t   ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ   \n");
    getch();
    fseek(fp,(long)cab.tamanho_cabecalho,0);/* posiciona ap¢s cabecalho */

    for(j=1;j<=cab.numero_de_registros;j++)
    {
       registro=(char *)malloc(cab.tamanho_registro);
       fread(registro,cab.tamanho_registro,1,fp);
       printf("\n%d %c",j,registro[0]); /* primeiro byte='*' se campo
				      deletado ou ' ' se nao deletado*/
       registro++;
       for(i=0;i<num_de_campos;i++)
       {
	 tam = (campo[i].tipo=='C') ?
	    (campo[i].tamanho+campo[i].dec*256): campo[i].tamanho;

	 switch(campo[i].tipo)
	 {
	    case 'M': printf("%s"," MEMO ");break;
	    case 'L': if(registro[0]==' ') registro[0]='F';
		      printf(" %c ",registro[0]);break;
	    default : printf(" %.*s ",tam,registro);
	 }
	 registro+=tam;
       }
     }
    fclose(fp);
}
