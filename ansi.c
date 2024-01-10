#define ESC 0x1B
void gotoxy(int x, int y) {
	printf("%c[%d;%d%c",ESC,y,x,'H');
}
void ClearScreen(){
	printf("%c[2J",ESC);
	gotoxy(0,0);
}
// Move cursor
void cursor_up(int amount) {
	printf("%c[%d%c",ESC,amount,'A');
}
void cursor_down(int amount) {
	printf("%c[%d%c",ESC,amount,'B');
}
void cursor_right(int amount) {
	printf("%c[%d%c",ESC,amount,'C');
}
void cursor_left(int amount) {
	printf("%c[%d%c",ESC,amount,'D');
}
