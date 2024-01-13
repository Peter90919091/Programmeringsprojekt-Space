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


void initiate_shot(int x, int y) {
	fgcolor(1);
	gotoxy(x,y);
	int SHOTS;
	for (SHOTS = 0; SHOTS < 33; ) {
		gotoxy(x,y--);
		printf("o");
		cursor_left(1);
		cursor_down(1);
		printf(" ");
		SHOTS += 1;

	}
	cursor_left(1);
	printf(" ");
}


void initiate_black_hole(int x,int y){
	fgcolor(8);
	gotoxy(x-2,y-1);
	for (int k=0; k <= 4; k++){
		printf("%c",187);
	}
	cursor_down(1);
	cursor_left(6);
	for (int k=0; k <= 6; k++){
		if (k == 0) {
			printf("%c",201);
		}
		else if (k==6){
			printf("%c",188);
		}
		else{
			printf("%c",178);
		}
	}
	cursor_down(1);
	cursor_left(6);
	for (int k=0; k <=4; k++){
		printf("%c",200);
	}
	fgcolor(15);
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



