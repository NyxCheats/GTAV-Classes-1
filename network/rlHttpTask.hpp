#pragma once
#include "WOLFSSL_CTX.hpp"
#include "diagChannel.hpp"
#include "base/rlTaskBase.hpp"
#include <cstdint>

#define RL_TASK_DECL(name)                    \
	virtual const char* GetTaskName() const { \
		return #name;                         \
	}
#define RL_TASK_USE_CHANNEL(tag)                        \
	virtual const diagChannel* GetDiagChannel() const { \
		return nullptr;                                 \
	}

namespace rage {
	class rlHttpTask : public rlTaskBase {
	public:
		static constexpr int MAX_MULTIPART_BOUNDARY_LENGTH = 32;
		static constexpr int MAX_MULTIPART_BOUNDARY_BUF_SIZE = MAX_MULTIPART_BOUNDARY_LENGTH + 1;
		RL_TASK_DECL(rlHttpTask);
		RL_TASK_USE_CHANNEL(rline_http);
		virtual ~rlHttpTask() = default;
		virtual bool IsCancelable() const {
			return true;
		}
		virtual void DoCancel() {
		}
		virtual void Start() {
		}
		virtual void Update(const uint32_t timeStep) {
		}
		virtual void Finish(const FinishType finishType, const int resultCode = 0) {
		}

	protected:
		virtual bool UseHttps() const {
			return false;
		}
		virtual SSL_CTX* GetSslCtx() const {
			return nullptr;
		}
		virtual const char* GetUrlHostName(char* /*hostnameBuf*/, const uint32_t /*sizeofBuf*/) const {
			return NULL;
		}
		virtual bool GetServicePath(char* /*svcPath*/, const uint32_t /*maxLen*/) const {
			return false;
		}
		virtual bool ProcessResponse(const char* response, int& resultCode) {
			return false;
		}
	};
}