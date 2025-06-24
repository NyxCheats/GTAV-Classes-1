#pragma once
#include <cstdint>

namespace rage {
	struct grcParameterAnnotation {
		uint32_t NameHash;
		enum AnnoType {
			AT_INT,
			AT_FLOAT,
			AT_STRING
		} Type;
		union {
			int Int;
			float Float;
			const char* String;
		};
	};
}