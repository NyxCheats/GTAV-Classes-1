#pragma once
#include "netIpAddress.hpp"

namespace rage {
	class netSocketAddress {
	public:
		netIpAddress m_Ip;
		uint16_t m_Port;
	};
}