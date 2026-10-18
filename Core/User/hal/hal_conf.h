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

#ifdef __cplusplus
}
#endif

#endif /* HAL_CONF_H_ */
