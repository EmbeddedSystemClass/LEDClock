#include "service.h"
#include "stdbool.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void latch_data(led_latch_t a_latch)
{
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_RESET);
}

void update_leds(led_latch_t a_latch, picture_t a_picture)
{
	int latch_size = 8;
	for(int led_num = 0; led_num < latch_size; led_num++)
	{
		HAL_GPIO_WritePin(a_latch.leds[led_num].GPIOx, a_latch.leds[led_num].pin, a_picture.data[led_num][a_picture.step]);
	}
}

void update_resolution_time(engine_tim_t *a_engine_tim, picture_tim_t *a_picture_tim)
{
	a_engine_tim->ratio_time += a_engine_tim->htim->Instance->CNT / 10; // final time in ms

	a_picture_tim->resolution_time = (a_engine_tim->ratio_time * 10) / a_picture_tim->resolution; 

	a_engine_tim->ratio_time = 0;
	
	// update picture timer
	a_picture_tim->htim->Instance->CNT = 0;
	a_engine_tim->htim->Instance->CNT = 0;
	__HAL_TIM_SET_AUTORELOAD(a_picture_tim->htim, a_picture_tim->resolution_time);
}
