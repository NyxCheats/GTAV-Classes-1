#pragma once
#include "ObfVar.hpp"

namespace rage {
	template<int MAX_KEY_SIZE>
	struct EncryptionKey {
		uint8_t m_Key [ MAX_KEY_SIZE ];
		uint32_t m_KeyLength;
	};
}