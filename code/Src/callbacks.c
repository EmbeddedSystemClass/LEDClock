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

extern state_t state;
extern engine_tim_t engine_tim;
extern picture_tim_t picture_tim;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == picture_tim.htim->Instance)
	{
		state = UPDATE_LEDS;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	state = UPDATE_RESOLUTION_TIME;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	state = CHANGE_PICTURE;
}
