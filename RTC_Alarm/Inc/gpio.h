/*
 * test.h
 *
 *  Created on: May 28, 2022
 *      Author: rahulpolisetti
 */


#ifndef GPIO_H_
#define GPIO_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32g0xx_nucleo.h"
#include <stdio.h>

/** @defgroup STM32G0XX_NUCLEO_GPIO GPIO Constants
  * @{
  */
#define GPIOn                               1

#define GPIO1_PIN                           GPIO_PIN_9
#define GPIO1_GPIO_PORT                     GPIOD
#define GPIO1_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOD_CLK_ENABLE()
#define GPIO1_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOD_CLK_DISABLE()

#define GPIOx_GPIO_CLK_ENABLE(__INDEX__)   do { if((__INDEX__) == 0) GPIO1_GPIO_CLK_ENABLE();} while(0)
#define GPIOx_GPIO_CLK_DISABLE(__INDEX__)  (((__INDEX__) == 0) ? GPIO1_GPIO_CLK_DISABLE() : 0)


typedef enum
{
  PIO = 0,
  TX2 = 1
} GPIO_PIN_TypeDef;

GPIO_TypeDef*  GPIO_PORT[GPIOn] = {GPIO1_GPIO_PORT};
const uint16_t GPIO_PIN[GPIOn] = {GPIO1_PIN};

/** @defgroup STM32G0XX_NUCLEO_GPIO_Functions  Custom GPIO Functions
  * @{
  */
void             BSP_GPIO_Init(GPIO_PIN_TypeDef Pin);
void             BSP_GPIO_DeInit(GPIO_PIN_TypeDef Pin);
void             BSP_GPIO_On(GPIO_PIN_TypeDef Pin);
void             BSP_GPIO_Off(GPIO_PIN_TypeDef Pin);
void             BSP_GPIO_Toggle(GPIO_PIN_TypeDef Pin);
/**
  * @}
  */


#endif /* GPIO_H_ */
