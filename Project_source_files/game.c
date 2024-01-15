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

struct Score scores[10];
void update_score(long int score) {
    for (int i = 0; i < 10; i++) {
        if (score > scores[i].score_count) {
        	if (i != 9) {
        	scores[i+1].score_count = scores[i].score_count;}
            scores[i].score_count = score;
            score = 0;
            break;
        }
    }
}

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

void points(int points) {
    globalPoints += points;
    gotoxy(70, 43);
    printf("%d", globalPoints);
}

void lives(int damage) {
    globalLives -= damage;
    gotoxy(70, 46);
    printf("Lives left: %d", globalLives);
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
struct Shot oldshots[100];
void addShot(int x, int y) {
    for (int i = 0; i < 100; ++i) {
        if (shots[i].x == 0 && shots[i].y == 0) {
            shots[i].x = x;
            shots[i].y = y;
            break;
        }
    }
}
void prevShot(int x, int y) {
    for (int i = 0; i < 100; ++i) {
        if (oldshots[i].x == 0 && shots[i].y == 0) {
            oldshots[i].x = x;
            oldshots[i].y = y;
            break;
        }
    }
}
bool isCollision(int shotX, int shotY, int enemyX, int enemyY) {
    return (shotX == enemyX || shotX == enemyX + 1 || shotX == enemyX + 2) && (shotY == enemyY);
}
bool isAstroidCollision(int shotX, int shotY, int asteroidX, int asteroidY) {
    return (shotX == asteroidX && shotY == asteroidY);
}
int gravity(int shotX, int shotY, int asteroidX, int asteroidY) {
	for (int i = 0; i < 1; i++){
    if (abs(shotX - asteroidX) <= 8 && abs(shotY - asteroidY) == 0 ) {
        if (shotX < asteroidX) {
            return +1;
        }
        else if (shotX > asteroidX) {
            return -1;
        }
        else {
        	return 0;}}

    else {
            	return 0;}
    }}

void enemies(int speed,int level) {
	lives(0);
	static int amount = 0;
	int size;
		if (level >= 1 && level <= 9) {
		        size = 10 * level;
		    }
		int pos_y = 2;
	if (globalLives != 0) {
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
	    		lives(1);
	    		    }
	    }
	        timer = 0;
	    }
	    if (amount == size && timer == speed) {
	    	 for (int j = 0; j < amount; j++) {
	    		 if (enemies_level[j].y != 39) {
	    		        if (enemies_level[j].x != 0 && enemies_level[j].y != 0) {


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
	    		 	    		lives(1);
	    		 	    		    }
	    		        timer = 0;	   	    }}}
	else {
		for (int i = 0; i< size; i++){enemies_level[i].x = 0;enemies_level[i].y = 0;enemies_level[i].color = 0;}
		amount = 0;
		update_score(globalPoints);
		globalPoints = 0;
		globalLives = 3;
		clearallshots();
		menu();
	}
	}
