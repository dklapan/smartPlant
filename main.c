/**
 *	Keil project for NRF24L01+ transceiver
 *
 *	Receiver code
 *
 *	Before you start, select your target, on the right of the "Load" button
 *
 *	@author		Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@ide		Keil uVision 5
 *	@packs		STM32F4xx Keil packs version 2.2.0 or greater required
 *	@stdperiph	STM32F4xx Standard peripheral drivers version 1.4.0 or greater required
 */
/* Include core modules */
#include <main.h>

/* Receiver address */
uint8_t TxAddress[] = {
	0xE7,
	0xE7,
	0xE7,
	0xE7,
	0xE7
};
/* My address */
uint8_t MyAddress[] = {
	0x7E,
	0x7E,
	0x7E,
	0x7E,
	0x7E
};

uint8_t dataOut[32], dataIn[32];

int main(void) {
	TM_NRF24L01_Transmit_Status_t transmissionStatus;

	if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* Capture error */ 
    while (1);
  }
  gpio_init();
	spi1_init();
	
	/* Initialize NRF24L01+ on channel 15 and 32bytes of payload */
	/* By default 2Mbps data rate and 0dBm output power */
	/* NRF24L01 goes to RX mode by default */
	TM_NRF24L01_Init(15, 32);
	
	/* Set RF settings, Data rate to 2Mbps, Output power to -18dBm */
	TM_NRF24L01_SetRF(TM_NRF24L01_DataRate_2M, TM_NRF24L01_OutputPower_M18dBm);
	
	/* Set my address, 5 bytes */
	TM_NRF24L01_SetMyAddress(MyAddress);
	/* Set TX address, 5 bytes */
	TM_NRF24L01_SetTxAddress(TxAddress);
	
	

	while (1) {
		LED_ON;
		/* If data is ready on NRF24L01+ */
		if (TM_NRF24L01_DataReady()) {
			/* Get data from NRF24L01+ */
			TM_NRF24L01_GetData(dataIn);
			
			/* Send it back, automatically goes to TX mode */
			TM_NRF24L01_Transmit(dataIn);
			
			/* Start send */
			LED_ON;
			/* Wait for data to be sent */
			do {
				transmissionStatus = TM_NRF24L01_GetTransmissionStatus();
			} while (transmissionStatus == TM_NRF24L01_Transmit_Status_Sending);
			/* Send done */
			LED_OFF;
			
			/* Go back to RX Mode */
			TM_NRF24L01_PowerUpRx();		
		}
	}
}

