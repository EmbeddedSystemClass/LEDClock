
#ifndef SERVICE_H
#define SERVICE_H

#include "stm32f1xx_hal.h"

// program states
typedef enum STATE {SET_LED, NOTHING} state_t;

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
	
	led_t leds[8];
} led_latch_t;

// service functions
void latch_data(led_latch_t a_latch);

#endif
