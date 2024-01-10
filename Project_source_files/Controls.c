/*
 * Controls.c
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
int ScoreControls() {
	int value = 0;
	while(1) {value = Joystickport();
	if (value == 16) {menu();}
	}
}
int HelpControls() {
	int value = 0;
	while(1) {value = Joystickport();
	if (value == 16) {menu();}
	}
}

int PlayControls() {
		int cursor_updown = 0;
		int cursor_leftright = 0;

		while(1) {
		int value = Joystickport();
		/// CURSOR MOVEMENT
		if (value == 1) { //UP
			if (cursor_updown> 0) {cursor_updown -= 1;}
		}
		if (value == 2 ) { //DOWN
			if (cursor_updown< 3) {cursor_updown += 1;}
		}
		if (value == 4 ) { //LEFT
					if (cursor_leftright> 0) {cursor_leftright -= 1;}
				}
		if (value == 8) { //RIGHT
					if (cursor_leftright< 3) {cursor_leftright += 1;}
				}
		/// CURSORPUSH level 1-4
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 0 )  { //LEVEL1
			ClearScreen();
			return 1;
		}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 1 )  { //LEVEL2
					ClearScreen();
					return 2;
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 2 )  { //LEVEL3
					ClearScreen();
					return 3;
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 3 )  { //LEVEL4
					ClearScreen();
					return 4;
				}
		/// CURSORPUSH level 5-8
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 0 )  { //LEVEL5
					ClearScreen();
					return 5;
				}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 1 )  { //LEVEL6
							ClearScreen();
							return 6;
						}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 2 )  { //LEVEL7
							ClearScreen();
							return 7;
						}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 3 )  { //LEVEL8
							ClearScreen();
							return 8;
						}
		/// CURSOR PLAY
				if (value == 16 && cursor_updown == 0  )  { //PLAY
											ClearScreen();
											return 9;
										}
				if (value == 16 && cursor_updown == 3  )  { //EXIT
															ClearScreen();
															return 10;
														}
		}
	}

int MenuControls() {
	int cursor_placement = 0;

	while(1) {
	int value = Joystickport();
	if (value == 1 || value == 5 || value== 9 || value == 17 || value == 21 || value == 25) { //UP
		if (cursor_placement> 0) {cursor_placement -= 1;}
	}
	if (value == 2 || value == 6 || value == 10 || value == 18 || value == 22 || value == 26) { //DOWN
		if (cursor_placement< 2) {cursor_placement += 1;}
	}
	if (value == 16 && cursor_placement == 0)  { //HELP
		ClearScreen();
		return 1;
	}
	if (value == 16 && cursor_placement == 1)  { //SCORE
		ClearScreen();
		return 2;
		}
	if (value == 16 && cursor_placement == 2)  { //PLAY
		ClearScreen();
				return 3;
		}

	if (cursor_placement == 0) {
		gotoxy(62,17);
		blink(1);
		fgcolor(1);
		write_help();
		fgcolor(7);
			blink(0);
		gotoxy(60,23);
		write_score();
		gotoxy(63,29);
		write_play();
	}
	if (cursor_placement == 1) {
			gotoxy(62,17);
			write_help();
			gotoxy(60,23);
			blink(1);
			fgcolor(1);
			write_score();
			fgcolor(7);
				blink(0);
			gotoxy(63,29);
			write_play();
	}
	if (cursor_placement == 2) {
			gotoxy(62,17);
			write_help();
			gotoxy(60,23);
			write_score();
			gotoxy(63,29);
			blink(1);
			fgcolor(1);
			write_play();
			fgcolor(7);
				blink(0);
		}
	}
}

