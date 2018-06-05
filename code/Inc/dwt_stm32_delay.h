#ifndef DWT
#define DWT

#include "stm32f1xx_hal.h"



static inline void stopwatch_reset(void);

static inline uint32_t stopwatch_getticks();

static inline void stopwatch_delay(uint32_t ticks);

uint32_t CalcNanosecondsFromStopwatch(uint32_t nStart, uint32_t nStop);
#endif