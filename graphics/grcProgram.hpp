#pragma once
#include "grcCBuffer.hpp"
#include "grcEffect.hpp"
#include "grcParameter.hpp"
#include "grcTexture.hpp"

#include <cstdint>

#define EFFECT_CONSTANT_BUFFER_COUNT 14
#define EFFECT_UAV_BUFFER_COUNT 4
#define EFFECT_SAMPLER_COUNT 16
#define EFFECT_TEXTURE_COUNT 42

namespace rage {
	class grcProgram {
		friend class grcEffect;
		friend class grcInstanceData;

	public:
		virtual ~grcProgram()                   = default;
		virtual uint32_t GetProgramSize() const = 0;

		const char* m_EntryName;
		atArray<uint32_t> m_Constants;
		void** m_ppDeviceCBuffers;
		uint32_t m_CBufferFingerprint;
		uint8_t m_CBufStartSlot, m_CBufEndSlot;
		int8_t m_TexStartSlot, m_TexEndSlot;
		int m_numCBuffers;
		grcCBuffer* m_pCBuffers [ EFFECT_CONSTANT_BUFFER_COUNT ];
		int m_numTexContainers;
		grcParameter* m_pTexContainers [ EFFECT_TEXTURE_COUNT + EFFECT_UAV_BUFFER_COUNT ];
		uint32_t m_HashKey;
	};
}