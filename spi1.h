#ifndef SPI1_H
#define SPI1_H

#include <stm32f0xx.h> // common stuff
#include <stm32f0xx_gpio.h> // gpio control
#include <stm32f0xx_rcc.h> // reset anc clocking
#include <stm32f0xx_spi.h> // spi control

#define SPI1_PORT 	GPIOA
#define SCK_PIN			GPIO_Pin_5
#define MISO_PIN		GPIO_Pin_6
#define MOSI_PIN		GPIO_Pin_7

void spi1_init(void);

#endif
