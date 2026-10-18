#ifndef USER_HAL_PULSE_THAL_PULSE_H_
#define USER_HAL_PULSE_THAL_PULSE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct
{
  void (*init)(void* hw_context);
  void (*set_width_ns)(void* hw_context, uint32_t ns);
  uint8_t (*fire)(void* hw_context);
} tHal_pulse_t;

typedef struct
{
  const tHal_pulse_t* impl;
  void* hw_context;
} tHal_pulse_instance_t;

void tHal_pulse_create(tHal_pulse_instance_t* instance, const tHal_pulse_t* impl, void* hw_context);
void tHal_pulse_init(tHal_pulse_instance_t* instance);
void tHal_pulse_set_width_ns(tHal_pulse_instance_t* instance, uint32_t ns);
uint8_t tHal_pulse_fire(tHal_pulse_instance_t* instance);

#ifdef __cplusplus
}
#endif

#endif /* USER_HAL_PULSE_THAL_PULSE_H_ */
