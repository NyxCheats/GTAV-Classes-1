#pragma once
#include "Rc4Context.hpp"
#include "Sha1.hpp"
#include "enums/rlRos.hpp"
#include "enums/rlRosHttpEncryption.hpp"
#include "enums/rlRosSecurityFlags.hpp"
#include "netHttpRequestFilter.hpp"
#include "rlRosContentSignature.hpp"
#include "rlRosCredentials.hpp"
#include "rlRosHttpUserAgentHeader.hpp"

#include <cstdint>

namespace rage {
	class rlRosHttpFilter : public netHttpFilter {
		struct VerifySignatureDelegate {
			char m_Delegate [ 32 ]; // Fuck impl for atDelegate. It's so retarded, I refuse to do it. SMD
		};

	public:
		virtual ~rlRosHttpFilter() {
		}
		virtual bool CanFilterRequest() const {
			return false;
		}
		virtual bool CanFilterResponse() const {
			return false;
		}
		virtual bool CanIntercept() const {
			return false;
		}
		virtual uint32_t DelayMs() const {
			return 0;
		}
		virtual bool FilterRequest(const uint8_t* data, const uint32_t dataLen, const bool finalCall, datGrowBuffer& output) {
			return false;
		}
		virtual bool FilterResponse(const uint8_t* data, const uint32_t dataLen, const bool allDataReceived, fiHandle& outputHandle, const fiDevice* outputDevice, uint32_t* numProcessed, bool* hasDataPending) {
			return false;
		}
		virtual const char* GetUserAgentString() const {
			return NULL;
		}
		virtual bool ProcessRequestHeader(class netHttpRequest* request) {
			return false;
		}
		virtual bool ProcessResponseHeader(const int statusCode, const char* header) {
		}
		virtual void Receive(void* buf, const uint32_t bufSize, uint32_t* bytesReceived) {
		}
		virtual bool AllowSucceeded(class netHttpRequest* request) {
			return false;
		}
		//These constants must EXACTLY match the values used on the backend.
		enum {
			KEY_LEN  = 16,
			SALT_LEN = 16
		};
		struct RequestData {
			rlRosHttpEncryption m_Encryption;
			rlRosSecurityFlags m_OriginalSecurityFlags;
			rlRosSecurityFlags m_SecurityFlags;
			Rc4Context m_Rc4;
			Sha1 m_Sha1;
			bool m_HaveWrittenPreamble;
			char m_UrlToGoTo [ 512 ];
			uint8_t m_Challenge [ 8 ];
			uint8_t m_HeaderHmacDigest [ Sha1::SHA1_DIGEST_LENGTH ];
		};
		RequestData m_Request;
		struct ResponseData {
			enum {
				KEY_OFFSET        = 0,
				BLOCK_SIZE_OFFSET = KEY_OFFSET + KEY_LEN,
				BLOCK_SIZE_LEN    = 4,
				PREAMBLE_LEN      = BLOCK_SIZE_OFFSET + BLOCK_SIZE_LEN
			};
			rlRosHttpEncryption m_Encryption;
			rlRosHttpEncryption m_DefaultEncryption;
			Rc4Context m_Rc4;
			uint8_t m_Key [ KEY_LEN ];
			bool m_HaveReadPreamble : 1;
			bool m_HaveContentSignature : 1;
			bool m_HaveContentHash : 1;
			uint8_t m_ExpectedContentHash [ Sha1::SHA1_DIGEST_LENGTH ];
			rlRosContentSignature m_ExpectedContentSignature;
			Sha1 m_ResponseSha1;
		};
		ResponseData m_Response;
		char m_UserAgentString [ rlRosHttpUserAgentHeader::MAX_USER_AGENT_LEN ];
		bool m_HaveSessionKey;
		rlRosCredentials::SessionKey m_SessionKey;
		char m_SessionTicket [ RLROS_MAX_SESSION_TICKET_SIZE ];
		VerifySignatureDelegate m_VerifySignatureDelegate;
		bool m_bDisableHttpDump;
	};
}
