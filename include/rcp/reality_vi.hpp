#ifndef __REALITY_VI__
#define __REALITY_VI__

#pragma region "Video Interface (VI) Registers"

#define VI_BASE             0x04400000

#define VI_REG_STATUS       VI_BASE
#define VI_REG_CONTROL      VI_BASE

#define VI_REG_ORIGIN       ( VI_BASE + 0x04 )
#define VI_REG_DRAM_ADDRESS VI_REG_ORIGIN

#define VI_REG_WIDTH        ( VI_BASE + 0x08 )
#define VI_REG_WIDTH_H      VI_REG_WIDTH

#define VI_REG_INTERRUPT    ( VI_BASE + 0x0C )
#define VI_REG_INTERRUPT_V  VI_REG_INTERRUPT

#define VI_REG_CURRENT      ( VI_BASE + 0x10 )
#define VI_REG_CURRENT_V    VI_REG_CURRENT

#define VI_REG_BURST        ( VI_BASE + 0x14 )
#define VI_REG_TIMING       VI_REG_BURST

#define VI_REG_VSYNC        ( VI_BASE + 0x18 )

#define VI_REG_HSYNC        ( VI_BASE + 0x1C )

#define VI_REG_LEAP         ( VI_BASE + 0x20 )
#define VI_REG_HSYNC_LEAP   VI_REG_LEAP

#define VI_REG_HSTART       ( VI_BASE + 0x24 )
#define VI_REG_HVIDEO       VI_REG_HSTART

#define VI_REG_VSTART       ( VI_BASE + 0x28 )
#define VI_REG_VVIDEO       VI_REG_VSTART

#define VI_REG_VBURST       ( VI_BASE + 0x2C )

#define VI_REG_SCALE_X      ( VI_BASE + 0x30 )
#define VI_REG_SCALE_Y      ( VI_BASE + 0x34 )

#pragma endregion

#pragma region "Video Interface (VI) Masks"

#define VI_MASK_PIXEL_16    0x00002
#define VI_MASK_PIXEL_32    0x00003
#define VI_MASK_DITHER      0x00004
#define VI_MASK_GAMMA       0x00008
#define VI_MASK_DIVOT       0x00010
#define VI_MASK_SERRATE     0x00040
#define VI_MASK_AA          0x00300
#define VI_MASK_FILTER      0x10000

#pragma endregion

#pragma region "Video Interface (VI) Clock Speeds"

#define VI_CLOCK_NTSC       48681812
#define VI_CLOCK_PAL        49656530
#define VI_CLOCK_MPAL       48628316

#pragma endregion

#endif