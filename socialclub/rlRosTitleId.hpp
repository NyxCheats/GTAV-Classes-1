#pragma once
#include "enums/rlRos.hpp"
#include "enums/rlRosEnvironment.hpp"
#include "enums/rlRosSecurityFlags.hpp"
#include "rlRosTitleSecrets.hpp"

#include <cstdint>
#include <wtypes.h>

namespace rage {
	class rlRosTitleId {
	public:
		rlRosTitleId(const char* titleName, const char* titleDirectoryName, const int scVersion, const int titleVersion, const char* titleSecretsBase64, const rlRosEnvironment env, const uint8_t* publicRsaKey, const uint32_t publicRsaKeyLen) {
		}
		char m_TitleName [ RLROS_MAX_TITLE_NAME_SIZE ];
		int m_TitleVersion;
		int m_ScVersion;
		rlRosSecurityFlags m_SecurityFlags;
		rlRosTitleSecrets m_TitleSecrets;
		const uint8_t* m_PublicRsaKey;
		uint32_t m_PublicRsaKeyLen;
		char m_TitleSecretsBase64 [ rlRosTitleSecrets::TOTAL_BASE64_SIZE ];
		char m_TitleDirectoryName [ RLROS_MAX_TITLE_DIRECTORY_SIZE ];
		rlRosEnvironment m_Env;
		char m_DomainName [ 128 ];
		char m_CloudDomainName [ 128 ];
		char m_HostNamePrefix [ 64 ];
		rlRosEnvironment m_ForcedEnv;
	};
}