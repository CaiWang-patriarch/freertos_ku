#ifndef _SELF_GPIO_BASE_H
#define _SELF_GPIO_BASE_H
#include <stdint.h>
#include <assert.h> 

// ---------------- 通用枚举：GPIO模式（覆盖所有单片机的常见模式） ----------------
typedef enum {
    GPIO_MODE_OUTPUT_PUSH_PULL,  // 推挽输出（LED/蜂鸣器）
    GPIO_MODE_OUTPUT_OPEN_DRAIN, // 开漏输出（I2C/总线）
    GPIO_MODE_INPUT_FLOATING,    // 浮空输入（ADC/传感器）
    GPIO_MODE_INPUT_PULL_UP,     // 上拉输入（按键）
    GPIO_MODE_INPUT_PULL_DOWN    // 下拉输入
} GPIO_GeneralMode; // 通用模式枚举，跨所有单片机

// ---------------- 通用虚函数表：定义接口规范（纯抽象） ----------------
typedef struct GPIO_VTable {
    void (*Init)(void *pThis);       // 通用初始化接口
    void (*SetLevel)(void *pThis, uint8_t level); // 通用电平设置接口
    void (*GetLevel)(void *pThis, uint8_t *level); // 通用电平获取接口
    void (*Toggle)(void *pThis);    // 通用电平切换接口
} GPIO_VTable;

// ---------------- 通用GPIO虚类（抽象层核心，所有单片机共用） ----------------
typedef struct GPIO_Base {
    // 通用硬件属性（用通用类型，适配所有单片机）
    volatile uint32_t        GPIOx;  // 端口物理地址（51:0x90=P1；STM32:0x40020000=GPIOA）
    uint16_t         GPIO_PIN;        // 引脚号（0~15，覆盖所有单片机引脚范围）
    GPIO_GeneralMode MODE; // 通用模式（映射到单片机实际模式）

    // 虚函数表指针（多态核心）
   const GPIO_VTable * vptr;
} GPIO_Base;

static inline void GPIO_Init(GPIO_Base *obj) {
    if (obj && obj->vptr && obj->vptr->Init) obj->vptr->Init(obj);
}
static inline void GPIO_SetLevel(GPIO_Base *obj, uint8_t level) {
    if (obj && obj->vptr && obj->vptr->SetLevel) obj->vptr->SetLevel(obj, level);
}
static inline void GPIO_GetLevel(GPIO_Base *obj, uint8_t *level) {
    if (obj && obj->vptr && obj->vptr->GetLevel) obj->vptr->GetLevel(obj, level);
}
static inline void GPIO_Toggle(GPIO_Base *obj) {
    if (obj && obj->vptr && obj->vptr->Toggle) obj->vptr->Toggle(obj);
}

#endif // GPIO_BASE_H