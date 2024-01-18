/*
 * ansi.c
 *
 *  Created on: 10. jan. 2024
 *      Author: Matti
 */

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#define ESC 0x1B
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

void blink(uint8_t on) {
	if (on) {printf("%c[%d%c",ESC,05,'m');}
	else {printf("%c[%d%c",ESC,25,'m');}
}
void gotoxy(int x, int y) {
	printf("%c[%d;%d%c",ESC,y,x,'H');
}
void ClearScreen(){
	printf("%c[2J",ESC);
	gotoxy(0,0);
}
// Move cursor
void cursor_up(int amount) {
	printf("%c[%d%c",ESC,amount,'A');
}
void cursor_down(int amount) {
	printf("%c[%d%c",ESC,amount,'B');
}
void cursor_right(int amount) {
	printf("%c[%d%c",ESC,amount,'C');
}
void cursor_left(int amount) {
	printf("%c[%d%c",ESC,amount,'D');
}
void underline(uint8_t on) {
	if (on) {
	printf("%c[%d%c",ESC,04,'m');
	}
	else {
		printf("%c[%d%c",ESC,24,'m');
	}
}
void hideCursor() {printf("\e[?25l");}
