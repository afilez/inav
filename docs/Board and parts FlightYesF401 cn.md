
# 飞控板 - FlightYesF401

没有图片

## 固件

...


## 硬件性能

* MCU: STM32F401CUU, 84MHz
* IMU: MPU6050 (外接)
* OSD: 无
* Baro: BMP280-3.3 (外接, STD, CTR)
* Compass: 无 (支持外接) 
* Blackbox: 无，也不支持
* VCP, UART1, UART2, UART6, SOFTSERIAL 一共5个串口
* I2C SDA & SCL: 支持
* LDO: RT9193 3.3V Max. 300mA
* 电流计: 无，不支持
* 6个PWM / DSHOT 兼容的舵机和电机输出
* WS2812 Led 灯条 : 可能支持，未测试
* 蜂鸣器: 外接
* RSSI: 无
* 1 个DFU启动模式按钮
* 1 个重启按扭
* 1 个未使用的按钮，在PA0上.

## 固件功能

由于 STM32F401CCU MCU 只有 265KB flash, 而且开发板上没有SD卡槽. 一些驱动和功能被取消:

* 黑匣子记录
* 航线导航
* 取消的驱动和功能如: 
    ** 除 MPU6050 以外的其它姿态运动传感器, 
    ** 除 BMP280 以外的其它大气压力传感器,
    ** 除 HMC5883, QMC5883, FAKE 以外的罗盘,
    ** 日志功能,
    ** OSD,
    ** 各种遥测信号输出,
    ** 固定翼自主降落功能,
    ** SUMD 串行接收机
    ** SUMH 串行接收机
    ** 串口直通
    ** CMS 

随后会针对不同应用场景和不同传感器环境提供不同的固件定制.

### I2C

硬件I2C接口的测试没有通过. 所以通过软件I2C为inav固件提供支持, 

* SDA => PB0 (14/P1), SCL => PB1 (15/P1)

### PWM 信号输出和舵机

按以下不同的场景和飞行器:

#### 飞翼

* S1 : 电调和电机
* S2 : 电调和电机
* S3 : 左混控副翼
* S4 : 右混控副翼

### 软串口

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

