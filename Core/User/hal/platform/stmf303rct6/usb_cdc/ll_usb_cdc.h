/*
 * ll_usb_cdc.h
 *
 *  Created on: Oct 16, 2026
 *      Author: Thang
 */

#ifndef USER_HAL_PLATFORM_STMF303RCT6_USB_CDC_LL_USB_CDC_H_
#define USER_HAL_PLATFORM_STMF303RCT6_USB_CDC_LL_USB_CDC_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "main.h"
#include "usbd_def.h"

typedef struct
{
  USBD_HandleTypeDef* husbd;
} stm32f303rct6_usb_cdc_hw_context_t;

uint16_t ll_stm32f303rct6_usb_cdc_write(void* hw_context, const uint8_t* data, uint16_t len);
void ll_stm32f303rct6_usb_cdc_poll(void* hw_context);
uint8_t ll_stm32f303rct6_usb_cdc_is_connected(void* hw_context);

#ifdef __cplusplus
}
#endif

#endif /* USER_HAL_PLATFORM_STMF303RCT6_USB_CDC_LL_USB_CDC_H_ */
