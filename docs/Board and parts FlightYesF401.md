
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
| PIN    | optional          | used as   | Shared with   |
| 3.3V   |                   |           |               |


| PC13   |RTC_AF             |LED0       |               |
| PC14   |RCC_OSC32_IN       |           |               |
| PC15   |RCC_OSC32_OUT      |           |               |
| PH0    |RCC_OSC32_IN       |           |               |
| PH1    |RCC_OSC32_OUT      |           |               |
| NRST   |                   |           |               |
| VSS/VREF|                  |           |               |
| VREF+  |                   |           |               |
| PA0    |TIM2_CH1/TIM5_CH1/ADC1_IN0 |PPM RC IN  |       |
| PA1    |TIM2_CH2/TIM5_CH2/ADC1_IN1 |           |       |
| PA2    |TIM2_CH3/TIM5_CH3/TIM9_CH1/UART2_TX    |UAART2_TX   |   |



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

