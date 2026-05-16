/*
 * WDT_program.c
 *
 * Created: 2/18/2026 12:40:09 PM
 *  Author: hamza
 */ 
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "WDT_interface.h"
#include "WDT_register.h"
#include "DIO_interface.h"

void WDT_voidEnable(void)
{
	/* set perscaler */
	
	CLR_BIT(WDTCR_REG, WDP2);
	SET_BIT(WDTCR_REG, WDP1);
	CLR_BIT(WDTCR_REG, WDP0);
	
	CLR_BIT(WDTCR_REG, WDTOE);
	SET_BIT(WDTCR_REG, WDE);
}

void WDT_voidDisable(void)
{
	SET_BIT(WDTCR_REG, WDTOE);
	
	CLR_BIT(WDTCR_REG, WDP2);
	CLR_BIT(WDTCR_REG, WDP1);
	CLR_BIT(WDTCR_REG, WDP0);
	
}