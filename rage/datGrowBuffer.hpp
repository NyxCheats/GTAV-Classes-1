#pragma once

typedef void* fiHandle;

namespace rage {
    class datGrowBuffer {
	public:
		void* GetBuffer() {
			return m_Len ? m_Buf : NULL;
		}
		uint8_t* m_Buf;
		uint32_t m_Capacity;
		uint32_t m_Len;
		uint32_t m_Flags;
		void* m_Allocator;
		uint32_t m_growIncr; //Multiples of size to grow the buffer in.
		fiHandle m_FiHandle;
	};
}