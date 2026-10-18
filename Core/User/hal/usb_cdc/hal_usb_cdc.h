#ifndef USER_HAL_USB_CDC_HAL_USB_CDC_H_
#define USER_HAL_USB_CDC_HAL_USB_CDC_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct
{
  uint16_t (*write)(void* hw_context, const uint8_t* data, uint16_t len);
  uint8_t (*is_connected)(void* hw_context);
  void (*poll)(void* hw_context);
} tHal_usb_cdc_t;

typedef struct
{
  const tHal_usb_cdc_t* impl;
  void* hw_context;
} tHal_usb_cdc_instance_t;

void tHal_usb_cdc_create(tHal_usb_cdc_instance_t* instance, const tHal_usb_cdc_t* impl, void* hw_context);
uint16_t tHal_usb_cdc_write(tHal_usb_cdc_instance_t* instance, const uint8_t* data, uint16_t len);
uint8_t tHal_usb_cdc_is_connected(tHal_usb_cdc_instance_t* instance);
void tHal_usb_cdc_poll(tHal_usb_cdc_instance_t* instance);

#ifdef __cplusplus
}
#endif

#endif /* USER_HAL_USB_CDC_HAL_USB_CDC_H_ */
