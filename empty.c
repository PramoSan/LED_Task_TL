/*
 *  ======== PWM LED ========
 */

/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
// #include <ti/drivers/I2C.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/Watchdog.h>

/* Driver configuration */
#include "ti_drivers_config.h"
#include <stdio.h>
#include <ti/drivers/PWM.h>


/*
 *  ======== mainThread ========
 */
uint16_t   duty;
void *mainThread(void *arg0)
{
        uint16_t   pwmPeriod = 5000;
        uint16_t   duty = 0;
        uint16_t   dutyInc = 100;
        uint32_t   time = 10000;
        PWM_Handle pwm1 = NULL;
        PWM_Params params;
        PWM_init();
        PWM_Params_init(&params);
            params.dutyUnits = PWM_DUTY_US;
            params.dutyValue = 0;
            params.periodUnits = PWM_PERIOD_US;
            params.periodValue = pwmPeriod;
            pwm1 = PWM_open(CONFIG_PWM_0, &params);
            if (pwm1 == NULL) {
                /* CONFIG_PWM_0 did not open */
                while (1);
            }
            PWM_start(pwm1);


    while (1) {

        PWM_setDuty(pwm1, duty);

                duty = (duty + dutyInc);

                if (duty == pwmPeriod || (!duty)) {
                    dutyInc = - dutyInc;
                }

                usleep(time);

                    printf("duty %d\n",duty);


           }
}
