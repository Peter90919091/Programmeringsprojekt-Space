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
void delete_rocket(int x, int y){
	gotoxy(x,(y-1));printf(" ");
	gotoxy(x,y);printf(" ");

	fgcolor(1);
	gotoxy(x,(y+1));printf(" ");
	fgcolor(15);

	gotoxy((x-1),(y+1));printf(" ");
	gotoxy((x+1),(y+1));printf(" ");
}
