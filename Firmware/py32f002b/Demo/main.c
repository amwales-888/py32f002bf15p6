/**
  ******************************************************************************
  * PY32F002B UART Printf Demo
  * 
  * PA3     -->              USB2TTL-RX
  * PA4     -->              USB2TTL-TX
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "py32f002b_bsp_clock.h"
#include "py32f002b_bsp_printf.h"

/* Private function prototypes -----------------------------------------------*/
static void APP_GpioConfig(void);

/**
  * @brief  Main program.
  * @retval int
  */
int main(void)
{
  uint8_t count = 0;
		
  BSP_RCC_HSI_48MConfig();

  /* Configure PA1 pin in output push-pull mode to drive external LEDs */
  APP_GpioConfig();

  /* LED off*/
  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
	
  BSP_USART_Config(9600);
  printf("PY32F002B LED Blink and UART Printf Demo\r\nClock: %u\r\n", SystemCoreClock);

  while (1)
  {
    printf("print count: %d\r\n", count++);
    LL_mDelay(1000);
		LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_1);
  }
}

void APP_ErrorHandler(void)
{
  /* Infinite loop */
  while (1);
}

/**
  * @brief  GPIO configuration program
  * @param  None
  * @retval None
  */
static void APP_GpioConfig(void)
{
  /* Enable GPIOA clock */
  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);

  /* Configure PA1 in output mode */
  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_1, LL_GPIO_MODE_OUTPUT);
  /* Default output type (after reset) is push-pull */
  /* LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_1, LL_GPIO_OUTPUT_PUSHPULL); */
  /* Configure GPIO speed in low speed */
  /* LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_1, LL_GPIO_SPEED_FREQ_LOW); */
  /* Default (after reset) is no pull */
  /* LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_1, LL_GPIO_PULL_NO); */
}



#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file：Pointer to the source file name
  * @param  line：assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add His own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1);
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
