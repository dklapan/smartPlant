#include <spi1.h>

void spi1_init(void){
  GPIO_InitTypeDef  GPIO_InitStructure;
  SPI_InitTypeDef   SPI_InitStructure;

  
  /* SPI1 */
  GPIO_InitStructure.GPIO_Pin = SCK_PIN | MISO_PIN | MOSI_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SPI1_PORT, &GPIO_InitStructure);
  
  GPIO_PinAFConfig(SPI1_PORT,GPIO_PinSource5,GPIO_AF_0);
  GPIO_PinAFConfig(SPI1_PORT,GPIO_PinSource6,GPIO_AF_0);
  GPIO_PinAFConfig(SPI1_PORT,GPIO_PinSource7,GPIO_AF_0);
  
  SPI_StructInit(&SPI_InitStructure);
  
  //SPI_I2S_DeInit(SPI1);
  
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;            // 48/32=1.5
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  
  SPI_Init(SPI1,&SPI_InitStructure);
  
  SPI_RxFIFOThresholdConfig(SPI1, SPI_RxFIFOThreshold_QF);
  
  SPI_Cmd(SPI1,ENABLE);
}
