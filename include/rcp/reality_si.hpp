#ifndef __REALITY_SI__
#define __REALITY_SI__

#include "types.hpp"

#pragma region "Serial Interface (SI) Registers"

#define SI_BASE                 0x04800000

#define SI_REG_ADDR_RDRAM       SI_BASE
#define SI_REG_ADDR_PIF_RD64B   ( SI_BASE + 0x04 )
#define SI_REG_ADDR_PIF_WD64B   ( SI_BASE + 0x10 )
#define SI_REG_STATUS           ( SI_BASE + 0x18 )

#pragma endregion

#pragma region "Serial Interface (SI) Values"

#define SI_STATUS_DMABUSY       0x0001
#define SI_STATUS_RDBUSY        0x0002
#define SI_STATUS_DMAERROR      0x0008
#define SI_STATUS_INTERRUPT     0x1000

#pragma endregion

extern u32 si_get_status();
extern IoResult si_device_available();
extern IoResult si_io_write(u32, u32);
extern IoResult si_io_read(u32, u32*);
extern IoResult si_io_dma(s32, void*);

#endif