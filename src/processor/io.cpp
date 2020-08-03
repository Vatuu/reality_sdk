#include <reality_cpu.hpp>

u32 vAddr_to_pAddr(void *address) {
    if (IS_SEG0(address) || IS_SEG1(address))
        return SEG_TO_PHYS(address);
        
    return 0;//__osProbeTLB(address);
}

void c0_move_to_status(s32 value) {
    asm("mtc0 %0, $%1" :: "r" (value), "n" (C0_REG_STATUS) : "memory");
}

s32 c0_move_from_status() {
    s32 val = 0;
    asm("mfc0 %0, $%1" :: "r" (val), "n" (C0_REG_STATUS) : "memory");
    return val;
}