#include "Header_file.h"
int main(void) {
	uart_init(115200);
	lcd_init();
	config_timer();
	hideCursor();
	blink(0);
	ClearScreen();
	//MenuControls();
	while (1) {
		//menu();
		ChooseUserInput();
		//gotoxy(2,0);
		//uint8_t value = readKeyboard();
		//printf("%c",value);
		//ChooseUserInput();

	}
	return 0;
}
