#include "service.h"
#include "stdbool.h"

//extern TIM_HandleTypeDef htim3;

void latch_data(led_latch_t a_latch)
{
	HAL_GPIO_WritePin(a_latch.GPIOx, a_latch.pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
}
