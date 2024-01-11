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

//################## ASTEROIDS ###################
void write_Welcome() {
	// 140x40 #178
	gotoxy(45,8);
	fgcolor(2);
//PRINT "A"
	for (int i=0;i<=5;i++) {
	printf("%c",178);
	cursor_up(1);cursor_left(1);
	}
	cursor_right(1);
	for (int j=0;j <= 3;j++) {
		printf("%c",178);
		cursor_down(2);cursor_left(1);
		printf("%c",178);
		cursor_up(2);
		}
	for (int i = 0; i<=5;i++) {
		cursor_down(1);
		printf("%c",178);
		cursor_left(1);
	}
//PRINT "S"
	for (int i=0;i<=4;i++) {
		printf("%c",178);
	}
	for (int i=0; i<= 1; i++) {
		cursor_up(1);
		printf("%c",178);
		cursor_left(1);
	}
	cursor_up(1); cursor_right(1);
	for (int i=0;i<=2; i++) {
		cursor_left(2);
		printf("%c",178);
	}
	cursor_left(2);cursor_up(1);
	printf("%c",178);
	cursor_up(1);
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_right(1);

//PRINT "T"
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_left(3);
	cursor_down(1);printf("%c",178);cursor_left(1);
	cursor_down(1);printf("%c",178);cursor_left(1);
	cursor_down(1);printf("%c",178);cursor_left(1);
	cursor_down(1);printf("%c",178);cursor_left(1);
	cursor_down(1);printf("%c",178);
	cursor_right(3);
//PRINT "E"
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_left(5);cursor_up(1);
	printf("%c",178);cursor_left(1);cursor_up(1);
	printf("%c",178);cursor_left(1);cursor_up(1);
	printf("%c",178);printf("%c",178);printf("%c",178);cursor_left(3);cursor_up(1);
	printf("%c",178);cursor_left(1);cursor_up(1);
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);

//PRINT "R"
	cursor_right(1);
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_left(6);cursor_down(1);
	printf("%c",178);cursor_right(5);printf("%c",178);
	cursor_left(7);cursor_down(1);
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_left(6);cursor_down(1);
	printf("%c",178);cursor_down(1);cursor_left(1);
	printf("%c",178);cursor_down(1);cursor_left(1);
	printf("%c",178);cursor_up(2);cursor_right(3);
	printf("%c",178);cursor_down(1);printf("%c",178);cursor_down(1);printf("%c",178);

//PRINT "O"
	cursor_right(2);
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	for (int i =0; i<=3; i++) {
		cursor_up(1);
		printf("%c",178);
		cursor_left(6);
		printf("%c",178);
		cursor_right(4);
	}
	cursor_up(1);cursor_left(4);
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
//PRINT "I"
	cursor_right(2);
	printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_down(1);cursor_left(2);printf("%c",178);
	cursor_down(1);cursor_left(1);printf("%c",178);
	cursor_down(1);cursor_left(1);printf("%c",178);
	cursor_down(1);cursor_left(1);printf("%c",178);
	cursor_down(1);cursor_left(2);printf("%c",178);printf("%c",178);printf("%c",178);
//PRINT "D"
	cursor_right(1);
	printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_left(4);cursor_up(1);printf("%c",178);
	cursor_left(1);cursor_up(1);printf("%c",178);
	cursor_left(1);cursor_up(1);printf("%c",178);
	cursor_left(1);cursor_up(1);printf("%c",178);
	cursor_left(1);cursor_up(1);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_down(1);printf("%c",178);
	cursor_down(1);cursor_left(1);printf("%c",178);
	cursor_down(1);cursor_left(1);printf("%c",178);
	cursor_down(1);cursor_left(1);printf("%c",178);
//PRINT "S"
	cursor_down(1);
		for (int i=0;i<=4;i++) {
			printf("%c",178);
		}
		for (int i=0; i<= 1; i++) {
			cursor_up(1);
			printf("%c",178);
			cursor_left(1);
		}
		cursor_up(1); cursor_right(1);
		for (int i=0;i<=2; i++) {
			cursor_left(2);
			printf("%c",178);
		}
		cursor_left(2);cursor_up(1);
		printf("%c",178);
		cursor_up(1);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_right(1);
		fgcolor(7);
}

//################## MENU ###################
void write_menu(){
	gotoxy(60,10);
	fgcolor(6);
	//Print M
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(3);printf("%c", 178);cursor_down(1);
	printf("%c", 178);
	cursor_up(1);printf("%c", 178);
	cursor_up(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(4);cursor_right(1);
	//print E
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_up(2);cursor_left(3);printf("%c", 178);printf("%c", 178);
	cursor_up(2);cursor_left(2);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	;cursor_right(1);

	//print N
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(4);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_down(1);printf("%c", 178);
	cursor_up(1);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);
	cursor_right(1);

	//print U
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_down(1);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_up(1);printf("%c",178);cursor_up(1);cursor_left(1);printf("%c",178);cursor_up(1);cursor_left(1);printf("%c",178);cursor_up(1);cursor_left(1);printf("%c",178);
	fgcolor(7);
}

