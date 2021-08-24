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
#include "target.h"

const timerHardware_t timerHardware[] = {

    //这个宏扩展的参数是：定时器，定时器通道，引脚，用途，标志，DMA通道
    DEF_TIM(TIM2,  CH1, PA0,  TIM_USE_PPM , 0,0), //S1_IN
    //DEF_TIM(TIM2,  CH2, PB13, TIM_USE_ANY,                  0, 0), // S2_IN

    DEF_TIM(TIM4,  CH2, PB7,  TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR,  0, 0),        // S5_OUT MOTOR, SERVO or LED
    DEF_TIM(TIM1,  CH1, PB6,  TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR,                0, 0), // S6_OUT

    DEF_TIM(TIM3,  CH1, PA6,  TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO,               0, 0), // S1_OUT D1_ST7
    DEF_TIM(TIM3,  CH2, PA7,  TIM_USE_MC_MOTOR | TIM_USE_MC_SERVO | TIM_USE_FW_SERVO | TIM_USE_LED,               0, 0), // S2_OUT D1_ST2
    DEF_TIM(TIM3,  CH3, PB0,  TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO,               0, 0), // S3_OUT D1_ST6
    DEF_TIM(TIM3,  CH4, PB1,  TIM_USE_MC_MOTOR | TIM_USE_FW_SERVO,               0, 0), // S4_OUT D1_ST1




    #ifdef FLYESF401_SS
    DEF_TIM(TIM2,  CH3, PB10,  TIM_USE_ANY,                                                           0, 0), // S7_OUT SOFTSERIAL_RX
    DEF_TIM(TIM1,  CH1, PA8,   TIM_USE_ANY,                                                           0, 0), // S8_OUT SOFTSERIAL_TX
    #endif
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
