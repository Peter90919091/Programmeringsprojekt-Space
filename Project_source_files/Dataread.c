#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include "system_stm32f30x.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Header_file.h"
uint16_t Joystickport(){
// PA4 UP
RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A PA0 = 110
GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
GPIOA->MODER |= (0x00000000 << (4 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
GPIOA->PUPDR |= (0x00000002 << (4 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_UP = GPIOA->IDR & (0x0001 << 4); //Read from pin PA0
if (val_UP != 0) {
	val_UP=1;
}
// PB0 DOWN
RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port A PA0 = 110
GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
GPIOB->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
GPIOB->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_DOWN = GPIOB->IDR & (0x0001 << 0); //Read from pin PA0
if (val_DOWN != 0) {
	val_DOWN=1;
}
// PC0 RIGHT
RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A PA0 = 110
GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
GPIOC->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
GPIOC->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_RIGHT = GPIOC->IDR & (0x0001 << 0); //Read from pin PA0
if (val_RIGHT != 0) {
	val_RIGHT=1;
}
// PC1 LEFT
RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A PA0 = 110
GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
GPIOC->MODER |= (0x00000000 << (1 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
GPIOC->PUPDR |= (0x00000002 << (1 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
uint16_t val_LEFT = GPIOC->IDR & (0x0001 << 1); //Read from pin PA0
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
    }
    return result;
	}
	return 0;
}


// Function to push buffer to LCD (assuming this function is already defined)
const char character_data[95][5] = {
  {0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x5F, 0x5F, 0x00, 0x00},
  {0x00, 0x07, 0x00, 0x07, 0x00},
  {0x14, 0x7F, 0x14, 0x7F, 0x14},
  {0x24, 0x2A, 0x7F, 0x2A, 0x12},
  {0x23, 0x13, 0x08, 0x64, 0x62},
  {0x36, 0x49, 0x55, 0x22, 0x50},
  {0x00, 0x05, 0x03, 0x00, 0x00},
  {0x00, 0x1C, 0x22, 0x41, 0x00},
  {0x00, 0x41, 0x22, 0x1C, 0x00},
  {0x14, 0x08, 0x3E, 0x08, 0x14},
  {0x08, 0x08, 0x3E, 0x08, 0x08},
  {0x00, 0x50, 0x30, 0x00, 0x00},
  {0x08, 0x08, 0x08, 0x08, 0x08},
  {0x00, 0x60, 0x60, 0x00, 0x00},
  {0x20, 0x10, 0x08, 0x04, 0x02},
  {0x3E, 0x51, 0x49, 0x45, 0x3E},
  {0x00, 0x42, 0x7F, 0x40, 0x00},
  {0x42, 0x61, 0x51, 0x49, 0x46},
  {0x22, 0x49, 0x49, 0x49, 0x36},
  {0x18, 0x14, 0x12, 0x7F, 0x10},
  {0x2F, 0x49, 0x49, 0x49, 0x31},
  {0x3E, 0x49, 0x49, 0x49, 0x32},
  {0x03, 0x01, 0x71, 0x09, 0x07},
  {0x36, 0x49, 0x49, 0x49, 0x36},
  {0x26, 0x49, 0x49, 0x49, 0x3E},
  {0x00, 0x36, 0x36, 0x00, 0x00},
  {0x00, 0x56, 0x36, 0x00, 0x00},
  {0x08, 0x14, 0x22, 0x41, 0x00},
  {0x14, 0x14, 0x14, 0x14, 0x14},
  {0x00, 0x41, 0x22, 0x14, 0x08},
  {0x02, 0x01, 0x51, 0x09, 0x06},
  {0x32, 0x49, 0x79, 0x41, 0x3E},
  {0x7C, 0x0A, 0x09, 0x0A, 0x7C},
  {0x7F, 0x49, 0x49, 0x49, 0x36},
  {0x3E, 0x41, 0x41, 0x41, 0x22},
  {0x7F, 0x41, 0x41, 0x41, 0x3E},
  {0x7F, 0x49, 0x49, 0x49, 0x41},
  {0x7F, 0x09, 0x09, 0x09, 0x01},
  {0x3E, 0x41, 0x49, 0x49, 0x7A},
  {0x7F, 0x08, 0x08, 0x08, 0x7F},
  {0x00, 0x41, 0x7F, 0x41, 0x00},
  {0x30, 0x40, 0x40, 0x40, 0x3F},
  {0x7F, 0x08, 0x14, 0x22, 0x41},
  {0x7F, 0x40, 0x40, 0x40, 0x40},
  {0x7F, 0x02, 0x0C, 0x02, 0x7F},
  {0x7F, 0x02, 0x04, 0x08, 0x7F},
  {0x3E, 0x41, 0x41, 0x41, 0x3E},
  {0x7F, 0x09, 0x09, 0x09, 0x06},
  {0x3E, 0x41, 0x51, 0x21, 0x5E},
  {0x7F, 0x09, 0x09, 0x09, 0x76},
  {0x26, 0x49, 0x49, 0x49, 0x32},
  {0x01, 0x01, 0x7F, 0x01, 0x01},
  {0x3F, 0x40, 0x40, 0x40, 0x3F},
  {0x1F, 0x20, 0x40, 0x20, 0x1F},
  {0x3F, 0x40, 0x38, 0x40, 0x3F},
  {0x63, 0x14, 0x08, 0x14, 0x63},
  {0x03, 0x04, 0x78, 0x04, 0x03},
  {0x61, 0x51, 0x49, 0x45, 0x43},
  {0x7F, 0x41, 0x41, 0x00, 0x00},
  {0x02, 0x04, 0x08, 0x10, 0x20},
  {0x00, 0x41, 0x41, 0x7F, 0x00},
  {0x04, 0x02, 0x01, 0x02, 0x04},
  {0x40, 0x40, 0x40, 0x40, 0x40},
  {0x00, 0x01, 0x02, 0x04, 0x00},
  {0x20, 0x54, 0x54, 0x54, 0x78},
  {0x7F, 0x48, 0x44, 0x44, 0x38},
  {0x38, 0x44, 0x44, 0x44, 0x20},
  {0x38, 0x44, 0x44, 0x48, 0x7F},
  {0x38, 0x54, 0x54, 0x54, 0x18},
  {0x08, 0x7E, 0x09, 0x01, 0x02},
  {0x0C, 0x52, 0x52, 0x52, 0x3E},
  {0x7F, 0x08, 0x04, 0x04, 0x78},
  {0x00, 0x44, 0x7D, 0x40, 0x00},
  {0x20, 0x40, 0x44, 0x3D, 0x00},
  {0x7F, 0x10, 0x28, 0x44, 0x00},
  {0x00, 0x41, 0x7F, 0x40, 0x00},
  {0x7C, 0x04, 0x18, 0x04, 0x78},
  {0x7C, 0x08, 0x04, 0x04, 0x78},
  {0x38, 0x44, 0x44, 0x44, 0x38},
  {0x7C, 0x14, 0x14, 0x14, 0x08},
  {0x08, 0x14, 0x14, 0x18, 0x7C},
  {0x7C, 0x08, 0x04, 0x04, 0x08},
  {0x48, 0x54, 0x54, 0x54, 0x20},
  {0x04, 0x3F, 0x44, 0x40, 0x20},
  {0x3C, 0x40, 0x40, 0x20, 0x7C},
  {0x1C, 0x20, 0x40, 0x20, 0x1C},
  {0x3C, 0x40, 0x38, 0x40, 0x3C},
  {0x44, 0x28, 0x10, 0x28, 0x44},
  {0x0C, 0x50, 0x50, 0x50, 0x3C},
  {0x44, 0x64, 0x54, 0x4C, 0x44},
  {0x00, 0x08, 0x36, 0x41, 0x00},
  {0x00, 0x00, 0x7F, 0x00, 0x00},
  {0x00, 0x41, 0x36, 0x08, 0x00},
  {0x08, 0x04, 0x08, 0x10, 0x08}};
// Function to write a string to the LCD

// Function to write a string to the LCD on a specified line
void lcd_resetwrite(const char* input_string, int line_number) {
    // Ensure that the line_number is within a valid range (adjust as needed)
    if (line_number < 1 || line_number > 4) {
        // Handle error or choose a default line
        return;
    }

    // Set the cursor position based on the line_number

    // Create a buffer to store the pixel data for the string
    uint8_t buffer[512]; // Adjust the buffer size based on your LCD resolution
    memset(buffer,0x00,512);

    // Initialize the buffer with zeros
    for (int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = 0x00;
    }

    // Calculate the starting index based on the line_number
    int buffer_index = (line_number - 1) * 128;

    // Iterate through each character in the input string
    while (*input_string) {
        // Find the index of the character in the character_data array
        int char_index = *input_string - 32; // Assuming ASCII characters starting from space (32)

        // Copy the character data to the buffer
        for (int i = 0; i < 5; i++) {
            buffer[buffer_index++] = character_data[char_index][i];
        }

        // Add a space between characters
        buffer[buffer_index++] = 0x00;

        // Move to the next character in the input string
        input_string++;
    }

    // Push the buffer to the LCD
    lcd_push_buffer(buffer);
}

void lcd_write_index(const char* input_string, int line_number, int index) {
	// Ensure that the line_number is within a valid range (adjust as needed)
		    if (line_number < 1 || line_number > 4) {
		        // Handle error or choose a default line
		        return;
		    }

		    // Set the cursor position based on the line_number

		    // Create a buffer to store the pixel data for the string
		    uint8_t buffer[512]; // Adjust the buffer size based on your LCD resolution

		    // Initialize the buffer with zeros
		    for (int i = 0; i < sizeof(buffer); i++) {
		    	if (buffer[i] != 0) {;}
		    	else {
		    		buffer[i] = 0x00;
		    }

		    // Calculate the starting index based on the line_number
		    int buffer_index = (line_number - 1) * 128+index;

		    // Iterate through each character in the input string
		    while (*input_string) {
		        // Find the index of the character in the character_data array
		        int char_index = *input_string - 32; // Assuming ASCII characters starting from space (32)

		        // Copy the character data to the buffer
		        for (int i = 0; i < 5; i++) {
		            buffer[buffer_index++] = character_data[char_index][i];
		        }

		        // Add a space between characters
		        buffer[buffer_index++] = 0x00;

		        // Move to the next character in the input string
		        input_string++;
		    }

		    // Push the buffer to the LCD
		    lcd_push_buffer(buffer);
		}

void lcd_write_array(uint8_t array[], int line_number, int index, int size) {
    if (line_number < 1 || line_number > 4) {
        // Handle error or choose a default line
        return;
    }

    // Initialize buffer of 512 bytes
    uint8_t bufferarray[512];

    // Preserve the existing contents of the buffer
    for (int i = 0; i < sizeof(bufferarray); i++) {
        // You may want to add logic here to check if the buffer[i] is not part of the existing content
        if (bufferarray[i] != 0) {
            ;
        }
        else {
            bufferarray[i] = 0x00;
        }
    }

    // Calculate the starting index based on the line_number and index
    int buffer_index = (line_number - 1) * 128 + index;

    // Add the new array to the buffer
    for (int i = 0; i < size; i++) {
        bufferarray[buffer_index++] = array[i];
    }



    // Push the buffer to the LCD
    lcd_push_buffer(bufferarray);
}

void write_heart(int line_number, int index) {
	uint8_t heartl1[17] ={0x38,0x7C,0xFE,0xFF,0xFF,0xFF,0xFE,0xFC,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFE,0x7C,0x38};
	uint8_t heartl2[11]= {0x01,0x03,0x07,0x0F,0x01F,0x3F,0x1F,0x0F,0x07,0x03,0x01};
	lcd_write_array(heartl1,line_number,index,17);
	lcd_write_array(heartl2,line_number+1,index+3,11);
}

void clear_line(int line_number) {
	 if (line_number < 1 || line_number > 4) {
	        // Handle error or choose a default line
	        return;
	    }
	 uint8_t bufferclear[512];
	 int buffer_index = (line_number - 1)*128;
	 for (int i =0 ; i<sizeof(bufferclear); i++) {
	         // You may want to add logic here to check if the buffer[i] is not part of the existing content
	         if (bufferclear[i] != 0) {
	             ;
	         }
	         else {
	             bufferclear[i] = 0x00;
	         }
	     }
	 for (int i = 0; i < 128; i++) {
	         bufferclear[buffer_index++] = 0x00;
	     }
	 for (int i = 0; i< 50;i++) {
		 printf("%d\n", bufferclear[i]);
	 }
	 lcd_push_buffer(bufferclear);
}














