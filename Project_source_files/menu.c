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
	HelpControls();

}
void menuPLAY() {
	background();
	border();
	initialize(3000000);

}
void menuSCORE() {
	background();
	border();
	write_score_header();
	box();
	write_exit();
	write_highscore();
	ScoreControls();
}
void menu() {
	ClearScreen();
	background(); //FØRST
	border();
	write_Welcome();
	menubox();
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

