/*
 * design.c
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
void text_color_blink(int on) {
	if (on == 1) {
		blink(1);
		fgcolor(1);
	}
	else if (on != 1) {
		blink(0);
		fgcolor(7);
	}
}
void hideCursor() {printf("\e[?25l");}
void credits() {
	gotoxy(2,39);
	printf("Lavet af Mattias, Ida, Emil & Peter");
}
void border() {
	fgcolor(7);
	// 140x40
			//Værdier vi benytter:
			int  toplength = 138; //trukket 2 fra for at have hjørner med
			int  sidelength = 40;
			int  bottomlength = 138;
			gotoxy(0,0);
			//toppen
			printf("%c",201);
			for (int j = 0; j <= (toplength); j++) {
				printf("%c",205);
			}
			printf("%c",187);
			//Sider
			for (int i = 2; i< sidelength;i++) {
				gotoxy(0,i);
				printf("%c",186);
				gotoxy(141,i);
				printf("%c",186);
			}
			//bund
			gotoxy(1,40);
			printf("%c",200);
			for (int j = 0; j <= (toplength); j++) {
							printf("%c",205);
						}
			printf("%c",188);
}
void game_border() {
	fgcolor(7);
	// 140x40
			//Værdier vi benytter:
			int  toplength = 138; //trukket 2 fra for at have hjørner med
			int  sidelength = 40;
			int  bottomlength = 138;
			gotoxy(0,0);
			//toppen
			printf("%c",201);
			for (int j = 0; j <= (toplength)/4 - 1; j++) {
				printf("%c",205);
			}
			printf("%c",203);
			for (int j = 0; j <= (toplength)/2-1; j++) {
							printf("%c",205);
						}
			printf("%c",203);
						for (int j = 0; j <= (toplength)/4 - 1; j++) {
										printf("%c",205);
									}
			printf("%c",187);
			//Sider
			for (int i = 2; i< sidelength;i++) {
				gotoxy(toplength/4+2,i);
				printf("%c",186);
				gotoxy(toplength/4+toplength/2+3,i);
				printf("%c",186);
			}
			for (int i = 2; i< sidelength;i++) {
							gotoxy(0,i);
							printf("%c",186);
							gotoxy(141,i);
							printf("%c",186);
						}
			//bund
			gotoxy(1,40);
			printf("%c",200);
						for (int j = 0; j <= (toplength)/4 - 1; j++) {
							printf("%c",205);
						}
						printf("%c",202);
						for (int j = 0; j <= (toplength)/2-1; j++) {
										printf("%c",205);
									}
						printf("%c",202);
									for (int j = 0; j <= (toplength)/4 - 1; j++) {
													printf("%c",205);
												}
			printf("%c",188);
}

void background() {
	fgcolor(7);
	printf("\n");
	printf("                                                                                                                                             \n");
	printf("                                                     *     *                                 *                        *                      \n");
	printf("          *           *     *  *                                                      *                             *                        \n");
	printf("            *           * *     *                   *                                                                                *       \n");
	printf("                *                         *                                                                                                  \n");
	printf("                                                                *                                              *                             \n");
	printf("                           * *                                              *    *        *          *               *                       \n");
	printf("     *                                                                               *                                                       \n");
	printf("             *       *                            *                                                                       *                  \n");
	printf("                                                                                                                   **  *                     \n");
	printf("         **        *         *    *                          *                                  ***    *                         *           \n");
	printf("                                    *                           *                     *                                 *           **       \n");
	printf("                          **  **                                                                  *                                          \n");
	printf("                                                                                *                                *                           \n");
	printf("           *                        *    *            *                       *                           *                     *            \n");
	printf("                 *                                       *              *                 *                                                  \n");
	printf("                                               *  *                                       *      *           *         *    *                \n");
	printf("                                                                                         *                             **                    \n");
	printf("                     *                                         *   *         *           *    *                    *     *                   \n");
	printf("             *         *                    *             * *                   *                                                            \n");
	printf("       *                      *                                * *  **  *            *                *                  *                   \n");
	printf("                 *                                                                *                                *           *      *      \n");
	printf("                *            *         *         *            *                                                                              \n");
	printf("             *                                                                                                                               \n");
	printf("                                                        *                                                                                    \n");
	printf("       *                                  **           *                                                                              *      \n");
	printf("                         *         *                          *   *                             *              *   *                         \n");
	printf("            * *          *                        *                 *        *   *                                                           \n");
	printf("                                  *                         *                             *     *                                            \n");
	printf("               *          *                                        *          *  *                                                   *       \n");
	printf("                                  **    *         *                                     *                                  *                 \n");
	printf("                                          *                        *                                                                         \n");
	printf("             *         *  * *         *      *  *        **                                              *   *     *              *          \n");
	printf("             *          *                *  *    *                 *         *      *                                                     *  \n");
	printf("                     *                               *                                 *        *                                            \n");
	printf("                                                                 *       *            *           *                                          \n");
	printf("            *        *                         *                * *                           *                        *       *             \n");
	printf("                    *            *   *                       *   *                        *                                                  \n");
/*

    int x_value = 0; // Initialize x_value
    int y_value = 0; // Initialize y_value
    int range = 140; // Calculate the range

        srand(123); // Set a constant seed for the random number generator
        for (int antal_stjerner = 0; antal_stjerner < 200; antal_stjerner++) {
            // Generate a random number within the specified range
        int random_number = (rand() % range) + 40;
        // Add random number to x_value and y_value
        x_value += random_number;
        y_value += random_number;

        // Adjust x_value and y_value based on conditions
        while (x_value < 2) {
            x_value += 10;
        }
        while (y_value < 2) {
            y_value += 10;
        }
        while (x_value > 139) {
            x_value -= 137;
        }
        while (y_value > 39) {
            y_value -= 37;
        }

        // Print asterisk at the computed position
        gotoxy(x_value, y_value);
        printf("%c", '*');
    }
    */
}
void menubox() {
	// 140x40
				//Værdier vi benytter:
				int  toplength = 51; //trukket 2 fra for at have hjørner med
				int  sidelength = 39;
				int  bottomlength = 45;
				gotoxy(45,9);
				//toppen
				printf("%c",201);
				for (int j = 0; j <= (toplength); j++) {
					printf("%c",205);
				}
				printf("%c",187);
				//Sider
				for (int i = 10; i< sidelength;i++) {
					gotoxy(45,i);
					printf("%c",186);
					gotoxy(98,i);
					printf("%c",186);
				}
				//bund
				gotoxy(45,39);
				printf("%c",200);
				for (int j = 0; j <= (toplength); j++) {
								printf("%c",205);
							}
				printf("%c",188);
				gotoxy(60,10);
				write_menu();
}
void box() {
	//Værdier vi benytter:
					int  toplength = 51; //trukket 2 fra for at have hjørner med
					int  sidelength = 39;
					int  bottomlength = 45;
					gotoxy(45,9);
					//toppen
					printf("%c",201);
					for (int j = 0; j <= (toplength); j++) {
						printf("%c",205);
					}
					printf("%c",187);
					//Sider
					for (int i = 10; i< sidelength;i++) {
						gotoxy(45,i);
						printf("%c",186);
						gotoxy(98,i);
						printf("%c",186);
					}
					//bund
					gotoxy(45,39);
					printf("%c",200);
					for (int j = 0; j <= (toplength); j++) {
									printf("%c",205);
								}
					printf("%c",188);
					gotoxy(60,10);
}
void Smallbox() {
	//Værdier vi benytter:
					int  toplength = 8; //trukket 2 fra for at have hjørner med
					int  sidelength = 5;
					int  bottomlength = 8;
					//toppen
					printf("%c",201);
					for (int j = 0; j <= (toplength); j++) {
						printf("%c",205);
					}
					printf("%c",187);
					cursor_down(1);
					cursor_left(1);
					//Sider
					for (int i = 0; i< sidelength;i++) {
						printf("%c",186);
						cursor_left(11);
						printf("%c",186);
						cursor_down(1);
						cursor_right(9);
					}
					//bund
					cursor_left(10);
					printf("%c",200);
					for (int j = 0; j <= (toplength); j++) {
									printf("%c",205);
								}
					printf("%c",188);
}
void help_design() {
	box();
	gotoxy(47,18);
	printf("Move the spaceship right or left using joystick");
	gotoxy(47,23);
	printf("Avoid obstacles");
	asteroid(55,25);

}

int big_asteroid(){
	fgcolor(3);
    printf("      .-\"\"\"\"\"\"-.\n");
    printf("    .-'   ()       '-.\n");
    printf("   .'          O       '.\n");
    printf(" /   O      .    ()       \\\n");
    printf(":           .           o  :\n");
    printf(" :  .   ()   .      '    :\n");
    printf("  \\           .    .    /\n");
    printf("   '.()   O        o  .'\n");
    printf("       '-.______ _.-'\n");
}


int small_asteroid(){
	fgcolor(3);
    printf("    .- .\"\"_.    \n");
    printf(" .  .   o     :  \n");
    printf("/     .  () .   \\ \n");
    printf(".  ()      o    :\n");
    printf(".   o  '  .    :\n");
    printf("\\    ( ) .  o  /\n");
    printf("  :  .        . \n");
    printf("   \ () __.. /  \n");
}
