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
int PlayControls();
int levelControls();

// #### dataread.c ####
uint16_t Joystickport();
void lcd_resetwrite(const char* input_string, int line_number);
void lcd_write_index(const char* input_string,int line_number, int index);
void lcd_write_array(uint8_t array[],int line_number,int index,int size);
void write_heart(int line_number, int index);
void clear_line(int line_number);

// #### ansi.c ####
void fgcolor(uint8_t foreground);
void blink(uint8_t on);
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
void game_border();
void help_design();
void text_color_blink(int on);

// #### menu.c ####
void menuHELP();
void menuSCORE();
void menuPLAY();
void menu();

// #### game.c ####
void initiate_rocket(int x, int y);
void initiate_enemies(int x, int y);
void clear_enemy(int x, int y);
void config_timer();
void enemies_down(int total_enemies[][2], int size);
void enemies();
void initialize(int time_between);
void delete_rocket(int x, int y);
void initiate_shot(int x, int y);
void initialize_screen();
void display_screen();
void initiate_shot(int x, int y);
void initiate_black_hole(int x,int y);
void TIM1_BRK_TIM15_IRQHandler(void);
int ScoreControls();
void addShot(int x, int y);
void updateAndPrintShots();


//#### levels.c ####
void level_1();
void level_2();
void level_3();
void level_4();
void level_5();
void level_6();
void level_7();
void level_8();
void level_9();

/*void addWhateverFunctionsYouNeed( type parameter );*/
#endif // _HEADER_FILE_H_

