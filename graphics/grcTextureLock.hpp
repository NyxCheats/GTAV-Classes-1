#pragma once
#include <cstdint>

namespace rage {
	struct grcTextureLock {
		int MipLevel;
		void* Base;
		int Pitch;
		int BitsPerPixel;
		int Width, Height;
		int RawFormat; // D3DFMT_... on D3D builds, or SCE_GS_PSM_... on PSX2.
		int Layer; // Represents either face of cubemap or layer of volume texture
	};
}