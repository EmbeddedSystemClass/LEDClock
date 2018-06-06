#include "stm32f1xx_hal.h"
#include "service.h"

extern led_latch_t U2_upper;
extern state_t state;
extern engine_tim_t engine_tim;
extern picture_tim_t picture_tim;
extern picture_tim_t htim4;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM3)//picture_tim.htim->Instance)
	{
		if(state != UPDATE_RESOLUTION_TIME)
		{
			state = UPDATE_LEDS;
		}
	} else if(htim->Instance == TIM4)//engine_tim.htim->Instance)
	{
		if(state != UPDATE_RESOLUTION_TIME)
		{
			state = UPDATE_RATIO_TIME;
		}
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	state = UPDATE_RESOLUTION_TIME;
}

