#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
#define ESC 0x1B
/* Includes -------------------------------------------------------------*/
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

/* Exported types -------------------------------------------------------*/
/* Exported constants ---------------------------------------------------*/
/* Exported macro -------------------------------------------------------*/
/* #define			 // Whatever needs to be defined < */
/* Exported functions -------------------------------------------------- */

// #### MENU_TEXT.c ####
void write_score();
void write_play();
void write_menu();
void write_help();
void write_help_header();
void write_score_header();
void write_exit();
void write_Welcome();
void write_highscore();
void write_exitplay();
void write_play_header();
void write_numbers(int number,int x,int y);
void asteroid(int x, int y);

// #### Controls.c ####
int ScoreControls();
int HelpControls();
int MenuControls();

// #### dataread.c ####
uint16_t Joystickport();
void lcd_write_string(const char* input_string, int line_number);

// #### ansi.c ####
void fgcolor(uint8_t foreground);
void blink();
void voidgotoxy();
void ClearScreen();
void cursor_up(int amount);
void cursor_down(int amount);
void cursor_right(int amount);
void cursor_left(int amount);

// #### design.c ####
void border();
void background();
void menubox();
void box();
void hideCursor();
void credits();
void Smallbox();
void help_design();

// #### menu.c ####
void menuHELP();
void menuSCORE();
void menuPLAY();
void menu();

// #### game.c ####


//initiate_gameplay.c
void initiate_rocket(int x, int y);
void initiate_enemies(int x, int y);
/*void addWhateverFunctionsYouNeed( type parameter );*/
#endif // _HEADER_FILE_H_

