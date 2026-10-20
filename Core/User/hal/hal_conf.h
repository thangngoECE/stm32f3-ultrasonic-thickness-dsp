#ifndef HAL_CONF_H_
#define HAL_CONF_H_

#ifdef __cplusplus
extern "C"
{
#endif

// Define platform to use
#define STM32F303RCT6

#include "main.h"

// USB CDC
#include "hal/usb_cdc/hal_usb_cdc.h"

#ifdef STM32F303RCT6
#include "hal/platform/stmf303rct6/usb_cdc/ll_usb_cdc.h"
extern USBD_HandleTypeDef hUsbDeviceFS;
static const tHal_usb_cdc_t g_stm32f303rct6_usb_cdc_impl = {
    .write = ll_stm32f303rct6_usb_cdc_write,
    .is_connected = ll_stm32f303rct6_usb_cdc_is_connected,
    .poll = ll_stm32f303rct6_usb_cdc_poll,
};
static stm32f303rct6_usb_cdc_hw_context_t g_stm32f303rct6_usb_cdc_context = {
    .husbd = &hUsbDeviceFS,
};
#endif

// Time
#include "hal/time/tHal_time.h"

#ifdef STM32F303RCT6
#include "hal/platform/stmf303rct6/time/ll_time.h"
static const tHal_time_t g_stm32f303rct6_time_impl = {
    .get_ms = ll_stm32f303rct6_time_get_ms,
};
#endif

// Pulse (TIM1 CH1 -> PA8 TX gate)
#include "hal/pulse/tHal_pulse.h"

#ifdef STM32F303RCT6
#include "hal/platform/stmf303rct6/pulse/ll_pulse.h"
static const tHal_pulse_t g_stm32f303rct6_pulse_impl = {
    .init = ll_stm32f303rct6_pulse_init,
    .set_width_ns = ll_stm32f303rct6_pulse_set_width_ns,
    .fire = ll_stm32f303rct6_pulse_fire,
};
static stm32f303rct6_pulse_hw_context_t g_stm32f303rct6_pulse_tx_context = {
    .htim = &htim1,
    .htim_trigger = &htim2, /* TIM2 1 kHz TRGO -> TIM1 ITR1 */
    .clk_hz = 144000000U,
    .delay_ticks = 100U,
};
#endif

#ifdef __cplusplus
}
#endif

#endif /* HAL_CONF_H_ */
