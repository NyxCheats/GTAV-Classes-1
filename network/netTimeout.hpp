#pragma once
#include <cstdint>

namespace rage {
	class netTimeout {
	public:
		static constexpr uint32_t DEFAULT_LONG_FRAME_THRESHOLD_MS = (3 * 1000);
		uint32_t m_CurTime;
		uint32_t m_LongFrameThresholdMs;
		int m_Timeout;
		int m_Countdown;
	};
}