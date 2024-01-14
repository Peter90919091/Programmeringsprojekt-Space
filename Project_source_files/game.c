/*
 * game.c
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
void initialize(int time_between) {
	gotoxy(60,10);
	printf("Iniatializing game ");
	int third = 0;
	int second = 0;
	int first = 0;
	int remove_text = 0;
	while (first < time_between) {first += 1;}
	if (first == time_between) {printf("3");}
	while (second < time_between) {second += 1;}
	if (second == time_between) {cursor_left(1);printf("2");}
	while (third < time_between) {third += 1;}
	if (third == time_between) {cursor_left(1);printf("1");}
	while (remove_text < time_between) {remove_text += 1;}
	if (remove_text == time_between) {cursor_left(20);printf("                    ");}
}
void pause_control(int time_between) {
	int first = 0;
	while (first < time_between) {first += 1;}
}
void initiate_rocket(int x, int y){
	y =38;
	gotoxy(x,(y-1));
	printf("%c",186);
	gotoxy(x,y);
	printf("%c",219);

	fgcolor(1);
	gotoxy(x,(y+1));
	printf("%c",177);
	fgcolor(15);

	gotoxy((x-1),(y+1));
	printf("%c",47);
	gotoxy((x+1),(y+1));
	printf("%c",92);
}
void delete_rocket(int x, int y){
	y = 38;
	gotoxy(x,(y-1));
	printf(" ");
	gotoxy(x,y);
	printf(" ");

	fgcolor(1);
	gotoxy(x,(y+1));
	printf(" ");
	fgcolor(15);

	gotoxy((x-1),(y+1));
	printf(" ");
	gotoxy((x+1),(y+1));
	printf(" ");
}





void initiate_enemies(int x, int y,int color) {
    fgcolor(color);
    gotoxy(x,y);
    printf("%c", 204);
    printf("%c", 219);
    printf("%c", 185);
    fgcolor(15);
}
int globalPoints = 0; //GLOBAL VARIABEL
void points(int points) {
    globalPoints += points;
    gotoxy(70, 43);
    printf("%d", globalPoints);
}

void clear_enemy(int x, int y) {
    gotoxy(x, y);
    printf("   ");
}

struct enemy {
    int x;
    int y;
    int color;
};
struct enemy enemies_level[100];


struct Shot {
    int x;
    int y;
};
struct Shot shots[100];
void addShot(int x, int y) {
    for (int i = 0; i < 100; ++i) {
        if (shots[i].x == 0 && shots[i].y == 0) {
            shots[i].x = x;
            shots[i].y = y;
            break;
        }
    }
}
bool isCollision(int shotX, int shotY, int enemyX, int enemyY) {
    return (shotX == enemyX || shotX == enemyX + 1 || shotX == enemyX + 2) && (shotY == enemyY);
}

void enemies(int speed,int level) {
	int size;
	if (level >= 1 && level <= 9) {
	        size = 10 * level;
	    }
	int pos_y = 2;
	static int amount = 0;
	    if (timer == speed && amount < size) {
	    	enemies_level[amount].x = rand() % 137 + 2;
	    	enemies_level[amount].y = pos_y;
	    	enemies_level[amount].color =rand() % 5 + 1;
	        initiate_enemies(enemies_level[amount].x, enemies_level[amount].y,enemies_level[amount].color);
	        timer = 0;
	        amount++;

	    for (int j = 0; j < amount; j++) {
	    	if (enemies_level[j].y != 39) {
	        if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
	            // Check if enemy is hit by a shot
	            for (int i = 0; i < 100; ++i) {
	                if (shots[i].x != 0 || shots[i].y != 0) {
	                    if (isCollision(shots[i].x, shots[i].y, enemies_level[j].x, enemies_level[j].y)) {
	                        // Shot hit an enemy, clear the enemy
	                        clear_enemy(enemies_level[j].x, enemies_level[j].y);
	                        enemies_level[j].x = 0;
	                        enemies_level[j].y = 0;
	                    }
	                }
	            }

	            // Move and print enemies that are not hit
	            if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
	                clear_enemy(enemies_level[j].x, enemies_level[j].y);
	                enemies_level[j].y++;
	                initiate_enemies(enemies_level[j].x, enemies_level[j].y,enemies_level[j].color);
	            }
	        }
	    }
	    	else {
	    		clear_enemy(enemies_level[j].x, enemies_level[j].y);
	    		enemies_level[j].x = 0;
	    		enemies_level[j].y = 0;
	    		    }
	    }
	        timer = 0;
	    }
	    if (amount == size && timer == speed) {
	    	 for (int j = 0; j < amount; j++) {
	    		 if (enemies_level[j].y != 39) {
	    		        if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
	    		            // Check if enemy is hit by a shot
	    		            for (int i = 0; i < 100; ++i) {
	    		                if (shots[i].x != 0 || shots[i].y != 0) {
	    		                    if (isCollision(shots[i].x, shots[i].y, enemies_level[j].x, enemies_level[j].y)) {
	    		                        // Shot hit an enemy, clear the enemy
	    		                        clear_enemy(enemies_level[j].x, enemies_level[j].y);
	    		                        enemies_level[j].x = 0;
	    		                        enemies_level[j].y = 0;
	    		                    }
	    		                }
	    		            }

	    		            // Move and print enemies that are not hit
	    		            if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {
	    		                clear_enemy(enemies_level[j].x, enemies_level[j].y);
	    		                enemies_level[j].y++;
	    		                initiate_enemies(enemies_level[j].x, enemies_level[j].y,enemies_level[j].color);
	    		            }
	    		        }
	    		    }
	    		 else {
	    		 	    		clear_enemy(enemies_level[j].x, enemies_level[j].y);
	    		 	    		enemies_level[j].x = 0;
	    		 	    		enemies_level[j].y = 0;
	    		 	    		    }
	    		        timer = 0;	   	    }}
	}

void updateAndPrintShots(int pause) {
    for (int i = 0; i < 100; ++i) {
        if (shots[i].x != 0 || shots[i].y != 0) {
            gotoxy(shots[i].x, shots[i].y);
            for (int j = 0; j < 100; ++j) {
                            if (enemies_level[j].x != 0 && enemies_level[j].y != 0 &&
                                isCollision(shots[i].x, shots[i].y, enemies_level[j].x, enemies_level[j].y)) {
                                // Shot hit an enemy, clear the enemy
                            	points(10);
                                clear_enemy(enemies_level[j].x, enemies_level[j].y);
                                enemies_level[j].x = 0;
                                enemies_level[j].y = 0;

                                // Clear the shot
                                printf(" ");
                                shots[i].x = 0;
                                shots[i].y = 0;

                                break;  // No need to check for more collisions
                            }
                        }
            if (shots[i].y > 1) {
                printf("o");
                cursor_left(1);
                cursor_down(1);
                printf(" ");
                --shots[i].y;
            } else {
            	 gotoxy(shots[i].x, ++shots[i].y);
            	 printf(" ");
                shots[i].x = 0;
                shots[i].y = 0;
            }
        }
       pause_control(pause);
	}
}
void initiate_black_hole(int x,int y){
	fgcolor(8);
	gotoxy(x-2,y-1);
	for (int k=0; k <= 4; k++){
		printf("%c",187);
	}
	cursor_down(1);
	cursor_left(6);
	for (int k=0; k <= 6; k++){
		if (k == 0) {
			printf("%c",201);
		}
		else if (k==6){
			printf("%c",188);
		}
		else{
			printf("%c",178);
		}
	}
	cursor_down(1);
	cursor_left(6);
	for (int k=0; k <=4; k++){
		printf("%c",200);
	}
	fgcolor(15);
}


