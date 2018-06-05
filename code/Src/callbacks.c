#include "stm32f1xx_hal.h"
#include "service.h"

extern led_latch_t U2_upper;
extern state_t state;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim3;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == htim3.Instance)
	{
		state = SET_LED;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	// HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
	
	state = UPDATE_TIME;
}

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == htim4.Instance)
	{
		switch(htim->Channel)
		{
			case HAL_TIM_ACTIVE_CHANNEL_1:
			{
				HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);

				return;
			}
			case HAL_TIM_ACTIVE_CHANNEL_2:
			{
				HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
				return;
			}
			case HAL_TIM_ACTIVE_CHANNEL_3:
			{
				HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);

				return;
			}
			case HAL_TIM_ACTIVE_CHANNEL_4:
			{
				return;
			}
			default:
			{
			}
		}
	}
}
