#pragma once
#include <cstdint>

namespace rage {
	class Rc4Context {
	public:
		uint8_t m_X, m_Y;
		uint8_t m_State [ 256 ];
		bool m_IsValid;
	};
}
