#pragma once
#include "enums/rlRos.hpp"
#include "enums/rlRosAccount.hpp"
#include "rlRosCredentials.hpp"

#include <cstdint>

namespace rage {
	typedef int64_t RockstarId;
	struct rlScAccountInfo {
		int m_Age;
		char m_AvatarUrl [ RLSC_MAX_AVATAR_URL_CHARS ];
		char m_CountryCode [ RLSC_MAX_COUNTRY_CODE_CHARS ];
		char m_Dob [ RLSC_MAX_DATE_CHARS ];
		char m_Email [ RLSC_MAX_EMAIL_CHARS ];
		bool m_IsApproxDob;
		char m_LanguageCode [ RLSC_MAX_LANGUAGE_ABBREV_CHARS ];
		char m_Nickname [ RLSC_MAX_NICKNAME_CHARS ];
		char m_Phone [ RLSC_MAX_PHONE_CHARS ];
		RockstarId m_RockstarId;
		char m_ZipCode [ RLSC_MAX_ZIP_CODE_CHARS ];
	};
}
