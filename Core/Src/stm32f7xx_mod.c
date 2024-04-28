/*
 * stm32f7xx_mod.c
 *
 *  Created on: Apr 27, 2024
 *      Author: kratos
 */

#include "stm32f7xx_mod.h"

#include "string.h"

#include "cmsis_os.h"
#include "usb_device.h"
#include "stm32f7xx_hal.h"

#include "usbd_cdc_if.h"

void mod_toggle_led1(void)
{
  HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
}

void _mod_led_quick_toggle(int count)
{
  for (int i = 0; i < count; i++) {
    mod_toggle_led1();
    HAL_Delay(500);
  }
}

void mod_send_usb_test_data(void)
{
  uint8_t ret;
  char testStr[] = "Test msg from STM32F7 !\n";

  ret = CDC_Transmit_FS(testStr, strlen(testStr));
  if (ret != USBD_OK) {
    _mod_led_quick_toggle(2);
  }
}

void mod_send_uart_test_logs(UART_HandleTypeDef *uart)
{
  HAL_StatusTypeDef ret;
  char testStr[] = "Test log from STM32F7 !\n";

  ret = HAL_UART_Transmit(uart, testStr, strlen(testStr), 300);
  if (ret != HAL_OK) {
    _mod_led_quick_toggle(4);
  }
}
