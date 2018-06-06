#include "service.h"
#include "stdbool.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void latch_data(led_latch_t a_latch)
{
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_RESET);
}

int update_leds(led_latch_t a_latch, picture_t a_picture)
{
	HAL_GPIO_WritePin(a_latch.leds[U6].GPIOx, a_latch.leds[U6].pin, a_picture.data[a_picture.step]);
	
	a_picture.step++;
	
	return a_picture.step == 4 ? 0 : a_picture.step;
}

void update_ratio_time(engine_tim_t *a_engine)
{
		a_engine->ratio_time += a_engine->htim->Init.Period;
}
void update_resolution_time(engine_tim_t *a_engine_tim, picture_tim_t *a_picture_tim)
{
	HAL_TIM_Base_Stop_IT(a_picture_tim->htim);
	HAL_TIM_Base_Stop_IT(a_engine_tim->htim);
	
	a_engine_tim->ratio_time += a_engine_tim->htim->Instance->CNT / 10; // final time in ms
	a_picture_tim->resolution_time = (a_engine_tim->ratio_time * 10) / a_picture_tim->resolution; 
	a_engine_tim->ratio_time = 0;
	
	// update picture timer
	__HAL_TIM_SET_AUTORELOAD(&htim3, a_picture_tim->resolution_time);
	a_picture_tim->htim->Instance->CNT = 0;
	a_engine_tim->htim->Instance->CNT = 0;
	
	HAL_TIM_Base_Start_IT(a_picture_tim->htim);
	HAL_TIM_Base_Start_IT(a_engine_tim->htim);
}
