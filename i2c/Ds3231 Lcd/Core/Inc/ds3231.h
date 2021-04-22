
/** Poner esto en carpeta .../libreri/inc **/

#include "device.h"


/*
**** CUBEMX ****
	Connectivity   ---->  I2C2 ( Depende del puerto ocupado )
		GPIO PB10 -> SCL
		GPIO PB11 -> SDA
		
	Parameters Settings:
		Master Features
			I2C Speed Mode								Standard Mode
			I2C Clock Speed(Hz)						1000000
			
		Slave Features
			Clock No Stretch Mode					Disabled
			Primary Address Length selection		7-bit
			Dual Address Acknowledged				Disabled
			Primary slave address					0
			General Call address detection		Disabled
			
		

**** KEIL V5 **** 
 **** Agregar en main.c ****
 
 Private includes ----------------------------------------------------------
 	USER CODE BEGIN Includes 
 	#include "i2c-ds3231.h"
 
 USER CODE BEGIN PV 
   I2C_HandleTypeDef I2C_DS3231;
	char 		hora[8];
 	char 		fecha[14];
	
 USER CODE BEGIN 2
  I2C_DS3231 = hi2c2;				// Depende i2c seleccionada.
 
  while (1)
  {
    // USER CODE END WHILE //

    // USER CODE BEGIN 3 //
	  ds3231_get_hora	 ( (char *) hora  );
	  ds3231_get_fecha	 ( ( char *)fecha );

	  lcd_send_string_file ( File_1, ( char *)hora );
	  lcd_send_string_file ( File_2, ( char *)fecha );

*/

// Registro ubicaci�n
#define DS1307_SECONDS							0x00
#define DS1307_MINUTES							0x01
#define DS1307_HOURS								0x02
#define DS1307_DAY								0x03
#define DS1307_DATE								0x04
#define DS1307_MONTH								0x05
#define DS1307_YEAR								0x06

// Bits in hours register
#define DS1307_HOUR_MODE						6
#define DS1307_AM_PM								5

// DS1307 modo de hora
#define DS1307_HOUR_12							1
#define DS1307_HOUR_24							0
#define DS1307_AM									0
#define DS1307_PM									1

// DS1307 d�a de la semana
#define DS1307_SUNDAY							1
#define DS1307_MONDAY							2
#define DS1307_TUESDAY							3
#define DS1307_WEDNESDAY						4
#define DS1307_THRUSDAY							5
#define DS1307_FRIDAY							6
#define DS1307_SATURDAY							7

uint8_t  ds3231_get_time_sec   	( void )				;
uint8_t  ds3231_get_time_min   	( void )				;
uint8_t  ds3231_get_time_hor   	( void )				;

void  	ds3231_set_time_sec   	( uint8_t data )	;
void  	ds3231_set_time_min 	( uint8_t data )	;
void  	ds3231_set_time_hor	 	( uint8_t data )	;

uint8_t  ds3231_get_date_diasem 	( void )				;
uint8_t  ds3231_get_date_dia   	( void )				;
uint8_t  ds3231_get_date_mes 		( void )				;
uint8_t  ds3231_get_date_ano	 	( void )				;

void     ds3231_set_date_diasem 	( uint8_t data  )	;
void  	ds3231_set_date_dia   	( uint8_t data )	;
void  	ds3231_set_date_mes 		( uint8_t data )	;
void  	ds3231_set_date_ano	 	( uint8_t data )	;

void  	ds3231_get_hora	 		( char *dat  )	;
void  	ds3231_get_fecha		 	( char *dat  )	;

uint8_t bcd2bin ( uint8_t bcd )							;
uint8_t bin2bcd ( uint8_t bin )							;

