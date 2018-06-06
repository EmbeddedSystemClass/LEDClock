
#ifndef SERVICE_H
#define SERVICE_H

#include "stm32f1xx_hal.h"
#include "stdbool.h"

// program states
typedef enum STATE {UPDATE_LEDS, UPDATE_RESOLUTION_TIME, UPDATE_RATIO_TIME, NOTHING} state_t;

// leds
enum {U6 = 3};

typedef struct LED
{
	GPIO_TypeDef* GPIOx;
	uint16_t pin;
} led_t;

typedef struct LED_LATCH
{
	GPIO_TypeDef* GPIOx;
	uint16_t pin;
	
	int step;
	
	led_t leds[8];
} led_latch_t;

typedef struct ENGINE_TIM
{
	uint32_t ratio_time; // miliseconds so if prescaler 7200 - 1 then ticks / 10
	
	TIM_HandleTypeDef *htim;
} engine_tim_t;

typedef struct PICTURE_TIM
{
	// microseconds so ratio_time / resolution * 1000
	uint16_t resolution_time; // htim3.Init.Period
	uint16_t resolution; // for example 360
	
	TIM_HandleTypeDef *htim;
} picture_tim_t;

typedef struct PICTURE
{
	bool *data;
} picture_t;

// service functions
void latch_data(led_latch_t a_latch);
int update_leds(led_latch_t a_latch, picture_t a_picture, int a_step);
void update_ratio_time(engine_tim_t *a_engine);
void update_resolution_time(engine_tim_t *a_engine, picture_tim_t *a_picture_tim);

#endif
