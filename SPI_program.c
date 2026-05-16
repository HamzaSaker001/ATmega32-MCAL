/*
 * SPI_program.c
 *
 * Created: 2/20/2026 4:02:20 PM
 *  Author: hamza
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "SPI_interface.h"
#include "SPI_register.h"

static void(*PRV_pToFunCallBack)(u8);


void SPI_voidInit(u8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case SPI_MASTER_MODE:
		
		/* Select Master Mode */
		SET_BIT(SPCR_REG, MSTR);
		
		/* Select CLK Rate = FCPU/128 (125 KHZ) */
		SET_BIT(SPCR_REG, SPR0);
		SET_BIT(SPCR_REG, SPR1);
		CLR_BIT(SPSR_REG, SPI2X);
		break;
		
		case SPI_SLAVE_MODE:
		
		/* Select Slave Mode */
		CLR_BIT(SPCR_REG, MSTR);
		break;
	}
	
	/* Disable SPI interrupt */
	CLR_BIT(SPCR_REG, SPIE);
	
	/* Select Data Order LSB transmitted first */
	SET_BIT(SPCR_REG, DORD);
	
	/* Select CLK Polarity Falling => Rising, Select CLK Phase Setup => Sample */
	SET_BIT(SPCR_REG, CPHA);
	SET_BIT(SPCR_REG, CPOL);
	
	/* Enable SPI */
	SET_BIT(SPCR_REG, SPE);
}

void SPI_voidTransceive(u8 copy_u8TxData, u8* pu8RxData)
{
	if(pu8RxData != NULL)
	{
		/* Write Tx Data into Data Reg. */
		SPDR_REG = copy_u8TxData;
		
		/* Busy wait for SPI transfer flag */
		while(0 == GET_BIT(SPSR_REG, SPIF));
		
		/* Pass out  Rx Data from Data Reg */
		*pu8RxData = SPDR_REG;
	}
	else
	{
		// return Error State
	}
}

void SPI_voidTransceiveAsynchronous(u8 copy_u8TxData, void(*pTpFunCallBack)(u8))
{
	if(pTpFunCallBack !=NULL)
	{
		/* Enable SPI interrupt */
		SET_BIT(SPCR_REG, SPIE);
		
		PRV_pToFunCallBack = pTpFunCallBack;
		
		/* Write Tx Data into Data Reg. */
		SPDR_REG = copy_u8TxData;
	}
	else
	{
		// return Error State
	}
}


void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	if(PRV_pToFunCallBack != NULL)
	{
		PRV_pToFunCallBack(SPDR_REG);
	}
	else
	{
		// return Error State
	}
}