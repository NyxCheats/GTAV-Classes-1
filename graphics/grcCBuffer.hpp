#pragma once
#include "grcTexture.hpp"

#include <cstdint>

namespace rage {
	class grcCBuffer {
	public:
		uint32_t Size;
		uint16_t Registers [ 6 ];
		uint32_t NameHash;
		grcString Name;
		grcBuffer* m_pBuffer;
		char* m_pAlignedBackingStore;
		char* m_pAllocatedBackingStore;
		uint32_t m_BufferStride;
		friend class grcProgram;
		friend class grcDevice;
	};
}