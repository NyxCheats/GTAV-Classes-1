#pragma once
#include <cstdint>

namespace rage {
	struct sysMemContainerData {
		void* m_Base;
		uint32_t m_Size;
	};
}