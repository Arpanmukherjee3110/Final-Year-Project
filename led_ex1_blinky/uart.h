#ifndef UART_H
#define UART_H

#include "driverlib.h"
#include "device.h"

void UART_init(void);
uint16_t UART_Available(void);
float UART_ReadFloat(void);

#endif