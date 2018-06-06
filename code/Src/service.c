#include "service.h"
#include "stdbool.h"

void latch_data(led_latch_t a_latch)
{
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_SET);
}

void update_leds(led_latch_t a_latch, picture_t a_picture, int a_step)
{
	if(a_picture.data[a_step] == 0)
	{
		HAL_GPIO_WritePin(a_latch.leds[U6].GPIOx, a_latch.leds[U6].pin, GPIO_PIN_RESET);
	}else
	{
		HAL_GPIO_WritePin(a_latch.leds[U6].GPIOx, a_latch.leds[U6].pin, GPIO_PIN_SET);
	}
}

void update_ratio_time(engine_tim_t *a_engine)
{
		a_engine->ratio_time += a_engine->htim->Init.Period;
}
void update_resolution_time(engine_tim_t *a_engine_tim, picture_tim_t *a_picture_tim)
{
	HAL_TIM_Base_Stop_IT(a_engine_tim->htim);
	HAL_TIM_Base_Stop_IT(a_picture_tim->htim);
	
	a_engine_tim->ratio_time += a_engine_tim->htim->Instance->CNT / 10; // final time
	
	a_picture_tim->resolution_time = (a_engine_tim->ratio_time * 1000) / a_picture_tim->resolution; 
	
	// update picture timer
	a_picture_tim->htim->Init.Period = a_picture_tim->resolution_time;
	
	a_picture_tim->htim->Instance->CNT = 0;
	a_engine_tim->htim->Instance->CNT = 0;
	HAL_TIM_Base_Start_IT(a_engine_tim->htim);
	HAL_TIM_Base_Start_IT(a_picture_tim->htim);
}
