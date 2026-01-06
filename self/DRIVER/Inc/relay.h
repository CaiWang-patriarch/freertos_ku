#ifndef __RELAY_H__
#define __RELAY_H__
#include "SELF_GPIO_BASE.h"
#include "self_gpio.h"

void relay_init(GPIO_Base *pThis);
void relay_On(GPIO_Base *pThis, uint8_t level);
void relay_Off(GPIO_Base *pThis, uint8_t level);
#endif