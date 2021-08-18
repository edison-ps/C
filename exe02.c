#include <stdio.h>
#include <dos.h>

void main ( )

{

  union REGS regs;

  struct SREGS sregs;

  char *nome = "C:\\COMMAND.COM";

  union {

	 char far *comp;
	 char *parte [2];

  } endereco;

  char *fcb1 = (char *) calloc (37, 1);
  char *fcb2 = (char *) calloc (37, 1);

  struct {

	 char *env;
	 char far *cmdl;
	 char far *fcb1;
	 char far *fcb2;

  } param;

  segread (&sregs);
  param.env = (char *) 0;
  endereco.parte [1] = (char *) sregs.ds;
  endereco.parte [0] = "";
  param.cmdl = endereco.comp;
  endereco.parte [0] = fcb1;
  param.fcb1 = endereco.comp;
  endereco.parte [0] = fcb2;
  param.fcb2 = endereco.comp;
  regs.x.ax = 0x4b00;
  regs.x.dx = (unsigned) nome;
  regs.x.bx = (unsigned) &param;
  intdosx (&regs, &regs, &sregs);
  printf ("\Voltei p/ o programa pai");
  getch ();

}
