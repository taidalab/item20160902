/** @file hal/micro/cortexm3/efm32/board/hwconf.h
 * Board header for use with HWCONF
 * See @ref board for detailed documentation.
 *
 * <!-- Copyright 2016 Silicon Laboratories, Inc.                        *80*-->
 */

/** @addtogroup board
 *  @brief Functions and definitions specific to the breakout board.
 *
 *@{
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#ifndef EMBER_AF_USE_HWCONF
#warning The hwconf board header is designed to be used with HW Configurator.
#endif

#include "inc/InitDevice.h"

/**************             Main Board Definitions               **************/

/** @name LED Definitions
 *
 * The following are used to aid in the abstraction with the LED
 * connections.  The microcontroller-specific sources use these
 * definitions so they are able to work across a variety of boards
 * which could have different connections.  The names and ports/pins
 * used below are intended to match with a schematic of the system to
 * provide the abstraction.
 *
 * The ::HalBoardLedPins enum values should always be used when manipulating the
 * state of LEDs, as they directly refer to the GPIOs to which the LEDs are
 * connected.
 *
 * \b Note: LEDs 0 and 1 are on the mainboard. There are no LEDs on the RCM
 *
 * \b Note: LEDs 2 and 3 simply redirects to LEDs 0 and 1.
 */
//@{

/**
 * @brief Assign each GPIO with an LED connected to a convenient name.
 * ::BOARD_ACTIVITY_LED and ::BOARD_HEARTBEAT_LED provide a further layer of
 * abstraction on top of the 3 LEDs for verbose coding.
 */
enum HalBoardLedPins {
  BOARDLED0 = 0,
  BOARDLED1 = 1,
  BOARDLED2 = BOARDLED0,
  BOARDLED3 = BOARDLED1,
  BOARD_ACTIVITY_LED  = BOARDLED0,
  BOARD_HEARTBEAT_LED = BOARDLED1
};
#define BSP_NO_OF_LEDS 2
#define BSP_GPIO_LEDARRAY_INIT  {{BSP_GPIO_LED0_PORT,BSP_GPIO_LED0_PIN}, {BSP_GPIO_LED1_PORT,BSP_GPIO_LED1_PIN}}

/** @} END OF LED DEFINITIONS  */

/** @name Button Definitions
 *
 * The following are used to aid in the abstraction with the Button
 * connections.  The microcontroller-specific sources use these
 * definitions so they are able to work across a variety of boards
 * which could have different connections.  The names and ports/pins
 * used below are intended to match with a schematic of the system to
 * provide the abstraction.
 *
 * The BUTTONn macros should always be used with manipulating the buttons
 * as they directly refer to the GPIOs to which the buttons are connected.
 *
 */
//@{
/**
 * @brief The interrupt service routine for all buttons.
 */
#define BUTTON_ISR buttonIrqCallback
/**
 * @brief The actual GPIO BUTTON0 is connected to.  This define should
 * be used whenever referencing BUTTON0.
 */
#define BUTTON0         (BSP_GPIO_PB0_PIN)
/**
 * @brief The GPIO port for BUTTON0.
 */
#define BUTTON0_PORT        (BSP_GPIO_PB0_PORT)

/**
 * @brief The actual GPIO BUTTON1 is connected to.  This define should
 * be used whenever referencing BUTTON1, such as controlling if pieces
 * are compiled in.
 */
#define BUTTON1         (BSP_GPIO_PB1_PIN)
/**
 * @brief The GPIO input register for BUTTON1.
 */
#define BUTTON1_PORT        (BSP_GPIO_PB1_PORT)
//@} //END OF BUTTON DEFINITIONS


/** @name UART Definitions
 *
 * The following are used to aid in the abstraction with the UART.
 * The microcontroller-specific sources use these definitions so they are able 
 * to work across a variety of boards which could have different connections.  
 * The names and ports/pins used below are intended to match with a schematic 
 * of the system to provide the abstraction.
 *
 */
