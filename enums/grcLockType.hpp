#pragma once
#include <cstdint>

namespace rage {
	enum grcLockType {
		grcsRead      = 0x01,
		grcsWrite     = 0x02,
		grcsDoNotWait = 0x04, // Will return a failed lock if unsuccessful
		grcsDiscard   = 0x08, // Discard contents of locked region entire buffer
		grcsNoOverwrite = 0x10, // Indicates that the region locked should not be in use by the GPU - Can cause visual artifacts if not used properly
		grcsNoDirty = 0x20, // Prevents driver from marking the region as dirty
		grcsAllowVRAMLock = 0x40, // don't assert VRAM lock if you know what you're doing
	};
}