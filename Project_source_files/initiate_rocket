#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include "stdint.h"
#include "header_file.h"



void initiate_rocket(int x1, int y1){
	gotoxy(x1,(y1-1));
	printf("%c",186);
	gotoxy(x1,y1);
	printf("%c",219);

	fgcolor(1);
	gotoxy(x1,(y1+1));
	printf("%c",177);
	fgcolor(15);

	gotoxy((x1-1),(y1+1));
	printf("%c",47);
	gotoxy((x1+1),(y1+1));
	printf("%c",92);
}
