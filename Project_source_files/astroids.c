/*
 * game.c
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

void Asteroid1(int size, const int x, const int y) {
    if (size == 0) {
    	fgcolor(1);
        very_small_asteroid1[0] = (struct Asteroid){x-2, y};
        very_small_asteroid1[1] = (struct Asteroid){x-1, y};
        very_small_asteroid1[2] = (struct Asteroid){x, y};
        very_small_asteroid1[3] = (struct Asteroid){x+1, y};
        very_small_asteroid1[4] = (struct Asteroid){x+2, y};
        very_small_asteroid1[5] = (struct Asteroid){x-2, y+1};
        very_small_asteroid1[6] = (struct Asteroid){x-1, y+1};
        very_small_asteroid1[7] = (struct Asteroid){x, y+1};
        very_small_asteroid1[8] = (struct Asteroid){x+1, y+1};
        very_small_asteroid1[9] = (struct Asteroid){x+2, y+1};
        very_small_asteroid1[10] = (struct Asteroid){x+1, y+2};
        very_small_asteroid1[11] = (struct Asteroid){x, y+2};
        very_small_asteroid1[12] = (struct Asteroid){x-1, y+2};
        very_small_asteroid1[13] = (struct Asteroid){x-2, y-1};
        very_small_asteroid1[14] = (struct Asteroid){x-1, y-1};
        very_small_asteroid1[15] = (struct Asteroid){x, y-1};
        very_small_asteroid1[16] = (struct Asteroid){x+1, y-1};
        very_small_asteroid1[17] = (struct Asteroid){x+2, y-1};
        very_small_asteroid1[18] = (struct Asteroid){x-1, y-2};
        very_small_asteroid1[19] = (struct Asteroid){x, y-2};
        very_small_asteroid1[20] = (struct Asteroid){x+1, y-2};
        for (int i = 0; i < 21; i++) {
                    	gotoxy(very_small_asteroid1[i].x,very_small_asteroid1[i].y);
                    	 printf("O");
                    }
	}
    if (size == 1) {
           small_asteroid1[0] = (struct Asteroid){x, y};
           small_asteroid1[1] = (struct Asteroid){x-1, y};
           small_asteroid1[2] = (struct Asteroid){x-2, y};
           small_asteroid1[3] = (struct Asteroid){x-3, y};
           small_asteroid1[4] = (struct Asteroid){x+1, y};
           small_asteroid1[5] = (struct Asteroid){x+2, y};
           small_asteroid1[6] = (struct Asteroid){x+3, y};
           small_asteroid1[7] = (struct Asteroid){x, y+1};
           small_asteroid1[8] = (struct Asteroid){x-1, y+1};
           small_asteroid1[9] = (struct Asteroid){x-2, y+1};
           small_asteroid1[10] = (struct Asteroid){x-3, y+1};
           small_asteroid1[11] = (struct Asteroid){x+1, y+1};
           small_asteroid1[12] = (struct Asteroid){x+2, y+1};
           small_asteroid1[13] = (struct Asteroid){x+3, y+1};
           small_asteroid1[14] = (struct Asteroid){x, y+2};
           small_asteroid1[15] = (struct Asteroid){x-1, y+2};
           small_asteroid1[16] = (struct Asteroid){x-2, y+2};
           small_asteroid1[17] = (struct Asteroid){x+1, y+2};
           small_asteroid1[18] = (struct Asteroid){x+2, y+2};
           small_asteroid1[19] = (struct Asteroid){x, y+3};
           small_asteroid1[20] = (struct Asteroid){x-1, y+3};
           small_asteroid1[21] = (struct Asteroid){x+1, y+3};
           small_asteroid1[22] = (struct Asteroid){x, y-1};
           small_asteroid1[23] = (struct Asteroid){x-1, y-1};
           small_asteroid1[24] = (struct Asteroid){x-2, y-1};
           small_asteroid1[25] = (struct Asteroid){x-3, y-1};
           small_asteroid1[26] = (struct Asteroid){x+1, y-1};
           small_asteroid1[27] = (struct Asteroid){x+2, y-1};
           small_asteroid1[28] = (struct Asteroid){x+3, y-1};
           small_asteroid1[29] = (struct Asteroid){x, y-2};
           small_asteroid1[30] = (struct Asteroid){x-1, y-2};
           small_asteroid1[31] = (struct Asteroid){x-2, y-2};
           small_asteroid1[32] = (struct Asteroid){x+1, y-2};
           small_asteroid1[33] = (struct Asteroid){x+2, y-2};
           small_asteroid1[34] = (struct Asteroid){x, y-3};
           small_asteroid1[35] = (struct Asteroid){x-1, y-3};
           small_asteroid1[36] = (struct Asteroid){x+1, y-3};
           for (int i = 0; i < 37; i++) {
                           	gotoxy(small_asteroid1[i].x,small_asteroid1[i].y);
                           	 printf("O");
           }
    }
}
void Asteroid2(int size, const int x, const int y) {
    if (size == 0) {
    	fgcolor(1);
        very_small_asteroid2[0] = (struct Asteroid){x-2, y};
        very_small_asteroid2[1] = (struct Asteroid){x-1, y};
        very_small_asteroid2[2] = (struct Asteroid){x, y};
        very_small_asteroid2[3] = (struct Asteroid){x+1, y};
        very_small_asteroid2[4] = (struct Asteroid){x+2, y};
        very_small_asteroid2[5] = (struct Asteroid){x-2, y+1};
        very_small_asteroid2[6] = (struct Asteroid){x-1, y+1};
        very_small_asteroid2[7] = (struct Asteroid){x, y+1};
        very_small_asteroid2[8] = (struct Asteroid){x+1, y+1};
        very_small_asteroid2[9] = (struct Asteroid){x+2, y+1};
        very_small_asteroid2[10] = (struct Asteroid){x+1, y+2};
        very_small_asteroid2[11] = (struct Asteroid){x, y+2};
        very_small_asteroid2[12] = (struct Asteroid){x-1, y+2};
        very_small_asteroid2[13] = (struct Asteroid){x-2, y-1};
        very_small_asteroid2[14] = (struct Asteroid){x-1, y-1};
        very_small_asteroid2[15] = (struct Asteroid){x, y-1};
        very_small_asteroid2[16] = (struct Asteroid){x+1, y-1};
        very_small_asteroid2[17] = (struct Asteroid){x+2, y-1};
        very_small_asteroid2[18] = (struct Asteroid){x-1, y-2};
        very_small_asteroid2[19] = (struct Asteroid){x, y-2};
        very_small_asteroid2[20] = (struct Asteroid){x+1, y-2};
        for (int i = 0; i < 21; i++) {
                    	gotoxy(very_small_asteroid2[i].x,very_small_asteroid2[i].y);
                    	 printf("O");
                    }
	}
    if (size == 1) {
           small_asteroid2[0] = (struct Asteroid){x, y};
           small_asteroid2[1] = (struct Asteroid){x-1, y};
           small_asteroid2[2] = (struct Asteroid){x-2, y};
           small_asteroid2[3] = (struct Asteroid){x-3, y};
           small_asteroid2[4] = (struct Asteroid){x+1, y};
           small_asteroid2[5] = (struct Asteroid){x+2, y};
           small_asteroid2[6] = (struct Asteroid){x+3, y};
           small_asteroid2[7] = (struct Asteroid){x, y+1};
           small_asteroid2[8] = (struct Asteroid){x-1, y+1};
           small_asteroid2[9] = (struct Asteroid){x-2, y+1};
           small_asteroid2[10] = (struct Asteroid){x-3, y+1};
           small_asteroid2[11] = (struct Asteroid){x+1, y+1};
           small_asteroid2[12] = (struct Asteroid){x+2, y+1};
           small_asteroid2[13] = (struct Asteroid){x+3, y+1};
           small_asteroid2[14] = (struct Asteroid){x, y+2};
           small_asteroid2[15] = (struct Asteroid){x-1, y+2};
           small_asteroid2[16] = (struct Asteroid){x-2, y+2};
           small_asteroid2[17] = (struct Asteroid){x+1, y+2};
           small_asteroid2[18] = (struct Asteroid){x+2, y+2};
           small_asteroid2[19] = (struct Asteroid){x, y+3};
           small_asteroid2[20] = (struct Asteroid){x-1, y+3};
           small_asteroid2[21] = (struct Asteroid){x+1, y+3};
           small_asteroid2[22] = (struct Asteroid){x, y-1};
           small_asteroid2[23] = (struct Asteroid){x-1, y-1};
           small_asteroid2[24] = (struct Asteroid){x-2, y-1};
           small_asteroid2[25] = (struct Asteroid){x-3, y-1};
           small_asteroid2[26] = (struct Asteroid){x+1, y-1};
           small_asteroid2[27] = (struct Asteroid){x+2, y-1};
           small_asteroid2[28] = (struct Asteroid){x+3, y-1};
           small_asteroid2[29] = (struct Asteroid){x, y-2};
           small_asteroid2[30] = (struct Asteroid){x-1, y-2};
           small_asteroid2[31] = (struct Asteroid){x-2, y-2};
           small_asteroid2[32] = (struct Asteroid){x+1, y-2};
           small_asteroid2[33] = (struct Asteroid){x+2, y-2};
           small_asteroid2[34] = (struct Asteroid){x, y-3};
           small_asteroid2[35] = (struct Asteroid){x-1, y-3};
           small_asteroid2[36] = (struct Asteroid){x+1, y-3};
           for (int i = 0; i < 37; i++) {
                           	gotoxy(small_asteroid2[i].x,small_asteroid2[i].y);
                           	 printf("O");
           }
    }
}
void Asteroid3(int size, const int x, const int y) {
    if (size == 0) {
    	fgcolor(1);
        very_small_asteroid3[0] = (struct Asteroid){x-2, y};
        very_small_asteroid3[1] = (struct Asteroid){x-1, y};
        very_small_asteroid3[2] = (struct Asteroid){x, y};
        very_small_asteroid3[3] = (struct Asteroid){x+1, y};
        very_small_asteroid3[4] = (struct Asteroid){x+2, y};
        very_small_asteroid3[5] = (struct Asteroid){x-2, y+1};
        very_small_asteroid3[6] = (struct Asteroid){x-1, y+1};
        very_small_asteroid3[7] = (struct Asteroid){x, y+1};
        very_small_asteroid3[8] = (struct Asteroid){x+1, y+1};
        very_small_asteroid3[9] = (struct Asteroid){x+2, y+1};
        very_small_asteroid3[10] = (struct Asteroid){x+1, y+2};
        very_small_asteroid3[11] = (struct Asteroid){x, y+2};
        very_small_asteroid3[12] = (struct Asteroid){x-1, y+2};
        very_small_asteroid3[13] = (struct Asteroid){x-2, y-1};
        very_small_asteroid3[14] = (struct Asteroid){x-1, y-1};
        very_small_asteroid3[15] = (struct Asteroid){x, y-1};
        very_small_asteroid3[16] = (struct Asteroid){x+1, y-1};
        very_small_asteroid3[17] = (struct Asteroid){x+2, y-1};
        very_small_asteroid3[18] = (struct Asteroid){x-1, y-2};
        very_small_asteroid3[19] = (struct Asteroid){x, y-2};
        very_small_asteroid3[20] = (struct Asteroid){x+1, y-2};
        for (int i = 0; i < 21; i++) {
                    	gotoxy(very_small_asteroid3[i].x,very_small_asteroid3[i].y);
                    	 printf("O");
                    }
	}
    if (size == 1) {
           small_asteroid3[0] = (struct Asteroid){x, y};
           small_asteroid3[1] = (struct Asteroid){x-1, y};
           small_asteroid3[2] = (struct Asteroid){x-2, y};
           small_asteroid3[3] = (struct Asteroid){x-3, y};
           small_asteroid3[4] = (struct Asteroid){x+1, y};
           small_asteroid3[5] = (struct Asteroid){x+2, y};
           small_asteroid3[6] = (struct Asteroid){x+3, y};
           small_asteroid3[7] = (struct Asteroid){x, y+1};
           small_asteroid3[8] = (struct Asteroid){x-1, y+1};
           small_asteroid3[9] = (struct Asteroid){x-2, y+1};
           small_asteroid3[10] = (struct Asteroid){x-3, y+1};
           small_asteroid3[11] = (struct Asteroid){x+1, y+1};
           small_asteroid3[12] = (struct Asteroid){x+2, y+1};
           small_asteroid3[13] = (struct Asteroid){x+3, y+1};
           small_asteroid3[14] = (struct Asteroid){x, y+2};
           small_asteroid3[15] = (struct Asteroid){x-1, y+2};
           small_asteroid3[16] = (struct Asteroid){x-2, y+2};
           small_asteroid3[17] = (struct Asteroid){x+1, y+2};
           small_asteroid3[18] = (struct Asteroid){x+2, y+2};
           small_asteroid3[19] = (struct Asteroid){x, y+3};
           small_asteroid3[20] = (struct Asteroid){x-1, y+3};
           small_asteroid3[21] = (struct Asteroid){x+1, y+3};
           small_asteroid3[22] = (struct Asteroid){x, y-1};
           small_asteroid3[23] = (struct Asteroid){x-1, y-1};
           small_asteroid3[24] = (struct Asteroid){x-2, y-1};
           small_asteroid3[25] = (struct Asteroid){x-3, y-1};
           small_asteroid3[26] = (struct Asteroid){x+1, y-1};
           small_asteroid3[27] = (struct Asteroid){x+2, y-1};
           small_asteroid3[28] = (struct Asteroid){x+3, y-1};
           small_asteroid3[29] = (struct Asteroid){x, y-2};
           small_asteroid3[30] = (struct Asteroid){x-1, y-2};
           small_asteroid3[31] = (struct Asteroid){x-2, y-2};
           small_asteroid3[32] = (struct Asteroid){x+1, y-2};
           small_asteroid3[33] = (struct Asteroid){x+2, y-2};
           small_asteroid3[34] = (struct Asteroid){x, y-3};
           small_asteroid3[35] = (struct Asteroid){x-1, y-3};
           small_asteroid3[36] = (struct Asteroid){x+1, y-3};
           for (int i = 0; i < 37; i++) {
                           	gotoxy(small_asteroid3[i].x,small_asteroid3[i].y);
                           	 printf("O");
           }
    }
}
void Asteroid4(int size, const int x, const int y) {
    if (size == 0) {
    	fgcolor(1);
        very_small_asteroid4[0] = (struct Asteroid){x-2, y};
        very_small_asteroid4[1] = (struct Asteroid){x-1, y};
        very_small_asteroid4[2] = (struct Asteroid){x, y};
        very_small_asteroid4[3] = (struct Asteroid){x+1, y};
        very_small_asteroid4[4] = (struct Asteroid){x+2, y};
        very_small_asteroid4[5] = (struct Asteroid){x-2, y+1};
        very_small_asteroid4[6] = (struct Asteroid){x-1, y+1};
        very_small_asteroid4[7] = (struct Asteroid){x, y+1};
        very_small_asteroid4[8] = (struct Asteroid){x+1, y+1};
        very_small_asteroid4[9] = (struct Asteroid){x+2, y+1};
        very_small_asteroid4[10] = (struct Asteroid){x+1, y+2};
        very_small_asteroid4[11] = (struct Asteroid){x, y+2};
        very_small_asteroid4[12] = (struct Asteroid){x-1, y+2};
        very_small_asteroid4[13] = (struct Asteroid){x-2, y-1};
        very_small_asteroid4[14] = (struct Asteroid){x-1, y-1};
        very_small_asteroid4[15] = (struct Asteroid){x, y-1};
        very_small_asteroid4[16] = (struct Asteroid){x+1, y-1};
        very_small_asteroid4[17] = (struct Asteroid){x+2, y-1};
        very_small_asteroid4[18] = (struct Asteroid){x-1, y-2};
        very_small_asteroid4[19] = (struct Asteroid){x, y-2};
        very_small_asteroid4[20] = (struct Asteroid){x+1, y-2};
        for (int i = 0; i < 21; i++) {
                    	gotoxy(very_small_asteroid4[i].x,very_small_asteroid4[i].y);
                    	 printf("O");
                    }
	}
    if (size == 1) {
           small_asteroid4[0] = (struct Asteroid){x, y};
           small_asteroid4[1] = (struct Asteroid){x-1, y};
           small_asteroid4[2] = (struct Asteroid){x-2, y};
           small_asteroid4[3] = (struct Asteroid){x-3, y};
           small_asteroid4[4] = (struct Asteroid){x+1, y};
           small_asteroid4[5] = (struct Asteroid){x+2, y};
           small_asteroid4[6] = (struct Asteroid){x+3, y};
           small_asteroid4[7] = (struct Asteroid){x, y+1};
           small_asteroid4[8] = (struct Asteroid){x-1, y+1};
           small_asteroid4[9] = (struct Asteroid){x-2, y+1};
           small_asteroid4[10] = (struct Asteroid){x-3, y+1};
           small_asteroid4[11] = (struct Asteroid){x+1, y+1};
           small_asteroid4[12] = (struct Asteroid){x+2, y+1};
           small_asteroid4[13] = (struct Asteroid){x+3, y+1};
           small_asteroid4[14] = (struct Asteroid){x, y+2};
           small_asteroid4[15] = (struct Asteroid){x-1, y+2};
           small_asteroid4[16] = (struct Asteroid){x-2, y+2};
           small_asteroid4[17] = (struct Asteroid){x+1, y+2};
           small_asteroid4[18] = (struct Asteroid){x+2, y+2};
           small_asteroid4[19] = (struct Asteroid){x, y+3};
           small_asteroid4[20] = (struct Asteroid){x-1, y+3};
           small_asteroid4[21] = (struct Asteroid){x+1, y+3};
           small_asteroid4[22] = (struct Asteroid){x, y-1};
           small_asteroid4[23] = (struct Asteroid){x-1, y-1};
           small_asteroid4[24] = (struct Asteroid){x-2, y-1};
           small_asteroid4[25] = (struct Asteroid){x-3, y-1};
           small_asteroid4[26] = (struct Asteroid){x+1, y-1};
           small_asteroid4[27] = (struct Asteroid){x+2, y-1};
           small_asteroid4[28] = (struct Asteroid){x+3, y-1};
           small_asteroid4[29] = (struct Asteroid){x, y-2};
           small_asteroid4[30] = (struct Asteroid){x-1, y-2};
           small_asteroid4[31] = (struct Asteroid){x-2, y-2};
           small_asteroid4[32] = (struct Asteroid){x+1, y-2};
           small_asteroid4[33] = (struct Asteroid){x+2, y-2};
           small_asteroid4[34] = (struct Asteroid){x, y-3};
           small_asteroid4[35] = (struct Asteroid){x-1, y-3};
           small_asteroid4[36] = (struct Asteroid){x+1, y-3};
           for (int i = 0; i < 37; i++) {
                           	gotoxy(small_asteroid4[i].x,small_asteroid4[i].y);
                           	 printf("O");
           }
    }
}
void Asteroid5(int size, const int x, const int y) {
    if (size == 0) {
    	fgcolor(1);
        very_small_asteroid5[0] = (struct Asteroid){x-2, y};
        very_small_asteroid5[1] = (struct Asteroid){x-1, y};
        very_small_asteroid5[2] = (struct Asteroid){x, y};
        very_small_asteroid5[3] = (struct Asteroid){x+1, y};
        very_small_asteroid5[4] = (struct Asteroid){x+2, y};
        very_small_asteroid5[5] = (struct Asteroid){x-2, y+1};
        very_small_asteroid5[6] = (struct Asteroid){x-1, y+1};
        very_small_asteroid5[7] = (struct Asteroid){x, y+1};
        very_small_asteroid5[8] = (struct Asteroid){x+1, y+1};
        very_small_asteroid5[9] = (struct Asteroid){x+2, y+1};
        very_small_asteroid5[10] = (struct Asteroid){x+1, y+2};
        very_small_asteroid5[11] = (struct Asteroid){x, y+2};
        very_small_asteroid5[12] = (struct Asteroid){x-1, y+2};
        very_small_asteroid5[13] = (struct Asteroid){x-2, y-1};
        very_small_asteroid5[14] = (struct Asteroid){x-1, y-1};
        very_small_asteroid5[15] = (struct Asteroid){x, y-1};
        very_small_asteroid5[16] = (struct Asteroid){x+1, y-1};
        very_small_asteroid5[17] = (struct Asteroid){x+2, y-1};
        very_small_asteroid5[18] = (struct Asteroid){x-1, y-2};
        very_small_asteroid5[19] = (struct Asteroid){x, y-2};
        very_small_asteroid5[20] = (struct Asteroid){x+1, y-2};
        for (int i = 0; i < 21; i++) {
                    	gotoxy(very_small_asteroid5[i].x,very_small_asteroid5[i].y);
                    	 printf("O");
                    }
	}
    if (size == 1) {
           small_asteroid5[0] = (struct Asteroid){x, y};
           small_asteroid5[1] = (struct Asteroid){x-1, y};
           small_asteroid5[2] = (struct Asteroid){x-2, y};
           small_asteroid5[3] = (struct Asteroid){x-3, y};
           small_asteroid5[4] = (struct Asteroid){x+1, y};
           small_asteroid5[5] = (struct Asteroid){x+2, y};
           small_asteroid5[6] = (struct Asteroid){x+3, y};
           small_asteroid5[7] = (struct Asteroid){x, y+1};
           small_asteroid5[8] = (struct Asteroid){x-1, y+1};
           small_asteroid5[9] = (struct Asteroid){x-2, y+1};
           small_asteroid5[10] = (struct Asteroid){x-3, y+1};
           small_asteroid5[11] = (struct Asteroid){x+1, y+1};
           small_asteroid5[12] = (struct Asteroid){x+2, y+1};
           small_asteroid5[13] = (struct Asteroid){x+3, y+1};
           small_asteroid5[14] = (struct Asteroid){x, y+2};
           small_asteroid5[15] = (struct Asteroid){x-1, y+2};
           small_asteroid5[16] = (struct Asteroid){x-2, y+2};
           small_asteroid5[17] = (struct Asteroid){x+1, y+2};
           small_asteroid5[18] = (struct Asteroid){x+2, y+2};
           small_asteroid5[19] = (struct Asteroid){x, y+3};
           small_asteroid5[20] = (struct Asteroid){x-1, y+3};
           small_asteroid5[21] = (struct Asteroid){x+1, y+3};
           small_asteroid5[22] = (struct Asteroid){x, y-1};
           small_asteroid5[23] = (struct Asteroid){x-1, y-1};
           small_asteroid5[24] = (struct Asteroid){x-2, y-1};
           small_asteroid5[25] = (struct Asteroid){x-3, y-1};
           small_asteroid5[26] = (struct Asteroid){x+1, y-1};
           small_asteroid5[27] = (struct Asteroid){x+2, y-1};
           small_asteroid5[28] = (struct Asteroid){x+3, y-1};
           small_asteroid5[29] = (struct Asteroid){x, y-2};
           small_asteroid5[30] = (struct Asteroid){x-1, y-2};
           small_asteroid5[31] = (struct Asteroid){x-2, y-2};
           small_asteroid5[32] = (struct Asteroid){x+1, y-2};
           small_asteroid5[33] = (struct Asteroid){x+2, y-2};
           small_asteroid5[34] = (struct Asteroid){x, y-3};
           small_asteroid5[35] = (struct Asteroid){x-1, y-3};
           small_asteroid5[36] = (struct Asteroid){x+1, y-3};
           for (int i = 0; i < 37; i++) {
                           	gotoxy(small_asteroid5[i].x,small_asteroid5[i].y);
                           	 printf("O");
           }
    }
}
