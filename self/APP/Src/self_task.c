#include "self_task.h"
#include "FreeRTOS.h"
#include "task.h"

#include "led_task.h"

void self_task_start(void)
{
    led_task_start();
    vTaskStartScheduler();
}
