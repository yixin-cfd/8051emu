/*
* 8051 emulator
* 2024-12-29
* JLX
* ref: https://study.163.com/course/courseMain.htm?courseId=1212809801
        https://www.yuque.com/lishutong-docs/8051/
*/
#include <string.h>
#include <stdio.h>
#include "../include/emu8051.h"


static emu8051_t emu;

void emu8051_reset(void)
{
    emu.pc = 0;
}

void emu8051_init(void)
{
    emu.mem.code = (void*) 0;
    memset(emu.mem.iram,0, MEM_IRAM_SIZE);
    memset(emu.mem.sfr,0, MEM_SFR_SIZE);
    memset(emu.mem.xram,0, MEM_XRAM_SIZE);
    emu8051_reset();
}

uint16_t emu8051_pc(void){
    return emu.pc;
}

void emu8051_fetch_instr(instr_t * instr){
    instr->opcode = emu.mem.code[emu.pc];
    instr->op0 = emu.mem.code[emu.pc + 1];  // TODO
    instr->op1 = emu.mem.code[emu.pc + 2];  
}

void emu8051_load(uint8_t * code){
    emu.mem.code = code;
}

void emu8051_exec(instr_t * instr){
    switch (instr->opcode)
    {
    case 0x00:
       printf("%d: %s\n", emu.pc, "nop");
        emu.pc += 1;
        break;
    case 0x80:{
        printf("%d: %s\n", emu.pc, "sjmp");
        emu.pc += 2 + (int8_t)instr->op0;
        break;
    }
    default:
        break;
    }
}