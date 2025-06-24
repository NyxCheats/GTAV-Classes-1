#pragma once
#include <cstdint>

namespace rage {
	struct rlRosResult {
		rlRosResult() :
		    m_Succeeded(true), m_Code(0), m_CodeEx(0), m_Ctx(0), m_Location(0), m_Msg(0) {
		}
		bool m_Succeeded;
		const char* m_Code;
		const char* m_CodeEx;
		const char* m_Ctx;
		const char* m_Location;
		const char* m_Msg;
	};
}
