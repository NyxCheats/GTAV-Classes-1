#pragma once

namespace rage {
	class atString {
	public:
		const char* c_str() const {
			return m_Length ? m_Data : "";
		}

		char* m_Data;
		uint16_t m_Length, m_Allocated;
	};
}