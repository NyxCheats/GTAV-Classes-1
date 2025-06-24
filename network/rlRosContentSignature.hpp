#pragma once
#include "enums/rlRos.hpp"

#include <cstdint>

namespace rage {
	struct rlRosContentSignature {
		uint8_t m_ContentSignature [ RLROS_MAX_RSA_ENCRYPTED_SIZE ];
		uint32_t m_Length;
	};
}
