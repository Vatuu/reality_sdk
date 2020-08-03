#ifndef __REALITY_PI__
#define __REALITY_PI__

#include "types.hpp"

#pragma region "Peripheral Interface (PI) Registers"

#define PI_BASE             0x04600000

#define PI_REG_ADDR_DRAM    PI_BASE
#define PI_REG_ADDR_CART    ( PI_BASE + 0x04 )
#define PI_REG_LENGTH_READ  ( PI_BASE + 0x08 )
#define PI_REG_LENGTH_WRITE ( PI_BASE + 0x0C )
#define PI_REG_STATUS       ( PI_BASE + 0x10 )

#define PI_REG_DOM1_LATENCY ( PI_BASE + 0x14 )
#define PI_REG_DOM1_PULSE   ( PI_BASE + 0x18 )
#define PI_REG_DOM1_PAGE    ( PI_BASE + 0x1C )
#define PI_REG_DOM1_RELEASE ( PI_BASE + 0x20 )

#define PI_REG_DOM2_LATENCY ( PI_BASE + 0x24 )
#define PI_REG_DOM2_PULSE   ( PI_BASE + 0x28 )
#define PI_REG_DOM2_PAGE    ( PI_BASE + 0x2C )
#define PI_REG_DOM2_RELEASE ( PI_BASE + 0x30 )

#pragma endregion

#pragma region "Peripheral Interface (PI) Values"

#define PI_DOM_OFF_LATENCY  0x00
#define PI_DOM_OFF_PULSE    0x04
#define PI_DOM_OFF_PAGE     0x08
#define PI_DOM_OFF_RELEASE  0x0C

#define PI_STATUS_DMA_BUSY  0x01
#define PI_STATUS_IO_BUSY   0x02
#define PI_STATUS_ERROR     0x04

#define PI_SET_RESET        0x01
#define PI_CLEAR_INTERRUPT  0x02

#define PI_BUFFER_SIZE      128

#define PI_DOM1_ADDR1		0x06000000
#define PI_DOM1_ADDR2		0x10000000
#define PI_DOM1_ADDR3		0x1FD00000
#define PI_DOM2_ADDR1		0x05000000
#define PI_DOM2_ADDR2		0x08000000

#pragma endregion

#pragma region "Peripheral Interface (PI) Types" 

typedef enum RomType {
    CARTRIDGE   = 0,
    BULK        = 1
} RomType;

#pragma endregion

#pragma region "Peripheral Interface (PI) Functions"

extern u32 pi_get_status();
extern s32 pi_io_write(u32, u32);
extern s32 pi_io_write_raw(u32, u32);
extern s32 pi_io_read(u32, u32*);
extern s32 pi_io_read_raw(u32, u32*);

#pragma endregion

#pragma region "Peripheral Interface (PI) Variables"

extern RomType romType;

#pragma endregion

#endif