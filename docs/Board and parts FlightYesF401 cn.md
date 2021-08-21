
# 飞控板 - FlightYesF401

没有图片

## 固件

...


## 硬件性能

* MCU: STM32F401CUU, 84MHz
* IMU: MPU6050 (外接)
* OSD: 无
* 气压计: BMP280-3.3 (外接, STD, CTR)
* 罗盘: 无 (支持外接) 
* 黑匣子: 无，也不支持
* VCP, UART1, UART2, UART6, SOFTSERIAL 一共5个串口
* I2C SDA & SCL: 支持
* 电源降压芯片: RT9193 3.3V Max. 300mA
* 电流计: 无，不支持
* 6个PWM / DSHOT 兼容的舵机和电机输出
* WS2812 Led 灯条 : 可能支持，未测试
* 蜂鸣器: 外接
* RSSI: 无
* 1 个DFU启动模式按钮
* 1 个重启按扭
* 1 个未使用的按钮，在PA0上.


## 引脚/开发板插针定义及功能

| 引脚  |片上复用功能            |定义功能    |复用的功能  |
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
| PA0   |TIM2_CH1/TIM5_CH1/ADC1_IN0 |PPM 接收机输入 |       |
| PA1   |TIM2_CH2/TIM5_CH2/ADC1_IN1 |           |       |
| PA2   |TIM2_CH3/TIM5_CH3/TIM9_CH1/UART2_TX    |UART2_TX   |   |
| PA3   |TIM9_CH2/TIM5_CH4/TIM2_CH4/UART2_RX    |UART2_RX   |   |
| PA4   |ADC1_IN4           |BEEPER     |               |
| PA5   |TIM2_CH1/ADC1_IN5/SPI1_CLK |   |               |
| PA6   |TIM3_CH1/ADC1_IN6/SPI1_MOSI    | 电调1     |           |
| PA7   |TIM3_CH2/ADC1_IN7/SPI1_MOSI    | 电调2     |           |
| PB0   |TIM3_CH3/ADC1_IN8  | 电调3/舵机1   |       |
| PB1   |TIM3_CH4/ADC1_IN9  | 电调4/舵机2   |       |
| PB2   |BOOT1              |                   |       |
| PB10  |TIM2_CH3/SPI_SCK/I2C2_SCL |    |               |
| GND   |                   |           |               |
| 5V    |                   |           |               |
|       |                   |           |               |
| PB9   |TIM4_CH4/I2C1_SDA  | I2C_SDA   |               |
| PB8   |TIM4_CH3/I2C1_SCL  | I2C_SCL   |               |
| PB7   |TIM4_CH2/I2C1_SDA/UART1_RX |舵机3  |          |
| PB6   |TIM4_CH1/I2C1_SCL/UART1_TX |舵机4  |          |
| PB5   |TIM3_CH2/SPI1_MOSI | 软串口 RX|       |
| PB4   |TIM3_CH1/SPI1_MOSI/I2C3_SDA | 软串口 TX   |   |
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

## 固件功能

由于 STM32F401CCU MCU 只有 256KB flash, 而且开发板上没有SD卡槽. 一些驱动和功能被取消:

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

### PWM 信号输出和舵机

按以下不同的场景和飞行器:

#### 飞翼

* S1 : 电调和电机
* S2 : 电调和电机
* S3 : 左混控副翼
* S4 : 右混控副翼

### 软串口



