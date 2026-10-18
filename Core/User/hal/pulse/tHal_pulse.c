#include "hal/pulse/tHal_pulse.h"

void tHal_pulse_create(tHal_pulse_instance_t* instance, const tHal_pulse_t* impl, void* hw_context)
{
  if (instance == 0)
  {
    return;
  }

  instance->impl = impl;
  instance->hw_context = hw_context;
}

void tHal_pulse_init(tHal_pulse_instance_t* instance)
{
  if (instance == 0 || instance->impl == 0 || instance->impl->init == 0)
  {
    return;
  }

  instance->impl->init(instance->hw_context);
}

void tHal_pulse_set_width_ns(tHal_pulse_instance_t* instance, uint32_t ns)
{
  if (instance == 0 || instance->impl == 0 || instance->impl->set_width_ns == 0)
  {
    return;
  }

  instance->impl->set_width_ns(instance->hw_context, ns);
}

uint8_t tHal_pulse_fire(tHal_pulse_instance_t* instance)
{
  if (instance == 0 || instance->impl == 0 || instance->impl->fire == 0)
  {
    return 0U;
  }

  return instance->impl->fire(instance->hw_context);
}
