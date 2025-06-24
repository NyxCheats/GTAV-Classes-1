#pragma once
#include <cstdint>

namespace rage {
	struct CellGcmTexture {
		uint8_t format;
		uint8_t mipmap;
		uint8_t dimension;
		uint8_t cubemap;
		uint32_t remap;
		uint16_t width;
		uint16_t height;
		uint16_t depth;
		uint8_t location;
		uint8_t _padding;
		uint32_t pitch;
		uint32_t offset;
	};
	struct grcCellGcmTextureWrapper : CellGcmTexture {
		inline void SetWidth(uint16_t in) {
			width = in;
		}
		inline uint16_t GetWidth() const {
			return width;
		};
		inline void SetHeight(uint16_t in) {
			height = in;
		}
		inline uint16_t GetHeight() const {
			return height;
		};
		inline void SetDepth(uint16_t in) {
			depth = in;
		}
		inline uint16_t GetDepth() const {
			return depth;
		};
		inline void SetFormat(uint8_t in) {
			format = in;
		}
		inline uint8_t GetFormat() const {
			return format;
		};
		inline void SetDimension(uint8_t in) {
			dimension = in;
		}
		inline uint8_t GetDimension() const {
			return dimension;
		};
		inline void SetMipMap(uint8_t in) {
			mipmap = in;
		}
		inline uint8_t GetMipMap() const {
			return mipmap;
		};
		inline void SetBindFlag(uint8_t in) {
			_padding = in;
		}
		inline uint8_t GetBindFlag() const {
			return _padding;
		};
		inline void SetTileMode(uint8_t in) {
			location = in;
		}
		inline uint8_t GetTileMode() const {
			return location;
		};
		inline void SetImageType(uint8_t in) {
			cubemap = in;
		}
		inline uint8_t GetImageType() const {
			return cubemap;
		};
		inline void SetOwnsMem(uint32_t in) {
			remap = in;
		}
		inline uint32_t GetOwnsMem() const {
			return remap;
		};
		inline void SetUsesPreAllocatedMem(uint32_t in) {
			pitch = in;
		}
		inline uint32_t GetUsesPreAllocatedMem() const {
			return pitch;
		};
	};
}