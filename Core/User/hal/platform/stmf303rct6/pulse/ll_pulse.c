#include "ll_pulse.h"

void ll_stm32f303rct6_pulse_init(void* hw_context)
{
  stm32f303rct6_pulse_hw_context_t* context = (stm32f303rct6_pulse_hw_context_t*)hw_context;

  if (context == 0 || context->htim == 0)
  {
    return;
  }

  context->htim->Instance->CR1 |= TIM_CR1_OPM;
  HAL_TIM_OnePulse_Start(context->htim, TIM_CHANNEL_1);

  if (context->htim_trigger != 0)
  {
    HAL_TIM_Base_Start(context->htim_trigger); /* hardware PRF: each TRGO fires one pulse */
  }
}

void ll_stm32f303rct6_pulse_set_width_ns(void* hw_context, uint32_t ns)
{
  stm32f303rct6_pulse_hw_context_t* context = (stm32f303rct6_pulse_hw_context_t*)hw_context;
  uint32_t ticks;

  if (context == 0 || context->htim == 0)
  {
    return;
  }

  /* round to nearest tick, at least one tick */
  ticks = (uint32_t)(((uint64_t)ns * context->clk_hz + 500000000ULL) / 1000000000ULL);
  if (ticks == 0U)
  {
    ticks = 1U;
  }

  __HAL_TIM_SET_COMPARE(context->htim, TIM_CHANNEL_1, context->delay_ticks);
  __HAL_TIM_SET_AUTORELOAD(context->htim, context->delay_ticks + ticks - 1U);

  /* hardware trigger skips fire(), so latch the preloads here; a running pulse latches them at its end */
  if ((context->htim->Instance->CR1 & TIM_CR1_CEN) == 0U)
  {
    HAL_TIM_GenerateEvent(context->htim, TIM_EVENTSOURCE_UPDATE);
  }
}

uint8_t ll_stm32f303rct6_pulse_fire(void* hw_context)
{
  stm32f303rct6_pulse_hw_context_t* context = (stm32f303rct6_pulse_hw_context_t*)hw_context;

  if (context == 0 || context->htim == 0)
  {
    return 0U;
  }

  if ((context->htim->Instance->CR1 & TIM_CR1_CEN) != 0U)
  {
    return 0U; /* previous pulse still running */
  }

  HAL_TIM_GenerateEvent(context->htim, TIM_EVENTSOURCE_UPDATE); /* latch CCR1/ARR preloads, CNT = 0 */
  __HAL_TIM_ENABLE(context->htim);                               /* OPM: one pulse, CEN auto-clears */

  return 1U;
}
