#pragma once
#include <cstdint>

namespace rage {
	enum Format {
		UNKNOWN, // Undefined
		DXT1,    // DXT1 (aka 'BC1')
		DXT3,    // DXT3 (aka 'BC2')
		DXT5,    // DXT5 (aka 'BC3', 'DXT5NM', 'RXGB')
		CTX1,    // CTX1 (like DXT1 but anchor colors are 8.8 instead of 5.6.5)
		DXT3A,   // alpha block of DXT3 (XENON-specific)
		DXT3A_1111, // alpha block of DXT3, split into four 1-bit channels (XENON-specific)
		DXT5A, // alpha block of DXT5 (aka 'BC4', 'ATI1')
		DXN, // DXN (aka 'BC5', 'ATI2', '3Dc', 'RGTC', 'LATC', etc.) // [CLEMENSP]
		BC6,      // BC6 (specifically BC6H_UF16)
		BC7,      // BC7
		A8R8G8B8, // 32-bit color with alpha, matches Color32 class
		A8B8G8R8, // 32-bit color with alpha, provided for completeness
		A8,       // 8-bit alpha-only (color is black)
		L8,       // 8-bit luminance (R=G=B=L, alpha is opaque)
		A8L8,     // 16-bit alpha + luminance
		A4R4G4B4, // 16-bit color and alpha
		A1R5G5B5, // 16-bit color with 1-bit alpha
		R5G6B5,   // 16-bit color
		R3G3B2,   // 8-bit color (not supported on consoles)
		A8R3G3B2, // 16-bit color with 8-bit alpha (not supported on consoles)
		A4L4,     // 8-bit alpha + luminance (not supported on consoles)
		A2R10G10B10,  // 32-bit color with 2-bit alpha
		A2B10G10R10,  // 32-bit color with 2-bit alpha
		A16B16G16R16, // 64-bit four channel fixed point (s10e5 per channel -- sign, 5 bit exponent, 10 bit mantissa)
		G16R16,       // 32-bit two channel fixed point
		L16,          // 16-bit luminance
		A16B16G16R16F, // 64-bit four channel floating point (s10e5 per channel)
		G16R16F,       // 32-bit two channel floating point (s10e5 per channel)
		R16F, // 16-bit single channel floating point (s10e5 per channel)
		A32B32G32R32F, // 128-bit four channel floating point (s23e8 per channel)
		G32R32F,       // 64-bit two channel floating point (s23e8 per channel)
		R32F,  // 32-bit single channel floating point (s23e8 per channel)
		D15S1, // 16-bit depth + stencil (depth is 15-bit fixed point, stencil is 1-bit) (not supported on consoles)
		D24S8, // 32-bit depth + stencil (depth is 24-bit fixed point, stencil is 8-bit)
		D24FS8, // 32-bit depth + stencil (depth is 24-bit s15e8, stencil is 8-bit)
		P4,     // 4-bit palettized (not supported on consoles)
		P8,     // 8-bit palettized (not supported on consoles)
		A8P8, // 16-bit palettized with 8-bit alpha (not supported on consoles)
		R8,   // non-standard R001 format (8 bits per channel)
		R16,  // non-standard R001 format (16 bits per channel)
		G8R8, // non-standard RG01 format (8 bits per channel)
		LINA32B32G32R32F_DEPRECATED,
		LINA8R8G8B8_DEPRECATED,
		LIN8_DEPRECATED,
		RGBE,
		LAST_FORMAT = RGBE
	};
}