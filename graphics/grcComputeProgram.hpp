#pragma once
#include "grcProgram.hpp"
#include <cstdint>

namespace rage {
	class grcComputeProgram : public grcProgram {
		friend class grcEffect;

	public:
		typedef grcComputeShader* ProgramType;
		ProgramType GetProgram() {
			return Program;
		}
		ProgramType GetProgram() const {
			return Program;
		}
		uint32_t GetProgramSize() const {
			return ProgramSize;
		}
		static ShaderType GetShaderType() {
			return CS_TYPE;
		}

	private:
		ProgramType Program;
		uint32_t ProgramSize;
	};
}