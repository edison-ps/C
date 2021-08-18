#define video 0xb8000000

void main ()

{
 unsigned char ch;
 unsigned far *p = (unsigned far *) video;
 unsigned l, c;

 while ((ch = getch ()) != 'X')

	   for (l = 0; l < 225; l++)

		   for (c = 0; c < 80; c++)

			   * (p + 80 * l + c) = 0x0700 | ch;

}