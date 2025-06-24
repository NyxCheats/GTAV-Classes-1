#pragma once
#include "base/pgBase.hpp"
#include "enums/grcLockType.hpp"
#include "grcCellGcmTextureWrapper.hpp"
#include "grcDevice.hpp"
#include "grcEffect.hpp"
#include "grcImage.hpp"
#include "grcResolveFlags.hpp"
#include "grcTextureLock.hpp"

#include <cstdint>

namespace rage {
	struct grcPoint {
		int x, y;
	};
	typedef struct grcRect {
		int x1, y1;
		int x2, y2;
	} GRCRECT;
	using grcString = const char*;
	class grcTexture : public pgBase {
	public:
		const char* GetName() const {
			return m_Name;
		}
		virtual void Download() const {
		}
		virtual int GetDownloadSize() const {
			return 0;
		}
		virtual int GetWidth() const        = 0;
		virtual int GetHeight() const       = 0;
		virtual int GetDepth() const        = 0;
		virtual int GetMipMapCount() const  = 0;
		virtual int GetBitsPerPixel() const = 0;
		virtual bool IsValid() const {
			return false;
		}
		virtual grcDevice::MSAAMode GetMSAA() const {
			return grcDevice::MSAA_None;
		}
		virtual bool IsGammaEnabled() const {
			return false;
		}
		virtual void SetGammaEnabled(bool /*enabled*/) {
		}
		virtual uint32_t GetTextureSignedMask() const {
			return 0;
		}
		virtual void SetTextureSignedMask(uint32_t /*mask*/) {
		}
		virtual grcTexture* GetReference() = 0;
		virtual bool IsSRGB() const {
			return false;
		}
		virtual const grcTexture* GetReference() const = 0;
		virtual grcTextureObject* GetTexturePtr() {
			return NULL;
		}
		virtual const grcTextureObject* GetTexturePtr() const {
			return NULL;
		}
		virtual grcDeviceView* GetTextureView() {
			return NULL;
		}
		virtual void UpdateGPUCopy() {
		}
		virtual uint32_t GetImageFormat() const {
			return 0;
		} // cast this to grcImage::Format
		grcTextureObject* GetCachedTexturePtr() const {
			if (!this)
				return NULL;
			return const_cast<grcTextureObject*>(GetTexturePtr());
		}
		virtual bool LockRect(int /*layer*/, int /*mipLevel*/, grcTextureLock& /*lock*/, uint32_t /*uLockFlags*/ = (grcsRead | grcsWrite)) const {
			return false;
		}
		virtual void UnlockRect(const grcTextureLock& /*lock*/) const {
		}
		virtual void SwizzleTexture2D(const grcTextureLock& /*lock*/) const {
		}
		virtual void UnswizzleTexture2D(const grcTextureLock& /*lock*/) const {
		}
		virtual void Resize(uint32_t /*width*/, uint32_t /*height*/) {
		}
		virtual void SetEffectInfo(grcEffect*, grcEffectVar) const {
		}
		virtual void CreateMipMaps(const grcResolveFlags* /*resolveFlags*/, int /*index*/ = 0) {};
		virtual void Blur(const grcResolveFlags* /*resolveFlags*/) {};
		virtual bool Copy(const grcImage* pImage) = 0;
		virtual bool Copy(const grcTexture* /*pTexture*/, int32_t /*dstSliceIndex*/ = -1, int32_t /*dstMipIndex*/ = -1, int32_t /*srcSliceIndex*/ = 0, int32_t /*srcMipIndex*/ = 0) {
			return false;
		}
		virtual bool Copy(const void* /*pvSrc*/, uint32_t /*uWidth*/, uint32_t /*uHeight*/, uint32_t /*uDepth*/) {
			return false;
		}
		virtual bool Copy2D(const void* /*pSrc*/, uint32_t /*imgFormat*/, uint32_t /*uWidth*/, uint32_t /*uHeight*/, uint32_t /*numMips*/) {
			return false;
		}
		virtual bool Copy2D(const void* /*pSrc*/, const grcPoint& /*oSrcDim*/, const grcRect& /*oDstRect*/, const grcTextureLock& /*lock*/, int32_t /*iMipLevel*/ = 0) {
			return false;
		}
		virtual void Tile(int) {
		}
		grcCellGcmTextureWrapper m_Texture;
		const char* m_Name;
		uint16_t m_RefCount;
		uint8_t m_ResourceTypeAndConversionFlags;
		uint8_t m_LayerCount;
		uint8_t m_pad64 [ 4 ]; // this is actually in the source.
		grcTextureObject* m_CachedTexturePtr;
		uint32_t m_PhysicalSizeAndTemplateType;
		uint32_t m_HandleIndex;
	};
}