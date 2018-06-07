#include "service.h"
#include "stdbool.h"

extern led_latch_t U2_upper;
extern led_latch_t U19_lower;

void latch_data(led_latch_t a_latch)
{
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_RESET);
}

void update_leds(picture_t a_picture)
{
	int led_num = 8;
	
	for(int led_idx = 0; led_idx < led_num; led_idx++)
	{
		HAL_GPIO_WritePin(U2_upper.leds[led_idx].GPIOx, U2_upper.leds[led_idx].pin, a_picture.data[led_idx][a_picture.step]);
	}
	
	latch_data(U2_upper);
	
	for(int led_idx = 0; led_idx < led_num; led_idx++)
	{
		HAL_GPIO_WritePin(U19_lower.leds[led_idx].GPIOx, U19_lower.leds[led_idx].pin, a_picture.data[led_idx + led_num][a_picture.step]);
	}

	latch_data(U19_lower);
}

void update_resolution_time(engine_tim_t *a_engine_tim, picture_tim_t *a_picture_tim)
{
	a_engine_tim->ratio_time += a_engine_tim->htim->Instance->CNT / 10; // final time in ms

	a_picture_tim->resolution_time = (a_engine_tim->ratio_time * 1000) / a_picture_tim->resolution; 

	a_engine_tim->ratio_time = 0;
	
	// update picture timer
	a_picture_tim->htim->Instance->CNT = 0;
	a_engine_tim->htim->Instance->CNT = 0;
	__HAL_TIM_SET_AUTORELOAD(a_picture_tim->htim, a_picture_tim->resolution_time);
}
