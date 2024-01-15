/*
 * menu.c
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

void menuHELP() {
	background();
	asteroid(2,2);
	asteroid(90,20);
	border();
	box();
	write_help_header();
	write_exit();
	help_design();
	lcd_resetwrite("Controls and object of the game!",1);
	HelpControls();
}
void menuPLAY() {
	background();
	border();
	asteroid(2,2);
	asteroid(90,20);
	lcd_resetwrite("Select a level to play!",1);
	//BORDER FOR LEVELS
	gotoxy(37,15);
	Smallbox();
	gotoxy(52,15);
	Smallbox();
	gotoxy(67,15);
	Smallbox();
	gotoxy(82,15);
	Smallbox();
	gotoxy(97,15);
	Smallbox();
	gotoxy(37,23);
	Smallbox();
	gotoxy(52,23);
	Smallbox();
	gotoxy(67,23);
	Smallbox();
	gotoxy(82,23);
	Smallbox();
	gotoxy(97,23);
	Smallbox();
	PlayControls();

}
void menuSCORE() {
	background();
	border();
	asteroid(2,2);
	asteroid(90,20);
	write_score_header(54,8,2);
	box();
	write_exit();
	write_highscore();
	lcd_resetwrite("Look at your highscore!",1);
	gotoxy(40,20);
		for (int i = 0; i< 10; i++) {
			gotoxy(40,20+i);
			printf("nr. %d Score is %lu",i+1,scores[i].score_count);
		}
	ScoreControls();
	//display scores:
}

void menu() {
	ClearScreen();
	background(); //FØRST
	border();
	asteroid(2,2);
	asteroid(90,20);
	write_Welcome();
	menubox();
	lcd_resetwrite("Please select a menu", 1);
	credits();
	int value = MenuControls();
	if (value == 1) {
				menuHELP();
			}
	if (value == 2) {
		menuSCORE();

	}
	if (value == 3) {
		menuPLAY();
		}
}

void menuGAMEOVER() {
	ClearScreen();
	background(); //FØRST
	border();
	write_exit();
	write_gameover(37,5);
	write_score(50,15,1);
	write_colon(75,16,1);
	write_yourendscore(77,14,1);
	globalPoints = 0;
	globalLives = 3;
	skull(67,22,7);
	lcd_resetwrite("",1);
	lcd_write_index("GAME",2,50);
	lcd_write_index("OVER!",3,50);
	lcd_write_index("   ",1,0);
	GAMEOVERControls();
}
