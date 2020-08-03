#include <rsdk.hpp>

extern __osExceptionVector exceptionVector;

u32 videoClock = VI_CLOCK_NTSC;

void system_init() {
    pif_send_command_await(PIF_CMD_UNFUCK);

    c0_move_to_status(c0_move_from_status() | C0_STATUS_USABLE_C1);
}