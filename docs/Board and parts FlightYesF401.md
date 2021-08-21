
# Board - FlightYesF401

There is no photo to the board and parts.

## Firmware

...


## Hardware features

* MCU: STM32F401CUU, 84MHz
* IMU: MPU6050 (EXTRENAL)
* OSD: No
* Baro: BMP280-3.3 (EXTERNAL, STD, CTR)
* Compass: No 
* Blackbox: No and will not support.
* VCP, UART1, UART2, SOFTSERIAL
* I2C SDA & SCL: Yes
* LDO: RT9193 3.3V Max. 300mA
* Current Sensor: No and not support.
* 6 PWM / DSHOT capable outputs
* WS2812 Led Strip : Mind support , not sure.
* Beeper: Yes
* RSSI: No
* Button for BOOT(DFU) mode
* Button for RESET
* 1 Button on PA0 not used.

## Pin defines

| PIN   |optional           |used as    |Shared with    |
| ----- | ----------------- | --------- | ------------- |
| 3.3V  |                   |           |               |
| PC13  |RTC_AF             |LED0       |               |
| PC14  |RCC_OSC32_IN       |           |               |
| PC15  |RCC_OSC32_OUT      |           |               |
| PH0   |RCC_OSC32_IN       |           |               |
| PH1   |RCC_OSC32_OUT      |           |               |
| NRST  |                   |           |               |
| VSS/VREF|                  |           |               |
| VREF+ |                   |           |               |
| PA0   |TIM2_CH1/TIM5_CH1/ADC1_IN0 |PPM RC IN  |       |
| PA1   |TIM2_CH2/TIM5_CH2/ADC1_IN1 |           |       |
| PA2   |TIM2_CH3/TIM5_CH3/TIM9_CH1/UART2_TX    |UART2_TX   |   |
| PA3   |TIM9_CH2/TIM5_CH4/TIM2_CH4/UART2_RX    |UART2_RX   |   |
| PA4   |ADC1_IN4           |BEEPER     |               |
| PA5   |TIM2_CH1/ADC1_IN5/SPI1_CLK |PINIO_OE   |               |
| PA6   |TIM3_CH1/ADC1_IN6/SPI1_MOSI    | Motor 1   |           |
| PA7   |TIM3_CH2/ADC1_IN7/SPI1_MOSI    | Motor 2   |           |
| PB0   |TIM3_CH3/ADC1_IN8  | Motor 3/Servo 1   |       |
| PB1   |TIM3_CH4/ADC1_IN9  | Motor 4/Servo 2   |       |
| PB2   |BOOT1              |                   |       |
| PB10  |TIM2_CH3/SPI_SCK/I2C2_SCL |SOFTSERIAL_2_TXRX |            |
| GND   |                   |           |               |
| 5V    |                   |           |               |
|       |                   |           |               |
| PB9   |TIM4_CH4/I2C1_SDA  | I2C_SDA   |               |
| PB8   |TIM4_CH3/I2C1_SCL  | I2C_SCL   |               |
| PB7   |TIM4_CH2/I2C1_SDA/UART1_RX |Servo 3|          |
| PB6   |TIM4_CH1/I2C1_SCL/UART1_TX |Servo 4|          |
| PB5   |TIM3_CH2/SPI1_MOSI |           |              |
| PB4   |TIM3_CH1/SPI1_MOSI/I2C3_SDA|       |           |
| PB3   |TIM2_CH2/SPI1_SCK/I2C2_SDA |       |           |
| PA15  |TIM2_CH1           |           |               |
| PA12  |USB_DP/UART6_RX    |USB_DP     |               |
| PA11  |USB_DM/UART6_tX    |USB_DM     |               |
| PA10  |TIM1_CH3/UART1_RX  |UART1_TX   |               |
| PA9   |TIM1_CH2/UART1_TX  |UART1_RX   |               |
| PA8   |TIM1_CH1/I2C3_SCL  |SOFTSERIAL_1_TXRX | IBUS RX  |
| PB15  |IM1_CH3N/SPI2_MOSI |           |               |
| PB14  |TIM1_CH2N/SPI2_MOSI/ADC1 |     |               |
| PB13  |TIM1_CH1N/SPI2_SCK |           |               |
| PB12  |TIM1_BKN           |           |               |

## Servo and ESC and RC input on 5V require 3.3V/5V adapter module



like:
TXS0108E 8 ports convert module.
PA5 will pull up after init to endbale TXS0108E module
...

Tested 5V GPS BN880 works fine while connected on UART1 without TXS0108E and use 5V TTL directly.
Tested Magmeter on BN880 and connected on I2C bus, but it is no required if flywing.
I guess it is better if use TXS0108E to connect the I2C bus to 5V


## Firmware features

For the STM32F401CCU MCU has 256KB flash only, and no SD card slot on the board. some features were removed:

* Blockbox
* Navigation Points
* Removed drivers/features like: 
    ** IMUs but MPU6050, 
    ** Baros but BMP280.
    ** Compass but HMC5883, QMC5883, FAKE.
    ** Log
    ** OSD
    ** TELEMETRY
    ** NAV_FIXED_WING_LANDING
    ** SERIALRX_SUMD
    ** SERIALRX_SUMH
    ** SERIAL_PASSTHROUGH
    ** CMS

It will customized the featues or drivers on diffrent conditions by firmwares soon.

### I2C

### PWM and Servos

Due to the available hardware, please note:

#### Flying Wing

* S1 : ESC
* S2 : ESC
* S3 : LEFT elevon
* S4 : RIGHT elevon

### Soft Serial


