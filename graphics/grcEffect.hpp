#pragma once
#include "grcCBuffer.hpp"
#include "grcComputeProgram.hpp"
#include "grcDomainProgram.hpp"
#include "grcFragmentProgram.hpp"
#include "grcGeometryProgram.hpp"
#include "grcHullProgram.hpp"
#include "grcInstanceData.hpp"
#include "grcParameter.hpp"
#include "grcParameterAnnotation.hpp"
#include "grcProgram.hpp"
#include "grcTexture.hpp"
#include "grcVertexProgram.hpp"
#include "rage/atArray.hpp"
#include "rage/atStringHash.hpp"
#include "rage/sysMemContainerData.hpp"

#include <cstdint>

namespace rage {
	typedef enum grcEffectGlobalVar__ {
		grcegvNONE
	} grcEffectGlobalVar;
	typedef enum grcEffectVar__ {
		grcevNONE
	} grcEffectVar;
	typedef enum grcEffectTechnique__ {
		grcetNONE
	} grcEffectTechnique;
	typedef enum grcEffectAnnotation__ {
		grceaNONE
	} grcEffectAnnotation;
	struct grcEffect_Technique_Pass {
		uint8_t VertexProgramIndex, FragmentProgramIndex;
		uint8_t GeometryProgramIndex, ComputeProgramIndex, DomainProgramIndex, HullProgramIndex;
		uint8_t RasterizerStateHandle, DepthStencilStateHandle, BlendStateHandle, AlphaRef, StencilRef, pad;
	};
	inline static uint8_t s_StencilRefMask = 0xFF;
	class grcEffect {
	public:
		static constexpr int MAX_TECHNIQUE_GROUPS = 64;
		grcEffectTechnique LookupTechnique(const char* name) {
			return LookupTechniqueByHash(atStringHash(name));
		}
		grcEffectTechnique LookupTechniqueByHash(uint32_t hash) {
			for (int i = 0; i < m_Techniques.size(); i++)
				if (m_Techniques [ i ].NameHash == hash)
					return (grcEffectTechnique)(i + 1);
			return grcetNONE;
		}
		grcEffectTechnique GetTechniqueByIndex(int idx) const {
			return (grcEffectTechnique)(idx + 1);
		}
		int GetTechniqueCount() const {
			return m_Techniques.size();
		}
		enum eDrawType {
			RMC_DRAW,
			RMC_DRAWSKINNED,
			RMC_DRAW_TESSELLATED,
			RMC_DRAWSKINNED_TESSELLATED,
			RMC_DRAW_INSTANCED,
			RMC_DRAWSKINNED_INSTANCED,
			RMC_DRAW_INSTANCED_TESSELLATED,
			RMC_DRAWSKINNED_INSTANCED_TESSELLATED,
			RMC_COUNT
		};
		void Clone(grcInstanceData& outClone) const {
			m_InstanceData.Clone(outClone);
		}
		struct Technique {
			typedef grcEffect_Technique_Pass Pass;
			uint32_t NameHash;
			const char* Name;
			atArray<Pass> Passes;
		};
		static uint8_t GetStencilRefMask() {
			return s_StencilRefMask;
		}
		static void SetStencilRefMask(uint8_t mask) {
			s_StencilRefMask = mask;
		}
		atArray<Technique> m_Techniques;
		atArray<grcParameter> m_Locals;
		atArray<grcCBuffer*> m_LocalsCBuf;
		atArray<grcVertexProgram> m_VertexPrograms;
		atArray<grcFragmentProgram> m_FragmentPrograms;
		uint8_t m_TechniqueMap [ MAX_TECHNIQUE_GROUPS ][ RMC_COUNT ];
		sysMemContainerData m_Container;
		char m_EffectName [ 40 ];
		grcInstanceData m_InstanceData;
		uint64_t m_EffectTimeStamp;
		const char* m_EffectPath;
		uint32_t m_NameHash;
		atArray<grcParameterAnnotation> m_Properties;
		uint32_t m_Dcl;
		uint16_t m_Ordinal;
		atArray<void*> m_VarInfo;
		atArray<grcComputeProgram> m_ComputePrograms;
		atArray<grcDomainProgram> m_DomainPrograms;
		atArray<grcGeometryProgram> m_GeometryPrograms;
		atArray<grcHullProgram> m_HullPrograms;
	};
}