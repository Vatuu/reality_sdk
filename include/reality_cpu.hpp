#ifndef __REALITY_CPU__
#define __REALITY_CPU__

#include "types.hpp"

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

#pragma region "Processor Functions" 

extern void flush_dcache(void*, s32);
extern void flush_dcache_all();

#pragma endregion

#pragma region "Processor Values"

/* Target cache */
#define	CACHE_INST		    0x0
#define	CACHE_DATA		    0x1
#define	CACHE_INST_SEC		0x2
#define	CACHE_DATA_SEC		0x3

/* Cache operations */
#define	C_IINV		0x0	/* index invalidate (inst, 2nd inst) */
#define	C_IWBINV	0x0	/* index writeback inval (d, sd) */
#define	C_ILT		0x4	/* index load tag (all) */
#define	C_IST		0x8	/* index store tag (all) */
#define	C_CDX		0xc	/* create dirty exclusive (d, sd) */
#define	C_HINV		0x10	/* hit invalidate (all) */
#define	C_HWBINV	0x14	/* hit writeback inv. (d, sd) */
#define	C_FILL		0x14	/* fill (i) */
#define	C_HWB		0x18	/* hit writeback (i, d, sd) */
#define	C_HSV		0x1c	/* hit set virt. (si, sd) */

#define CACHE_DATA_SIZE     0x2000
#define CACHE_DATA_LINESIZE 16
#define CACHE_DATA_LINEMASK ( CACHE_DATA_LINESIZE - 1 )

#define CACHE_INST_SIZE     0x4000
#define CACHE_INST_LINESIZE 32
#define CACHE_INST_LINEMASK ( CACHE_INST_LINESIZE - 1 )

#pragma endregion

#pragma region "Processor Utility Functions"

extern u32 vAddr_to_pAddr(void*);

#pragma endregion

#endif