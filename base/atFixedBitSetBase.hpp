#pragma once
#include <cstdint>

namespace rage {
	template<uint64_t X>
	struct CompileTimeLog2Floor {
		enum {
			value = 1 + CompileTimeLog2Floor<(X >> 1)>::value
		};
	};
	template<>
	struct CompileTimeLog2Floor<1> {
		enum {
			value = 0
		};
	};
	template<int, typename>
	class atFixedBitSetIterator;
	template<int Size, typename Type = uint32_t>
	class atFixedBitSetBase {
		template<int X, typename Y>
		friend class atFixedBitSetIterator;

	protected:
		static constexpr int BlockSize    = sizeof(Type);
		static constexpr int BitsPerBlock = BlockSize * 8;
		static constexpr int BlockBitShift = CompileTimeLog2Floor<BitsPerBlock>::value;
		static constexpr int NumBlocks = (((Size) + (BitsPerBlock - 1)) >> BlockBitShift);

	public:
		enum {
			NUM_BITS   = Size,
			NUM_BLOCKS = NumBlocks,
			BLOCK_SIZE = BlockSize
		};
		typedef atFixedBitSetBase<Size, Type> myType;

	protected:
		Type m_Bits [ NumBlocks ];
		__forceinline void ClearUndefinedBits() {
			const int numOnes = ((Size - 1) % BitsPerBlock) + 1; // numOnes is 1..32
			const Type ones = (Type) ~(Type)0x0u; // ones = 0xFFFFFFFF
			const Type mask = ones >> (BitsPerBlock - numOnes); // Shift by (32 - (1..32)) = (31..0)
			m_Bits [ NumBlocks - 1 ] &= mask;
		}
		__forceinline Type& Block(uint32_t i) {
			return m_Bits [ i >> BlockBitShift ];
		}
		__forceinline const Type& Block(uint32_t i) const {
			return m_Bits [ i >> BlockBitShift ];
		}
		__forceinline Type BitInBlock(uint32_t i) const {
			return (Type)1 << (i & (BitsPerBlock - 1));
		}
	};
}