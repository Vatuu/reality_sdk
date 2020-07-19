#ifndef __REALITY_TYPES__
#define __REALITY_TYPES__

#pragma region "Primitives"

typedef unsigned char byte, u8;
typedef signed char sbyte, s8; 

typedef unsigned short ushort, u16;
typedef signed short s16;

typedef unsigned int uint, u32;
typedef signed int s32;

typedef unsigned long ulong, u64;
typedef signed long s64;

#pragma endregion

typedef struct {
    u32 inst1;
    u32 inst2;
    u32 inst3;
    u32 inst4;
} __osExceptionVector;

#endif