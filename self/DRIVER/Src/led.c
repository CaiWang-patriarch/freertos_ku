#include "led.h"
#include "SELF_GPIO_BASE.h"

void led_init(GPIO_Base *pThis)
{
    stm32_gpio_create((GPIO_Base *)pThis, pThis->GPIOx, pThis->GPIO_PIN);
    ((GPIO_Base *)pThis)->vptr->Init((GPIO_Base *)pThis);
    return;
}

void led_On(GPIO_Base *pThis, uint8_t level)
{
    pThis->vptr->SetLevel(pThis, level);
    return;
}

void led_Off(GPIO_Base *pThis, uint8_t level)
{
    pThis->vptr->SetLevel(pThis, level);
    return;
}

void led_Toggle(GPIO_Base *pThis)
{
    pThis->vptr->Toggle(pThis);
    return;
}