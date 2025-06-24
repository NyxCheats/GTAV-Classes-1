#pragma once
#include "enums/rlRos.hpp"
#include "enums/rlRosHttpEncryption.hpp"
#include "rlRosCredentials.hpp"

#include <cstdint>

namespace rage {
	class rlRosHttpUserAgentHeader {
	public:
		enum {
			MAX_USER_AGENT_LEN = 160
		};

	private:
		enum {
			RANDOM_PREFIX_LEN = 4
		};
		rlRosHttpEncryption m_Encryption;
		char m_TitleName [ RLROS_MAX_TITLE_NAME_SIZE ];
		char m_PlatformName [ RLROS_MAX_PLATFORM_NAME_SIZE ];
		int64_t m_SessionId;
		PlayerAccountId m_AccountId;
		int m_Version;
		bool m_IsValid : 1;
	};
}