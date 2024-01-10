void border() {
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
void background() {
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
				int  sidelength = 35;
				int  bottomlength = 45;
				gotoxy(45,12);
				//toppen
				printf("%c",201);
				for (int j = 0; j <= (toplength); j++) {
					printf("%c",205);
				}
				printf("%c",187);
				//Sider
				for (int i = 13; i< sidelength;i++) {
					gotoxy(45,i);
					printf("%c",186);
					gotoxy(98,i);
					printf("%c",186);
				}
				//bund
				gotoxy(45,35);
				printf("%c",200);
				for (int j = 0; j <= (toplength); j++) {
								printf("%c",205);
							}
				printf("%c",188);
}
void menu() {
	background(); //FØRST
	border();
	menubox();
	credits();
}
