/*
 * kratos_log.c
 *
 *  Created on: Apr 27, 2024
 *      Author: kratos
 */

#include "kratos_log.h"

#include "stm32f7xx_hal.h"

static UART_HandleTypeDef *_uart_log;

void log_send_uart_logs(void *data, int size)
{
  if (!_uart_log)
    return;

  HAL_UART_Transmit(_uart_log, data, size, 300);
}

/*
 * Re-direct printf() logs to UART1 (connected to
 * ST-link).
 */
int __io_putchar(int ch)
{
  char c = (char)ch;
  log_send_uart_logs(&c, sizeof(char));
}

void log_set_uart(UART_HandleTypeDef *uart)
{
  _uart_log = uart;
}
