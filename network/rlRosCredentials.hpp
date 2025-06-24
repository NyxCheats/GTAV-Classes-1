#pragma once
#include "enums/rlRos.hpp"
#include "enums/rlRosPrivilegeId.hpp"
#include "rage/atFixedBitSet.hpp"
#include "rlScAccountInfo.hpp"
#include "security/EncryptionKey.hpp"

#include <cstdint>

namespace rage {
	typedef int32_t PlayerAccountId;
	struct rlRosCredentials {
		static constexpr uint32_t SESSION_KEY_SIZE = 32;
		static constexpr uint32_t CLOUD_KEY_SIZE   = 32;
		typedef EncryptionKey<SESSION_KEY_SIZE> SessionKey;
		typedef EncryptionKey<CLOUD_KEY_SIZE> CloudKey;
		struct PrivilegeInfo {
			bool m_IsValid : 1;
			bool m_IsGranted : 1;
			bool m_HasEndDate : 1;
			uint64_t m_EndPosixTime;
		};
		char m_Ticket [ RLROS_MAX_TICKET_SIZE ];
		char m_SessionTicket [ RLROS_MAX_SESSION_TICKET_SIZE ];
		uint32_t m_ValidMs;
		int m_Region;
		PlayerAccountId m_PlayerAccountId;
		int64_t m_SessionId;
		rlScAccountInfo m_RockstarAcct;
		atFixedBitSet<RLROS_NUM_PRIVILEGEID> m_Privileges;
	};
}
