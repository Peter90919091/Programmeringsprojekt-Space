int ScoreControls() {
	int value = 0;
	while(1) {value = Joystickport();
	if (value == 16) {menu();}
	}
}
int HelpControls() {
	int value = 0;
	while(1) {value = Joystickport();
	if (value == 16) {menu();}
	}
}
int MenuControls() {
	int cursor_placement = 0;

	while(1) {
	int value = Joystickport();
	if (value == 1 || value == 5 || value== 9 || value == 17 || value == 21 || value == 25) { //UP
		if (cursor_placement> 0) {cursor_placement -= 1;}
	}
	if (value == 2 || value == 6 || value == 10 || value == 18 || value == 22 || value == 26) { //DOWN
		if (cursor_placement< 2) {cursor_placement += 1;}
	}
	if (value == 16 && cursor_placement == 0)  { //HELP
		ClearScreen();
		return 1;
	}
	if (value == 16 && cursor_placement == 1)  { //SCORE
		ClearScreen();
		return 2;
		}
	if (value == 16 && cursor_placement == 2)  { //PLAY
		ClearScreen();
				return 3;
		}

	if (cursor_placement == 0) {
		gotoxy(62,17);
		blink(1);
		fgcolor(1);
		write_help();
		fgcolor(7);
			blink(0);
		gotoxy(60,23);
		write_score();
		gotoxy(63,29);
		write_play();
	}
	if (cursor_placement == 1) {
			gotoxy(62,17);
			write_help();
			gotoxy(60,23);
			blink(1);
			fgcolor(1);
			write_score();
			fgcolor(7);
				blink(0);
			gotoxy(63,29);
			write_play();
	}
	if (cursor_placement == 2) {
			gotoxy(62,17);
			write_help();
			gotoxy(60,23);
			write_score();
			gotoxy(63,29);
			blink(1);
			fgcolor(1);
			write_play();
			fgcolor(7);
				blink(0);
		}
	}
}
