/*
 * Menu_text.c
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
#include "Header_file.h"
void heart_power(const int x, const int y) {
    for (int i = 0; i < 2; i++) {
        switch (i) {
            case 0: heart[i].x = x ; heart[i].y = y; break;
            case 1: heart[i].x = x+1;     heart[i].y = y; break;
        }
    }
}
void bomb_power(const int x, const int y) {
    for (int i = 0; i < 10; i++) {
        switch (i) {
            case 0: bomb[i].x = x ; bomb[i].y = y; break;
            case 1: bomb[i].x = x+1 ; bomb[i].y = y; break;
            case 2: bomb[i].x = x+2 ; bomb[i].y = y; break;
            case 3: bomb[i].x = x+3 ; bomb[i].y = y; break;
            case 4: bomb[i].x = x+4 ; bomb[i].y = y; break;
            case 5: bomb[i].x = x ; bomb[i].y = y-1; break;
            case 6: bomb[i].x = x+1 ; bomb[i].y = y-1; break;
            case 7: bomb[i].x = x+2 ; bomb[i].y = y-1; break;
            case 8: bomb[i].x = x+3 ; bomb[i].y = y-1; break;
            case 9: bomb[i].x = x+4 ; bomb[i].y = y-1; break;
        }
    }
}
void start_black_hole(int x, int y) {
	 for (int i = 0; i < 18; i++) {
	        switch (i) {
	            case 0: hole[i].x = x ; hole[i].y = y; break;
	            case 1: hole[i].x = x+1 ; hole[i].y = y; break;
	            case 2: hole[i].x = x+2 ; hole[i].y = y; break;
	            case 3: hole[i].x = x+3 ; hole[i].y = y; break;
	            case 4: hole[i].x = x+4 ; hole[i].y = y; break;
	            case 5: hole[i].x = x ; hole[i].y = y+1; break;
	            case 6: hole[i].x = x+1 ; hole[i].y = y+1; break;
	            case 7: hole[i].x = x+2 ; hole[i].y = y+1; break;
	            case 8: hole[i].x = x+3 ; hole[i].y = y+1; break;
	            case 9: hole[i].x = x+4 ; hole[i].y = y+1; break;
	            case 10: hole[i].x = x ; hole[i].y = y+2; break;
	            case 11: hole[i].x = x+1 ; hole[i].y = y+2; break;
	            case 12: hole[i].x = x+2 ; hole[i].y = y+2; break;
	            case 13: hole[i].x = x+3 ; hole[i].y = y+2; break;
	            case 14: hole[i].x = x+4 ; hole[i].y = y+2; break;
	        }
	    }
}


void initiate_black_hole(int x,int y){
	start_black_hole(x,y);
}
void print_black_hole(int x, int y) {
	for (int i = 0; i < 15; i++) {
		int symbol = (i < 5) ? 187 : ((i < 10) ? 178 : ((i < 15) ? 200 : 0));
		int color = (i < 5) ? 8 : ((i < 10) ? 12 : ((i < 15) ? 8 : 0));
	fgcolor(color);
	gotoxy(hole[i].x,hole[i].y);
	printf("%c",symbol);
	fgcolor(7);
	}
}
