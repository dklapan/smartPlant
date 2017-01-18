#include <gpio.h>


void gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct; //Create GPIO struct
	
//Enable clocks to both GPIOA (SPI1) and GPIOC (output LED)
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	
	GPIO_DeInit( GPIOA);
	GPIO_DeInit( GPIOC);
	
	/* LED pin */
	GPIO_InitStruct.GPIO_Pin = BlueLED_Pin; //Set pins inside the struct
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //Set GPIO pins as output
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; //Ensure output is push-pull vs open drain
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; //No internal pullup resistors required
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_1; //Set GPIO speed to lowest
	GPIO_Init(LED_GPIO, &GPIO_InitStruct); //Assign struct to LED_GPIO

	/* NRF CE and CS pin */
	GPIO_InitStruct.GPIO_Pin = PIN_CE | PIN_CS;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
}
