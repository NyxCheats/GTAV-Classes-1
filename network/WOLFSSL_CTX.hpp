#pragma once
#include "rage/derBuffer.hpp"

#include <minwinbase.h>

namespace rage {
	struct WOLFSSL_CTX {
		void* method;
		CRITICAL_SECTION countMtx;
		int refCount, err;
		struct buffer {
			uint8_t* buffer;
			uint32_t length;
		} serverDH_P, serverDH_G;
		DerBuffer* certificate;
		DerBuffer* certChain;
		DerBuffer* privateKey;
		uint8_t privateKeyType : 6;
		uint8_t privateKeyId : 1;
		uint8_t privateKeyLabel : 1;
		int privateKeySz, privateKeyDevId;
	};
	typedef WOLFSSL_CTX SSL_CTX;
}