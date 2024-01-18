#ifndef _HEADER_FILE_H_
#define _HEADER_FILE_H_
#define ESC 0x1B

/* Includes -------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
// GLOBAL VARIABLER
int globalLives;
int globalPoints;
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
void write_score_header(int x, int y, int colour);
void write_exit();
void write_Welcome();
void write_highscore();
void write_exitplay();
void write_play_header();
void write_numbers(int number,int x,int y);
void asteroid(int x, int y);
void write_gameover(int x, int y);
void write_colon(int x,int y,int colour);
void write_yourendscore(int x,int y, int colour);
void skull(int x, int y, int colour);
void write_youwin(int x, int y, int colour);
void write_nextlevel(int x, int y, int colour);

// #### Controls.c ####
int ScoreControls();
int HelpControls();
int MenuControls();
int PlayControls();
int levelControls(int difficulty);
void GAMEOVERControls();
int GAMEWINControls();

// #### dataread.c ####
uint16_t Joystickport();
void lcd_resetwrite(const char* input_string, int line_number);
void lcd_write_index(const char* input_string,int line_number, int index);
void level_lcd(int level, int globalLives, int globalPoints);



// #### ansi.c ####
void fgcolor(uint8_t foreground);
void blink(uint8_t on);
void gotoxy();
void ClearScreen();
void cursor_up(int amount);
void cursor_down(int amount);
void cursor_right(int amount);
void cursor_left(int amount);

// #### design.c ####
void border();
void text_color_blink(int on,int colour);
void background();
void menubox();
void box();
void hideCursor();
void credits();
void Smallbox();
void game_border();
void help_design();
void small_gravity(int x, int y);
void large_gravity(int x, int y);


// #### menu.c ####
void menuHELP();
void menuSCORE();
void menuPLAY();
void menu();
void menuGAMEOVER();
void menuWIN(int level);

//initiate_gameplay.c
void initiate_rocket(int x1, int y1);

// #### game.c ####
void initiate_rocket(int x, int y);
void initiate_enemies(int x, int y,int color);
void clear_enemy(int x, int y);
void config_timer();
void enemiesbegin(int speed,int level, int reset);
void initialize(int time_between);
void delete_rocket(int x, int y);
void initiate_shot(int x, int y);
void initialize_screen();
void display_screen();
void pause_control(int time_between);
void points(int points);
void addShot(int x, int y);
void updateAndPrintShots(int pause, int level,int speed);
void initiate_black_hole(int x,int y);
struct Score {
    long int score_count;
};
extern struct Score scores[10];
void update_score(long int score);
void lives(int damage);
struct enemy {
    int x;
    int y;
    int color;
};
struct Shot {
    int x;
    int y;
};
void prevShot(int x, int y);

void clearallshots();

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

//#### astroids.c ####
struct Asteroid {
	    int x;
	    int y;
	};
struct Asteroid very_small_asteroid1[21];
struct Asteroid very_small_asteroid2[21];
struct Asteroid very_small_asteroid3[21];
struct Asteroid very_small_asteroid4[21];
struct Asteroid very_small_asteroid5[21];
struct Asteroid small_asteroid1[37];
struct Asteroid small_asteroid2[37];
struct Asteroid small_asteroid3[37];
struct Asteroid small_asteroid4[37];
struct Asteroid small_asteroid5[37];
void Asteroid1(int size, const int x, const int y);
void Asteroid2(int size, const int x, const int y);
void Asteroid3(int size, const int x, const int y);
void Asteroid4(int size, const int x, const int y);

//#### LED.c ####
void LED(int colour);
/*void addWhateverFunctionsYouNeed( type parameter );*/
#endif // _HEADER_FILE_H_