//@{
/**
 * @brief Enable VCOM Pin, passthrough UART via the WSTK
 */
#define halEnableVCOM()

// Turn on Flow Control
#define COM_USART0_HW_FC

// Define USART0 TX/RX Location
#define USART0_TX_LOCATION _USART_ROUTELOC0_TXLOC_LOC0
#define USART0_RX_LOCATION _USART_ROUTELOC0_RXLOC_LOC0

// Define USART0 flow control pins
#ifndef USART0_CTS_PORT
  #define USART0_CTS_PORT gpioPortA
#endif
#ifndef USART0_CTS_PIN
  #define USART0_CTS_PIN 2
#endif
#ifndef USART0_RTS_PORT
  #define USART0_RTS_PORT gpioPortA
#endif
#ifndef USART0_RTS_PIN
  #define USART0_RTS_PIN 3
#endif
//@} //END OF BUTTON DEFINITIONS
//
/** @name External Flash Definitions
 *
 * The following are used to aid in the abstraction with the external flash.
 * The microcontroller-specific sources use these definitions so they are able 
 * to work across a variety of boards which could have different connections.  
 * The names and ports/pins used below are intended to match with a schematic 
 * of the system to provide the abstraction.
 *
 * This default configuration sets the location to the WSTK expansion header
 */
//@{
// Define external flash pins

#ifndef EXTERNAL_FLASH_USART0_TXLOC
#define EXTERNAL_FLASH_USART0_TXLOC             USART_ROUTELOC0_TXLOC_LOC11
#endif
#ifndef EXTERNAL_FLASH_USART0_RXLOC
#define EXTERNAL_FLASH_USART0_RXLOC             USART_ROUTELOC0_RXLOC_LOC11
#endif
#ifndef EXTERNAL_FLASH_USART0_CLKLOC
#define EXTERNAL_FLASH_USART0_CLKLOC            USART_ROUTELOC0_CLKLOC_LOC11
#endif

#ifndef EXTERNAL_FLASH_MOSI_PORT
  #define EXTERNAL_FLASH_MOSI_PORT    gpioPortC
#endif
#ifndef EXTERNAL_FLASH_MOSI_PIN
  #define EXTERNAL_FLASH_MOSI_PIN     6
#endif
#ifndef EXTERNAL_FLASH_MISO_PORT
  #define EXTERNAL_FLASH_MISO_PORT    gpioPortC
#endif
#ifndef EXTERNAL_FLASH_MISO_PIN
  #define EXTERNAL_FLASH_MISO_PIN     7
#endif
#ifndef EXTERNAL_FLASH_CLK_PORT
  #define EXTERNAL_FLASH_CLK_PORT     gpioPortC
#endif
#ifndef EXTERNAL_FLASH_CLK_PIN
  #define EXTERNAL_FLASH_CLK_PIN      8
#endif
#ifndef EXTERNAL_FLASH_CS_PORT
  #define EXTERNAL_FLASH_CS_PORT      gpioPortC
#endif
#ifndef EXTERNAL_FLASH_CS_PIN
  #define EXTERNAL_FLASH_CS_PIN       9
#endif
//@} //END OF BUTTON DEFINITIONS
/**************            Common Configuration Options          **************/

/** @name Packet Trace
 *
 * Packet Trace Interface (PTI) will be turned on by default unless 
 * ::DISABLE_PTI is defined
 *
 * @note PTI uses PB11-13
 */
//@{
#define RADIO_PTI_INIT                                                        \
  {                                                                           \
    RADIO_PTI_MODE_UART,    /* Simplest output mode is UART mode */           \
    1600000,                /* Choose 1.6 MHz for best compatibility */       \
    6,                      /* WSTK uses location 6 for DOUT */               \
    gpioPortB,              /* Get the port for this loc */                   \
    12,                     /* Get the pin, location should match above */    \
    6,                      /* WSTK uses location 6 for DCLK */               \
    gpioPortB,              /* Get the port for this loc */                   \
    11,                     /* Get the pin, location should match above */    \
    6,                      /* WSTK uses location 6 for DFRAME */             \
    gpioPortB,              /* Get the port for this loc */                   \
    13,                     /* Get the pin, location should match above */    \
  }

