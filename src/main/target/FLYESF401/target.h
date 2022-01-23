/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef FLYESF401
#define FLYESF401
#endif

#define FLASH_PAGE_SIZE ((uint32_t)0x4000)

#ifndef HSE_VALUE
#define HSE_VALUE 25000000
#endif


#define TARGET_BOARD_IDENTIFIER "FY40"
#define USBD_PRODUCT_STRING "FlyYes!401"


#define LED0                    PC13
#define BEEPER                  PA4
// #define BEEPER_INVERTED
//#define USE_I2C_PULLUP

#define USE_I2C
// #define USE_I2C_DEVICE_EMULATED
// //#define I2C_DEVICE_EMULATED_SHARES_UART3
// #define SOFT_I2C
// #define SOFT_I2C_SCL            PB1 //TX3 pad
// #define SOFT_I2C_SDA            PB0 //RX3 pad
// #define I2C_EXT_BUS BUS_I2C_EMULATED

#define USE_I2C_DEVICE_1
#define I2C1_SCL                PB8
#define I2C1_SDA                PB9



// //2022-01-22 added I2C2
// #define USE_UART3
// #define UART3_RX_PIN            PB3
// #define UART3_TX_PIN            PB10

#define USE_I2C_DEVICE_2
#define I2C2_SCL                PB10
#define I2C2_SDA                PB3
#define I2C_EXT_BUS BUS_I2C1
#define I2C_INT_BUS BUS_I2C1

#define USE_BARO
#define USE_BARO_BMP280
#define BARO_I2C_BUS          I2C_INT_BUS

// #define USE_I2C_DEVICE_2
// #define I2C_DEVICE_2_SHARES_UART3
// #define I2C_EXT_BUS BUS_I2C2

// //试图使用USB MSC功能(默认已打开)
// #define USE_USB_MSC
// //使用开关切换，这个打不开
// #define MSC_USE_BUTTON

//#define UG2864_I2C_BUS I2C_EXT_BUS

// // MPU6000 interrupts
// #define USE_EXTI
// #define GYRO_INT_EXTI            PC4
// #define USE_MPU_DATA_READY_SIGNAL

// #define MPU6000_CS_PIN          PA4
// #define MPU6000_SPI_BUS         BUS_SPI1

// #define USE_IMU_MPU6000
// #define IMU_MPU6000_ALIGN       CW180_DEG


// // ICM20608 instead of MPU6000
// #define MPU6500_CS_PIN          MPU6000_CS_PIN
// #define MPU6500_SPI_BUS         MPU6000_SPI_BUS
// #define USE_IMU_MPU6500
// #define IMU_MPU6500_ALIGN       IMU_MPU6000_ALIGN

#define USE_IMU_MPU6050
#define IMU_MPU6050_ALIGN       CW180_DEG
#define MPU6050_I2C_BUS         I2C_INT_BUS
#define MPU_ADDRESS             0x68

// MAG leave on EXT I2C BUS (I2C2)
#define USE_MAG
#define MAG_I2C_BUS             I2C_EXT_BUS
#define MAG_HMC5883_ALIGN       CW90_DEG
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883

// Hacked here to turn the fake compass on.
#define USE_FAKE_MAG

// #define TEMPERATURE_I2C_BUS     I2C_EXT_BUS



//#define PITOT_I2C_BUS           I2C_EXT_BUS

//禁用光流
//#define USE_RANGEFINDER
//#define RANGEFINDER_I2C_BUS     I2C_EXT_BUS

//VCP 虚拟口
#define USE_VCP
// #define VBUS_SENSING_PIN        PA12
// #define VBUS_SENSING_ENABLED

// //串口反相
// #if defined(OMNIBUSF4PRO) || defined(OMNIBUSF4V3)
// #define USE_UART_INVERTER
// #endif

// #define USE_UART_INVERTER

#define FLYESF401_SS
#define USE_SOFTSERIAL1
#define SOFTSERIAL_1_RX_PIN     PA8     
#define SOFTSERIAL_1_TX_PIN     PA8     


