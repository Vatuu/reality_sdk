#ifndef __REALITY_PIF__
#define __REALITY_PIF__

#include "types.hpp"

#define PIF_ROM_START    0x1FC00000
#define PIF_ROM_END      0x1FC007BF

#define PIF_RAM_START    0x1FC007C0
#define PIF_RAM_END      0x1FC007FF

#define PIF_REG_COMMAND  ( PIF_RAM_END - 0x03 )

#define PIF_CMD_UNFUCK   0x08

extern void pif_send_command_await(u32 cmd);

#endif