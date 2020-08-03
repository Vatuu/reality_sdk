#ifndef __REALITY_CPU__
#define __REALITY_CPU__

#include "types.hpp"

#pragma region "Coprocessor (C0) Control Registers"

#define C0_REG_INDEX            0
#define C0_REG_RANDOM           1
#define C0_REG_ENTRY_LOW_0      2
#define C0_REG_ENTRY_LOW_1      3
#define C0_REG_CONTEXT          4
#define C0_REG_PAGE_MASK        5
#define C0_REG_WIRED            6
#define C0_REG_UNUSED_0         7
#define C0_REG_BAD_VADDRESS     8
#define C0_REG_TIMER_COUNT      9
#define C0_REG_ENTRY_HIGH       10
#define C0_REG_TIMER_COMPARE    11
#define C0_REG_STATUS           12
#define C0_REG_EX_CAUSE         13
#define C0_REG_EX_COUNTER       14
#define C0_REG_PROCESSOR_ID     15
#define C0_REG_CONFIG           16
#define C0_REG_LOAD_LADDRESS    17
#define C0_REG_MEMWATCH_LOW     18
#define C0_REG_MEMWATCH_HIGH    19
#define C0_REG_MIPS_CONTEXT     20
#define C0_REG_UNUSED_1         21
#define C0_REG_UNUSED_2         22
#define C0_REG_UNUSED_3         23
#define C0_REG_UNUSED_4         24
#define C0_REG_UNUSED_5         25
#define C0_REG_ERR_PARITY       26
#define C0_REG_UNUSED_6         27
#define C0_REG_TAG_LOW          28
#define C0_REG_TAG_HIGH         29
#define C0_REG_ERR_COUNTER      30
#define C0_REG_UNUSED_7         31

#pragma endregion

#pragma region "Processor Functions" 

extern void dcache_flush(void*, s32);
extern void dcache_flush_all();
extern void dcache_invalidate(void*, s32);

extern u32 vAddr_to_pAddr(void*);
extern void c0_move_to_status(s32 value);
extern s32 c0_move_from_status();

#pragma endregion

#pragma region "Processor Values"

#define C0_STATUS_USABLE_C1 0x20000000

#define	CACHE_INST		    0x0
#define	CACHE_DATA		    0x1
#define	CACHE_INST_SEC		0x2
#define	CACHE_DATA_SEC		0x3

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

#endif