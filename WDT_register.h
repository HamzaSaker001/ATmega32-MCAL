/*
 * WDT_register.h
 *
 * Created: 2/18/2026 12:40:42 PM
 *  Author: hamza
 */ 


#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_

#define WDTCR_REG     (*(volatile u8*)0x41)
#define WDTOE         4
#define WDE 	      3
#define WDP2 	      2
#define WDP1 	      1
#define WDP0          0


#endif /* WDT_REGISTER_H_ */