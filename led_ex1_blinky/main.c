#include "driverlib.h"
#include "device.h"

#include "pwm.h"
#include "uart.h"

float Vin = 12.0f;
float Vout = 0.0f;
float Duty = 0.0f;

int main(void)
{
    Device_init();

    Device_initGPIO();

    Interrupt_initModule();
    Interrupt_initVectorTable();

    PWM_init();

    UART_init();

    EINT;
    ERTM;

    while(1)
    {
        if(UART_Available())
        {
            Vout = UART_ReadFloat();

            if(Vout < 0.0f)
                Vout = 0.0f;

            if(Vout > 11.0f)
                Vout = 11.0f;

            Duty = (Vout / Vin) * 100.0f;

            PWM_SetDuty(Duty);
        }
    }
}