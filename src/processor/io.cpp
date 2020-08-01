#include <reality_cpu.hpp>

u32 vAddr_to_pAddr(void *address) {
    if (IS_SEG0(address) || IS_SEG1(address))
        return SEG_TO_PHYS(address);
        
    return 0;//__osProbeTLB(address);
}