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

#ifdef FLYESF401_4IN1
    #define TARGET_BOARD_IDENTIFIER "FY41"
#else 
    #ifdef FLYESF401_MPU9250
        #define TARGET_BOARD_IDENTIFIER "FY42"
    #else
        #define TARGET_BOARD_IDENTIFIER "FY40"
    #endif
#endif
#define USBD_PRODUCT_STRING "FlyYes!401"


#define LED0                    PC13
#define BEEPER                  PA4
#define USE_GPS_PROTO_UBLOX
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



// #define USE_I2C_DEVICE_2
// #define I2C2_SCL                PB10
// #define I2C2_SDA                PB3
#define I2C_EXT_BUS BUS_I2C1
#define I2C_INT_BUS BUS_I2C1

#define USE_BARO
#ifdef FLYESF401_4IN1
    #define USE_BARO_BMP085
    // #define USE_BARO_BMP280
    #define FLYESF401_SS
    #define FLYESF401_APM_OSD
#else 
    #define USE_BARO_BMP280
#endif
#define BARO_I2C_BUS          I2C_INT_BUS

// //试图使用USB MSC功能(默认已打开)
// #define USE_USB_MSC
// //使用开关切换，这个打不开
// #define MSC_USE_BUTTON

#define USE_DYNAMIC_FILTERS

//#undef USE_USB_MSC          // 0.13% saved but can't access MSP over USB port.
#undef USE_SERVO_SBUS       // 0.48% saved 92.10%
#undef USE_SERIALRX_SBUS    // 0.12% saved 91.98%
// #undef USE_SERIALRX_IBUS    // 0.32% saved 91.66%
// #undef USE_SERIAL_RX        // unuseful 91.67%
#undef USE_DSHOT
// #undef NAV_FIXED_WING_LANDING
//#undef USE_TELEMETRY        // 0.16% saved 91.51%

#define NAV_NON_VOLATILE_WAYPOINT_STORAGE   // 0.05% reqire 91.56%
#define USE_MAG

#ifndef FLYESF401_MPU9250
    #define USE_IMU_MPU6050
    #define IMU_MPU6050_ALIGN       CW180_DEG
    #define MPU6050_I2C_BUS         I2C_INT_BUS
    #define MPU_ADDRESS             0x68
    // MAG on INT I2C BUS (I2C2)
    #define MAG_I2C_BUS             I2C_INT_BUS
    #define MAG_HMC5883_ALIGN       CW90_DEG
    #define USE_MAG_HMC5883
    #define USE_MAG_QMC5883
#else
    #define USE_IMU_MPU9250
    #define IMU_MPU9250_ALIGN       CW180_DEG
    #define MPU9250_I2C_BUS         I2C_INT_BUS
    #define USE_MAG_MPU9250
#endif



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

   


#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9
#define UART1_AHB1_PERIPHERALS  RCC_AHB1Periph_DMA2


#define USE_UART2
#define UART2_RX_PIN            PA3
#define UART2_TX_PIN            PA2
//#define UART2_AHB1_PERIPHERALS  RCC_AHB1Periph_DMA2

#ifdef FLYESF401_SPI_OSD
    #define USE_SPI
    #define USE_SPI_DEVICE_1
    #define SPI1_SCK_PIN            PA5
    #define SPI1_MISO_PIN           PA6
    #define SPI1_MOSI_PIN           PA7

    #define USE_OSD
    #define USE_MAX7456
    #define MAX7456_SPI_BUS         BUS_SPI1
    #define MAX7456_CS_PIN          PA15
#else 
    #ifdef FLYESF401_APM_OSD
        // require more 4.61% of 256KB
        #define USE_TELEMETRY_MAVLINK
    #endif
#endif

#ifdef FLYESF401_SS
#define USE_SOFTSERIAL1
#define SOFTSERIAL_1_RX_PIN     PA0     
#define SOFTSERIAL_1_TX_PIN     PA1  
#define USE_SOFTSERIAL2
#define SOFTSERIAL_2_RX_PIN     PB0    // SHARED WITH S3 
#define SOFTSERIAL_2_TX_PIN     PB1    // SHARED WITH S4
#define SERIAL_PORT_COUNT       5       // VCP ， USART1, USART2, SS1
#else
#define SERIAL_PORT_COUNT       3       // VCP ， USART1, USART2
#endif



// //PINIO TO SET TXS0108E
// #define USE_PINIO
// #define USE_PINIOBOX
// #define PINIO1_PIN              PB15
// #define PINIO1_HI_ON_BOOT




#define USE_ADC
#define ADC_CHANNEL_1_PIN               PA4
#define ADC_CHANNEL_2_PIN               PA5
#define CURRENT_METER_ADC_CHANNEL       ADC_CHN_1
// #define VBAT_ADC_CHANNEL                ADC_CHN_2
// // #define RSSI_ADC_CHANNEL                ADC_CHN_3

#define SENSORS_SET (SENSOR_ACC|SENSOR_MAG|SENSOR_BARO)

#define USE_LED_STRIP
#define WS2811_PIN                   PA15


#define DEFAULT_RX_TYPE         RX_TYPE_PPM
#define DISABLE_RX_PWM_FEATURE
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

#define PCA9685_I2C_BUS         I2C_INT_BUS
