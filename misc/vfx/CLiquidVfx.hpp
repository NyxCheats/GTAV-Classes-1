#pragma once
#include <cstdint>

namespace rage {
	struct CLiquidVfx {
		float m_duration_foot;
		float m_duration_wheel_in;
		float m_life_foot;
		float m_life_wheel;
		char _0x0010 [ 0x48 ];
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
		char _0x005C [ 0x4 ];
	};
}