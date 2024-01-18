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


void pause_control(int time_between) {
	int first = 0;
	while (first < time_between) {first += 1;}
}
void points(int points) {
    globalPoints += points;
}
void lives(int damage) {
    globalLives -= damage;
}
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
bool isCollision(struct vector_t shot_values, struct enemy enemy_values) {
    return (shot_values.x == enemy_values.x || shot_values.x == enemy_values.x + 1 || shot_values.x == enemy_values.x + 2) && (shot_values.y == enemy_values.y);
}
bool isCollisionHole(struct vector_t shot_values, struct vector_t hole) {
    return (shot_values.x == hole.x  && shot_values.y == hole.y);
}

bool isAstroidCollision(struct vector_t shot_values, struct vector_t asteroid_values) {
    return (shot_values.x == asteroid_values.x && shot_values.y == asteroid_values.y);
}
int gravity(struct vector_t shot_values, struct vector_t asteroid_values) {
    if (abs(shot_values.x - asteroid_values.x) <= 8 && shot_values.y == asteroid_values.y) {
        if (shot_values.x < asteroid_values.x) {
            return +1;
        } else if (shot_values.x > asteroid_values.x) {
            return -1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
