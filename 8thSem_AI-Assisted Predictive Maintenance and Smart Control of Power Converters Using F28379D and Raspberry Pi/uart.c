#include "uart.h"
#include <stdlib.h>

#define RX_BUFFER_SIZE 20

static char rxBuffer[RX_BUFFER_SIZE];
static uint16_t index = 0;

void UART_init(void)
{
    //
    // GPIO16 -> SCIA TX
    // GPIO17 -> SCIA RX
    //
    GPIO_setPinConfig(GPIO_16_SCIA_TX);
    GPIO_setPinConfig(GPIO_17_SCIA_RX);

    GPIO_setPadConfig(16, GPIO_PIN_TYPE_STD);
    GPIO_setPadConfig(17, GPIO_PIN_TYPE_STD);

    GPIO_setQualificationMode(17, GPIO_QUAL_ASYNC);

    SCI_performSoftwareReset(SCIA_BASE);

    SCI_setConfig(SCIA_BASE,
                  DEVICE_LSPCLK_FREQ,
                  115200,
                  (SCI_CONFIG_WLEN_8 |
                   SCI_CONFIG_STOP_ONE |
                   SCI_CONFIG_PAR_NONE));

    SCI_resetChannels(SCIA_BASE);

    SCI_clearInterruptStatus(SCIA_BASE,
                             SCI_INT_RXFF |
                             SCI_INT_TXFF);

    SCI_enableModule(SCIA_BASE);

    SCI_performSoftwareReset(SCIA_BASE);
}

uint16_t UART_Available(void)
{
    return SCI_getRxFIFOStatus(SCIA_BASE);
}

float UART_ReadFloat(void)
{
    char c;

    while(1)
    {
        while(SCI_getRxFIFOStatus(SCIA_BASE) == SCI_FIFO_RX0)
        {

        }

        c = SCI_readCharBlockingFIFO(SCIA_BASE);

        if(c == '\n' || c == '\r')
        {
            rxBuffer[index] = '\0';

            index = 0;

            return (float)atof(rxBuffer);
        }

        if(index < RX_BUFFER_SIZE - 1)
        {
            rxBuffer[index++] = c;
        }
    }
}