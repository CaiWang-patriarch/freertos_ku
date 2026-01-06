#ifndef __LED_H__
#define __LED_H__
#include "SELF_GPIO_BASE.h"
#include "self_gpio.h"

void led_init(GPIO_Base *pThis);
void led_On(GPIO_Base *pThis, uint8_t level);
void led_Off(GPIO_Base *pThis, uint8_t level);
void led_Toggle(GPIO_Base *pThis);

#endif
