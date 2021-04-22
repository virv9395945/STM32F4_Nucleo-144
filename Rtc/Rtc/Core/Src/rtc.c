/*
 * rtc.c
 *
 *  Created on: 04-04-2021
 *      Author: Victor R.
 */

/** Put this in the src folder **/
#include "stm32f4xx_hal.h"

#include "rtc.h"
#include "stdio.h"


extern RTC_HandleTypeDef hrtc;

extern char 	time[10];
extern char 	date[10];
/**
  ******************************************************************************
  * @brief	go
  * @param
  * @retval
  ******************************************************************************
  */

void rtc_init(  )
{
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	  if (HAL_RTC_Init(&hrtc) != HAL_OK)
	  {
	   Error_Handler();
	  }

}
/**
  ******************************************************************************
  * @brief	go
  * @param
  * @retval
  ******************************************************************************
  */
void set_time_date (  uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t weekday, uint8_t month, uint8_t date, uint8_t year )
{

  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef sDate;

  sTime.Hours 			= hours;
  sTime.Minutes 		= minutes;
  sTime.Seconds 		= seconds;
  sTime.DayLightSaving 	= RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation 	= RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN ) != HAL_OK)
  {
    Error_Handler();
  }

  sDate.WeekDay = weekday;
  sDate.Month 	= month;
  sDate.Date 	= date;
  sDate.Year 	= year;
  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
	  Error_Handler();
  }
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2); // backup register

}
/**
  ******************************************************************************
  * @brief	go
  * @param
  * @retval
  ******************************************************************************
  */
void set_time ( uint8_t hours,  uint8_t minutes,  uint8_t seconds )
{
		RTC_TimeTypeDef sTime;

  sTime.Hours 			= hours;
  sTime.Minutes 		= minutes;
  sTime.Seconds 		= seconds;
  sTime.DayLightSaving 	= RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation 	= RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN ) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2); // backup register

}
/**
  ******************************************************************************
  * @brief	go
  * @param
  * @retval
  ******************************************************************************
  */
void set_date ( uint8_t weekday, uint8_t month, uint8_t date, uint8_t year )
{
  RTC_DateTypeDef sDate;


  sDate.WeekDay = weekday;
  sDate.Month 	= month;
  sDate.Date 	= date;
  sDate.Year 	= year;
  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
	  Error_Handler();
  }
  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2); // backup register

}
/**
  ******************************************************************************
  * @brief	go
  * @param
  * @retval
  ******************************************************************************
  */
void set_alarma (   uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t weekday )
{
	RTC_AlarmTypeDef sAlarm = {0};

	sAlarm.AlarmTime.Hours = hours;
	sAlarm.AlarmTime.Minutes = minutes;
	sAlarm.AlarmTime.Seconds = seconds;
	sAlarm.AlarmTime.SubSeconds = 0;
	sAlarm.AlarmTime.DayLightSaving =  RTC_DAYLIGHTSAVING_NONE ; //RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_WEEKDAY;
	sAlarm.AlarmDateWeekDay = weekday;
	sAlarm.Alarm = RTC_ALARM_A;
	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
	{
		Error_Handler();
	}
}
/**
  ******************************************************************************
  * @brief	go
  * @param
  * @retval
  ******************************************************************************
  */
void get_time(void)
{
	RTC_DateTypeDef gDate;
	RTC_TimeTypeDef gTime;

	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &gTime, RTC_FORMAT_BIN);
	/* Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc, &gDate, RTC_FORMAT_BIN);
	/* Display time Format: hh:mm:ss */
	sprintf((char*)time,"%02d:%02d:%02d",gTime.Hours, gTime.Minutes, gTime.Seconds);
	/* Display date Format: dd-mm-yy */
	sprintf((char*)date,"%02d-%02d-%2d",gDate.Date, gDate.Month, 2000 + gDate.Year);
}
/**
  ******************************************************************************
  * @brief	go
  * @param
  * @retval
  ******************************************************************************
  */