#ifndef DISABLE_PTI
#define halInternalConfigPti() do {                                \
  RADIO_PTIInit_t ptiInit = RADIO_PTI_INIT;                        \
  RADIO_PTI_Init(&ptiInit);                                        \
} while(0)
#else
#define halInternalConfigPti() do {                                \
  RADIO_PTIInit_t ptiInit = RADIO_PTI_INIT;                        \
  ptiInit.mode = RADIO_PTI_MODE_DISABLED;                          \
  RADIO_PTI_Init(&ptiInit);                                        \
} while(0)
#endif

//@} //END OF PACKET TRACE DEFINITIONS

/** @name DC-DC
 *
 * The DC to DC Interface will be turned on by default unless 
 * ::DISABLE_DCDC is defined, in which case the DC-DC will be put
 * in bypass mode.
 *
 * @note Use EMU_DCDCPowerOff() to poweroff the DC-DC if not connected
 * 
 * @note DC-DC configuration is write once on power-on, so a POR reset
 * is required to change DC-DC mode.
 */
//@{
#ifdef DISABLE_DCDC
  #warning DISABLE_DCDC has no effect when HWCONF is used.
#endif
//@} //END OF DC-DC DEFINITIONS

// Let AppBuilder contribute coexistence configurations.
#ifdef EMBER_AF_API_COEXISTENCE
  #include EMBER_AF_API_COEXISTENCE
#endif

// Define GPIO macros based on external port and pin macros
#define GPIO_PIN_DEF(gpio) GPIO_PIN_DEF_(gpio ## _PORT, gpio ## _PIN)
#define GPIO_PIN_DEF_(port,pin) GPIO_PIN_DEF__(port,pin)

#ifdef USE_GPIO_PORT_LETTER
//Use port letter definition
#define GPIO_PIN_DEF__(port,pin) (PORT ## port ## _PIN(pin))
#else //!USE_GPIO_PORT_LETTER
//Use numeric port definition
#define GPIO_PIN_DEF__(port,pin) ((0u<<port)|pin)
#endif //USE_GPIO_PORT_LETTER

/** @name Antenna Selection
 *
 * Define the antenna select pins ANTENNA_SELECT_GPIO and ANTENNA_nSELECT_GPIO
 * ANTENNA_SELECT_GPIO - low,  ANTENNA_nSELECT_GPIO - low: undefined
 * ANTENNA_SELECT_GPIO - low,  ANTENNA_nSELECT_GPIO - high: select antenna 1
 * ANTENNA_SELECT_GPIO - high, ANTENNA_nSELECT_GPIO - low: select antenna 2
 * ANTENNA_SELECT_GPIO - high, ANTENNA_nSELECT_GPIO - high: undefined
 *
 * @note The antenna select mode can be configured at runtime
 * via halSetAntennaMode().
 */
//@{

/**
 * @brief Enable antenna diversity by default.
 */
//#define ANTENNA_DIVERSITY_DEFAULT_ENABLED

/**
 * @brief GPIO used to control antenna select(low for antenna 1, high for antenna 2).
 */
#if defined(ANTENNA_SELECT_GPIO_PORT) && defined(ANTENNA_SELECT_GPIO_PIN)
#define ANTENNA_SELECT_GPIO GPIO_PIN_DEF(ANTENNA_SELECT_GPIO)
#define ANTENNA_SELECT_GPIO_CFG      gpioModePushPull
#define halInternalInitAntennaSelect() do {                          \
  halGpioSetConfig(ANTENNA_SELECT_GPIO, ANTENNA_SELECT_GPIO_CFG);    \
  halSetAntennaMode(HAL_ANTENNA_SELECT_DEFAULT);                     \
  halSetAntennaMode(HAL_ANTENNA_MODE_DEFAULT);                       \
} while(0)
#else//!(defined(ANTENNA_SELECT_GPIO_PORT) && defined(ANTENNA_SELECT_GPIO_PIN))
#define halInternalInitAntennaSelect() do {                          \
} while(0)
#endif//(defined(ANTENNA_SELECT_GPIO_PORT) && defined(ANTENNA_SELECT_GPIO_PIN))

