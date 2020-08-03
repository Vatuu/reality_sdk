#include <reality_si.hpp>
#include <reality_cpu.hpp>

u32 si_get_status() {
    return IO_READ(SI_REG_STATUS);
}

IoResult si_io_write(u32 deviceAddress, u32 data) {
    if(!si_device_available())
        return IoResult::BUSY;

    IO_WRITE(deviceAddress, data);   
    return IoResult::SUCCESS; 
}

IoResult si_io_read(u32 deviceAddress, u32 *data) {
    if(!si_device_available())
        return IoResult::BUSY;

    *data = IO_READ(deviceAddress);
    return IoResult::SUCCESS;
}

IoResult si_io_dma(DmaDirection direction, void *dramAddress) {
    if(!si_device_available())
        return IoResult::BUSY;

    if(direction == DmaDirection::WRITE)
        dcache_flush(dramAddress, 64);

    IO_WRITE(SI_REG_ADDR_RDRAM, vAddr_to_pAddr(dramAddress));    

    if(direction == DmaDirection::READ) {
        IO_WRITE(SI_REG_ADDR_PIF_RD64B, 0x1FC007C0);
        dcache_invalidate(dramAddress, 64);
        return IoResult::SUCCESS;
    }

    IO_WRITE(SI_REG_ADDR_PIF_WD64B, 0x1FC007C0);

    return IoResult::SUCCESS;
}

IoResult si_device_available() {
    if(IO_READ(SI_REG_STATUS) & (SI_STATUS_DMABUSY | SI_STATUS_RDBUSY))
        return IoResult::BUSY;
    return IoResult::SUCCESS;
}