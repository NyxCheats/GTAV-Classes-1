#pragma once
#include "grcProgram.hpp"

#include <cstdint>

namespace rage {
	class grcGeometryProgram : public grcProgram {
		friend class grcEffect;

	public:
		struct grcStream {
			char mSemanticName [ 16 ];
			uint8_t mSemanticIndex;
			uint8_t mStartComponent;
			uint8_t mComponentCount;
			uint8_t mOutputSlot;
		};
		typedef grcGeometryShader* ProgramType;
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
			return GS_TYPE;
		};

	private:
		ProgramType Program;
		uint32_t ProgramSize;
		grcStream* Streams;
		uint32_t StreamCount;
	};
}