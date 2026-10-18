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
#include "stm32f3xx_hal.h"

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
#define GP22_SSN_Pin GPIO_PIN_12
#define GP22_SSN_GPIO_Port GPIOB
#define DEBUG_STROBE_Pin GPIO_PIN_6
#define DEBUG_STROBE_GPIO_Port GPIOC
#define TX_PWR_EN_Pin GPIO_PIN_7
#define TX_PWR_EN_GPIO_Port GPIOC
#define TX_DAMP_Pin GPIO_PIN_8
#define TX_DAMP_GPIO_Port GPIOC
#define USB_PU_Pin GPIO_PIN_9
#define USB_PU_GPIO_Port GPIOA
#define GP22_EN_START_Pin GPIO_PIN_11
#define GP22_EN_START_GPIO_Port GPIOC
#define GP22_INTN_Pin GPIO_PIN_3
#define GP22_INTN_GPIO_Port GPIOB
#define RX_SEL_Pin GPIO_PIN_8
#define RX_SEL_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
