#include "device.h"

/*******************************************************************************
**** CUBEMX ****
	Connectivity   ---->  I2C1
		COnfiguration --> default
		GPIO PB6 -> SCL					// los pines dependen del i2c ocupado
		GPIO PB7 -> SDA
		
		
**** KEIL V5 **** 
 **** Agregar en main.c ****
 
 Private includes ----------------------------------------------------------
 	USER CODE BEGIN Includes 
 	#include <i2c-lcd.h>
 	#include <stdio.h>
 
 
 USER CODE BEGIN PV 
  I2C_HandleTypeDef I2C_LCD;
  
  char Linea_1[20] 	= "STM32F START LCD";
  char Linea_2[20] 	= "                ";
  char Linea[20] 		= "                "; 
 
  
  
 USER CODE BEGIN 2
  HAL_TIM_Base_Start_IT(&htim1);
  I2C_LCD = hi2c1 o hi2c2 o hi2c3;								// Depende i2c seleccionado. 
  lcd_init();
  lcd_send_string_file ( File_1, Linea_1 );
  lcd_send_string_file ( File_2, Linea_2 );  
 

		
 **** Ejemplo / Ocupar en while (1) / USER CODE BEGIN 3 ****	
 
	int contador = 0;
	sprintf( Linea, "Contador: %d     ", contador++ );
	lcd_send_string_file ( File_2, Linea );

	lcd_send_string_file ( File_1, "Titulo" );

	... etc.

*******************************************************************************/

/** Instructions bit location (SEGÚN DATO DATASHEED)--------------------------*/
#define LCD16X2_CLEAR_DISPLAY						0x01
#define LCD16X2_CURSOR_HOME						0x02
#define LCD16X2_CHARACTER_ENTRY_MODE			0x04
#define LCD16X2_DISPLAY_CURSOR_ON_OFF			0x08
#define LCD16X2_DISPLAY_CURSOR_SHIFT 			0x10
#define LCD16X2_FUNCTION_SET						0x20
#define LCD16X2_SET_CGRAM_ADDRESS	 			0x40
#define LCD16X2_SET_DDRAM_ADDRESS	 			0x80
/* Character entry mode instructions */
#define LCD16X2_INCREMENT							0x02	// Initialization setting
#define LCD16X2_DECREMENT							0x00
#define LCD16X2_DISPLAY_SHIFT_ON					0x01
#define LCD16X2_DISPLAY_SHIFT_OFF				0x00	// Initialization setting
/* Display cursor on off instructions */
#define LCD16X2_DISPLAY_ON	 						0x04
#define LCD16X2_DISPLAY_OFF	 					0x00	// Initialization setting
#define LCD16X2_CURSOR_UNDERLINE_ON	 			0x02
#define LCD16X2_CURSOR_UNDERLINE_OFF			0x00	// Initialization setting
#define LCD16X2_CURSOR_BLINK_ON	 				0x01
#define LCD16X2_CURSOR_BLINK_OFF	 				0x00	// Initialization setting
/* Display cursor shift instructions */
#define LCD16X2_DISPLAY_SHIFT						0x08
#define LCD16X2_CURSOR_MOVE						0x00
#define LCD16X2_RIGHT_SHIFT						0x04
#define LCD16X2_LEFT_SHIFT							0x00
/* Function set instructions */
#define LCD16X2_8BIT_INTERFACE					0x10	// Initialization setting
#define LCD16X2_4BIT_INTERFACE					0x00
#define LCD16X2_2LINE_MODE							0x08
#define LCD16X2_1LINE_MODE							0x00	// Initialization setting
#define LCD16X2_5X10DOT_FORMAT					0x04
#define LCD16X2_5X7DOT_FORMAT						0x00	// Initialization setting
/* Busy flag bit location */
#define LCD16X2_BUSY_FLAG							0x80

/** LCD display and cursor attributes (SEGÚN DATO DATASHEED)----------------- */
#define LCD16X2_DISPLAY_OFF_CURSOR_OFF_BLINK_OFF	(LCD16X2_DISPLAY_OFF | \
	LCD16X2_CURSOR_UNDERLINE_OFF | LCD16X2_CURSOR_BLINK_OFF)
#define LCD16X2_DISPLAY_ON_CURSOR_OFF_BLINK_OFF		(LCD16X2_DISPLAY_ON | \
	LCD16X2_CURSOR_UNDERLINE_OFF | LCD16X2_CURSOR_BLINK_OFF)					
#define LCD16X2_DISPLAY_ON_CURSOR_OFF_BLINK_ON		(LCD16X2_DISPLAY_ON | \
	LCD16X2_CURSOR_UNDERLINE_OFF | LCD16X2_CURSOR_BLINK_ON)
#define LCD16X2_DISPLAY_ON_CURSOR_ON_BLINK_OFF		(LCD16X2_DISPLAY_ON | \
	LCD16X2_CURSOR_UNDERLINE_ON | LCD16X2_CURSOR_BLINK_OFF)
#define LCD16X2_DISPLAY_ON_CURSOR_ON_BLINK_ON		(LCD16X2_DISPLAY_ON | \
	LCD16X2_CURSOR_UNDERLINE_ON | LCD16X2_CURSOR_BLINK_ON)


#define File_1		0
#define File_2		1


#define row_0										0
#define row_1										1
#define row_2										row_0
#define row_3										row_1
#define row_4										row_0
#define row_5										row_1


#define col_0										0  
#define col_1										1  
#define col_2										2 
#define col_3										3 
#define col_4										4  
#define col_5										5  
#define col_6										6  
#define col_7										7  
#define col_8										8  
#define col_9										9  
#define col_10										10 
#define col_11										11 
#define col_12										12 
#define col_13										13 
#define col_14										14 
#define col_15										15 
	
#define with_line									16	
	
	
void lcd_init (void)											;  // inicializar lcd

void lcd_send_cmd (char cmd)								;  // enviar comando al  lcd

void lcd_send_data (char data)							;  // enviar dato al lcd

void lcd_send_string (char *str)							;  // enviar una string al lcd

void lcd_send_string_file (uint8_t File, char *str);
	
void lcd_send_string_cr (char *str);

void LCD_print	(char * str, uint8_t x, uint8_t y);


