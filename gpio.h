#ifndef GPIO_H
#define GPIO_H

#include <stm32f0xx.h> // common stuff
#include <stm32f0xx_gpio.h> // gpio control
#include <stm32f0xx_rcc.h> // reset anc clocking

#define BlueLED_Pin 			GPIO_Pin_8
#define LED_GPIO 					GPIOC

#define CTRLPORT					GPIOA
#define PIN_CE 						GPIO_Pin_3
#define PIN_CS						GPIO_Pin_4

#define LED_ON						GPIO_SetBits(LED_GPIO, BlueLED_Pin)
#define LED_OFF						GPIO_ResetBits(LED_GPIO, BlueLED_Pin);

void gpio_init(void);

#endif
