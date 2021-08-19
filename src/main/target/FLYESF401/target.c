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

#include <stdint.h>

#include <platform.h>
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"
#include "drivers/bus.h"

const timerHardware_t timerHardware[] = {

    DEF_TIM(TIM2,  CH1, PA0,  TIM_USE_PPM | TIM_USE_PWM, 0,0),
    DEF_TIM(TIM2, CH2, PB13, TIM_USE_ANY,                  0, 0), // S2_IN

    // DEF_TIM(TIM8,  CH1, PB14,  TIM_USE_ANY,                 0, 0), // S3_IN, UART6_TX
    // DEF_TIM(TIM8,  CH2, PB15,  TIM_USE_ANY,                 0, 0), // S4_IN, UART6_RX
    // DEF_TIM(TIM8,  CH3, PA8,  TIM_USE_ANY,                 0, 0), // S5_IN // pad labelled CH5 on OMNIBUSF4PRO
    // DEF_TIM(TIM8,  CH4, PA9,  TIM_USE_ANY,                 0, 0), // S6_IN // pad labelled CH6 on OMNIBUSF4PRO
    //以下定义的意思：计时器编号，IO通道，IO引脚，用途，后面的 0,1两个参数不确定
    DEF_TIM(TIM3,  CH3, PB9,  TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR ,               0, 0), // S1_OUT D1_ST7

    //这是原版的，定时器配置不改的话，S2通道有PWM输出，但是S1就没有
    DEF_TIM(TIM3,  CH4, PB8,  TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR,               0, 0), // S2_OUT D1_ST2

    //如果改了定时器，S1（电调有输出），S2没输出
    //DEF_TIM(TIM2,  CH2, PB1,  TIM_USE_MC_MOTOR  | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO,               0, 0), // S2_OUT D1_ST2

    DEF_TIM(TIM2,  CH4, PB7,  TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO,               0, 1), // S3_OUT D1_ST6
    DEF_TIM(TIM2,  CH3, PB6,  TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO,               0, 0), // S4_OUT D1_ST1

    DEF_TIM(TIM5,  CH2, PB5,  TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO | TIM_USE_LED,  0, 0), // S5_OUT MOTOR, SERVO or LED
    DEF_TIM(TIM1,  CH1, PB4,  TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO,                0, 0), // S6_OUT


#if (defined(OMNIBUSF4PRO) || defined(OMNIBUSF4V3)) && !defined(OMNIBUSF4PRO_LEDSTRIPM5)
    DEF_TIM(TIM4,  CH1, PA6,  TIM_USE_LED,                                                           0, 0), // LED strip for F4 V2 / F4-Pro-0X and later (RCD_CS for F4)
#endif
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
