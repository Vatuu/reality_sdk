#include <reality_system.hpp>

extern __osExceptionVector exceptionVector;

u32 videoClock = VI_CLOCK_NTSC;

void system_init() {
    pif_send_command_await(PIF_CMD_UNFUCK);
}