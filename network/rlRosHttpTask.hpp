#pragma once
#include "WOLFSSL_CTX.hpp"
#include "enums/rlRosSecurityFlags.hpp"
#include "netsync/parTree.hpp"
#include "netsync/parTreeNode.hpp"
#include "rlHttpTask.hpp"
#include "rlRosHttpFilter.hpp"
#include "rlRosResult.hpp"

#include <cstdint>

namespace rage {
	class rlRosHttpTask : public rlHttpTask {
		friend class rlRosSaxReader;

	public:
		RL_TASK_USE_CHANNEL(rline_ros);
		RL_TASK_DECL(rlRosHttpTask);
		virtual ~rlRosHttpTask() = default;
		enum rlRosHttpServices {
			GAME_SERVICES,
			LAUNCHER_SERVICES
		};
		virtual bool UseHttps() const {
			return false;
		}
		virtual SSL_CTX* GetSslCtx() const {
			return nullptr;
		}
		virtual rlRosSecurityFlags GetSecurityFlags() const {
			return rlRosSecurityFlags::RLROS_SECURITY_NONE;
		}
		virtual const char* GetUrlHostName(char* hostnameBuf, const uint32_t sizeofBuf) const {
			return NULL;
		}
		virtual bool ProcessResponse(const char* response, int& resultCode) {
			return false;
		}
		virtual bool GetServicePath(char* svcPath, const uint32_t maxLen) const {
			return false;
		}
		virtual const char* GetServiceMethod() const {
			return NULL;
		}
		virtual bool ProcessSuccess(const rlRosResult& result, const parTreeNode* node, int& resultCode) {
			return false;
		}
		virtual void ProcessError(const rlRosResult& result, const parTreeNode* node, int& resultCode) {
		}
		virtual bool SaxStartElement(const char* name) {
			return false;
		}
		virtual bool SaxAttribute(const char* name, const char* val) {
			return false;
		}
		virtual bool SaxCharacters(const char* ch, const int start, const int length) {
			return false;
		}
		virtual bool SaxEndElement(const char* name) {
			return false;
		}
		virtual bool UseFilter() const {
			return false;
		}
		virtual const char* GetServiceSet() const {
			return NULL;
		}
		rlRosHttpFilter m_Filter;

	private:
		int m_LocalGamerIndex;
		rlRosHttpServices m_Service;
		parTree** m_ParserTree;
	};
}