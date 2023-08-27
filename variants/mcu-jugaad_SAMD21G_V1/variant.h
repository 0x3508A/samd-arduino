/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  ---------------------------------------------------------------------------------------

  Copyright (c) 2023 Abhijit Bose - All Rights Reserved
  This work is licensed under the 
  Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 
  To view a copy of this license, 
  visit http://creativecommons.org/licenses/by-nc-nd/4.0/ or 
  send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
 
  SPDX: CC-BY-NC-ND-4.0
 
  You should have received a copy of the Creative Commons
  Attribution-NonCommercial-NoDerivatives 4.0 International License
  along with this Package; if not, write to the Creative Commons, PO Box 1866, 
  Mountain View, CA 94042, USA.
*/

#ifndef _VARIANT_MCU_JUGAAD_SAMD21G_V1_
#define _VARIANT_MCU_JUGAAD_SAMD21G_V1_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)

/** Offset Used during Porting of the Variants */
#define VARIANT_PIN_OFFSET 0
//#define VARIANT_PIN_OFFSET 46

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
//#define NUM_DIGITAL_PINS     (20u)
#define NUM_DIGITAL_PINS     (40u)
//#define NUM_ANALOG_INPUTS    (6u)
#define NUM_ANALOG_INPUTS    (10u)
#define NUM_ANALOG_OUTPUTS   (1u)
//#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs
//#define PIN_LED_13           (13u)
#define PIN_LED_13           (VARIANT_PIN_OFFSET + 25u)
//#define PIN_LED_RXL          (25u)
//#define PIN_LED_TXL          (26u)
#define PIN_LED              PIN_LED_13
//#define PIN_LED2             PIN_LED_RXL
//#define PIN_LED3             PIN_LED_TXL
//#define LED_BUILTIN          PIN_LED_13
#define LED_BUILTIN          (VARIANT_PIN_OFFSET + 25u)

/*
 * Analog pins
 */
//#define PIN_A0               (14ul)
#define PIN_A0               (VARIANT_PIN_OFFSET + 10ul)
//#define PIN_A1               (15ul)
#define PIN_A1               (VARIANT_PIN_OFFSET + 11ul)
//#define PIN_A2               (16ul)
#define PIN_A2               (VARIANT_PIN_OFFSET + 12ul)
//#define PIN_A3               (17ul)
#define PIN_A3               (VARIANT_PIN_OFFSET + 13ul)
//#define PIN_A4               (18ul)
#define PIN_A4               (VARIANT_PIN_OFFSET + 14ul)
//#define PIN_A5               (19ul)
#define PIN_A5               (VARIANT_PIN_OFFSET + 15ul)
#define PIN_A6               (VARIANT_PIN_OFFSET + 16ul)
#define PIN_A7               (VARIANT_PIN_OFFSET + 17ul)
#define PIN_A8               (VARIANT_PIN_OFFSET + 18ul)
#define PIN_A9               (VARIANT_PIN_OFFSET + 19ul)
#define PIN_A10               (VARIANT_PIN_OFFSET + 22ul)
#define PIN_A11               (VARIANT_PIN_OFFSET + 23ul)
#define PIN_A12               (VARIANT_PIN_OFFSET + 24ul) // Button
#define PIN_A13               (VARIANT_PIN_OFFSET + 25ul) // LED

//#define PIN_DAC0             (14ul)
#define PIN_DAC0             (VARIANT_PIN_OFFSET + 44ul)
#define PIN_AREF             (VARIANT_PIN_OFFSET + 43ul)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t A6  = PIN_A6;
static const uint8_t A7  = PIN_A7;
static const uint8_t A8  = PIN_A8;
static const uint8_t A9  = PIN_A9;
static const uint8_t A10  = PIN_A10;
static const uint8_t A11  = PIN_A11;
static const uint8_t A12  = PIN_A12;
static const uint8_t A13  = PIN_A13;
static const uint8_t AREF  = PIN_AREF;
static const uint8_t DAC0 = PIN_DAC0;
#define ADC_RESOLUTION		12

// Other pins
// #define PIN_ATN              (38ul)
// static const uint8_t ATN = PIN_ATN;

/*
 * Pin by Port Names
 */
