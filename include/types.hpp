#ifndef __REALITY_TYPES__
#define __REALITY_TYPES__

#pragma region "Primitives"

typedef unsigned char byte, u8;
typedef signed char sbyte, s8; 

typedef unsigned short ushort, u16;
typedef signed short s16;

typedef unsigned int uint, u32;
typedef volatile unsigned int vuint, vu32;
typedef signed int s32;

typedef unsigned long ulong, u64;
typedef volatile unsigned long vulong, vu64;
typedef signed long s64;

typedef float f32;
typedef double f64;

#pragma endregion

#pragma region "Structs and Enums"

typedef enum IoResult {
    BUSY    = -1,
    SUCCESS = 0,
} IoResult;

typedef enum DmaDirection {
    READ = 0,
    WRITE = 1,
} DmaDirection;

typedef struct ExceptionVector{
    u32 inst1;
    u32 inst2;
    u32 inst3;
    u32 inst4;
} __osExceptionVector;

#pragma endregion

#pragma region "Architecture Values" 

#define	KUBASE		            0
#define	KUSIZE		            0x80000000

#define	SEG0BASE		        0x80000000
#define	SEG0SIZE		        0x20000000

#define	SEG1BASE		        0xA0000000
#define	SEG1SIZE		        0x20000000

#define	SEG2BASE		        0xC0000000
#define	SEG2SIZE		        0x20000000

#pragma endregion

#pragma region "Common Macros"

#define	SEG0_TO_SEG1(x)	        ( (u32)(x) | SEG1BASE )
#define	SEG1_TO_SEG0(x)	        ( (u32)(x) & 0x9FFFFFFF )

#define	SEG_TO_PHYS(x)	        ( (u32)(x) & 0x1FFFFFFF )

#define PHYS_TO_SEG0(x)         ( (u32)(x) | SEG0BASE )
#define PHYS_TO_SEG1(x)         ( (u32)(x) | SEG1BASE )

#define	IS_SEG0(x)	            ( (u32)(x) >= SEG0BASE && (u32)(x) < SEG1BASE )
#define	IS_SEG1(x)	            ( (u32)(x) >= SEG1BASE && (u32)(x) < SEG2BASE )

#define IO_READ(address)        ( *(vu32*) PHYS_TO_SEG1(address) )
#define IO_WRITE(address, data) ( *(vu32*) PHYS_TO_SEG1(address) = (u32) data )

#pragma endregion

#endif