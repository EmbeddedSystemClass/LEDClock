
#ifndef SERVICE_H
#define SERVICE_H

#include "stm32f1xx_hal.h"
#include "stdbool.h"

// program states
typedef enum STATE {UPDATE_LEDS, UPDATE_RESOLUTION_TIME, NOTHING} state_t;

// upper leds
enum {U9, U8, U7, U6, U5, U4, U3, U1};
// lower leds
enum {U32, U30, U28, U25, U24, U22, U20, U17};

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
	uint32_t resolution_time; // htim3.Init.Period
	uint32_t resolution; // for example 360
	
	TIM_HandleTypeDef *htim;
} picture_tim_t;

typedef struct PICTURE
{
	bool (*data)[360];
	int step;
} picture_t;

// service functions
void latch_data(led_latch_t a_latch);
void update_leds(led_latch_t a_latch, picture_t a_picture);
void update_resolution_time(engine_tim_t *a_engine, picture_tim_t *a_picture_tim);

#endif
