#include "pwm.h"

void PWM_init(void)
{
    //
    // GPIO0 -> ePWM1A
    //
    GPIO_setPinConfig(GPIO_0_EPWM1_A);
    GPIO_setDirectionMode(0, GPIO_DIR_MODE_OUT);
    GPIO_setPadConfig(0, GPIO_PIN_TYPE_STD);

    //
    // Disable TBCLK during configuration
    //
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // Time Base
    //
    EPWM_setTimeBaseCounterMode(
            EPWM1_BASE,
            EPWM_COUNTER_MODE_UP);

    EPWM_setClockPrescaler(
            EPWM1_BASE,
            EPWM_CLOCK_DIVIDER_1,
            EPWM_HSCLOCK_DIVIDER_1);

    EPWM_setTimeBasePeriod(
            EPWM1_BASE,
            TBPRD_VALUE);

    EPWM_setTimeBaseCounter(
            EPWM1_BASE,
            0);

    //
    // Initial Duty = 50%
    //
    EPWM_setCounterCompareValue(
            EPWM1_BASE,
            EPWM_COUNTER_COMPARE_A,
            (TBPRD_VALUE + 1) / 2);

    //
    // HIGH at ZERO
    //
    EPWM_setActionQualifierAction(
            EPWM1_BASE,
            EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_HIGH,
            EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    //
    // LOW at CMPA
    //
    EPWM_setActionQualifierAction(
            EPWM1_BASE,
            EPWM_AQ_OUTPUT_A,
            EPWM_AQ_OUTPUT_LOW,
            EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    //
    // Enable TBCLK
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
}

void PWM_SetDuty(float duty)
{
    uint16_t cmp;

    //
    // Limit duty cycle
    //
    if(duty < 0.0f)
        duty = 0.0f;

    if(duty > 95.0f)
        duty = 95.0f;

    //
    // Calculate Compare Value
    //
    cmp = (uint16_t)(((TBPRD_VALUE + 1) * duty) / 100.0f);

    EPWM_setCounterCompareValue(
            EPWM1_BASE,
            EPWM_COUNTER_COMPARE_A,
            cmp);
}