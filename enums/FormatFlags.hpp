#pragma once
#include <cstdint>

namespace rage {
	enum {
		FORMAT_COUNT = LAST_FORMAT + 1
	};
	enum FormatFlags { // doesn't hurt to put this in its own enum, and this would allow switching on Format without 'default'
		FORMAT_FLAG_sRGB   = 0x80000000,
		FORMAT_FLAG_LINEAR = 0x40000000,
		FORMAT_FLAG_SYSMEM = 0x20000000,
		FORMAT_MASK        = 0x1fffffff,
	};
}