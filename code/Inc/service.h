/**
 * @file service.h
 * @author  Jakub Wieczorek <jakub.wieczorek0101@gmail.com>
 * @date 10.06.2018
 * @version 1.0
 *
 * @brief service header file.
 */

#ifndef SERVICE_H
#define SERVICE_H

#include "stm32f1xx_hal.h"

/** 
 * @enum STATE
 * @brief Updating in particular callbacks. Directs the program execution.
 * @var STATE::UPDATE_LEDS 
 * update led information by the data from image
 * @var STATE::UPDATE_RESOLUTION_TIME 
 * update resolution time when response from sensor
 * @var STATE::CHANGE_PICTURE 
 * change picture depending on user command by bluetooth
 * @var STATE::NOTHING 
 * sleep
 */
typedef enum STATE {UPDATE_LEDS, UPDATE_RESOLUTION_TIME, CHANGE_PICTURE, NOTHING} state_t;

/** 
 * @enum UPPER_LEDS
 * @brief leds for upper latch from up to down on schema
 */
enum UPPER_LEDS {U9, U8, U7, U6, U5, U4, U3, U1};

/** 
 * @enum LOWER_LEDS
 * @brief leds for lower latch from up to down on schema
 */
enum LOWER_LEDS {U32, U30, U28, U25, U24, U22, U20, U17};

/** @struct LED
 *  @brief struct represanting particular LED instance with port and pin
 *  @var LED::GPIOx 
 *  For example GPIOA
 *  @var LED::pin 
 *  For example GPIO_PIN_10
 */
typedef struct LED
{
	GPIO_TypeDef* GPIOx;
	uint16_t pin;
} led_t;

/** @struct LED_LATCH
 *  @brief struct represanting one of latches with port and pin also the array with leds instances
 *  @var LED_LATCH::GPIOx 
 *  For example GPIOA
 *  @var LED_LATCH::pin 
 *  For example GPIO_PIN_10
 *  @var LED_LATCH::leds 
 *  The array of leds instances
 *  @see LED
 */
typedef struct LED_LATCH
{
	GPIO_TypeDef* GPIOx;
	uint16_t pin;
	
	led_t leds[8];
} led_latch_t;

/** @struct ENGINE_TIM
 *  @brief struct represanting timer for counting the time of whole ratio
 *  @var ENGINE_TIM::ratio_time 
 *  The time of whole ratio 
 *  @var ENGINE_TIM::htim 
 *  The timer instance for example *htim4
 */
typedef struct ENGINE_TIM
{
	uint32_t ratio_time; // miliseconds so if prescaler 7200 - 1 then ticks / 10
	
	TIM_HandleTypeDef *htim;
} engine_tim_t;

/** @struct PICTURE_TIM
 *  @brief struct represanting timer for counting the time of leds switching on in smallest angle
 *  @var PICTURE_TIM::resolution_time 
 *  The time of switching or no led in smallest angle described by resolution
 *  @var PICTURE_TIM::resolution 
 *  How much angles will be in whole circle
 *  @var PICTURE_TIM::htim 
 *  The timer instance for example *htim4
 */
typedef struct PICTURE_TIM
{
	// microseconds so ratio_time / resolution * 1000
	uint32_t resolution_time; // htim3.Init.Period
	uint32_t resolution; // for example 360
	
	TIM_HandleTypeDef *htim;
} picture_tim_t;

/** @struct PICTURE
 *  @brief the picture displayed by leds
 *  @var PICTURE::data 
 *  The data to display usually in picture.h
 *  @var PICTURE::step 
 *  the part of resolution for example if resolution 360 then from 0 to 359. It is the part of an image 
 *  @see picture.h
 */
typedef struct PICTURE
{
	uint8_t (*data)[360];
	int step;
} picture_t;

/** 
 *  @brief latches states which are in leds array in led_latch_t instance
 *  @param led_latch_t a_latch LED_LATCH instance
 *  @see LED_LATCH
 */
void latch_data(led_latch_t a_latch);

/** 
 *  @brief sets information from the picture data into leds in particular latches
 *  @param picture_t a_picture picture_t instance
 *  @see PICTURE
 */
void update_leds(picture_t a_picture);

/** 
 *  @brief updates resolution time
 *
 *	the most important part of the processing. Basing on time from engine timer (ratio time) the resoltion
 *  time is counting. It is in every read from callback feedback from gpio input by phototransisor sensor.
 *  @param engine_tim_t engine_tim_t instance
 *  @param picture_tim_t picture_tim_t instance
 *  @see PICTURE_TIM
 *  @see ENGINE_TIM
 */
void update_resolution_time(engine_tim_t *a_engine, picture_tim_t *a_picture_tim);

#endif
