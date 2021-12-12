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
 *  ======== gpioButtonFxn0 ========
 *  Callback function for the GPIO interrupt on CONFIG_GPIO_BUTTON_0.
 *
 *  Note: GPIO interrupts are cleared prior to invoking callbacks.
 */
void gpioButtonFxn0(uint_least8_t index)
{
    /* Toggle an LED */
    GPIO_toggle(CONFIG_GPIO_LED_0);
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

      printf("Button R Pressed \n");

}


void gpioButtonFxn1(uint_least8_t index)
{
    /* Toggle an LED */
    GPIO_toggle(CONFIG_GPIO_LED_0);
        GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

         printf("Button L Pressed \n");

}


/*
 *  ======== mainThread ========
 */

void *mainThread(void *arg0)
{

        GPIO_init();


        GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
        GPIO_setConfig(CONFIG_GPIO_BUTTON_0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);


        GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);

        /* Install Button callback */
        GPIO_setCallback(CONFIG_GPIO_BUTTON_0, gpioButtonFxn0);

        /* Enable interrupts */
        GPIO_enableInt(CONFIG_GPIO_BUTTON_0);

        /*
         *  If more than one input pin is available for your device, interrupts
         *  will be enabled on CONFIG_GPIO_BUTTON1.
         */
        if (CONFIG_GPIO_BUTTON_0 != CONFIG_GPIO_BUTTON_1) {
            /* Configure BUTTON1 pin */
        GPIO_setConfig(CONFIG_GPIO_BUTTON_1, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

            /* Install Button callback */
            GPIO_setCallback(CONFIG_GPIO_BUTTON_1, gpioButtonFxn1);
            GPIO_enableInt(CONFIG_GPIO_BUTTON_1);


        }

        return (NULL);


}
