
#ifndef SERVICE_H
#define SERVICE_H

#include "stm32f1xx_hal.h"

// program states
typedef enum STATE {SET_LED, NOTHING} state_t;

// model
enum {U9};

typedef struct LED
{
	GPIO_TypeDef* GPIOx;
	uint16_t pin;
} led_t;

typedef struct LED_LATCH
{
	GPIO_TypeDef* GPIOx;
	uint16_t pin;
	
	led_t leds[1];
} led_latch_t;

// service functions
void set_rgb(led_latch_t a_latch, int a_led_num, uint8_t a_red, uint8_t a_green, uint8_t a_blue);
void set_bit(led_latch_t a_latch, int a_led_num);
//void start_picture_timer();

#endif
