
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
| PA5   |TIM2_CH1/ADC1_IN5/SPI1_CLK |   |               |
| PA6   |TIM3_CH1/ADC1_IN6/SPI1_MOSI    | Motor 1   |           |
| PA7   |TIM3_CH2/ADC1_IN7/SPI1_MOSI    | Motor 2   |           |
| PB0   |TIM3_CH3/ADC1_IN8  | Motor 3/Servo 1   |       |
| PB1   |TIM3_CH4/ADC1_IN9  | Motor 4/Servo 2   |       |
| PB2   |BOOT1              |                   |       |
| PB10  |TIM2_CH3/SPI_SCK/I2C2_SCL |    |               |
| GND   |                   |           |               |
| 5V    |                   |           |               |
|       |                   |           |               |
| PB9   |TIM4_CH4/I2C1_SDA  | I2C_SDA   |               |
| PB8   |TIM4_CH3/I2C1_SCL  | I2C_SCL   |               |
| PB7   |TIM4_CH2/I2C1_SDA/UART1_RX |Servo 3|          |
| PB6   |TIM4_CH1/I2C1_SCL/UART1_TX |Servo 4|          |
| PB5   |TIM3_CH2/SPI1_MOSI | SOFT_SERIAL_RX    |       |
| PB4   |TIM3_CH1/SPI1_MOSI/I2C3_SDA | SOFT_SERIAL_TX   |   |
| PB3   |TIM2_CH2/SPI1_SCK/I2C2_SDA |   |               |
| PA15  |TIM2_CH1           |           |               |
| PA12  |USB_DP/UART6_RX    |USB_DP     |               |
| PA11  |USB_DM/UART6_tX    |USB_DM     |               |
| PA10  |TIM1_CH3/UART1_RX  |UART1_TX   |               |
| PA9   |TIM1_CH2/UART1_TX  |UART1_RX   |               |
| PA8   |TIM1_CH1/I2C3_SCL  |           |               |
| PB15  |IM1_CH3N/SPI2_MOSI |           |               |
| PB14  |TIM1_CH2N/SPI2_MOSI/ADC1 |     |               |
| PB13  |TIM1_CH1N/SPI2_SCK |           |               |
| PB12  |TIM1_BKN           |           |               |




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

Hardware I2C not passed while test. For iNav there is a software I2C provision by the pins, as:

* SDA => PB0 (14/P1), SCL => PB1 (15/P1)

### PWM and Servos

Due to the available hardware, please note:

#### Flying Wing

* S1 : ESC
* S2 : ESC
* S3 : LEFT elevon
* S4 : RIGHT elevon

### Soft Serial

Soft serial is available as an alternative to a hardware UART on RX4/TX4 and TX2. By default this is NOT inverted. In order to use this feature:

* Enable soft serial
* Do not assign any function to hardware UART4
* Assign the desired function to the soft-serial ports
* UART4 TX/RX pads will be used as SoftSerial 1 TX/RX pads
* UART2 TX pad will be used as SoftSerial 2 TX pad

RX2 and SBUS pads can be used as normal for receiver-only UART. If you need a full duplex UART (IE: TBS Crossfire) and SoftSerial, then use UART 1, 3 or 5 for Full Duplex.


### USB

This board uses STM32 VCP and does _not_ use a UART when USB is connected. STM32 VCP drivers might be required on some operating systems.

Flashing requires DFU mode and STM32 DFU drivers. On Linux, the configurator or `dfu-util` work with a `udev` rule.

````
# DFU (Internal bootloader for STM32 MCUs)
SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="df11", MODE="0664", GROUP="plugdev"
ATTRS{idVendor}=="0483", ATTRS{idProduct}=="5740", ENV{ID_MM_DEVICE_IGNORE}="1"
````

On Windows, it may be necessary to use the [Zadig](http://zadig.akeo.ie) tool to install the WinUSB driver.

