#pragma once
#include "grcProgram.hpp"

#include <cstdint>

namespace rage {
	class grcHullProgram : public grcProgram {
		friend class grcEffect;

	public:
		typedef grcHullShader* ProgramType;
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
			return HS_TYPE;
		};

	private:
		ProgramType Program;
		uint32_t ProgramSize;
	};
}