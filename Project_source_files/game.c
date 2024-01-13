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
#define MAX_SHOTS 100
void initialize(int time_between) {
	gotoxy(60,10);
	printf("Iniatializing game ");
	int third = 0;
	int second = 0;
	int first = 0;
	int remove_text = 0;
	while (first < time_between) {first += 1;}
	if (first == time_between) {printf("3");}
	while (second < time_between) {second += 1;}
	if (second == time_between) {cursor_left(1);printf("2");}
	while (third < time_between) {third += 1;}
	if (third == time_between) {cursor_left(1);printf("1");}
	while (remove_text < time_between) {remove_text += 1;}
	if (remove_text == time_between) {cursor_left(20);printf("                    ");}
}
void pause_control(int time_between) {
	int first = 0;
	while (first < time_between) {first += 1;}
}
void initiate_rocket(int x, int y){
	y =38;
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
	y = 38;
	gotoxy(x,(y-1));
	printf(" ");
	gotoxy(x,y);
	printf(" ");

	fgcolor(1);
	gotoxy(x,(y+1));
	printf(" ");
	fgcolor(15);

	gotoxy((x-1),(y+1));
	printf(" ");
	gotoxy((x+1),(y+1));
	printf(" ");
}


void initiate_enemies(int x, int y) {
    fgcolor(1);
    gotoxy(x,y);
    printf("%c", 204);
    printf("%c", 219);
    printf("%c", 185);
    fgcolor(15);
}

void clear_enemy(int x, int y) {
    gotoxy(x, y);
    printf("   ");
}


void config_timer() {
    RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
    TIM15->CR1 |= 0x01; // Enable timer 15
    TIM15->ARR = 10000; // Set reload value
    TIM15->PSC = 1000; // Set prescale value
    TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
    NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
    NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}

void TIM1_BRK_TIM15_IRQHandler(void) {
    timer++;
    TIM15->SR &= ~0x0001; // Clear interrupt bit
}


void enemies_down(int total_enemies[][2], int size) {
    for (int j = 0; j < size; j++) {
        clear_enemy(total_enemies[j][0], total_enemies[j][1]);
        total_enemies[j][1]++;
        initiate_enemies(total_enemies[j][0], total_enemies[j][1]);
    }
}
void enemies() {
    static int total_enemies[10][2];
    static int i = 0;
    int init_pos_y = 0;

    if (timer == 10) {
        total_enemies[i][0] = rand()% 71;
        total_enemies[i][1] = init_pos_y;
        initiate_enemies(total_enemies[i][0], total_enemies[i][1]);

        timer = 0;
        i++;
        enemies_down(total_enemies, i);
    }
}

struct Shot {
    int x;
    int y;
};
struct Shot shots[MAX_SHOTS];
int ScoreControls() {
	int value = 0;
	while(1) {value = Joystickport();
	if (value == 16) {menu();}
	}
}
void addShot(int x, int y) {
    for (int i = 0; i < MAX_SHOTS; ++i) {
        if (shots[i].x == 0 && shots[i].y == 0) {
            shots[i].x = x;
            shots[i].y = y;
            break;
        }
    }
    for (int i = 0; i < 300000; ++i) {}
}
void updateAndPrintShots() {
    for (int i = 0; i < MAX_SHOTS; ++i) {
        if (shots[i].x != 0 || shots[i].y != 0) {
            gotoxy(shots[i].x, shots[i].y);

            if (shots[i].y > 1) {
                printf("o");
                cursor_left(1);
                cursor_down(1);
                printf(" ");
                --shots[i].y;
            } else {
            	 gotoxy(shots[i].x, ++shots[i].y);
            	 printf(" ");
                shots[i].x = 0;
                shots[i].y = 0;
            }
        }
    }
    for (int i = 0; i < 60000; ++i) {}
}



