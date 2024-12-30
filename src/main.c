#include <stdio.h>
#include "../include/emu8051.h"

static uint8_t t0_nop_code[] = {0x00, 0x00, 0x80, 0xFE};
void test_instr(void){
    uint16_t pc;
    printf("Test instr\n");

    emu8051_reset();
    emu8051_load(t0_nop_code);
    do {
        instr_t instr;
        pc = emu8051_pc();
        emu8051_fetch_instr(&instr);
        emu8051_exec(&instr);
    }while(pc != emu8051_pc());
}
int main(int argc, char** argv) {
    printf("8051 emu\n");
    emu8051_init();
    test_instr();
    return 0;
}
