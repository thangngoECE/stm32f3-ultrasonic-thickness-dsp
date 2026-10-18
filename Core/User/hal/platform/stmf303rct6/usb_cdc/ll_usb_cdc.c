/*
 * ll_usb_cdc.c
 *
 *  Created on: Oct 16, 2026
 *      Author: Thang
 */

#include "ll_usb_cdc.h"

#include <string.h>

#include "usbd_cdc.h"
#include "usbd_cdc_if.h"

#define LL_USB_CDC_TX_BUF_SIZE 1024U

/* two buffers: one is being sent by USB while the other collects new output */
static uint8_t s_tx_buf[2][LL_USB_CDC_TX_BUF_SIZE];
static uint8_t s_fill = 0U;
static uint16_t s_fill_len = 0U;

uint8_t ll_stm32f303rct6_usb_cdc_is_connected(void* hw_context)
{
  stm32f303rct6_usb_cdc_hw_context_t* context = (stm32f303rct6_usb_cdc_hw_context_t*)hw_context;

  if (context == 0 || context->husbd == 0)
  {
    return 0U;
  }

  return (context->husbd->dev_state == USBD_STATE_CONFIGURED && context->husbd->pClassData != 0) ? 1U : 0U;
}

void ll_stm32f303rct6_usb_cdc_poll(void* hw_context)
{
  if (s_fill_len == 0U || !ll_stm32f303rct6_usb_cdc_is_connected(hw_context))
  {
    return;
  }

  if (CDC_Transmit_FS(s_tx_buf[s_fill], s_fill_len) == USBD_OK)
  {
    s_fill ^= 1U;
    s_fill_len = 0U;
  }
}

uint16_t ll_stm32f303rct6_usb_cdc_write(void* hw_context, const uint8_t* data, uint16_t len)
{
  uint16_t room = (uint16_t)(LL_USB_CDC_TX_BUF_SIZE - s_fill_len);

  if (data == 0 || len == 0U || !ll_stm32f303rct6_usb_cdc_is_connected(hw_context))
  {
    return 0U;
  }

  if (len > room)
  {
    /* shortcut: drops output that doesn't fit while the host isn't reading, raise the size if a burst exceeds 1 KB */
    len = room;
  }

  memcpy(&s_tx_buf[s_fill][s_fill_len], data, len);
  s_fill_len += len;
  ll_stm32f303rct6_usb_cdc_poll(hw_context);

  return len;
}
