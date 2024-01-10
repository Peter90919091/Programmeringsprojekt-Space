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
// #### Controls.c ####
int ScoreControls();
int HelpControls();
int MenuControls();
// #### dataread.c ####
uint16_t Joystickport();
// #### ansi.c ####
void fgcolor();
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
/*void addWhateverFunctionsYouNeed( type parameter );*/
#endif // _HEADER_FILE_H_
