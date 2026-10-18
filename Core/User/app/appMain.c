#include "appMain.h"

#include <stdio.h>

#include "hal/hal_conf.h"
#include "hal/pulse/tHal_pulse.h"
#include "hal/time/tHal_time.h"
#include "hal/usb_cdc/hal_usb_cdc.h"

#define PRINT_PERIOD_MS 10000U
#define TX_PULSE_WIDTH_NS 20U /* 3 ticks at 144 MHz = 20.8 ns */

static tHal_usb_cdc_instance_t g_usb_cdc;
static tHal_time_instance_t g_time;
static tHal_pulse_instance_t g_pulse;

static void app_init(void)
{
  tHal_usb_cdc_create(&g_usb_cdc, &g_stm32f303rct6_usb_cdc_impl, &g_stm32f303rct6_usb_cdc_context);
  tHal_time_create(&g_time, &g_stm32f303rct6_time_impl);
  tHal_pulse_create(&g_pulse, &g_stm32f303rct6_pulse_impl, &g_stm32f303rct6_pulse_tx_context);
  tHal_pulse_init(&g_pulse);
  tHal_pulse_set_width_ns(&g_pulse, TX_PULSE_WIDTH_NS);
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
  uint32_t last_fire = 0U;

  app_init();

  while (1)
  {
    tHal_usb_cdc_poll(&g_usb_cdc);

    uint32_t now = tHal_time_getMs(&g_time);

    if (now != last_fire)
    {
      last_fire = now;
      tHal_pulse_fire(&g_pulse);
    }

    if ((now - last_print) >= PRINT_PERIOD_MS)
    {
      last_print += PRINT_PERIOD_MS;
      printf("STM32F3RCT6!\r\n");
    }
  }
}
