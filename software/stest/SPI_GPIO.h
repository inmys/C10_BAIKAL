/*
 * SPI_GPIO.h
 *
 *  Created on: 22 июля 2020 г.
 *      Author: ikoml
 */
#ifndef SPI_GPIO_H_
#define SPI_GPIO_H_


alt_u32 SPIReadReg(int);
void SPIWriteReg(int,alt_u32);
void SPI_TxData(alt_u32);
void SPI_GPIOInit(alt_u32 gpio);
void SPI_GPIOWrite(alt_u32);
void SPI_GPIO_Set(alt_u32);
void SPI_GPIO_Clr(alt_u32);
void SPI_GPIO_Mash();


#endif /* SPI_GPIO_H_ */
