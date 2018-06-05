#include "service.h"
#include "stdbool.h"

//extern TIM_HandleTypeDef htim3;

//void start_picture_timer()
//{
//	htim3.Instance->CNT = 0;
//	HAL_TIM_Base_Start_IT(&htim3);
//}

void set_rgb(led_latch_t a_latch, int a_led_num, uint8_t a_red, uint8_t a_green, uint8_t a_blue)
{
	HAL_GPIO_WritePin(a_latch.leds[a_led_num].GPIOx, a_latch.leds[a_led_num].pin, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(a_latch.GPIOx, a_latch.pin);
	
	//HAL_TIM_Base_Stop_IT(&htim3);
}

void set_bit(led_latch_t a_latch, int a_led_num)
{
//	htim3.Instance->CNT = 0;
//	HAL_TIM_Base_Start_IT(&htim2);
//	HAL_GPIO_WritePin(a_latch.leds[a_led_num].GPIOx, a_latch.leds[a_led_num].pin, GPIO_PIN_SET);
//	htim3.Instance->CNT = 0;
//	HAL_TIM_Base_Start_IT(&htim2);
//	
//	HAL_GPIO_TogglePin(a_latch.GPIOx, a_latch.pin);
}
