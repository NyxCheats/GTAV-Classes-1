#pragma once
#include "network/diagChannel.hpp"
#include "network/netStatus.hpp"
#include "rage/inmap_node.hpp"

#include <cstdint>

namespace rage {
	class rlTaskBase {
		friend class rlTaskManager;

	public:
		enum FinishType {
			FINISH_FAILED,
			FINISH_SUCCEEDED,
			FINISH_CANCELED
		};
		enum ShutdownBehaviour {
			CANCEL_ON_SHUTDOWN,
			EXECUTE_ON_SHUTDOWN,
		};
		virtual ~rlTaskBase() {
		}
		virtual const char* GetTaskName() const {
			return NULL;
		}
		virtual void Start() {
		}
		virtual void Update(const uint32_t timeStepMs) {
		}
		virtual bool IsCancelable() const {
			return false;
		}
		virtual const diagChannel* GetDiagChannel() const {
			return nullptr;
		}
		virtual ShutdownBehaviour GetShutdownBehaviour() {
			return CANCEL_ON_SHUTDOWN;
		}

	protected:
		virtual void Finish(const FinishType finishType) {
		}
		virtual void Finish(const FinishType finishType, const int resultCode) {
		}
		virtual void DoCancel() {
		}

	public:
		enum State {
			STATE_INVALID = -1,
			STATE_CONFIGURED,
			STATE_STARTED,
			STATE_FINISHED
		};
		enum Flags {
			FLAG_CANCELING = 0x01,
			FLAG_CANCELED  = 0x02,
		};
		uint32_t m_Id;
		netStatus* m_Status;
		State m_State;
		uint32_t m_Flags;
		int m_TimeoutTimerMs;
		//Task manager that's processing this instance.
		class rlTaskManager* m_Owner;
		//Task manager that created this instance.
		class rlTaskManager* m_Creator;
		inmap_node<unsigned, rlTaskBase> m_MapNodeByTaskId;
		inmap_node<const netStatus*, rlTaskBase> m_MapNodeByStatus;
		inmap_node<uint64_t, rlTaskBase> m_MapNodeByQueueId;
		rlTaskBase* m_Next;
		//Prevent copying
		rlTaskBase(const rlTaskBase&);
		rlTaskBase& operator=(const rlTaskBase&);
	};
}