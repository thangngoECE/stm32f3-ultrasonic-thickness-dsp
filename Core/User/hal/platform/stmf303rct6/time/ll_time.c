#include "ll_time.h"

uint32_t ll_stm32f303rct6_time_get_ms(void)
{
  return HAL_GetTick();
}
