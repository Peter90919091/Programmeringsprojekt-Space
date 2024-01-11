#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include "stdint.h"
#include "Header_file.h"



void initiate_rocket(int x, int y){
	gotoxy(x,(y-1));
	printf("%c",186);
	gotoxy(x,y);
	printf("%c",219);

	fgcolor(1);
	gotoxy(x,(y+1));
	printf("%c",177);
	fgcolor(15);

	gotoxy((x-1),(y+1));
	printf("%c",47);
	gotoxy((x+1),(y+1));
	printf("%c",92);
}


void initiate_enemies(int x, int y){
	void initiate_enemies(int x, int y){
	fgcolor(1);
	gotoxy(x,y);
	printf("%c",219);
	gotoxy((x-1),y);
	printf("%c",204);
	gotoxy((x+1),y);
	printf("%c",185);
	fgcolor(15);
}
}
