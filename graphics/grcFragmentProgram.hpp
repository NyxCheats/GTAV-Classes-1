#pragma once
#include "enums/ShaderType.hpp"
#include "grcDevice.hpp"
#include "grcProgram.hpp"

#include <cstdint>

namespace rage {
	class grcFragmentProgram : public grcProgram {
		friend class grcEffect;

	public:
		typedef grcPixelShader* ProgramType;
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
			return PS_TYPE;
		}
		ProgramType Program;
		uint32_t ProgramSize;
	};
}