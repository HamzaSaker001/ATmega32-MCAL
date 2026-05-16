/*
 * SPI_interface.h
 *
 * Created: 2/20/2026 4:02:05 PM
 *  Author: hamza
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_MASTER_MODE			0
#define SPI_SLAVE_MODE			1

/********************* APIs Prototypes *********************/

void SPI_voidInit(u8 copy_u8Mode);
void SPI_voidTransceive(u8 copy_u8TxData, u8* pu8RxData);
void SPI_voidTransceiveAsynchronous(u8 copy_u8TxData, void(*pTpFunCallBack)(u8));

#endif /* SPI_INTERFACE_H_ */