/**
 * @brief GPIO used to control inverted antenna select(high for antenna 1, low for antenna 2).
 */
#if defined(ANTENNA_nSELECT_GPIO_PORT) && defined(ANTENNA_nSELECT_GPIO_PIN)
#define ANTENNA_SELECT_GPIO GPIO_PIN_DEF(ANTENNA_nSELECT_GPIO)
#define ANTENNA_nSELECT_GPIO_CFG     gpioModePushPull
#define halInternalInitAntennaNSelect() do {                         \
  halGpioSetConfig(ANTENNA_nSELECT_GPIO, ANTENNA_nSELECT_GPIO_CFG);  \
} while(0)
#else//!(defined(ANTENNA_nSELECT_GPIO_PORT) && defined(ANTENNA_nSELECT_GPIO_PIN))
#define halInternalInitAntennaNSelect() do {                         \
} while(0)
#endif//(defined(ANTENNA_nSELECT_GPIO_PORT) && defined(ANTENNA_nSELECT_GPIO_PIN))

/**
 * @brief Configure default antenna select at powerup.
 */
#define HAL_ANTENNA_SELECT_DEFAULT   HAL_ANTENNA_MODE_ENABLE1

#define halInternalInitAntennaDiversity() do {                 \
  halInternalInitAntennaNSelect();                             \
  halInternalInitAntennaSelect();                              \
} while(0)
//@} //END OF ANTENNA SELECTION

/** @name Radio HoldOff Configuration Definitions
 *
 * The following are used to aid in the abstraction with Radio
 * HoldOff (RHO).  The microcontroller-specific sources use these
 * definitions so they are able to work across a variety of boards
 * which could have different connections.  The names and ports/pins
 * used below are intended to match with a schematic of the system to
 * provide the abstraction.
 *
 * The Radio HoldOff input GPIO is abstracted like BUTTON0/1.
 */
//@{
/**
 * @brief The GPIO configuration register for Radio HoldOff.
 */
#define RHO_GPIOCFG gpioModeInputPull

/** @brief The following definitions are helpers for managing
 *  Radio HoldOff and should not be modified.
 */
#if     (defined(RADIO_HOLDOFF) && defined(RHO_GPIO))
  // Initial bootup configuration is for Radio HoldOff
  #define halInternalInitRadioHoldOff() halSetRadioHoldOff(true)
#else//!(defined(RADIO_HOLDOFF) && defined(RHO_GPIO))
  // Initial bootup configuration is for default
  #define halInternalInitRadioHoldOff() /* no-op */
#endif//(defined(RADIO_HOLDOFF) && defined(RHO_GPIO))

//@} //END OF RADIO HOLDOFF CONFIGURATION DEFINITIONS

/** @name PTA Configuration Definitions
 *
 * The following are used to aid in the abstraction with Packet
 * Traffic Arbitration (PTA).  The microcontroller-specific sources
 * use these definitions so they are able to work across a variety of
 * boards which could have different connections.  The names and
 * ports/pins used below are intended to match with a schematic of the
 * system to provide the abstraction.
 *
 * PTA 2-wire (Request out/shared, Grant in) or 3-wire (Request out/shared,
 * Priority out, and Grant in) configurations are supported.
 */
//@{
// PTA REQUEST signal (OUT or OUT_DO when shared with other radios):
#define PTA_REQ_GPIOCFG_NORMAL gpioModePushPull
#if (PTA_REQ_ASSERTED == 1)
#define PTA_REQ_GPIOCFG_SHARED gpioModeWiredOR
#else //(PTA_REQ_ASSERTED == 1)
#define PTA_REQ_GPIOCFG_SHARED gpioModeWiredAnd
#endif

