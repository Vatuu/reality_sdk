#include <reality_pi.hpp>

u32 pi_get_status() {
    return IO_READ(PI_REG_STATUS);
}

s32 pi_io_write(u32, u32) {
    return 0;
}

s32 pi_io_write_raw(u32, u32) {
    return 0;
}

s32 pi_io_read(u32, u32*) {
    return 0;
}

s32 pi_io_read_raw(u32, u32*) {
    return 0;
}