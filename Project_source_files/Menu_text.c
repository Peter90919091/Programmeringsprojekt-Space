#include "menu.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include <stdint.h>
#include "math.h"

################## ASTEROIDS ###################
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
/*
 * menu.c
 *
 *  Created on: 9. jan. 2024
 *      Author: noohr
 */

#define ESC 0x1B

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

//Function for writing "menu"
void write_menu(){
	gotoxy(50,20);
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
}

//Function for writing "HELP"
void write_help(){
	gotoxy(50,30);
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

void write_score() {
	//Sets cursor
	gotoxy(50,40);
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

void write_play(){

	//Sets cursor
	gotoxy(50,50);
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

void write_score_header() {
	//Setting cursor
	gotoxy(60,10);
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
}

void write_help_header() {
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
}

void write_exit() {
	//Setting cursor
	gotoxy(50,30);
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






