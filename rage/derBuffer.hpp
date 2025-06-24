#pragma once

namespace rage {
	typedef struct DerBuffer {
		uint8_t* buffer;
		void* heap;
		uint32_t length;
		int type, dynType;
	} DerBuffer;
}