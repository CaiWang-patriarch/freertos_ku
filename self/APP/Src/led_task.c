#include "led_task.h"
#include "led.h"
#include "FreeRTOS.h"
#include "main.h"
#include "task.h"
#include <stdint.h>

static GPIO_Base pThis;

static void led_task(void *pvParameters)
{
    led_init((GPIO_Base *)pvParameters);
    while (1)
    {
        led_Toggle((GPIO_Base *)pvParameters);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void led_task_start(void)
{
    pThis = (GPIO_Base){
        .GPIOx = (uint32_t)LED_GPIO_Port,
        .GPIO_PIN = LED_Pin,
    };
    xTaskCreate(led_task, "led_task", configMINIMAL_STACK_SIZE, (void *)&pThis, tskIDLE_PRIORITY + 1, NULL);
}