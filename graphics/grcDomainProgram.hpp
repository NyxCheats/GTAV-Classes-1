#pragma once
#include "enums/ShaderType.hpp"
#include "grcProgram.hpp"

#include <cstdint>

namespace rage {
	class grcDomainProgram : public grcProgram {
		friend class grcEffect;

	public:
		typedef grcDomainShader* ProgramType;
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
			return DS_TYPE;
		};

	private:
		ProgramType Program;
		uint32_t ProgramSize;
	};
}