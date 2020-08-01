#include <reality_pif.hpp>
#include <reality_si.hpp>

void pif_send_command_await(u32 cmd) {
    u32 pif;
    while(si_io_read(PIF_REG_COMMAND, &pif)) { }
    while(si_io_write(PIF_REG_COMMAND, pif | cmd)) { }
}