//################## HELP ###################
void write_help(){
	//print H
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_down(1);cursor_left(1);printf("%c", 178);cursor_up(2);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);
	//Print E
	cursor_right(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_up(2);cursor_left(3);printf("%c", 178);cursor_left(1);cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//Print L
	cursor_right(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_up(3);cursor_right(1);
	//Print P
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(3);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);
	cursor_right(2);cursor_up(2);
}
//################## SCORE ###################
void write_score() {
	//Sets cursor
	//Print S
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);
	printf("%c", 178);cursor_down(1);cursor_left(4);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_up(3);cursor_left(3);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_right(1);
	//Print C
	cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_up(3);cursor_left(3);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//print O
	cursor_right(1);
	cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);printf("%c", 178);printf("%c", 178);cursor_up(1);printf("%c", 178);cursor_up(1);
	cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(3);printf("%c", 178);printf("%c", 178);cursor_right(2);
	//Print R
	cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(1);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);
	cursor_up(3);cursor_left(3);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);
	//Print E
	cursor_right(1);cursor_up(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_up(2);cursor_left(3);printf("%c", 178);cursor_left(1);cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
}
//################## PLAY ###################
void write_play(){

	//Print P
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(3);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);
	cursor_right(2);cursor_up(2);
	//Print L
	printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	printf("%c", 178);printf("%c", 178);printf("%c", 178);
	cursor_up(3);cursor_right(1);
	//Print A
	cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_up(1);printf("%c", 178);printf("%c", 178);
	cursor_down(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(3);printf("%c", 178);printf("%c", 178);
	//Print Y
	cursor_right(2);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
	cursor_up(3);printf("%c", 178);cursor_left(1);cursor_down(1);printf("%c", 178);
}
//################## SCORE HEADER ###################
void write_score_header() {
	//Setting cursor
	gotoxy(54,8);
	fgcolor(2);
	//Print big S
	for (int i=0;i<=4;i++) {
			printf("%c",178);
		}
		for (int i=0; i<= 1; i++) {
			cursor_up(1);
			printf("%c",178);
			cursor_left(1);
		}
		cursor_up(1); cursor_right(1);
		for (int i=0;i<=3; i++) {
			cursor_left(2);
			printf("%c",178);
		}
		cursor_left(2);cursor_up(1);
		printf("%c",178);
		cursor_up(1);cursor_left(1);printf("%c", 178);
		cursor_up(1);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_right(1);

	//Print C
		cursor_right(1);
		cursor_down(2);printf("%c",178);cursor_down(1);cursor_left(1);printf("%c",178);
		cursor_down(1);cursor_left(1);printf("%c",178);cursor_down(1);cursor_left(1);printf("%c",178);
		cursor_down(1);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_up(5);cursor_left(4);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_right(1);
	//PRINT "O"
		cursor_right(2); cursor_down(5);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		for (int i =0; i<=3; i++) {
			cursor_up(1);
			printf("%c",178);
			cursor_left(6);
			printf("%c",178);
			cursor_right(4);
		}
		cursor_up(1);cursor_left(4);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	//PRINT "R"
		cursor_right(3);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_left(6);cursor_down(1);
		printf("%c",178);cursor_right(5);printf("%c",178);
		cursor_left(7);cursor_down(1);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_left(6);cursor_down(1);
		printf("%c",178);cursor_down(1);cursor_left(1);
		printf("%c",178);cursor_down(1);cursor_left(1);
		printf("%c",178);cursor_up(2);cursor_right(3);
		printf("%c",178);cursor_down(1);printf("%c",178);cursor_down(1);printf("%c",178);

	//PRINT "E"
		cursor_right(2);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_left(5);cursor_up(1);
		printf("%c",178);cursor_left(1);cursor_up(1);
		printf("%c",178);cursor_left(1);cursor_up(1);
		printf("%c",178);printf("%c",178);printf("%c",178);cursor_left(3);cursor_up(1);
		printf("%c",178);cursor_left(1);cursor_up(1);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		fgcolor(7);
}
//################## HELP HEADER ###################
void write_help_header() {
	fgcolor(2);
	//setting cursor
	gotoxy(60,10);
	//Print H
	for (int i = 0;i <7;i++) {
		printf("%c",178);cursor_down(1);
		cursor_left(1);
	}
	cursor_up(4);cursor_right(1);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	cursor_down(1);cursor_left(1);printf("%c",178);cursor_down(1);cursor_left(1);printf("%c",178);cursor_down(1);
	cursor_left(1);printf("%c",178);cursor_up(4);cursor_left(1);printf("%c",178);cursor_up(1);cursor_left(1);printf("%c",178);
	cursor_up(1);cursor_left(1);printf("%c",178);cursor_right(2);

	//PRINT "E"
		cursor_down(6);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		cursor_left(5);cursor_up(1);
		printf("%c",178);cursor_left(1);cursor_up(1);
		printf("%c",178);cursor_left(1);cursor_up(1);
		printf("%c",178);printf("%c",178);printf("%c",178);cursor_left(3);cursor_up(1);
		printf("%c",178);cursor_left(1);cursor_up(1);
		printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
	//Print L
		cursor_right(2);
		for (int i = 0; i<5;i++) {
			printf("%c",178);
			cursor_down(1);
			cursor_left(1);
		}
		for (int j = 0; j<5;j++) {
			printf("%c",178);
		}
	//Print P
		cursor_right(2);cursor_up(4);
		for (int i = 0; i<5;i++) {
				printf("%c",178);
				cursor_down(1);
				cursor_left(1);
			}
		cursor_up(3);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);cursor_up(1);printf("%c",178);
		cursor_up(1);cursor_left(1);printf("%c",178);cursor_up(1);cursor_left(5);printf("%c",178);printf("%c",178);printf("%c",178);printf("%c",178);
		fgcolor(7);
}
//################## EXIT ###################
void write_exit() {
	//Setting cursor
	gotoxy(62,36);
	blink(1);
	fgcolor(1);
	//Print E
		cursor_right(1);cursor_up(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
		printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_up(2);cursor_left(3);printf("%c", 178);cursor_left(1);cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//Print X
		cursor_right(1);printf("%c", 178);cursor_down(1);printf("%c", 178);printf("%c", 178);cursor_down(1);
		cursor_left(2);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_left(4);printf("%c", 178);
		cursor_up(3);cursor_right(2);printf("%c", 178);
	//Print I
		cursor_right(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_down(1);
		cursor_left(3);printf("%c", 178);printf("%c", 178);cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//Print T
		cursor_up(3);cursor_right(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
	fgcolor(7);
	blink(0);
}
void write_highscore() {
	//Sets cursor
	gotoxy(47,10);
	fgcolor(11);
	//Print H
		printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
		cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(1);printf("%c", 178);cursor_up(2);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);

	//Print I
		cursor_right(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_down(1);
		cursor_left(3);printf("%c", 178);printf("%c", 178);cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);

	//Print G
		cursor_up(2);cursor_right(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
		cursor_down(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);printf("%c", 178);
		cursor_left(4);cursor_up(2);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);

	//Print H
		cursor_right(1);
		printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
		cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(1);printf("%c", 178);cursor_up(2);cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(1);printf("%c", 178);

	//Print "-"
		cursor_right(1);cursor_down(2); printf("%c", 178);printf("%c", 178);
		cursor_up(2);cursor_right(1);

	//Print S
		printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);
		printf("%c", 178);cursor_down(1);cursor_left(4);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_up(3);cursor_left(3);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_right(1);

	//Print C
		cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_up(3);cursor_left(3);printf("%c", 178);printf("%c", 178);printf("%c", 178);

	//print O
		cursor_right(1);
		cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);printf("%c", 178);printf("%c", 178);cursor_up(1);printf("%c", 178);cursor_up(1);
		cursor_left(1);printf("%c", 178);cursor_up(1);cursor_left(3);printf("%c", 178);printf("%c", 178);cursor_right(2);

	//Print R
		cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
		cursor_up(1);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);
		cursor_up(3);cursor_left(3);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);

	//Print E
		cursor_right(1);cursor_up(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
		printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_up(2);cursor_left(3);printf("%c", 178);cursor_left(1);cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		fgcolor(7);
	}
