int HelpControls() {
	int value = 0;
	while(1) {
		value = Joystickport();
		if (value == 16) {
			menu();
		}
	}
}

void menuHELP() {
	background();
	border();
	printf("THIS IS HELP WINDOW");
	HelpControls();
}
