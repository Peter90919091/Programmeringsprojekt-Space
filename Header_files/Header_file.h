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
volatile uint32_t timer;

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
int levelControls(int difficulty);

// #### dataread.c ####
uint16_t Joystickport();
void lcd_resetwrite(const char* input_string, int line_number);
void lcd_write_index(const char* input_string, int line_number, int index);
void lcd_write_array(uint8_t array[], int line_number, int index, int size);
void write_heart(int line_number, int index);
void clear_line(int line_number);


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
void text_color_blink(int on);
void background();
void menubox();
void box();
void hideCursor();
void credits();
void Smallbox();
void game_border();
void help_design();

// #### menu.c ####
void menuHELP();
void menuSCORE();
void menuPLAY();
void menu();

//initiate_gameplay.c
void initiate_rocket(int x1, int y1);

// #### game.c ####
void initiate_rocket(int x, int y);
void initiate_enemies(int x, int y,int color);
void clear_enemy(int x, int y);
void config_timer();
void enemies(int speed,int level);
void initialize(int time_between);
void delete_rocket(int x, int y);
void initiate_shot(int x, int y);
void initialize_screen();
void display_screen();
void pause_control(int time_between);
void points(int points);
void addShot(int x, int y);
bool isCollision(int shotX, int shotY, int enemyX, int enemyY);
void updateAndPrintShots(int pause);
void initiate_black_hole(int x,int y);

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

