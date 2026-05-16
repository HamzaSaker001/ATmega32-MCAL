#ifndef DIO_ABIS_H
#define DIO_ABIS_H

void DIO_voidSetBinDirection       (u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDirection);
void DIO_voidSetPinValue           (u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue);
void DIO_voidTogglePinValue        (u8 copy_u8PortID, u8 copy_u8PinID);
u8 DIO_u8GetPinValue               (u8 copy_u8PortID, u8 copy_u8PinID);   
void DIO_voidGetPinValue           (u8 copy_u8PortID, u8 copy_u8PinID, u8*pu8PinValue);
void DIO_voidActivePinInternalPUR  (u8 copy_u8PortID, u8 copy_u8PinID);

#endif