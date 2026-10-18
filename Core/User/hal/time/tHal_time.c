#include "hal/time/tHal_time.h"

void tHal_time_create(tHal_time_instance_t* instance, const tHal_time_t* impl)
{
  if (instance == 0)
  {
    return;
  }

  instance->impl = impl;
}

uint32_t tHal_time_getMs(tHal_time_instance_t* instance)
{
  if (instance == 0 || instance->impl == 0 || instance->impl->get_ms == 0)
  {
    return 0U;
  }

  return instance->impl->get_ms();
}
