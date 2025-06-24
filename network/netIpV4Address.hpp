#pragma once
#include <cstdint>

namespace rage {
	class netIpV4Address {
	public:
		union {
			uint32_t pck;
			struct {
				uint8_t f4, f3, f2, f1;
			};
		} m_Ip;
	};
}