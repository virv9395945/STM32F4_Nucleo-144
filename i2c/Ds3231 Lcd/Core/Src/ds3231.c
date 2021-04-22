
/** Poner esto en carpeta .../libreria/src **/

#include "ds3231.h"
#include "stdio.h"

//extern I2C_HandleTypeDef hi2c1;  
extern I2C_HandleTypeDef I2C_DS3231; 
/**
  ******************************************************************************
  * @brief	Direccion I2C del dispositivo, se entrega valor desplazado y unico
  *			para lectura y escritura
  ******************************************************************************
  */
#define SLAVE_ADDRESS_DS3231 0x68 << 1 

/**
  ******************************************************************************
  * @brief	Declaraci�n variables denerales
  ******************************************************************************
  */
#define timeout 100

/**
  ******************************************************************************
  * @brief	Consulta valor del segundo en reloj ds3231
  * @param	none
  * @retval	Valor del segundo actual
  ******************************************************************************
  */
uint8_t  ds3231_get_time_sec ( )
{
	uint8_t reg_data[3]						;
	uint8_t reg_cmd[1] 						; 
	reg_cmd[0] = DS1307_SECONDS			;
	HAL_I2C_Master_Transmit ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 1 , timeout );	
	HAL_I2C_Master_Receive  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_data , 1 , timeout );	
	
	return ( bcd2bin(reg_data[0]) )		;
}
/**
  ******************************************************************************
  * @brief	Consulta valor del minuto en reloj ds3231
  * @param	none
  * @retval	Valor del minuto actual
  ******************************************************************************
  */
uint8_t  ds3231_get_time_min ( )
{
	uint8_t reg_data[3]						;
	uint8_t reg_cmd[1] 						; 
	reg_cmd[0] = DS1307_MINUTES 			;	
	HAL_I2C_Master_Transmit ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 1 , timeout );	
	HAL_I2C_Master_Receive  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_data , 1 , timeout );	
	
	return ( bcd2bin(reg_data[0]) )		;
}
/**
  ******************************************************************************
  * @brief	Consulta valor de la hora en reloj ds3231
  * @param	none
  * @retval	Valor de la hora actual
  ******************************************************************************
  */
uint8_t  ds3231_get_time_hor ( )
{
	uint8_t reg_data[3]						;
	uint8_t reg_cmd[1] 						; 
	reg_cmd[0] = DS1307_HOURS 				;
	HAL_I2C_Master_Transmit ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 1 , timeout );	
	HAL_I2C_Master_Receive  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_data , 1 , timeout );	
	
	return ( bcd2bin(reg_data[0]) )		;
}

/**
  ******************************************************************************
  * @brief
  * @param
  * @retval
  ******************************************************************************
  */
void ds3231_set_time_sec ( uint8_t data )
{
	uint8_t reg_cmd[2] 						;
	reg_cmd[0] 	= DS1307_SECONDS			;
	reg_cmd[1] 	= bin2bcd ( data )		;
	HAL_I2C_Master_Transmit  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 2 , timeout );
}
/**
  ******************************************************************************
  * @brief
  * @param
  * @retval
  ******************************************************************************
  */
void ds3231_set_time_min ( uint8_t data )
{
	uint8_t reg_cmd[2] 						;
	reg_cmd[0] 	= DS1307_MINUTES 				;
	reg_cmd[1] 	= bin2bcd ( data )		;
	HAL_I2C_Master_Transmit  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 2 , timeout );
}
/**
  ******************************************************************************
  * @brief
  * @param
  * @retval
  ******************************************************************************
  */
void ds3231_set_time_hor ( uint8_t data )
{
	uint8_t reg_cmd[2] 						;
	reg_cmd[0] 	= DS1307_HOURS 				;
	reg_cmd[1] 	= bin2bcd ( data )		;
	HAL_I2C_Master_Transmit  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 2 , timeout );
}
/**
  ******************************************************************************
  * @brief	Consulta valor del dia de la semana vigente en reloj ds3231
  * @param	none
  * @retval	Valor del dia de la semana actual
  ******************************************************************************
  */
uint8_t  ds3231_get_date_diasem ( )
{
	uint8_t reg_data[3]						;
	uint8_t reg_cmd[1] 						; 
	reg_cmd[0] = DS1307_DAY 				;
	HAL_I2C_Master_Transmit ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 1 , timeout );	
	HAL_I2C_Master_Receive  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_data , 1 , timeout );	
	
	return ( bcd2bin(reg_data[0]) )		;
}
/**
  ******************************************************************************
  * @brief	Consulta valor del dia en reloj ds3231
  * @param	none
  * @retval	Valor del dia actual
  ******************************************************************************
  */
uint8_t  ds3231_get_date_dia ( )
{
	uint8_t reg_data[3]						;
	uint8_t reg_cmd[1] 						; 
	reg_cmd[0] = DS1307_DATE 				;
	HAL_I2C_Master_Transmit ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 1 , timeout );	
	HAL_I2C_Master_Receive  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_data , 1 , timeout );	
	
	return ( bcd2bin(reg_data[0]) )		;
}
/**
  ******************************************************************************
  * @brief	Consulta valor del mes en reloj ds3231
  * @param	none
  * @retval	Valor del mes actual
  ******************************************************************************
  */
uint8_t  ds3231_get_date_mes ( )
{
	uint8_t reg_data[3]						;
	uint8_t reg_cmd[1] 						; 
	reg_cmd[0] = DS1307_MONTH 				;
	HAL_I2C_Master_Transmit ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 1 , timeout );	
	HAL_I2C_Master_Receive  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_data , 1 , timeout );	
	
	return ( bcd2bin(reg_data[0]) )		;
}
/**
  ******************************************************************************
  * @brief	Consulta valor del a�o en reloj ds3231
  * @param	none
  * @retval	Valor del a�o actual
  ******************************************************************************
  */
