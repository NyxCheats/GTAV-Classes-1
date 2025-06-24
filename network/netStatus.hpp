#pragma once
#include <cstdint>

namespace rage {
	class netStatus {
	public:
		enum StatusCode {
			NET_STATUS_NONE,
			NET_STATUS_PENDING,
			NET_STATUS_FAILED,
			NET_STATUS_SUCCEEDED,
			NET_STATUS_CANCELED,
			NET_STATUS_COUNT
		};
		union {
			uint32_t m_Status;
			StatusCode m_StatusCode;
		};
		int m_ResultCode;
	};
}