#ifdef PTA_REQ_SHARED
#define PTA_REQ_GPIOCFG    PTA_REQ_GPIOCFG_SHARED
#else //!PTA_REQ_SHARED
#define PTA_REQ_GPIOCFG    PTA_REQ_GPIOCFG_NORMAL
#endif //PTA_REQ_SHARED

//Define ENABLE_PTA_REQ_PULSE to pulse request when grant is lost
//#define ENABLE_PTA_REQ_PULSE
// PTA GRANT signal (IN): [optional]
#define PTA_GNT_GPIOCFG    gpioModeInputPull


// PTA PRIORITY signal (OUT): [optional]
#define PTA_PRI_GPIOCFG    gpioModePushPull // or gpioModeWiredOr if shared


#if     (defined(ENABLE_PTA) && (defined(PTA_REQ_GPIO) || defined(PTA_GNT_GPIO)))
  // Initial bootup configuration is to enable PTA
  #define halInternalInitPta() halPtaSetEnable(true)
#else//!(defined(ENABLE_PTA) && (defined(PTA_REQ_GPIO) || defined(PTA_GNT_GPIO)))
  // Initial bootup configuration is not to enable PTA
  #define halInternalInitPta() /* no-op */
#endif//(defined(ENABLE_PTA) && (defined(PTA_REQ_GPIO) || defined(PTA_GNT_GPIO)))

//@} //END OF PTA CONFIGURATION DEFINITIONS

#ifndef halInternalInitPrs
#define halInternalInitPrs()  do {                                                               \
} while(0)
#endif //halInternalInitPrs

/**************            Essential Board Functions             **************/

/**
 * @name halInternalInitBoard
 *
 * Called on startup from halInit(). Should contain calls to all board
 * specific startup sequences.
 * 
 */
#define halInternalInitBoard() do {                                \
 enter_DefaultMode_from_RESET();                                   \
 halInternalInitButton();                                          \
 halInternalPowerUpBoard();                                        \
 halInternalConfigPti();                                           \
 halInternalConfigPa();                                            \
 halInternalInitRadioHoldOff();                                    \
 halInternalInitPta();                                             \
 halInternalInitPrs();                                             \
 halInternalInitAntennaDiversity();                                \
} while(0)

/**
 * @name halInternalPowerUpBoard
 *
 * Call after coming out of sleep to restore any features which need to
 * power off for sleep
 * 
 */
#ifndef halInternalPowerUpBoard
  #define halInternalPowerUpBoard() do {                             \
  } while(0)
#endif

/**
 * @name halInternalPowerDownBoard
 *
 * Call before going to sleep to power down any features which need to
 * off for sleep
 * 
 */
#ifndef halInternalPowerDownBoard
  #define halInternalPowerDownBoard() do {                           \
  } while(0)
#endif

/**
 *  Instantiate any variables that are used in the board header
 */
#ifndef DEFINE_BOARD_GPIO_CFG_VARIABLES
  #define DEFINE_BOARD_GPIO_CFG_VARIABLES()
#endif
/**
 * Define TEMP_SENSOR to satisfy Ember HAL. Should not be used
 */
#define TEMP_SENSOR_ADC_CHANNEL 0
#define TEMP_SENSOR_SCALE_FACTOR 0

/**************              Radio Module Options                **************/

/**
 * PA Configuration
 */
#define halInternalConfigPa() do {                                 \
  RADIO_PAInit_t paInit = {                                        \
    PA_SEL_2P4_HP,    /* Power Amplifier mode */                   \
    PA_VOLTMODE_DCDC, /* Power Amplifier vPA Voltage mode */       \
    100,              /* Desired output power in dBm * 10 */       \
    0,                /* Output power offset in dBm * 10 */        \
    10};              /* Desired ramp time in us */                \
  RADIO_PA_Init(&paInit);                                          \
} while(0)


#endif //__BOARD_H__

/** @} END Board Specific Functions */

/** @} END addtogroup */
