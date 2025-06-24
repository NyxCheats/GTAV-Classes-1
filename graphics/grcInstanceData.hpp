#pragma once
#include "grcTexture.hpp"

#include <cstdint>

namespace rage {
	typedef void grcBufferBasic;
	typedef void grcBufferUAV;
	typedef void grcTextureUAV;
	class grcInstanceData {
	public:
		void Clone(grcInstanceData& outClone) const {
			outClone.Basis = Basis;
			if (Flags & FLAG_MATERIAL)
				outClone.Material = const_cast<grcInstanceData*>(this);
			else
				outClone.Material = NULL;
			outClone.Count              = Count;
			outClone.TotalSize          = TotalSize;
			outClone.SpuSize            = SpuSize;
			outClone.DrawBucket         = DrawBucket;
			outClone.DrawBucketMask     = DrawBucketMask;
			outClone.PhysMtl_DEPRECATED = PhysMtl_DEPRECATED;
			outClone.pad                = pad;
			outClone.TextureCount       = TextureCount;
			outClone.IsInstanced        = IsInstanced;
			outClone.UserFlags          = UserFlags;
			outClone.Flags              = Flags & ~FLAG_MATERIAL;
			char* buffer     = (TotalSize ? new char [ TotalSize ] : NULL);
			outClone.Entries = (grcInstanceData::Entry*)buffer;
			memcpy(buffer, Entries, TotalSize);
			ptrdiff_t fixup = buffer - (char*)Entries;
			for (int i = 0; i < TextureCount; i++) {
				outClone.Data() [ i ].Texture = Data() [ i ].Texture;
			}
			for (int i = TextureCount; i < Count; i++) {
				outClone.Data() [ i ].Any = (void*)((char*)Data() [ i ].Any + fixup);
			}
		}
		struct Entry {
			uint8_t Count;
			uint8_t Register;
			uint8_t SamplerStateSet, SavedSamplerStateSet;
			union {
				float* Float;
				void* Texture;
				const grcBufferUAV* RO_Buffer;
				grcBufferUAV* RW_Buffer;
				const grcTextureUAV* RW_Texture;
				void* Any;
			};
		};
		__forceinline Entry* Data() const {
			return Entries;
		}
		Entry* Entries;
		union {
			class grcEffect* Basis;
			uint32_t BasisHashCode;
		};
		enum {                      // For 'Flags' immediately below
			FLAG_MATERIAL = 0x01,   // This instanceData is really a material
			FLAG_EXTRA_DATA = 0x80, // This instanceData already has its MTR-expanded buffers allocated (if relevant)
		};
		uint8_t Count, DrawBucket, PhysMtl_DEPRECATED, Flags;
		uint16_t SpuSize, TotalSize;
		union {
			grcInstanceData* Material;
			uint32_t MaterialHashCode;
			const char* MaterialName;
		};
		uint32_t DrawBucketMask;
		bool IsInstanced;
		uint8_t UserFlags;
		uint8_t pad, TextureCount;
		uint32_t SortKey_DEPRECATED;
	};
}