void hideCursor() {
    printf("\e[?25l"); // ANSI escape code to hide cursor
}

uint16_t Joystickport(){
// PA4 UP
RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A PA0 = 110
GPIOA->MODER &= ~(0x00000003 << (4 * 2)); 
GPIOA->MODER |= (0x00000000 << (4 * 2));
GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); 
GPIOA->PUPDR |= (0x00000002 << (4 * 2));
uint16_t val_UP = GPIOA->IDR & (0x0001 << 4); 
if (val_UP != 0) {
	val_UP=1;
}
// PB0 DOWN
RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port A PA0 = 110
GPIOB->MODER &= ~(0x00000003 << (0 * 2)); 
GPIOB->MODER |= (0x00000000 << (0 * 2));
GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); 
GPIOB->PUPDR |= (0x00000002 << (0 * 2)); 
uint16_t val_DOWN = GPIOB->IDR & (0x0001 << 0); //Read from pin PA0
if (val_DOWN != 0) {
	val_DOWN=1;
}
// PC0 RIGHT
RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A PA0 = 110
GPIOC->MODER &= ~(0x00000003 << (0 * 2));
GPIOC->MODER |= (0x00000000 << (0 * 2));
GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); 
GPIOC->PUPDR |= (0x00000002 << (0 * 2));
uint16_t val_RIGHT = GPIOC->IDR & (0x0001 << 0); 
if (val_RIGHT != 0) {
	val_RIGHT=1;
}
// PC1 LEFT
RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A PA0 = 110
GPIOC->MODER &= ~(0x00000003 << (1 * 2)); 
GPIOC->MODER |= (0x00000000 << (1 * 2));
GPIOC->PUPDR &= ~(0x00000003 << (1 * 2));
GPIOC->PUPDR |= (0x00000002 << (1 * 2)); 
uint16_t val_LEFT = GPIOC->IDR & (0x0001 << 1); 
if (val_LEFT != 0) {
	val_LEFT=1;
}
// PB5 CENTER
RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port A PA0 = 110
GPIOB->MODER &= ~(0x00000003 << (5 * 2));
GPIOB->MODER |= (0x00000000 << (5 * 2));
GPIOB->PUPDR &= ~(0x00000003 << (5 * 2));
GPIOB->PUPDR |= (0x00000002 << (1 * 2));
uint16_t val_CENTER = GPIOB->IDR & (0x0001 << 5);
if (val_CENTER != 0) {
	 val_CENTER=1;
}
int all_bits = val_CENTER + val_RIGHT + val_LEFT + val_UP + val_DOWN;
if (all_bits != 0) {
uint8_t bit[8] = {0,0,0,val_CENTER,val_RIGHT,val_LEFT,val_DOWN,val_UP};
    uint8_t result = 0;

    for (int i = 0; i < 8; i++) {
        result = (result << 1) | bit[i];
    }delay_ms(2000000);
    return result;
}
}
