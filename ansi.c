void gotoxy(int x, int y) {
	printf("%c[%d;%d%c",ESC,y,x,'H');
}
