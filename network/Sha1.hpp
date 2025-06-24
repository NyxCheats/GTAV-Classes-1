#pragma once
#include <cstdint>

namespace rage {
	class Sha1 {
	public:
		static constexpr uint8_t SHA1_DIGEST_LENGTH = 20; // 160-bit digest
		static constexpr uint8_t SHA1_BLOCK_LENGTH  = 64; // 512-bit block
		struct SHA1_CTX {
			uint32_t state [ 5 ];
			uint64_t count;
			uint8_t buffer [ SHA1_BLOCK_LENGTH ];
		};
		SHA1_CTX m_Context;
		uint8_t m_Kpad [ Sha1::SHA1_BLOCK_LENGTH ];
		uint8_t m_Key [ Sha1::SHA1_BLOCK_LENGTH ];
		uint32_t m_KeyLen;
	};
}
