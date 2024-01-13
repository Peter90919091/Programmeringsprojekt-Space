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
int HelpControls() {
	int value = 0;
	while(1) {value = Joystickport();
	if (value == 16) {menu();}
	}
}

int levelControls() {
	int cursor_leftright = 38;
	int prev_cursor_leftright = 3;
	int shot_x = 0;
	int shot_y = 0;
	int timer = 0;
	initiate_rocket(cursor_leftright, 0);
	blink(0);
	fgcolor(7);
	int shot = 0;
	while(1) {
		enemies();
		int value =  Joystickport();
	if (value == 4 ) { //LEFT
						if (cursor_leftright> 38) {cursor_leftright -= 2;}
					}
			if (value == 8) { //RIGHT
						if (cursor_leftright< 103) {cursor_leftright += 2;}
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
		}
	if (shot == 1) {
	        updateAndPrintShots();
	    }
	}
}
int PlayControls() {
		int timer = 0;
		int cursor_updown = 0;
		int cursor_leftright = 0;
		int prev_cursor_updown = 0;
		int prev_cursor_leftright = 0;
		int stop = 100;
		blink(0);
					fgcolor(7);
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
			return 1;
		}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 1 )  { //LEVEL2
					ClearScreen();
					level_2();
					return 2;
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 2 )  { //LEVEL3
					ClearScreen();
					level_3();
					return 3;
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 3 )  { //LEVEL4
					ClearScreen();
					level_4();
					return 4;
				}
		if (value == 16 && cursor_updown == 1 && cursor_leftright== 3 )  { //LEVEL5
							ClearScreen();
							level_5();
							return 5;
						}
		/// CURSORPUSH level 5-8
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 0 )  { //LEVEL6
					ClearScreen();
					level_6();
					return 6;
				}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 1 )  { //LEVEL7
							ClearScreen();
							level_7();
							return 7;
						}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 2 )  { //LEVEL8
							ClearScreen();
							level_8();
							return 8;
						}
				if (value == 16 && cursor_updown == 2 && cursor_leftright== 3 )  { //LEVEL9
							ClearScreen();
							level_9();
							return 9;
						}
		/// CURSOR PLAY
				if (value == 16 && cursor_updown == 0  )  { //PLAY
											ClearScreen();
											return 9;
										}
				if (value == 16 && cursor_updown == 3  )  { //EXIT
															ClearScreen();
															menu();
														}

		if (cursor_leftright != prev_cursor_leftright ||cursor_updown != prev_cursor_updown ) {
			blink(0);
			fgcolor(7);
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
		fgcolor(1);
		blink(1);
		write_play_header();
		fgcolor(7);
		blink(0);
		stop = 0;
			}
		}
		if (cursor_updown == 3) {
			if (stop != 3) {
			prev_cursor_updown = cursor_updown;
			fgcolor(1);
			blink(1);
			write_exitplay();
			fgcolor(7);
			blink(0);
			stop = 3;}
				}
		if (cursor_updown == 1 && cursor_leftright == 0) {
			if (stop != 10) {
			prev_cursor_updown = cursor_updown;
			prev_cursor_leftright = cursor_leftright;
					fgcolor(2);
					blink(1);
					write_numbers(1,40,16);
					fgcolor(7);
					blink(0);
					stop = 10;}
						}
		if (cursor_updown == 1 && cursor_leftright == 1) {
			if (stop != 11) {
			prev_cursor_updown = cursor_updown;
			prev_cursor_leftright = cursor_leftright;
							fgcolor(2);
							blink(1);
							write_numbers(2,55,16);
							fgcolor(7);
							blink(0);
							stop = 11;}
								}
		if (cursor_updown == 1 && cursor_leftright == 2 ) {
			if (stop != 12) {
			prev_cursor_updown = cursor_updown;
			prev_cursor_leftright = cursor_leftright;
		fgcolor(2);
		blink(1);
		write_numbers(3,70,16);
		fgcolor(7);
		blink(0);
		stop = 12;}
		}
		if (cursor_updown == 1 && cursor_leftright == 3 ) {
			if (stop != 13) {
			prev_cursor_updown = cursor_updown;
						prev_cursor_leftright = cursor_leftright;
		fgcolor(2);
		blink(1);
		write_numbers(4,85,16);
		fgcolor(7);
		blink(0);
		stop = 13;}

		}
		if (cursor_updown == 1 && cursor_leftright == 4 ) {
			if (stop != 14) {
			prev_cursor_updown = cursor_updown;
						prev_cursor_leftright = cursor_leftright;
		fgcolor(2);
		blink(1);
		write_numbers(5,100,16);
		fgcolor(7);
		blink(0);
		stop = 14;}

		}
		if (cursor_updown == 2 && cursor_leftright == 0 ) {
			if (stop != 20) {
			prev_cursor_updown = cursor_updown;
						prev_cursor_leftright = cursor_leftright;
		fgcolor(2);
		blink(1);
		write_numbers(6,40,24);
		fgcolor(7);
		blink(0);
		stop = 20;}

		}
		if (cursor_updown == 2 && cursor_leftright == 1 ) {
			if (stop != 21) {
			prev_cursor_updown = cursor_updown;
						prev_cursor_leftright = cursor_leftright;
		fgcolor(2);
		blink(1);
		write_numbers(7,55,24);
		fgcolor(7);
		blink(0);
		stop = 21;}
		}
		if (cursor_updown == 2 && cursor_leftright == 2 ) {
			if (stop != 22) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		fgcolor(2);
		blink(1);
		write_numbers(8,70,24);
		fgcolor(7);
		blink(0);
		stop = 22;}
		}
		if (cursor_updown == 2 && cursor_leftright == 3 ) {
			if (stop != 23) {
		prev_cursor_updown = cursor_updown;
		prev_cursor_leftright = cursor_leftright;
		text_color_blink(1);
		write_numbers(9,85,24);
		text_color_blink(0);
		stop = 23;}
		}
		if (value != 0) {
			pause_control(1000000);}}
}



int MenuControls() {
	int timer = 0;
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

