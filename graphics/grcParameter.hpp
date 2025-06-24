#pragma once
#include "grcInstanceData.hpp"
#include "grcTexture.hpp"

#include <cstdint>

namespace rage {
	enum {
		TEXTURE_REGISTER_BITS = 6,
		TEXTURE_USAGE_BITS    = 7
	};

	class grcParameter {
		friend class grcEffect;
		friend class grcInstanceData;

	public:
		struct Annotation {
			uint32_t NameHash; // Annotation name
			enum AnnoType {
				AT_INT,
				AT_FLOAT,
				AT_STRING
			} Type; // Discriminator for payload
			union { // Payload (String is allocated on heap)
				int Int;
				float Float;
				const char* String;
			};
		};
		uint8_t Type;
		uint8_t Count;
		uint8_t DataSize;
		uint8_t AnnotationCount;
		const char* Name;
		const char* Semantic;
		uint32_t NameHash;
		uint32_t SemanticHash;
		Annotation* Annotations;
		void* Data;
		uint16_t Register : TEXTURE_REGISTER_BITS;
		uint16_t TextureType : 8 - TEXTURE_REGISTER_BITS;
		uint16_t Usage : TEXTURE_USAGE_BITS;
		uint16_t ComparisonFilter : 8 - TEXTURE_USAGE_BITS;
		uint8_t SamplerStateSet;
		uint8_t SavedSamplerStateSet;
		uint32_t CBufferOffset;
		uint32_t CBufferNameHash;
		union {
			grcCBuffer* CBuf;
			const class grcTexture* Tex;
			const grcBufferUAV* RO_Buffer;
			grcBufferUAV* RW_Buffer;
			const grcTextureUAV* RW_Texture;
		};
	};
}