void write_exitplay() {
	//Setting cursor
	gotoxy(62,36);
	//Print E
		cursor_right(1);cursor_up(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
		printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_up(2);cursor_left(3);printf("%c", 178);cursor_left(1);cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//Print X
		cursor_right(1);printf("%c", 178);cursor_down(1);printf("%c", 178);printf("%c", 178);cursor_down(1);
		cursor_left(2);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);cursor_left(4);printf("%c", 178);
		cursor_up(3);cursor_right(2);printf("%c", 178);
	//Print I
		cursor_right(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_down(1);
		cursor_left(3);printf("%c", 178);printf("%c", 178);cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//Print T
		cursor_up(3);cursor_right(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
		cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
}
void write_play_header() {
	gotoxy(60,10);
	//"P"

	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_down(1);printf("%c", 178);
	cursor_left(7);cursor_down(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//"L"
	cursor_down(3); cursor_right(2);printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);
	cursor_down(5);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
	//"A"
	cursor_right(1);
	for (int i=0;i<=4;i++) {
	printf("%c",178);
	cursor_up(1);cursor_left(1);
	}
	cursor_right(1);
	for (int j=0;j <= 3;j++) {
		printf("%c",178);
		cursor_down(2);cursor_left(1);
		printf("%c",178);
		cursor_up(2);
		}
	for (int i = 0; i<=4;i++) {
		cursor_down(1);
		printf("%c",178);
		cursor_left(1);
	}
	//"Y"
	cursor_right(5);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_left(1);cursor_up(1);
	printf("%c", 178);cursor_up(1);
	printf("%c", 178);cursor_left(3);printf("%c", 178);cursor_up(1);
	cursor_left(2);printf("%c", 178);cursor_right(3);printf("%c", 178);

}
void write_numbers(int number,int x,int y) {
	//Set cursor
	gotoxy(x,y);
	//Print 1
		if (number == 1) {
			cursor_down(1);printf("%c", 178);
			cursor_up(1);
			printf("%c", 178);printf("%c", 178);printf("%c", 178);
			for (int i = 0;i < 4;i++) {
				cursor_down(1);
				cursor_left(1);
				printf("%c", 178);
			}
			printf("%c", 178);
			cursor_left(4);
			printf("%c", 178);
			printf("%c", 178);
		}
		else if (number == 2) {
			cursor_down(1);
			printf("%c", 178);
			cursor_up(1);
			printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);printf("%c", 178);
			cursor_down(1);cursor_left(3);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(3);printf("%c", 178);
			cursor_down(1);cursor_left(2);printf("%c", 178);
			printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);


		}
		else if (number == 3) {
			cursor_down(1);printf("%c", 178);
			cursor_up(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);cursor_down(1);
			printf("%c", 178);cursor_down(1);cursor_left(2);printf("%c", 178);printf("%c", 178);
			cursor_left(1);cursor_down(1);printf("%c", 178);cursor_left(5);printf("%c", 178);
			cursor_down(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		}
		else if (number == 4) {
			printf("%c", 178);cursor_down(1);cursor_left(1);printf("%c", 178);
			cursor_left(1);cursor_down(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_up(2);
			for (int i = 0;i <5;i++) {
				printf("%c", 178);
				cursor_down(1);
				cursor_left(1);
			}
		}
		else if (number == 5) {
			cursor_right(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(5);printf("%c", 178);
			cursor_down(1);cursor_left(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_left(1),cursor_down(1);printf("%c", 178);cursor_down(1);cursor_left(5);
			printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		}
		else if (number == 6) {
			printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(5);printf("%c", 178);cursor_down(1);cursor_left(1);
			printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_left(5);cursor_down(1);printf("%c", 178);cursor_right(3);printf("%c", 178);
			cursor_left(5);cursor_down(1);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			printf("%c", 178);printf("%c", 178);
		}
		else if (number == 7) {
			printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(1);printf("%c", 178);
			for (int i = 0;i<3;i++) {
				cursor_left(2);cursor_down(1);
				printf("%c", 178);
			}
		}
		else if (number == 8) {
			printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(5);printf("%c", 178);cursor_right(3);printf("%c", 178);
			cursor_down(1),cursor_left(4);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(4);printf("%c", 178);cursor_right(3);printf("%c", 178);
			cursor_down(1);cursor_left(5);printf("%c", 178);printf("%c", 178);
			printf("%c", 178);printf("%c", 178);printf("%c", 178);
		}
		else if (number == 9) {
			printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(5);printf("%c", 178);cursor_right(3);printf("%c", 178);
			cursor_down(1);cursor_left(5);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
			cursor_down(1);cursor_left(1);printf("%c", 178);
			cursor_down(1);cursor_left(5);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);printf("%c", 178);
		}
}
void asteroid(int x, int y){
	fgcolor(3);
	gotoxy(x,y);
    printf("      .-\"\"\"\"\"\"-.\n");
    gotoxy(x,y+1);
    printf("    .-'   ()       '-.\n");
    gotoxy(x,y+2);
    printf("   .'          O       '.\n");
    gotoxy(x,y+3);
    printf(" /   O      .    ()       \\\n");
    gotoxy(x,y+4);
    printf(":           .           o  :\n");
    gotoxy(x,y+5);
    printf(" :  .   ()   .      '    :\n");
    gotoxy(x,y+6);
    printf("  \\           .    .    /\n");
    gotoxy(x,y+7);
    printf("   '.()   O        o  .'\n");
    gotoxy(x,y+8);
    printf("       '-.______ _.-'\n");
    fgcolor(7);
}
