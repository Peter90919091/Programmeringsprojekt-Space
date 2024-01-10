int main(void) {
	uart_init(9600);
	hideCursor();
	blink(0);
	ClearScreen();
	menu();

	//MenuControls();
	while (1) {
	}
	return 0;
}
