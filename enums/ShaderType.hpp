#pragma once
#include <cstdint>

namespace rage {
	enum ShaderType {
		VS_TYPE,
		PS_TYPE,
		CS_TYPE,
		DS_TYPE,
		GS_TYPE,
		HS_TYPE,
		NUM_TYPES,
		NONE_TYPE = NUM_TYPES
	};
}