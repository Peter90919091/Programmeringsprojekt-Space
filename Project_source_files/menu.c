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
void menuHELP() {
	background();
	border();
	box();
	write_help_header();
	write_exit();
	lcd_write_string("A tutorial of the game",2);
	HelpControls();

}
void menuPLAY() {
	background();
	border();
	lcd_write_string("Select a level to play",2);
	initialize(3000000);
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
	write_score_header();
	box();
	write_exit();
	write_highscore();
	lcd_write_string("Look at your highscore!",2);
	ScoreControls();
}
void menu() {
	ClearScreen();
	background(); //FØRST
	border();
	write_Welcome();
	menubox();
	lcd_write_string("Please select a menu", 3);
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

