/*
 *  ======== Blink with Console Print ========
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

/*
 *  ======== mainThread ========
 */

void *mainThread(void *arg0)
{
    /* 1 second delay */
   // uint32_t time = 2;

    /* Call driver init functions */
    GPIO_init();
    // I2C_init();
    // SPI_init();
    // UART_init();
    // Watchdog_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Turn on user LED */
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);

    while (1) {

        GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
        printf("LED ON \n");
        sleep(1);

        GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
        printf("LED OFF \n");
        sleep(1);

        /*
              printf("1-GPIO_write: %d\n", GPIO_write);
              printf("2-GPIO_toggle: %d\n", GPIO_toggle);
              printf("3-CONFIG_GPIO_LED_0: %d\n", CONFIG_GPIO_LED_0);
              printf("4-GPIO_CFG_OUT_STD: %d\n", GPIO_CFG_OUT_STD);
              printf("5-GPIO_CFG_OUT_LOW: %d\n", GPIO_CFG_OUT_LOW);
              printf("6-CONFIG_GPIO_LED_ON: %d\n", CONFIG_GPIO_LED_ON);
        */


           }
}
