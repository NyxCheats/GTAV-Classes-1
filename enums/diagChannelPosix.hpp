#pragma once

namespace rage {
	enum diagChannelPosix {
		CHANNEL_POSIX_UNSPECIFIED = 0, // use default (off) or inherit parent
		CHANNEL_POSIX_OFF,             // expressly off
		CHANNEL_POSIX_ON,              // expressly on
	};
}