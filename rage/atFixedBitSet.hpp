#pragma once
#include "atStringHash.hpp"
#include "base/atFixedBitSetBase.hpp"
#include "datGrowBuffer.hpp"

#include <cstdint>

namespace rage {
	template<int Size, typename Type = uint32_t>
	class atFixedBitSet : public atFixedBitSetBase<Size, Type> {
	public:
		typedef atFixedBitSetBase<Size, Type> myBaseType;
		typedef atFixedBitSet<Size, Type> myType;
	};

#define bsWordSize (((Size) + 31) >> 5)
	typedef atFixedBitSet<8, uint8_t> atFixedBitSet8;
	typedef atFixedBitSet<16, uint16_t> atFixedBitSet16;
	typedef atFixedBitSet<32, uint32_t> atFixedBitSet32;
}