// Left Side
#define PB22                (VARIANT_PIN_OFFSET + 4ul)
#define PB23                (VARIANT_PIN_OFFSET + 5ul)
#define PB27                (VARIANT_PIN_OFFSET + 6ul)
#define PB28                (VARIANT_PIN_OFFSET + 7ul)
#define PA30                (VARIANT_PIN_OFFSET + 8ul)
#define PA31                (VARIANT_PIN_OFFSET + 9ul)
#define PB02                (VARIANT_PIN_OFFSET + 10ul)
#define PB03                (VARIANT_PIN_OFFSET + 11ul)
#define PA02                (VARIANT_PIN_OFFSET + 12ul)
#define PA03                (VARIANT_PIN_OFFSET + 13ul)
#define PB08                (VARIANT_PIN_OFFSET + 14ul)
#define PB09                (VARIANT_PIN_OFFSET + 15ul)
#define PA04                (VARIANT_PIN_OFFSET + 16ul)
#define PA05                (VARIANT_PIN_OFFSET + 17ul)
#define PA06                (VARIANT_PIN_OFFSET + 18ul)
#define PA07                (VARIANT_PIN_OFFSET + 19ul)
// Right Side
#define PA08                (VARIANT_PIN_OFFSET + 22ul)
#define PA09                (VARIANT_PIN_OFFSET + 23ul)
#define PA10                (VARIANT_PIN_OFFSET + 24ul)
#define PA11                (VARIANT_PIN_OFFSET + 25ul)
#define PB10                (VARIANT_PIN_OFFSET + 26ul)
#define PB11                (VARIANT_PIN_OFFSET + 27ul)
#define PA12                (VARIANT_PIN_OFFSET + 28ul)
#define PA13                (VARIANT_PIN_OFFSET + 29ul)
#define PA14                (VARIANT_PIN_OFFSET + 30ul)
#define PA15                (VARIANT_PIN_OFFSET + 31ul)
#define PA16                (VARIANT_PIN_OFFSET + 32ul)
#define PA17                (VARIANT_PIN_OFFSET + 33ul)
#define PA18                (VARIANT_PIN_OFFSET + 34ul)
#define PA19                (VARIANT_PIN_OFFSET + 35ul)
#define PA20                (VARIANT_PIN_OFFSET + 36ul)
#define PA21                (VARIANT_PIN_OFFSET + 37ul)
#define PA22                (VARIANT_PIN_OFFSET + 38ul)
#define PA23                (VARIANT_PIN_OFFSET + 39ul)

/*
 * Serial interfaces
 */
// Serial (EDBG)
// Now this is Serial0
//#define PIN_SERIAL_RX       (31ul)
#define PIN_SERIAL_RX       (VARIANT_PIN_OFFSET + 5ul)
//#define PIN_SERIAL_TX       (30ul)
#define PIN_SERIAL_TX       (VARIANT_PIN_OFFSET + 4ul)
#define PAD_SERIAL_TX       (UART_TX_PAD_2)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_3)

// Serial1
//#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_RX       (VARIANT_PIN_OFFSET + 27ul)
//#define PIN_SERIAL1_TX       (1ul)
#define PIN_SERIAL1_TX       (VARIANT_PIN_OFFSET + 26ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_2)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_3)

/*
 * SPI Interfaces
 */
//#define SPI_INTERFACES_COUNT 1
#define SPI_INTERFACES_COUNT 2

//#define PIN_SPI_MISO         (22u)
#define PIN_SPI_MISO         (VARIANT_PIN_OFFSET + 31u)
//#define PIN_SPI_MOSI         (23u)
#define PIN_SPI_MOSI         (VARIANT_PIN_OFFSET + 28u)
//#define PIN_SPI_SCK          (24u)
#define PIN_SPI_SCK          (VARIANT_PIN_OFFSET + 29u)
#define PIN_SPI_SS           (VARIANT_PIN_OFFSET + 30u)
//#define PERIPH_SPI           sercom4
#define PERIPH_SPI           sercom2
//#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
//#define PAD_SPI_RX           SERCOM_RX_PAD_0
#define PAD_SPI_RX           SERCOM_RX_PAD_3

//static const uint8_t SS	  = PIN_A2 ;	// SERCOM4 last PAD is present on A2 but HW SS isn't used. Set here only for reference.
static const uint8_t SS	  = PIN_SPI_SS ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

#define PIN_SPI1_MISO         (VARIANT_PIN_OFFSET + 35u)
#define PIN_SPI1_MOSI         (VARIANT_PIN_OFFSET + 32u)
#define PIN_SPI1_SCK          (VARIANT_PIN_OFFSET + 33u)
#define PIN_SPI1_SS           (VARIANT_PIN_OFFSET + 34u)
#define PERIPH_SPI1           sercom1
#define PAD_SPI1_TX           SPI_PAD_0_SCK_1
#define PAD_SPI1_RX           SERCOM_RX_PAD_3

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

//#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SDA         (VARIANT_PIN_OFFSET + 38u)
//#define PIN_WIRE_SCL         (21u)
#define PIN_WIRE_SCL         (VARIANT_PIN_OFFSET + 39u)
#define PERIPH_WIRE          sercom3
#define WIRE_IT_HANDLER      SERCOM3_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
//#define PIN_USB_HOST_ENABLE (27ul)
//#define PIN_USB_DM          (28ul)
#define PIN_USB_DM          (VARIANT_PIN_OFFSET + 41ul)
//#define PIN_USB_DP          (29ul)
#define PIN_USB_DP          (VARIANT_PIN_OFFSET + 42ul)

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 1

#define I2S_DEVICE          0
#define I2S_CLOCK_GENERATOR 3
//#define PIN_I2S_SD          (9u)
#define PIN_I2S_SD          (VARIANT_PIN_OFFSET + 19u)
//#define PIN_I2S_SCK         (1u)
#define PIN_I2S_SCK         (VARIANT_PIN_OFFSET + 24u)
//#define PIN_I2S_FS          (0u)
#define PIN_I2S_FS          (VARIANT_PIN_OFFSET + 25u)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

//extern Uart Serial;
extern Uart Serial0;
extern Uart Serial1;

#endif

#ifdef __cplusplus
extern "C" {
#endif
unsigned int PINCOUNT_fn();
#ifdef __cplusplus
}
#endif

// Override of the Default Serial Port
#define Serial SerialUSB

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
//#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE        Serial0
#define SERIAL_PORT_HARDWARE_OPEN   Serial1


#endif /* _VARIANT_MCU_JUGAAD_SAMD21G_V1_ */

