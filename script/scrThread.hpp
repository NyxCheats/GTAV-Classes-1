#pragma once
#include "../rage/scrValue.hpp"
#include "enums/scrProgramId.hpp"
#include "enums/scrThreadId.hpp"
#include "rage/atRangeArray.hpp"
#include "scrThreadContext.hpp"
#include "scriptHandler.hpp"
#include "scriptHandlerNetComponent.hpp"

#define MAX_CALLSTACK 16

namespace rage {
	class scrThread {
	public:
		enum {
			c_DefaultStackSize = 512
		}; // static constexpr causes missing symbol under gcc 4.1.1 debug builds.
		// Presume it's something to do with its use as a default parameter.
		enum {
			c_NativeInsnLength = 4
		}; // Length of OP_NATIVE insn in case caller needs PC of *next* insn.
		enum State {
			RUNNING,
			BLOCKED,
			ABORTED,
			HALTED
		};
		enum Priority {
			THREAD_PRIO_HIGHEST,
			THREAD_PRIO_NORMAL,
			THREAD_PRIO_LOWEST,
			THREAD_PRIO_MANUAL_UPDATE = 100
		};
		struct Serialized {
			scrThreadId m_ThreadId; // +0 Unique thread ID (always increasing)
			scrProgramId m_Prog; // +4 Stored by hashcode rather than pointer so load/save can work
			State m_State; // +8 Current thread state
			int m_PC; // +12 Current program counter (index into program's opcodes array)
			int m_FP; // +16 Current frame pointer (anchor for local variables)
			int m_SP; // +20 Stack pointer
			float m_TimerA, m_TimerB; // Local per-thread timer values
			float m_Wait;             // Accumulated wait timer
			int m_MinPC, m_MaxPC;     // Step region for debugger
			atRangeArray<scrValue, 4> m_TLS; // Thread-local storage for blocking functions
			int m_StackSize;
			int m_CatchPC, m_CatchFP, m_CatchSP;
			Priority m_Priority; // 0=highest (runs first), 2=lowest (runs last)
			s8 m_CallDepth;
			atRangeArray<int, MAX_CALLSTACK> m_CallStack;
		};
		struct Global {
			int BasicType; // enumerant in scrValue
			int Offset;    // Base address of this variable
			u32 Hash; // Hashed name of this variable (as per scrComputeHash)
		};
		struct Info {
			Info(scrValue* resultPtr, int parameterCount, const scrValue* params) :
			    ResultPtr(resultPtr), ParamCount(parameterCount), Params(params), BufferCount(0) {
			}
			// Return result, if applicable
			scrValue* ResultPtr;
			// Parameter count
			int ParamCount;
			// Pointer to parameter values
			const scrValue* Params;
			// Temp storage for managing copyin/copyout of Vector3 parameters
			int BufferCount;
			enum {
				MAX_VECTOR3 = 4
			};
			scrValue* Orig [ MAX_VECTOR3 ];
			scrVector Buffer [ MAX_VECTOR3 ];
			scrVector& GetVector3(int& N) {
				scrValue* v          = Params [ N++ ].Reference;
				Orig [ BufferCount ] = v;
				Buffer [ BufferCount ].set(v [ 0 ].Float, v [ 1 ].Float, v [ 2 ].Float);
			}
			void CopyReferencedParametersOut() {
				int bc = BufferCount;
				while (bc--) {
					Orig [ bc ][ 0 ].Float = Buffer [ bc ].x;
					Orig [ bc ][ 1 ].Float = Buffer [ bc ].y;
					Orig [ bc ][ 2 ].Float = Buffer [ bc ].z;
				}
			}
		};
		virtual ~scrThread() = default;
		virtual void Reset(scrProgramId program, const void* argStruct, int argStructSize) {
		}
		virtual State Run(int insnCount) {
			return m_Serialized.m_State;
		}
		virtual State Update(int insnCount) {
			return m_Serialized.m_State;
		}
		virtual void Kill() {
		}
		struct ThreadStack {
			scrThread* m_Owner;
			int m_StackSize;
			scrValue* m_Stack;
		};
		Serialized m_Serialized;
		scrValue* m_Stack;
		int m_iInstructionCount;
		int m_argStructSize;
		int m_argStructOffset;
		const char* m_AbortReason;
		u32 m_ScriptNameHash;
		char m_ScriptName [ 64 ];
	};
	typedef void (*scrCmd)(scrThread::Info*);
}
