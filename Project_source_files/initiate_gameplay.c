#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include "stdint.h"
#include "Header_file.h"



void initiate_rocket(int x, int y){
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


void initiate_enemies(int x, int y) {
    fgcolor(1);
    gotoxy(x,y);
    printf("%c", 204);
    printf("%c", 219);
    printf("%c", 185);
    fgcolor(15);
}

void clear_enemy(int x, int y) {
    gotoxy(x, y);
    printf("   ");
}


void config_timer() {
    RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
    TIM15->CR1 |= 0x01; // Enable timer 15
    TIM15->ARR = 10000; // Set reload value
    TIM15->PSC = 1000; // Set prescale value
    TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
    NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0); // Set interrupt priority
    NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn); // Enable interrupt
}

void TIM1_BRK_TIM15_IRQHandler(void) {
    timer++;
    TIM15->SR &= ~0x0001; // Clear interrupt bit
}


void enemies_down(int total_enemies[][2], int size) {
    for (int j = 0; j < size; j++) {
        clear_enemy(total_enemies[j][0], total_enemies[j][1]);
        total_enemies[j][1]++;
        initiate_enemies(total_enemies[j][0], total_enemies[j][1]);
    }
}
void enemies() {
    static int total_enemies[10][2];
    static int i = 0;
    int init_pos_y = 0;

    if (timer == 10) {
        total_enemies[i][0] = rand()% 71;
        total_enemies[i][1] = init_pos_y;
        initiate_enemies(total_enemies[i][0], total_enemies[i][1]);

        timer = 0;
        i++;
        enemies_down(total_enemies, i);
    }
}
