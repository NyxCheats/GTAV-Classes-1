#pragma once
#include "datGrowBuffer.hpp"
#include "atStringHash.hpp"

namespace rage {
	class atHashString {
	public:
		atHashString(uint32_t hash) : m_hash(hash) {
		}
		atHashString(const char* hashKey) : m_hash(atStringHash(hashKey)) {
		}
		atHashString() {
		}
		uint32_t m_hash;
	};
	typedef atHashString atHashWithStringBank;
	typedef atHashString atFinalHashString;
	typedef atHashString strStreamingObjectName;
}