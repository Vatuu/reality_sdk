#include <reality_cpu.hpp>

void dcache_flush(void *address, s32 bytes) {
    if (bytes <= 0)
        return;
    
    if (bytes < CACHE_DATA_SIZE) {
        u32 address_end = (u32)address + bytes;
        if (bytes < address_end)
            for(u32 i = (u32)address - ((u32)address & CACHE_DATA_LINEMASK); i <= (address_end - CACHE_DATA_LINESIZE); i += CACHE_DATA_LINESIZE)
                asm("cache %0, (%1)" :: "n" (C_HWB | CACHE_DATA), "r" (i) : "memory");
        return;
    }

    dcache_flush_all();
}

void dcache_flush_all() {
    for(u32 i = SEG0BASE; i <= ((SEG0BASE + CACHE_DATA_SIZE) - CACHE_DATA_LINESIZE); i += CACHE_DATA_LINESIZE) 
        asm("cache %0, (%1)" :: "n" (C_IWBINV | CACHE_DATA), "r" (i) : "memory");
}

void dcache_invalidate(void *address, s32 bytes) {

}