#ifndef PWM_H
#define PWM_H

#include "driverlib.h"
#include "device.h"

#define PWM_FREQUENCY      50000UL
#define SYSCLK_FREQUENCY   100000000UL
#define TBPRD_VALUE        ((SYSCLK_FREQUENCY / PWM_FREQUENCY) - 1)

void PWM_init(void);
void PWM_SetDuty(float duty);

#endif