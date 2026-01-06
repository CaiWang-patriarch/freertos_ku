#include "self_gpio.h"
#include "SELF_GPIO_BASE.h"
#include <stdint.h>

static void stm32h7xx_gpio_init()
{
    return;
}

static void stm32h7xx_gpio_set_level(void *pThis, uint8_t level)
{
    GPIO_Base *obj = (GPIO_Base *)pThis;
    if (level)
        HAL_GPIO_WritePin((GPIO_TypeDef *)obj->GPIOx, obj->GPIO_PIN, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin((GPIO_TypeDef *)obj->GPIOx, obj->GPIO_PIN, GPIO_PIN_RESET);
    return;
}

static void stm32h7xx_gpio_get_level(void *pThis, uint8_t *level)
{
    GPIO_Base *obj = (GPIO_Base *)pThis;
    *level = HAL_GPIO_ReadPin((GPIO_TypeDef *)obj->GPIOx, obj->GPIO_PIN);
    return;
}

static void stm32h7xx_gpio_toggle(void *pThis)
{
    GPIO_Base *obj = (GPIO_Base *)pThis;
    HAL_GPIO_TogglePin((GPIO_TypeDef *)obj->GPIOx, obj->GPIO_PIN);
    return;
}

static const GPIO_VTable stm32h7xx_gpio_vtable = {
    .Init = stm32h7xx_gpio_init,
    .SetLevel = stm32h7xx_gpio_set_level,
    .GetLevel = stm32h7xx_gpio_get_level,
    .Toggle = stm32h7xx_gpio_toggle,
};

void stm32_gpio_create(GPIO_Base *obj, uint32_t GPIOx, uint16_t GPIO_PIN)
{
    assert(obj != NULL);
    obj->GPIOx = GPIOx;
    obj->GPIO_PIN = GPIO_PIN;
    obj->vptr = &stm32h7xx_gpio_vtable;
}