#ifndef __REALITY_RI__
#define __REALITY_RI__

#pragma region "RDRAM Registers"

#define RDRAM_REG_BASE 0x03F00000

#define RDRAM_REG_CONFIG        RDRAM_REG_BASE
#define RDRAM_REG_DEVIDE_ID     ( RDRAM_REG_BASE + 0x04 )
#define RDRAM_REG_DELAY         ( RDRAM_REG_BASE + 0x08 )
#define RDRAM_REG_MODE          ( RDRAM_REG_BASE + 0x0C )
#define RDRAM_REG_REF_INTERVAL  ( RDRAM_REG_BASE + 0x10 )
#define RDRAM_REG_REF_ROW       ( RDRAM_REG_BASE + 0x14 )
#define RDRAM_REG_RAS_INTERVAL  ( RDRAM_REG_BASE + 0x18 )
#define RDRAM_REG_MIN_INTERVAL  ( RDRAM_REG_BASE + 0x1C )
#define RDRAM_REG_ADDR_SELECT   ( RDRAM_REG_BASE + 0x20 )
#define RDRAM_REG_DEVICE_MAKER  ( RDRAM_REG_BASE + 0x24 )

#pragma endregion

#pragma region "RDRAM Values"

#define RDRAM_SIZE              ( 2 * 512 * 2048 )

#define RDRAM_ID_0              0
#define RDRAM_ID_1              1

#define RDRAM_MODE_RESET        0
#define RDRAM_MODE_ACTIVE       1
#define RDRAM_MODE_STANDBY      2

#define RDRAM_BASE_0            ( RDRAM_ID_0 * RDRAM_SIZE )
#define RDRAM_BASE_1            ( RDRAM_ID_1 * RDRAM_SIZE )

#define RDRAM_CONFIG_GLOBAL     0x80000
#define RDRAM_CONFIG_0          0x00000
#define RDRAM_CONFIG_1          0x00400

#pragma endregion

#pragma region "RDRAM Interface (RI) Registers"

#define RI_BASE                 0x04700000

#define RI_REG_MODE             RI_BASE
#define RI_REG_CONFIG           ( RI_BASE + 0x04 )
#define RI_REG_CURRENT_LOAD     ( RI_BASE + 0x08 )
#define RI_REG_SELECT           ( RI_BASE + 0x0C )
#define RI_REG_REFRESH          ( RI_BASE + 0x10 )
#define RI_REG_COUNT            RI_REG_REFRESH
#define RI_REG_LATENCY          ( RI_BASE + 0x14 )
#define RI_REG_ERROR_R          ( RI_BASE + 0x18 )
#define RI_REG_ERROR_W          ( RI_BASE + 0x1C )

#pragma endregion

#endif