void clearallshots() {
	for (int j = 0; j <100; j++) {
		shots[j].x = 0;
		shots[j].y = 0;
	}
}
void updateAndPrintShots(int pause, int level) {
	static int once = 0;
	static int enemies = 0;
	int gravityResult;
	if (!once) {
	        enemies = level * 10;
	        once = 1;
	    }

	if (enemies == 0) {
		update_score(globalPoints);
		globalPoints = 0;
		globalLives = 3;
		once = 0;
		clearallshots();
		menu();
	}
	if (globalLives == 0) {
		once = 0;
		clearallshots();
	}
    for (int i = 0; i < 100; ++i) {
    	        if (shots[i].x != 0 || shots[i].y != 0) {
    	        	oldshots[i].x = shots[i].x;
    	        	oldshots[i].y = shots[i].y;
    	        	if (shots[i].y > 2) {
    	        		for (int j = 0; j< 21; j++) {
    	        			if (level > 0) {
    	        			gravityResult = gravity(shots[i].x, shots[i].y, very_small_asteroid1[j].x, very_small_asteroid1[j].y);}
    	    	        			if (level > 1)	{gravityResult +=gravity(shots[i].x, shots[i].y, very_small_asteroid2[j].x, very_small_asteroid2[j].y);}
		    	        			if (level > 2)	{gravityResult +=gravity(shots[i].x, shots[i].y, very_small_asteroid3[j].x, very_small_asteroid3[j].y);}
		    	        			if (level > 3)	{gravityResult +=gravity(shots[i].x, shots[i].y, very_small_asteroid4[j].x, very_small_asteroid4[j].y);}
		    	        			if (level > 4)	{gravityResult +=gravity(shots[i].x, shots[i].y, very_small_asteroid5[j].x, very_small_asteroid5[j].y);}
    	        			    if (gravityResult != 0) {
    	        			        shots[i].x += gravityResult;
    	        			        break;
    	        			    }
    	        		 }
    	        		for (int j = 0; j< 37; j++) {
    	        			if (level > 0) {
    	        			gravityResult = gravity(shots[i].x, shots[i].y, small_asteroid1[j].x, small_asteroid1[j].y);}
    	        			if (level > 1) {gravityResult += gravity(shots[i].x, shots[i].y, small_asteroid2[j].x, small_asteroid2[j].y);}
    	        			if (level > 2) {gravityResult +=gravity(shots[i].x, shots[i].y, small_asteroid3[j].x, small_asteroid3[j].y);}
    	    	        	if (level > 3){gravityResult +=gravity(shots[i].x, shots[i].y, small_asteroid4[j].x, small_asteroid4[j].y);}
    	        			if (level > 4){gravityResult +=gravity(shots[i].x, shots[i].y, small_asteroid5[j].x, small_asteroid5[j].y);}
    	        			    if (gravityResult != 0) {
    	        			        shots[i].x += gravityResult;
    	        			        break;
    	        			    }
    	        		}
    	        		--shots[i].y;
    	        		gotoxy(shots[i].x, shots[i].y);
    	        		printf("o");
    	        		gotoxy(oldshots[i].x, oldshots[i].y);
    	        		printf(" ");
    	        			} else {
    	        				gotoxy(oldshots[i].x, oldshots[i].y);
        	            	 printf(" ");
        	                shots[i].x = 0;
        	                shots[i].y = 0;
        	                oldshots[i].x = 0;
        	                oldshots[i].y = 0;
        	                break;
        	            }

    	        	for (int j = 0; j < 21; ++j) {
    	        		if (level > 0) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, very_small_asteroid1[j].x, very_small_asteroid1[j].y)) {
    	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        printf(" ");
    	        	        shots[i].x = 0;
    	        	        shots[i].y = 0;
    	        	        break;
    	        	    }}
    	        		if (level > 1) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, very_small_asteroid2[j].x, very_small_asteroid2[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        		if (level > 2) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, very_small_asteroid3[j].x, very_small_asteroid3[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        	    if (level > 3) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, very_small_asteroid4[j].x, very_small_asteroid4[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        	    if (level > 4) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, very_small_asteroid5[j].x, very_small_asteroid5[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        	}

    	        	for (int j = 0; j < 37; ++j) {
    	        		if (level > 0) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, small_asteroid1[j].x, small_asteroid1[j].y)) {
    	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        printf(" ");
    	        	        shots[i].x = 0;
    	        	        shots[i].y = 0;
    	        	        break;
    	        	    }}
    	        		if (level > 1) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, small_asteroid2[j].x, small_asteroid2[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        		if (level > 2) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, small_asteroid3[j].x, small_asteroid3[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        		if (level > 3) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, small_asteroid4[j].x, small_asteroid4[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        		if (level > 4) {
    	        	    if (isAstroidCollision(shots[i].x, shots[i].y, small_asteroid5[j].x, small_asteroid5[j].y)) {
    	        	        	        	        gotoxy(shots[i].x, shots[i].y + 1);
    	        	        	        	        printf(" ");
    	        	        	        	        shots[i].x = 0;
    	        	        	        	        shots[i].y = 0;
    	        	        	        	        break;
    	        	        	        	    }}
    	        	}

            for (int loop= 0; loop < 20; loop++) {
            for (int j = 0; j < 90; ++j) {
                            if (enemies_level[j].x != 0 && enemies_level[j].y != 0 &&
                                isCollision(shots[i].x, shots[i].y, enemies_level[j].x, enemies_level[j].y)) {
                                // Shot hit an enemy, clear the enemy
                            	if (enemies_level[j].color == 1) {
                            	points(2);
                            	enemies -= 1;

                            	}
                            	if (enemies_level[j].color == 2) {
                            	                            	points(4);
                            	                            	enemies -= 1;

                            	                            	}
                            	if (enemies_level[j].color == 3) {
                            	                            	points(6);
                            	                            	enemies -= 1;

                            	                            	}
                            	if (enemies_level[j].color == 4) {
                            	                            	points(8);
                            	                            	enemies -= 1;

                            	                            	}
                            	if (enemies_level[j].color == 5) {
                            	                            	points(10);
                            	                            	enemies -= 1;

                            	                            	}
                            	clear_enemy(enemies_level[j].x, enemies_level[j].y);
                            	enemies_level[j].x = 0;
                            	enemies_level[j].y = 0;



                                // Clear the shot
                                gotoxy(shots[i].x,shots[i].y+1);
                                printf(" ");
                                shots[i].x = 0;
                                shots[i].y = 0;
                                  // No need to check for more collisions
                            }}
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
}
}
