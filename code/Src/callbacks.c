/**
 * @file callbacks.c
 * @author  Jakub Wieczorek <jakub.wieczorek0101@gmail.com>
 * @date 10.06.2018
 * @version 1.0
 *
 * @brief Callbacks file implemeting or overiding __weak functions invoking in interrupts.
 */

#include "stm32f1xx_hal.h"
#include "service.h"

extern events_t events;
extern engine_tim_t engine_tim;
extern picture_tim_t picture_tim;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == picture_tim.htim->Instance)
	{
		events.was_leds_event = true;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	events.was_engine_event = true;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	events.was_bluetooth_event = true;
}
