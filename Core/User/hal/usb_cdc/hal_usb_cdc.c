#include "hal/usb_cdc/hal_usb_cdc.h"

void tHal_usb_cdc_create(tHal_usb_cdc_instance_t* instance, const tHal_usb_cdc_t* impl, void* hw_context)
{
  if (instance == 0)
  {
    return;
  }

  instance->impl = impl;
  instance->hw_context = hw_context;
}

uint16_t tHal_usb_cdc_write(tHal_usb_cdc_instance_t* instance, const uint8_t* data, uint16_t len)
{
  if (instance == 0 || instance->impl == 0 || instance->impl->write == 0)
  {
    return 0U;
  }

  return instance->impl->write(instance->hw_context, data, len);
}

uint8_t tHal_usb_cdc_is_connected(tHal_usb_cdc_instance_t* instance)
{
  if (instance == 0 || instance->impl == 0 || instance->impl->is_connected == 0)
  {
    return 0U;
  }

  return instance->impl->is_connected(instance->hw_context);
}

void tHal_usb_cdc_poll(tHal_usb_cdc_instance_t* instance)
{
  if (instance == 0 || instance->impl == 0 || instance->impl->poll == 0)
  {
    return;
  }

  instance->impl->poll(instance->hw_context);
}
