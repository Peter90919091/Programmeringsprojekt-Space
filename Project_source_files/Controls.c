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
#include "Header_file.h"
volatile uint32_t timer;
int levelControls(int difficulty) {
	int speed = 0;
	int level = 0;
	int pause = 0;
	if (difficulty == 1) {speed = 10;level = 1;pause = 3000;Asteroid1(0, 20, 20);Asteroid1(1, 70, 30);}
	if (difficulty == 2) {speed = 10;level = 2;pause = 2000;}
	if (difficulty == 3) {speed = 9;level = 3;pause = 1500;}
	if (difficulty == 4) {speed = 9;level = 4;pause = 1000;}
	if (difficulty == 5) {speed = 8;level = 5;pause = 1000;}
	if (difficulty == 6) {speed = 8;level = 6;pause = 500;}
	if (difficulty == 7) {speed = 7;level = 7;pause = 500;}
	if (difficulty == 8) {speed = 7;level = 8;pause = 500;}
	if (difficulty == 9) {speed = 7;level = 9;pause = 300;Asteroid1(0, 20, 20);Asteroid1(1, 70, 30);Asteroid2(0, 30, 25);Asteroid2(1, 40, 15);Asteroid3(0, 100, 20);Asteroid3(1, 70, 30);Asteroid4(0, 57, 17);Asteroid4(1, 89, 10);Asteroid5(0, 20, 20);Asteroid5(1, 10, 30);}

	int cursor_leftright = 38;
	int prev_cursor_leftright = 3;
	int shot_x = 0;
	int shot_y = 0;
	initiate_rocket(cursor_leftright, 0);
	text_color_blink(0);
	int shot = 0;
	while(1) {
		level_lcd(difficulty,globalLives,globalPoints);
		gotoxy(0,0);
		printf("%lu",timer);
		enemies(speed,level);
		int value =  Joystickport();
		if (cursor_leftright == 139 && value == 8) {
			cursor_leftright = 3;}
		if (cursor_leftright == 3 && value == 4) {
					cursor_leftright = 139;}

	if (cursor_leftright > 3 && value == 4 ) { //LEFT
						if (cursor_leftright> 3) {cursor_leftright -= 1;}
						pause_control(pause<<2);
					}
			if (cursor_leftright < 139 && value == 8) { //RIGHT
						if (cursor_leftright< 139) {cursor_leftright += 1;}
						pause_control(pause<<2);
					}
	if (cursor_leftright != prev_cursor_leftright) {
						blink(0);
						fgcolor(7);
						delete_rocket(prev_cursor_leftright , 0);
						prev_cursor_leftright = cursor_leftright;
						initiate_rocket(cursor_leftright, 0);
							}

	if (value == 16) { //SKUD
		gotoxy(cursor_leftright,35);
		printf("o");
		shot_x = cursor_leftright;
		shot_y = 35;
		shot = 1;
		addShot(shot_x, shot_y);
		prevShot(shot_x, shot_y);
		pause_control(200000);
		}
	if (shot == 1) {
	        updateAndPrintShots(pause,level);
	    }
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
		int prev_cursor_updown = 0;
		int prev_cursor_leftright = 0;
		int stop = 100;
		text_color_blink(0);
					write_exitplay();
					write_play_header();
					write_numbers(1,40,16);
					write_numbers(2,55,16);
					write_numbers(3,70,16);
					write_numbers(4,85,16);
					write_numbers(5,100,16);
					write_numbers(6,40,24);
					write_numbers(7,55,24);
					write_numbers(8,70,24);
					write_numbers(9,85,24);
		while(1) {
		int value = Joystickport();
		/// CURSOR MOVEMENT
		if (value == 1) { //UP
			if (cursor_updown> 0) {cursor_updown -= 1;}
		}
		if (value == 2 ) { //DOWN
			if (cursor_updown< 4) {cursor_updown += 1;}
		}
		if (value == 4 ) { //LEFT
					if (cursor_leftright> 0) {cursor_leftright -= 1;}
				}
		if (value == 8) { //RIGHT
					if (cursor_leftright< 4) {cursor_leftright += 1;}
				}
		/// CURSORPUSH level 1-4
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 0 )  { //LEVEL1
			ClearScreen();
			level_1();
		}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 1 )  { //LEVEL2
					ClearScreen();
					level_2();
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 2 )  { //LEVEL3
					ClearScreen();
					level_3();
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 3 )  { //LEVEL4
					ClearScreen();
					level_4();
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 3 )  { //LEVEL5
							ClearScreen();
							level_5();
						}
		/// CURSORPUSH level 5-8
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 0 )  { //LEVEL6
					ClearScreen();
					level_6();
				}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 1 )  { //LEVEL7
							ClearScreen();
							level_7();
						}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 2 )  { //LEVEL8
							ClearScreen();
							level_8();
						}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 3 )  { //LEVEL9
							ClearScreen();
							level_9();
						}
		/// CURSOR PLAY
				if (value == 16 && cursor_updown == 0  )  { //PLAY
											ClearScreen();
										}
				if (value == 16 && cursor_updown == 3  )  { //EXIT
															ClearScreen();
															menu();
														}

		if (cursor_leftright != prev_cursor_leftright ||cursor_updown != prev_cursor_updown ) {
			text_color_blink(0);
			write_exitplay();
			write_play_header();
			write_numbers(1,40,16);
			write_numbers(2,55,16);
			write_numbers(3,70,16);
			write_numbers(4,85,16);
			write_numbers(5,100,16);
			write_numbers(6,40,24);
			write_numbers(7,55,24);
			write_numbers(8,70,24);
			write_numbers(9,85,24);
				}
		if (cursor_updown == 0) {
			if (stop != 0) {
		prev_cursor_updown = cursor_updown;
		text_color_blink(1);
		write_play_header();
		text_color_blink(0);
		stop = 0;
			}
		}
		if (cursor_updown == 3) {
			if (stop != 3) {
			prev_cursor_updown = cursor_updown;
			text_color_blink(1);
			write_exitplay();
			text_color_blink(0);
			stop = 3;}
				}
		if (cursor_updown == 1 && cursor_leftright == 0) {
			if (stop != 10) {
			prev_cursor_updown = cursor_updown;
			prev_cursor_leftright = cursor_leftright;
			text_color_blink(1);
					write_numbers(1,40,16);
					text_color_blink(0);
					stop = 10;}
						}
		if (cursor_updown == 1 && cursor_leftright == 1) {
			if (stop != 11) {
			prev_cursor_updown = cursor_updown;
			prev_cursor_leftright = cursor_leftright;
			text_color_blink(1);
							write_numbers(2,55,16);
							text_color_blink(0);
							stop = 11;}
								}
		if (cursor_updown == 1 && cursor_leftright == 2 ) {
			if (stop != 12) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		text_color_blink(1);
		write_numbers(3,70,16);
		text_color_blink(0);
		stop = 12;}	}
		if (cursor_updown == 1 && cursor_leftright == 3 ) {
			if (stop != 13) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		text_color_blink(1);
		write_numbers(4,85,16);
		text_color_blink(0);
		stop = 13;}	}
		if (cursor_updown == 1 && cursor_leftright == 4 ) {
			if (stop != 14) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		text_color_blink(1);
		write_numbers(5,100,16);
		text_color_blink(0);
		stop = 14;}	}
		if (cursor_updown == 2 && cursor_leftright == 0 ) {
			if (stop != 20) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		text_color_blink(1);
		write_numbers(6,40,24);
		text_color_blink(0);
		stop = 20;}	}
		if (cursor_updown == 2 && cursor_leftright == 1 ) {
			if (stop != 21) {
			prev_cursor_updown = cursor_updown;
			prev_cursor_leftright = cursor_leftright;
			text_color_blink(1);
			write_numbers(7,55,24);
			text_color_blink(0);
			stop = 21;}	}
		if (cursor_updown == 2 && cursor_leftright == 2 ) {
			if (stop != 22) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		text_color_blink(1);
		write_numbers(8,70,24);
		text_color_blink(0);
		stop = 22;}	}
		if (cursor_updown == 2 && cursor_leftright == 3 ) {
			if (stop != 23) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		text_color_blink(1);
		write_numbers(9,85,24);
		text_color_blink(0);
		stop = 23;}	}
		if (value != 0) {
			pause_control(1000000);}}
}
int ScoreControls() {
	int value = 0;
	while(1) {value = Joystickport();
	if (value == 16) {menu();}
	}
}


