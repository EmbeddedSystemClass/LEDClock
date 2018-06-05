#include "dwt_stm32_delay.h"

static void stopwatch_reset(void)
{
    /* Enable DWT */
    DEMCR |= DEMCR_TRCENA; 
    *DWT_CYCCNT = 0;             
    /* Enable CPU cycle counter */
    DWT_CTRL |= CYCCNTENA;
}

static uint32_t stopwatch_getticks()
{
    return CPU_CYCLES;
}

static void stopwatch_delay(uint32_t ticks)
{
    uint32_t end_ticks = ticks + stopwatch_getticks();
    while(1)
    {
            if (stopwatch_getticks() >= end_ticks)
                    break;
    }
}

uint32_t CalcNanosecondsFromStopwatch(uint32_t nStart, uint32_t nStop)
{
    uint32_t nDiffTicks;
    uint32_t nClkTicksPerMicrosec;

    nDiffTicks = nStop - nStart;
    nDiffTicks *= 1000;                               // Scale diff by 1000.
    nClkTicksPerMicrosec = SystemCoreClock / 1000000; // Convert (clkTicks/sec) to (clkTicks/microsec), SystemCoreClock = 168000000

    return nDiffTicks / nClkTicksPerMicrosec;         // nanosec = (ticks * 1000) / (clkTicks/microsec)
} 