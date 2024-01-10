#define ESC 0x1B
#include "ansi.h"

void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}
void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}
void clrscr() {
    printf("%c[2J", ESC);
}
void clreol() {
    printf("%c[1A%c[2K",ESC,ESC);
}
void gotoxy(int x, int y) {
    printf("%c[%d;%dH",ESC,x,y);
}
void underline(uint8_t on) {
    if (on) {
        printf("%c[%dm",ESC,4);
    } else {
        printf("%c[%dm",ESC,24);
    }
}
void blink(uint8_t bl) {
    if (bl) {
        printf("%c[%dm",ESC,5);
    } else {
        printf("%c[%dm",ESC,25);
    }
}
void inverse(uint8_t inv) {
    if (inv) {
        printf("%c[%dm",ESC,7);
    } else {
        printf("%c[%dm",ESC,27);
    }
}
void cursemup(int amount) {
	printf("%c[%d;%c", ESC, amount, 'A');
}
void cursemdown(int amount) {
	printf("%c[%d;%c", ESC, amount, 'B');
}
void cursemleft(int amount) {
	printf("%c[%d;%c", ESC, amount, 'D');
}
void cursemright(int amount) {
	printf("%c[%d;%c", ESC, amount, 'C');
}
