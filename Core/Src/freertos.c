/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LED0A */
osThreadId_t LED0AHandle;
const osThreadAttr_t LED0A_attributes = {
  .name = "LED0A",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LED0B */
osThreadId_t LED0BHandle;
const osThreadAttr_t LED0B_attributes = {
  .name = "LED0B",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for LED1A */
osThreadId_t LED1AHandle;
const osThreadAttr_t LED1A_attributes = {
  .name = "LED1A",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LED1B */
osThreadId_t LED1BHandle;
const osThreadAttr_t LED1B_attributes = {
  .name = "LED1B",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartLED0A(void *argument);
void StartLED0B(void *argument);
void StartLED1A(void *argument);
void StartLED1B(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LED0A */
  LED0AHandle = osThreadNew(StartLED0A, NULL, &LED0A_attributes);

  /* creation of LED0B */
  LED0BHandle = osThreadNew(StartLED0B, NULL, &LED0B_attributes);

  /* creation of LED1A */
  LED1AHandle = osThreadNew(StartLED1A, NULL, &LED1A_attributes);

  /* creation of LED1B */
  LED1BHandle = osThreadNew(StartLED1B, NULL, &LED1B_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartLED0A */
/**
  * @brief  Function implementing the LED0A thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartLED0A */
void StartLED0A(void *argument)
{
  /* USER CODE BEGIN StartLED0A */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    osDelay(1000);
  }
  /* USER CODE END StartLED0A */
}

/* USER CODE BEGIN Header_StartLED0B */
/**
* @brief Function implementing the LED0B thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLED0B */
void StartLED0B(void *argument)
{
  /* USER CODE BEGIN StartLED0B */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
    osDelay(1100);
  }
  /* USER CODE END StartLED0B */
}

/* USER CODE BEGIN Header_StartLED1A */
/**
* @brief Function implementing the LED1A thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLED1A */
void StartLED1A(void *argument)
{
  /* USER CODE BEGIN StartLED1A */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    osDelay(1000);
  }
  /* USER CODE END StartLED1A */
}

/* USER CODE BEGIN Header_StartLED1B */
/**
* @brief Function implementing the LED1B thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLED1B */
void StartLED1B(void *argument)
{
  /* USER CODE BEGIN StartLED1B */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    osDelay(1050);
  }
  /* USER CODE END StartLED1B */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

