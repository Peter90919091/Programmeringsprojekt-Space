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
    for (int i = 0; i< 2; i++) {
    		gotoxy(heart[i].x,heart[i].y);
    		fgcolor(1);
    		if (i == 0) {printf("<");}
    		if (i == 1) {printf("3");}
    		fgcolor(7);
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
    	for (int i = 0; i< 10; i++) {
    		gotoxy(bomb[i].x,bomb[i].y);
    		fgcolor(1);
    		underline(1);
    		switch(i) {
    		case 0:{printf(":");} break;
    		case 1:{printf("T");} break;
    		case 2:{printf("N");} break;
    		case 3:{printf("T");} break;
    		case 4:{printf(":");} break;
    		case 5:{printf(" ");} break;
    		case 6:{printf(" ");} break;
    		case 7:{printf(" ");} break;
    		case 8:{printf(" ");} break;
    		case 9:{printf(" ");} break;
    		}
    		underline(0);
    		fgcolor(7);
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
void powerUpHeart() {
	int x_pos = rand() % 139 + 2;
	heart_power(x_pos, 38);
}
void powerUpBomb() {
	int x_pos = rand() % 139 + 2;
	int y_pos = 3;
	bomb_power(x_pos, y_pos);
	}
void deletepowerUpBomb() {
	for (int i = 0; i< 10; i++) {
		gotoxy(bomb[i].x,bomb[i].y);
		printf(" ");
		bomb[i].x = 0;
		bomb[i].y = 0;
 }
}
int hitpowerupBomb(struct vector_t shot_values,int level) {
	int hit_bomb = 0;
	int enemies_down = 0;
		for (int i = 0; i< 10; i++) {
			if (hit_bomb == 0) {
			if (shot_values.x == bomb[i].x && shot_values.y == bomb[i].y) {
				LED(3);
				hit_bomb = 1;
				deletepowerUpBomb();
				clearallshots();
				for (int j = 0; j < 100; j++) {
					if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
											enemies_down += 1;
										}
					handleEnemyCollision(0,j,level);
				}
				callreturn(1);
			}
		}
	}
		LED(8);
		return enemies_down;
}
void deletepowerUpHeart() {
	for (int i = 0; i< 2; i++) {
		gotoxy(heart[i].x,heart[i].y);
		printf(" ");
		heart[i].x = 0;
		heart[i].y = 0;
 }
}
int hitpowerupHeart(int pos) {
	int ekstra_liv = 0;
	for (int i = 0; i < 2; i ++) {
		if (pos == heart[i].x) {
			LED(2);
			ekstra_liv = 1;
		}
	}
	if (ekstra_liv == 1) {
		deletepowerUpHeart();
	}
	LED(8);
    return (ekstra_liv);
}
