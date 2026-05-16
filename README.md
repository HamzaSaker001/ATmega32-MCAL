# ATmega32 MCAL — Microcontroller Abstraction Layer

A complete set of hardware driver modules for the **ATmega32 AVR microcontroller**, written in Embedded C following an **AUTOSAR-inspired layered architecture**. Each driver is structured with a clean separation between interface, implementation, configuration, and private registers.

---

## Architecture

```
Application Layer
      │
HAL (Hardware Abstraction Layer)
      │
MCAL (Microcontroller Abstraction Layer)  ← This repo
      │
ATmega32 Hardware
```

---

## Modules

| Driver | Files | Description |
|---|---|---|
| DIO | DIO_Interface.h / DIO_Program.c | Digital Input/Output port & pin control |
| ADC | ADC_Interface.h / ADC_Program.c | 10-bit ADC with polling & interrupt modes |
| UART | UART_Interface.h / UART_Program.c | Asynchronous serial communication |
| SPI | SPI_Interface.h / SPI_Program.c | Master/Slave SPI communication |
| I2C (TWI) | I2C_Interface.h / I2C_Program.c | Two-wire interface for EEPROM, sensors |
| Timer | TIMER_Interface.h / TIMER_Program.c | Timer0/1/2 — normal, CTC, PWM modes |
| EXTI | EXTI_Interface.h / EXTI_Program.c | External interrupt configuration (INT0/1/2) |

---

## File Convention (AUTOSAR MCAL style)

Each module follows a 4-file structure:

| File | Purpose |
|---|---|
| `MODULE_Interface.h` | Public API — functions & macros used by upper layers |
| `MODULE_Program.c` | Driver implementation |
| `MODULE_Private.h` | Register addresses & internal macros (not exposed) |
| `MODULE_Config.h` | User-configurable options (baud rate, prescaler, etc.) |

---

## Shared Types (LIB/)

- `Std_Types.h` — Standard type definitions (uint8, uint16, uint32, etc.)
- `Compiler.h` — Compiler abstraction macros
- `Platform_Types.h` — Platform-specific types

---

## Tools & Environment

- **Language:** Embedded C (C99)
- **MCU:** ATmega32 (AVR, 8-bit, 16 MHz)
- **Toolchain:** AVR-GCC / Atmel Studio / VSCode + avr-gcc
- **Programmer:** USBasp / AVRDUDE
- **Simulation:** Proteus

---

## Author

**Hamza Alaa Saker**
Mechatronics Engineering Student — Zagazig University
[![GitHub](https://img.shields.io/badge/GitHub-HamzaSaker001-black?logo=github)](https://github.com/HamzaSaker001)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Hamza_Saker-blue?logo=linkedin)](https://linkedin.com/in/hamzasaker)

---

## License

Educational use. Feel free to reference or build upon with attribution.
