#pragma once
#include <cstdint>
#include <wtypes.h>

namespace rage {
	class rlRosTitleSecrets {
	public:
		enum {
			SECRET_VERSION     = 11,
			VERSION_OFFSET     = 0,
			VERSION_SIZE       = 1,
			MASTER_KEY_OFFSET  = VERSION_OFFSET + VERSION_SIZE,
			MASTER_SECRET_SIZE = 32,
			KEY_OFFSET         = MASTER_KEY_OFFSET + MASTER_SECRET_SIZE,
			KEY_SIZE           = 16,
			SALT_OFFSET        = KEY_OFFSET + KEY_SIZE,
			SALT_SIZE          = 16,
			TOTAL_SIZE         = SALT_OFFSET + SALT_SIZE,
			TOTAL_BASE64_SIZE = (((TOTAL_SIZE + 2) / 3) * 4) + 1 //datBase64::GetMaxEncodedSize(TOTAL_SIZE)
		};
		uint8_t m_Secret [ TOTAL_SIZE ];
	};
}