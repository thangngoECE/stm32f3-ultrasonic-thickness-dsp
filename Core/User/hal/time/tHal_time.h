#ifndef USER_HAL_TIME_THAL_TIME_H_
#define USER_HAL_TIME_THAL_TIME_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef struct
{
  uint32_t (*get_ms)(void);
} tHal_time_t;

typedef struct
{
  const tHal_time_t* impl;
} tHal_time_instance_t;

void tHal_time_create(tHal_time_instance_t* instance, const tHal_time_t* impl);
uint32_t tHal_time_getMs(tHal_time_instance_t* instance);

#ifdef __cplusplus
}
#endif

#endif /* USER_HAL_TIME_THAL_TIME_H_ */
