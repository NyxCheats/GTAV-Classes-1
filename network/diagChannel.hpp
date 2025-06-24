#pragma once
#include "enums/diagChannelPosix.hpp"
#include "enums/diagSeverity.hpp"

#include <cstdint>

namespace rage {
	class diagChannel {
	public:
		diagChannel(diagChannel* parent, const char* tag, const char* paramTag, diagSeverity fileLevel = DIAG_SEVERITY_DEBUG1, diagSeverity ttyLevel = DIAG_SEVERITY_DISPLAY, diagSeverity popupLevel = DIAG_SEVERITY_ASSERT, diagChannelPosix posixPrefix = CHANNEL_POSIX_UNSPECIFIED);
		diagChannel() = default;
		uint8_t FileLevel, TtyLevel, PopupLevel, MaxLevel;
		uint8_t ParentCount; // Number of parents (could easily be u8)
		uint8_t OriginalFileLevel; //stores the original file severity level when setting an override
		uint8_t OriginalTtyLevel; //stores the original tty severity level when setting an override
		diagChannelPosix PosixPrefix;

	private:
		diagChannel* Parent;
		diagChannel* Next;
	};
}