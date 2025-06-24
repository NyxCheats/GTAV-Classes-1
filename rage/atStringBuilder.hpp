#pragma once
#include "datGrowBuffer.hpp"

namespace rage {
	class atStringBuilder {
	public:
		const char* ToString() {
			char* str = (char*)m_DBuf.GetBuffer();
			return str ? str : "";
		}
		char* ToData() {
			return (char*)m_DBuf.GetBuffer();
		}
		datGrowBuffer m_DBuf;
	};
}