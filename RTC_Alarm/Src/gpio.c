/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    RTC/RTC_Alarm/Src/gpio.c
  * @author  rahul polisetti
  * @brief   general purpose GPIO functions
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018-2020 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#include "gpio.h"

GPIO_TypeDef*  GPIO_PORT[GPIOn] = {GPIO1_GPIO_PORT};
const uint16_t GPIO_PIN[GPIOn] = {GPIO1_PIN};

/**
  * @brief  Configures  GPIO.
  * @param  Pin: pin to be configured.
  *         This parameter can be one of the following values:
  * @arg pin
  * @retval None
  */
void BSP_GPIO_Init(GPIO_PIN_TypeDef Pin)
{
  GPIO_InitTypeDef  gpioinitstruct;

  /* Enable the GPIO_LED Clock */
  GPIOx_GPIO_CLK_ENABLE(Pin);

  /* Configure the GPIO_LED pin */
  gpioinitstruct.Pin = GPIO_PIN[Pin];
  gpioinitstruct.Mode = GPIO_MODE_OUTPUT_PP;
  gpioinitstruct.Pull = GPIO_PULLUP;
  gpioinitstruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  HAL_GPIO_Init(GPIO_PORT[Pin], &gpioinitstruct);
}

/**
  * @brief  DeInit Pins.
  * @param  Pin: Pin to be de-init.
  *   This parameter can be one of the following values:
  *     @arg  Pin
  * @note Pin DeInit does not disable the GPIO clock nor disable the Mfx
  * @retval None
  */
void BSP_GPIO_DeInit(GPIO_PIN_TypeDef Pin)
{
  GPIO_InitTypeDef  gpio_init_structure;

  /* Make sure GPIO_LED clock is enable */
  GPIOx_GPIO_CLK_ENABLE(Pin);

  /* DeInit the GPIO_LED pin */
  gpio_init_structure.Pin = GPIO_PIN[Pin];
  HAL_GPIO_DeInit(GPIO_PORT[Pin], gpio_init_structure.Pin);
}

/**
  * @brief  Turns selected PIN On.
  * @param  PIN: Specifies the PIN to be set on.
  *   This parameter can be one of following parameters:
  *     @arg PIN
  * @retval None
  */
void BSP_GPIO_On(GPIO_PIN_TypeDef Pin)
{
  HAL_GPIO_WritePin(GPIO_PORT[Pin], GPIO_PIN[Pin], GPIO_PIN_SET);
}

/**
  * @brief  Turns selected PIN Off.
  * @param  PIN: Specifies the PIN to be set off.
  *   This parameter can be one of following parameters:
  *     @arg PIN
  * @retval None
  */
void BSP_GPIO_Off(GPIO_PIN_TypeDef Pin)
{
  HAL_GPIO_WritePin(GPIO_PORT[Pin], GPIO_PIN[Pin], GPIO_PIN_RESET);
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled.
  *   This parameter can be one of following parameters:
  *     @arg LED4
  * @retval None
  */
void BSP_GPIO_Toggle(GPIO_PIN_TypeDef Pin)
{
  HAL_GPIO_TogglePin(GPIO_PORT[Pin], GPIO_PIN[Pin]);
}

/**
  * @}
  */
