#include "appMain.h"

#include <stdio.h>

#include "hal/hal_conf.h"
#include "hal/time/tHal_time.h"
#include "hal/usb_cdc/hal_usb_cdc.h"

#define PRINT_PERIOD_MS 10000U

static tHal_usb_cdc_instance_t g_usb_cdc;
static tHal_time_instance_t g_time;

static void app_init(void)
{
  tHal_usb_cdc_create(&g_usb_cdc, &g_stm32f303rct6_usb_cdc_impl, &g_stm32f303rct6_usb_cdc_context);
  tHal_time_create(&g_time, &g_stm32f303rct6_time_impl);
}

int _write(int file, char *ptr, int len)
{
  (void)file;
  tHal_usb_cdc_write(&g_usb_cdc, (const uint8_t*)ptr, (uint16_t)len);
  return len;
}

void appMain(void)
{
  uint32_t last_print = 0U;

  app_init();

  while (1)
  {
    tHal_usb_cdc_poll(&g_usb_cdc);

    uint32_t now = tHal_time_getMs(&g_time);

    if ((now - last_print) >= PRINT_PERIOD_MS)
    {
      last_print += PRINT_PERIOD_MS;
      printf("STM32F3RCT6!\r\n");
    }
  }
}
