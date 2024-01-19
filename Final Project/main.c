#include "Header_file.h"
int main(void) {
	uart_init(115200);
	lcd_init();
	config_timer();
	initim2();
	hideCursor();
	blink(0);
	ClearScreen();
	setFreq(0);
	
	while (1) {
		ChooseUserInput();
	}
	return 0;
}
