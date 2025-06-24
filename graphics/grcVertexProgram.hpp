#pragma once
#include "enums/ShaderType.hpp"
#include "grcEffect.hpp"

#include <cstdint>
#include <d3d11.h>

namespace rage {
	struct grcVertexDeclaration {
		int Release() const {
			return !(--refCount) ? refCount : (delete this, 0);
		}
		void AddRef() const {
			++refCount;
		}
		static constexpr uint32_t c_MaxStreams = 4; // Really 16 under DX11...
		int elementCount;
		mutable int refCount;
		uint32_t Stream0Size;
		//d3d11InputElementDesc desc[0];
	};
	class grcVertexProgram : public grcProgram {
		friend class grcEffect;

	public:
		typedef grcPixelShader* ProgramType;
		ProgramType GetProgram() {
			return Program;
		}
		ProgramType GetProgram() const {
			return Program;
		}
		void* GetProgramData() {
			return ProgramData;
		}
		void* GetProgramData() const {
			return ProgramData;
		}
		uint32_t GetProgramSize() const {
			return ProgramSize;
		}
		static ShaderType GetShaderType() {
			return VS_TYPE;
		}
		struct DeclSetup {
			const grcVertexDeclaration* FetchDecl;
			ID3D11InputLayout* InputLayout;
			DeclSetup* Next;
		};
		ProgramType Program;
		uint32_t ProgramSize;
		void* ProgramData;
		DeclSetup* FirstDecl;
	};
}