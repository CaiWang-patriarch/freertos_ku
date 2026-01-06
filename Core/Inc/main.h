/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PSC_VALUE (1-1)
#define ARR_VALUE (12-1)
#define LED_Pin GPIO_PIN_12
#define LED_GPIO_Port GPIOE
#define REY6_Pin GPIO_PIN_11
#define REY6_GPIO_Port GPIOC
#define REY5_Pin GPIO_PIN_12
#define REY5_GPIO_Port GPIOC
#define REY4_Pin GPIO_PIN_0
#define REY4_GPIO_Port GPIOD
#define REY3_Pin GPIO_PIN_1
#define REY3_GPIO_Port GPIOD
#define REY2_Pin GPIO_PIN_2
#define REY2_GPIO_Port GPIOD
#define REY1_Pin GPIO_PIN_3
#define REY1_GPIO_Port GPIOD
#define REY14_Pin GPIO_PIN_4
#define REY14_GPIO_Port GPIOD
#define REY13_Pin GPIO_PIN_5
#define REY13_GPIO_Port GPIOD
#define REY12_Pin GPIO_PIN_6
#define REY12_GPIO_Port GPIOD
#define REY11_Pin GPIO_PIN_7
#define REY11_GPIO_Port GPIOD
#define REY10_Pin GPIO_PIN_3
#define REY10_GPIO_Port GPIOB
#define REY9_Pin GPIO_PIN_4
#define REY9_GPIO_Port GPIOB
#define REY8_Pin GPIO_PIN_5
#define REY8_GPIO_Port GPIOB
#define REY7_Pin GPIO_PIN_6
#define REY7_GPIO_Port GPIOB
#define REY16_Pin GPIO_PIN_7
#define REY16_GPIO_Port GPIOB
#define REY15_Pin GPIO_PIN_9
#define REY15_GPIO_Port GPIOB
#define REY18_Pin GPIO_PIN_0
#define REY18_GPIO_Port GPIOE
#define REY17_Pin GPIO_PIN_1
#define REY17_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
