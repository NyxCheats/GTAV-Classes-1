#pragma once
#include "netHttpRequest.hpp"

namespace rage {
	class netHttpFilter {
		friend class netHttpRequest;

	public:
		virtual ~netHttpFilter() {
		}
		virtual bool CanFilterRequest() const {
			return false;
		}
		virtual bool CanFilterResponse() const {
			return false;
		}
		virtual uint32_t DelayMs() const {
			return 0;
		}
		virtual bool CanIntercept() const {
			return false;
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
			return false;
		}
		virtual void Receive(void* buf, const uint32_t bufSize, uint32_t* bytesReceived) {
		}
		virtual bool AllowSucceeded(class netHttpRequest* request) {
			return false;
		}
		virtual void DisableHttpDump(bool /*bDisabled*/) {
		}
		const netHttpRequest* m_HttpRequest;
	};
}