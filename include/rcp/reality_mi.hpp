#ifndef __REALITY_MI__
#define __REALITY_MI__

#pragma region "MIPS Interface (MI) Registers"

#define MI_BASE                 0x04300000

#define MI_REG_MODE             MI_BASE
#define MI_REG_VERSION          ( MI_BASE_REG + 0x04 )
#define MI_REG_INTR     	    ( MI_BASE_REG + 0x08 )
#define MI_REG_INTR_MASK	    ( MI_BASE_REG + 0x0C )

#pragma endregion

#pragma region "MIPS Interface (MI) Values"

#define MI_MODE_INIT	        0x0080
#define MI_MODE_EBUS	        0x0100
#define MI_MODE_RDRAM	        0x0200

#define MI_INTR_SP		        0x01
#define MI_INTR_SI		        0x02
#define MI_INTR_AI		        0x04
#define MI_INTR_VI		        0x08
#define MI_INTR_PI		        0x10
#define MI_INTR_DP		        0x20

#pragma endregion

#pragma region "MIPS Interface (MI) Masks"

#define MI_MASK_INIT_CLEAR		0x0080
#define MI_MASK_INIT_SET		0x0100
#define MI_MASK_EBUS_CLEAR		0x0200
#define MI_MASK_EBUS_SET 	    0x0400
#define MI_MASK_CLR_DP_INTR		0x0800
#define MI_MASK_RDRAM_CLEAR		0x1000
#define MI_MASK_RDRAM_SET		0x2000

#define MI_MASK_INTR_SP_CLEAR	0x0001
#define MI_MASK_INTR_SP_SET     0x0002
#define MI_MASK_INTR_SI_CLEAR   0x0004
#define MI_MASK_INTR_SI_SET     0x0008
#define MI_MASK_INTR_AI_CLEAR	0x0010
#define MI_MASK_INTR_AI_SET 	0x0020
#define MI_MASK_INTR_VI_CLEAR	0x0040
#define MI_MASK_INTR_VI_SET	    0x0080
#define MI_MASK_INTR_PI_CLEAR	0x0100
#define MI_MASK_INTR_PI_SET	    0x0200
#define MI_MASK_INTR_DP_CLEAR	0x0400
#define MI_MASK_INTR_DP_SER	    0x0800

#pragma endregion

#endif