uint8_t  ds3231_get_date_ano ( )
{
	uint8_t reg_data[3]						;
	uint8_t reg_cmd[1] 						; 
	reg_cmd[0] = DS1307_YEAR 				;
	HAL_I2C_Master_Transmit ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 1 , timeout );	
	HAL_I2C_Master_Receive  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_data , 1 , timeout );	
	
	return ( bcd2bin(reg_data[0]) )		;
}
/**
  ******************************************************************************
  * @brief	
  * @param	
  * @retval	
  ******************************************************************************
  */
void ds3231_set_date_diasem ( uint8_t data )
{
	uint8_t reg_cmd[2] 						; 
	reg_cmd[0] 	= DS1307_DAY 				;
	reg_cmd[1] 	= bin2bcd ( data )			;
	HAL_I2C_Master_Transmit  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 2 , timeout );	
}
/**
  ******************************************************************************
  * @brief	
  * @param	
  * @retval	
  ******************************************************************************
  */
void ds3231_set_date_dia ( uint8_t data )
{
	uint8_t reg_cmd[2] 						; 
	reg_cmd[0] 	= DS1307_DATE 				;
	reg_cmd[1] 	= bin2bcd ( data )		;
	HAL_I2C_Master_Transmit  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 2 , timeout );	
}
/**
  ******************************************************************************
  * @brief	
  * @param	
  * @retval	
  ******************************************************************************
  */
void ds3231_set_date_mes ( uint8_t data )
{
	uint8_t reg_cmd[2] 						; 
	reg_cmd[0] 	= DS1307_MONTH 			;
	reg_cmd[1] 	= bin2bcd ( data )		;
	HAL_I2C_Master_Transmit  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 2 , timeout );		
}
/**
  ******************************************************************************
  * @brief	
  * @param	
  * @retval	
  ******************************************************************************
  */
void ds3231_set_date_ano ( uint8_t data )
{
	uint8_t reg_cmd[2] 						; 
	reg_cmd[0] 	= DS1307_YEAR 				;
	reg_cmd[1] 	= bin2bcd ( data )			;
	HAL_I2C_Master_Transmit  ( &I2C_DS3231, SLAVE_ADDRESS_DS3231,( uint8_t *) reg_cmd  , 2 , timeout );		
}

/**
  ******************************************************************************
  * @brief	Convertir de formato BCD a formato BIN
  * @param	BCD valor a convertir
  * @retval	Valor BIN de BCD dado
  ******************************************************************************
  */
uint8_t bcd2bin(uint8_t bcd)
{
	uint8_t bin = (bcd >> 4) * 10 		;
	bin += bcd & 0x0F							;
	
	return bin									;
}
/**
  ******************************************************************************
  * @brief	Convertir de formato BIN a formato BCD
  * @param	BIN valor a convertir
  * @retval	Valor BCD de BIN dado
  ******************************************************************************
  */
uint8_t bin2bcd(uint8_t bin)
{
	uint8_t high = bin / 10				;
	uint8_t low = bin - (high *10)	;
	
	return (high << 4) | low			;
}

/**
  ******************************************************************************
  * @brief	Convertir de formato BIN a formato BCD
  * @param	BIN valor a convertir
  * @retval	Valor BCD de BIN dado
  ******************************************************************************
  */
void   ds3231_get_hora( char *dat )
{	
		sprintf( dat , "%02d:%02d:%02d",	   ds3231_get_time_hor ( )   ,
											   ds3231_get_time_min ( )   ,
											   ds3231_get_time_sec ( ) ) ;
}

/**
  ******************************************************************************
  * @brief	Convertir de formato BIN a formato BCD
  * @param	BIN valor a convertir
  * @retval	Valor BCD de BIN dado
  ******************************************************************************
  */
void   ds3231_get_fecha( char *dat )
{	
		if ( ds3231_get_date_diasem () == 1 )
			sprintf( dat , "Dom %02d/%02d/20%02d"	, ds3231_get_date_dia (), ds3231_get_date_mes (),  ds3231_get_date_ano () );
		if ( ds3231_get_date_diasem () == 2 )
			sprintf( dat , "Lun %02d/%02d/20%02d"	, ds3231_get_date_dia (), ds3231_get_date_mes (),  ds3231_get_date_ano () );
		if ( ds3231_get_date_diasem () == 3 )
			sprintf( dat , "Mar %02d/%02d/20%02d"	, ds3231_get_date_dia (), ds3231_get_date_mes (),  ds3231_get_date_ano () );
		if ( ds3231_get_date_diasem () == 4 )
			sprintf( dat , "Mie %02d/%02d/20%02d"	, ds3231_get_date_dia (), ds3231_get_date_mes (),  ds3231_get_date_ano () );
		if ( ds3231_get_date_diasem () == 5 )
			sprintf( dat , "Jue %02d/%02d/20%02d"	, ds3231_get_date_dia (), ds3231_get_date_mes (),  ds3231_get_date_ano () );
		if ( ds3231_get_date_diasem () == 6 )
			sprintf( dat , "Vie %02d/%02d/20%02d"	, ds3231_get_date_dia (), ds3231_get_date_mes (),  ds3231_get_date_ano () );
		if ( ds3231_get_date_diasem () == 7 )
			sprintf( dat , "Sab %02d/%02d/20%02d"	, ds3231_get_date_dia (), ds3231_get_date_mes (),  ds3231_get_date_ano () );

}
