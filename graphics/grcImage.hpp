#pragma once
#include "Color32.hpp"
#include "enums/Format.hpp"
#include "enums/ImageType.hpp"

#include <cstdint>
#include <xmmintrin.h>

namespace rage {
	struct grcImage {
		uint16_t m_Width, m_Height;
		Format m_Format;
		ImageType m_Type;
		uint16_t m_Stride;
		uint8_t m_Depth;
		uint8_t m_StrideHi;
		uint8_t* m_Bits;
		Color32* m_Lut;
		grcImage* m_Next;
		grcImage* m_NextLayer;
		int m_RefCount;
		int pad0, pad1, pad2;
		// For some fucking retarded reason, Vector3 is represented as a v4 (aka a __m128)
		__m128 m_ColorExp;
		__m128 m_ColorOfs;
	};
}