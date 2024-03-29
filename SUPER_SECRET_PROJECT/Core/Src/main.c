/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
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
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "i2s.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "audio.h"
#include <stdlib.h>
#include "signals.h"
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

/* USER CODE BEGIN PV */
char RX_BUFFER[BUFSIZE];
int RX_BUFFER_HEAD, RX_BUFFER_TAIL;
uint8_t rx_data;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	char c;
	int tone_state[TONE_NUMBER] = {0};
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  MX_DMA_Init();
  MX_I2S3_Init();
  /* USER CODE BEGIN 2 */
  configAudio();
  generateSignals();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if ( USART2_Dequeue(&c) != 0) {
		  if(c=='a'){
			  tone_state[TON_C]^=1;
		  }
		  else if(c=='w'){
			  tone_state[TON_C_SHARP]^=1;
		  }
		  else if(c=='s'){
			  tone_state[TON_D]^=1;
		  }
		  else if(c=='e'){
			  tone_state[TON_D_SHARP]^=1;
		  }
		  else if(c=='d'){
			  tone_state[TON_E]^=1;
		  }
		  else if(c=='f'){
			  tone_state[TON_F]^=1;
		  }
		  else if(c=='t'){
			  tone_state[TON_F_SHARP]^=1;
		  }
		  else if(c=='g'){
			  tone_state[TON_G]^=1;
		  }
		  else if(c=='y' || c=='z'){
			  tone_state[TON_G_SHARP]^=1;
		  }
		  else if(c=='h'){
			  tone_state[TON_A]^=1;
		  }
		  else if(c=='u'){
			  tone_state[TON_A_SHARP]^=1;
		  }
		  else if(c=='j'){
			  tone_state[TON_H]^=1;
		  }
	  }

	  if (tone_state[TON_C] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, C, 2*C_SAMPLES);
	  } else if (tone_state[TON_C_SHARP] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, C_SHARP, 2*C_SHARP_SAMPLES);
	  } else if (tone_state[TON_D] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, D, 2*D_SAMPLES);
	  }	else if (tone_state[TON_D_SHARP] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, D_SHARP, 2*D_SHARP_SAMPLES);
	  } else if (tone_state[TON_E] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, E, 2*E_SAMPLES);
	  } else if (tone_state[TON_F] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, F, 2*F_SAMPLES);
	  } else if (tone_state[TON_F_SHARP] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, F_SHARP, 2*F_SHARP_SAMPLES);
	  } else if (tone_state[TON_G] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, C, 2*G_SAMPLES);
	  } else if (tone_state[TON_G_SHARP] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, G_SHARP, 2*G_SHARP_SAMPLES);
	  } else if (tone_state[TON_A] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, A, 2*A_SAMPLES);
	  } else if (tone_state[TON_A_SHARP] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, A_SHARP, 2*A_SHARP_SAMPLES);
	  } else if (tone_state[TON_H] == 1) {
		  HAL_I2S_Transmit_DMA(&hi2s3, H, 2*H_SAMPLES);
	  } else {
		  HAL_I2S_DMAStop(&hi2s3);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

