void menuHELP() {
	background();
	border();
	box();
	write_help_header();
	write_exit();
	HelpControls();

}
void menuPLAY() {
	background();
	border();
	initialize(3000000);

}
void menuSCORE() {
	background();
	border();
	write_score_header();
	box();
	write_exit();
	ScoreControls();
}
void menu() {
	ClearScreen();
	background(); //FØRST
	border();
	write_Welcome();
	menubox();
	credits();
	int value = MenuControls();
	if (value == 1) {
				menuHELP();
			}
	if (value == 2) {
		menuSCORE();

	}
	if (value == 3) {
		menuPLAY();
		}
}

