#ifndef _SELF_GPIO_H
#define _SELF_GPIO_H
#include "SELF_GPIO_BASE.h"
#include "stm32h7xx_hal.h"
#include "main.h"
#include <stdint.h>
void stm32_gpio_create(GPIO_Base *obj, uint32_t GPIOx, uint16_t GPIO_PIN);

#endif // _SELF_GPIO_H