#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9
#define UART1_AHB1_PERIPHERALS  RCC_AHB1Periph_DMA2

#define USE_UART2
#define UART2_RX_PIN            PA3
#define UART2_TX_PIN            PA2
//#define UART2_AHB1_PERIPHERALS  RCC_AHB1Periph_DMA2


#define SERIAL_PORT_COUNT       4       // VCP ， USART1, USART2, SS1

//PINIO TO SET TXS0108E
#define USE_PINIO
#define USE_PINIOBOX
#define PINIO1_PIN              PA5
#define PINIO1_HI_ON_BOOT


// #define USE_SPI

// #define USE_SPI_DEVICE_1
// #define SPI1_SCK_PIN            PA5
// #define SPI1_MISO_PIN           PA6
// #define SPI1_MOSI_PIN           PA7


// // #define USE_SPI_DEVICE_3
// // #if defined(OMNIBUSF4PRO) || defined(OMNIBUSF4V3)
// //   #define SPI3_NSS_PIN          PA15
// // #else
// //   #define SPI3_NSS_PIN          PB3
// // #endif
// // #define SPI3_SCK_PIN            PC10
// // #define SPI3_MISO_PIN           PC11
// // #define SPI3_MOSI_PIN           PC12

// // #define USE_OSD
// // #define USE_MAX7456
// // #define MAX7456_SPI_BUS         BUS_SPI3
// // #define MAX7456_CS_PIN          PA15

// // #if defined(OMNIBUSF4PRO) || defined(OMNIBUSF4V3)
// //   #define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT
// //   #define USE_SDCARD
// //   #define USE_SDCARD_SPI

// //   #define SDCARD_SPI_BUS        BUS_SPI2
// //   #define SDCARD_CS_PIN         SPI2_NSS_PIN

// //   #define SDCARD_DETECT_PIN     PB7
// //   #define SDCARD_DETECT_INVERTED
// // #else
// //   #define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
// //   #define M25P16_CS_PIN           SPI3_NSS_PIN
// //   #define M25P16_SPI_BUS          BUS_SPI3
// //   #define USE_FLASHFS
// //   #define USE_FLASH_M25P16
// // #endif

#define USE_ADC
// #define ADC_CHANNEL_1_PIN               PA5
// #define ADC_CHANNEL_2_PIN               PA6

// // #ifdef DYSF4PRO
// //     #define ADC_CHANNEL_3_PIN               PC3
// // #else
// //     #define ADC_CHANNEL_3_PIN               PA0
// // #endif

// // #define CURRENT_METER_ADC_CHANNEL       ADC_CHN_1
// // #define VBAT_ADC_CHANNEL                ADC_CHN_2
// // #define RSSI_ADC_CHANNEL                ADC_CHN_3

#define SENSORS_SET (SENSOR_ACC|SENSOR_MAG|SENSOR_BARO)

#define USE_LED_STRIP
#define WS2811_PIN                   PA1


// #define DEFAULT_RX_TYPE         RX_TYPE_PPM
// #define DISABLE_RX_PWM_FEATURE
// #define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL  | FEATURE_VBAT )

// // #define USE_SPEKTRUM_BIND
// // #define BIND_PIN                PB11 // USART3 RX

// //#define USE_SERIAL_4WAY_BLHELI_INTERFACE

// Number of available PWM outputs
#define MAX_PWM_OUTPUT_PORTS    16
#define TARGET_MOTOR_COUNT      6
#define USE_ESC_SENSOR
// //#define USE_DSHOT


#define TARGET_IO_PORTA (0xffff & ~(BIT(14)|BIT(13)))
#define TARGET_IO_PORTB (0xffff & ~(BIT(2)))
#define TARGET_IO_PORTC (0xffff & ~(BIT(15)|BIT(14)))
// #define TARGET_IO_PORTD         0xffff

// #ifdef OMNIBUSF4PRO
// #define CURRENT_METER_SCALE   265
// #endif

#define PCA9685_I2C_BUS         I2C_EXT_BUS
