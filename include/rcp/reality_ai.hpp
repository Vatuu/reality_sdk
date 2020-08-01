#ifndef __REALITY_HI__
#define __REALITY_HI__

#pragma region "Audio Interface (AI) Registers"

#define AI_BASE             0x04500000

#define AI_REG_DRAM_ADDR    AI_BASE
#define AI_REG_LENGTH       ( AI_BASE + 0x04 )
#define AI_REG_CONTROL      ( AI_BASE + 0x08 )
#define AI_REG_STATUS       ( AI_BASE + 0x0C )
#define AI_REG_RATE_DAC     ( AI_BASE + 0x10 )
#define AI_REG_RATE_BIT     ( AI_BASE + 0x14 )

#pragma endregion

#pragma region "Audio Interface (AI) Values"

#define AI_STATUS_DMA_OFF   0x00
#define AI_STATUS_DMA_ON    0x01

#define AI_STATUS_FIFO_FULL 0x80000000
#define AI_STATUS_DMA_BUSY  0x40000000

#define AI_RATE_DAC_MIN     132
#define AI_RATE_DAC_MAX     16384
#define AI_RATE_BIT_MIN     2
#define AI_RATE_BIT_MAX     16

#define AI_FREQ_NTSC_MIN    3000
#define AI_FREQ_NTSC_MAX    368000
#define AI_FREQ_PAL_MIN     3050
#define AI_FREQ_PAL_MAX     376000 
#define AI_FREQ_MPAL_MIN    3000
#define AI_FREQ_MPAL_MAX    368000

#pragma region

#endif