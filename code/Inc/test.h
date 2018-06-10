/**
 * @file test.h
 * @author  Jakub Wieczorek <jakub.wieczorek0101@gmail.com>
 * @date 10.06.2018
 * @version 1.0
 *
 * @brief test header file.
 */

#ifndef TEST_H
#define TEST_H

#include "stm32f1xx_hal.h"

/**
  * @brief enable to switch on 3 leds after switching on power supply
  */
void test_power_suply(void);

/**
  * @brief test view leds
  */
void test_leds_and_latch(void);

#endif
