#ifndef USER_HAL_PLATFORM_STMF303RCT6_PULSE_LL_PULSE_H_
#define USER_HAL_PLATFORM_STMF303RCT6_PULSE_LL_PULSE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "hal/pulse/tHal_pulse.h"
#include "main.h"
#include "tim.h"

typedef struct
{
  TIM_HandleTypeDef* htim;
  TIM_HandleTypeDef* htim_trigger; /* PRF timer whose TRGO starts htim; started by init */
  uint32_t clk_hz;
  uint32_t delay_ticks;
} stm32f303rct6_pulse_hw_context_t;

void ll_stm32f303rct6_pulse_init(void* hw_context);
void ll_stm32f303rct6_pulse_set_width_ns(void* hw_context, uint32_t ns);
uint8_t ll_stm32f303rct6_pulse_fire(void* hw_context);

#ifdef __cplusplus
}
#endif

#endif /* USER_HAL_PLATFORM_STMF303RCT6_PULSE_LL_PULSE_H_ */
