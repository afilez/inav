/*
*****************************************************************************
**
**  File        : stm32_flash.ld
**
**  Abstract    : Linker script for STM32F30x Device with
**                256KByte FLASH and 40KByte RAM
**
*****************************************************************************
*/

/* Stack & Heap sizes */
_Min_Heap_Size = 0;
_Min_Stack_Size = 0x1800;

/* Specify the memory areas. */
MEMORY
{
    FLASH (rx)        : ORIGIN = 0x08000000, LENGTH = 16K
    FLASH_CONFIG (r)  : ORIGIN = 0x08004000, LENGTH = 16K
    FLASH1 (rx)       : ORIGIN = 0x08008000, LENGTH = 224K

    RAM (xrw)         : ORIGIN = 0x20000000, LENGTH = 64K
    CCM (xrw)         : ORIGIN = 0x10000000, LENGTH = 0K
    MEMORY_B1 (rx)    : ORIGIN = 0x60000000, LENGTH = 0K
}

REGION_ALIAS("STACKRAM", RAM)
REGION_ALIAS("FASTRAM", RAM)

INCLUDE "stm32_flash_split.ld"
