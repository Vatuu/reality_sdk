#ifndef __REALITY_CPU__
#define __REALITY_CPU__

#pragma region "Coprocessor (C0) Control Registers"

#define REG_C0_INDEX 0
#define REG_C0_RANDOM 1
#define REG_C0_ENTRY_LOW_0 2
#define REG_C0_ENTRY_LOW_1 3
#define REG_C0_CONTEXT 4
#define REG_C0_PAGE_MASK 5
#define REG_C0_WIRED 6
#define REG_C0_UNUSED_0 7
#define REG_C0_BAD_VADDRESS 8
#define REG_C0_TIMER_COUNT 9
#define REG_C0_ENTRY_HIGH 10
#define REG_C0_TIMER_COMPARE 11
#define REG_C0_STATUS 12
#define REG_C0_EX_CAUSE 13
#define REG_C0_EX_COUNTER 14
#define REG_C0_PROCESSOR_ID 15
#define REG_C0_CONFIG 16
#define REG_C0_LOAD_LADDRESS 17
#define REG_C0_MEMWATCH_LOW 18
#define REG_C0_MEMWATCH_HIGH 19
#define REG_C0_MIPS_CONTEXT 20
#define REG_C0_UNUSED_1 21
#define REG_C0_UNUSED_2 22
#define REG_C0_UNUSED_3 23
#define REG_C0_UNUSED_4 24
#define REG_C0_UNUSED_5 25
#define REG_C0_ERR_PARITY 26
#define REG_C0_UNUSED_6 27
#define REG_C0_TAG_LOW 28
#define REG_C0_TAG_HIGH 29
#define REG_C0_ERR_COUNTER 30
#define REG_C0_UNUSED_7 31

#pragma endregion

#endif