int MenuControls() {
	int cursor_placement = 0;
	int prev_cursor_placement = 0;
	int stop = 100;
	text_color_blink(0);
			gotoxy(62,17);
			write_help();
			gotoxy(60,23);
			write_score();
			gotoxy(63,29);
			write_play();
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
		return 1;}
	if (value == 16 && cursor_placement == 1)  { //SCORE
		ClearScreen();
		return 2;}
	if (value == 16 && cursor_placement == 2)  { //PLAY
		ClearScreen();
		return 3;}
	if (cursor_placement != prev_cursor_placement) {
		text_color_blink(0);
		gotoxy(62,17);
		write_help();
		gotoxy(60,23);
		write_score();
		gotoxy(63,29);
		write_play();
	}
	if (cursor_placement == 0) {
		if (stop != 0) {
		prev_cursor_placement = cursor_placement;
		gotoxy(62,17);
		text_color_blink(1);
		write_help();
		text_color_blink(0);
		stop = 0;}
	}
	if (cursor_placement == 1) {
		if (stop != 1) {
		prev_cursor_placement = cursor_placement;
			gotoxy(60,23);
			text_color_blink(1);
			write_score();
			text_color_blink(0);;
				stop = 1;}
	}
	if (cursor_placement == 2) {
		if (stop != 2) {
			prev_cursor_placement = cursor_placement;
			gotoxy(63,29);
			text_color_blink(1);
			write_play();
			text_color_blink(0);
			stop = 2;}
		}
	if (value != 0) {
	pause_control(1000000);}}
}

void GAMEOVERControls() {
	int value = 0;
	while(1) {value = Joystickport();
		if (value == 16) {menu();}
		}
}
