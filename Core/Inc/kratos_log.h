/*
 * kratos_log.h
 *
 *  Created on: Apr 27, 2024
 *      Author: kratos
 */

#pragma once

#include "stm32f7xx_hal.h"

void log_set_uart(UART_HandleTypeDef *uart);
void log_send_uart_logs(void *data, int size);
