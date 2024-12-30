/*
* 8051 emulator
* 2024-12-29
* JLX
* ref: https://study.163.com/course/courseMain.htm?courseId=1212809801
        https://www.yuque.com/lishutong-docs/8051/
*/
#pragma once
#include <stdint.h>

/* config area */
#define MEM_CODE_SIZE 65536 // code size, max 64KB
#define MEM_IRAM_SIZE 128   // intenal ram + sfr, max 128B
#define MEM_SFR_SIZE 128    // sfr size
#define MEM_XRAM_SIZE 65536 // external ram size, max 64KB
/*
* memory region
*/
typedef struct _memory_t
{
    uint8_t *code;
    uint8_t iram[MEM_IRAM_SIZE];
    uint8_t sfr[MEM_SFR_SIZE];
    uint8_t xram[MEM_XRAM_SIZE];
}memory_t;

/*
* 8051 emulator
*/
typedef struct _emu8051_t
{
    uint16_t pc;
    memory_t mem;

}emu8051_t;

/*
* instruction 
*/
typedef struct _instr_t{
    uint8_t opcode;
    uint8_t op0;
    uint8_t op1;
}instr_t;

uint16_t emu8051_pc(void);

void emu8051_init(void);
void emu8051_reset(void);
void emu8051_load(uint8_t * code);
void emu8051_fetch_instr(instr_t * instr);
void emu8051_exec(instr_t * instr);
