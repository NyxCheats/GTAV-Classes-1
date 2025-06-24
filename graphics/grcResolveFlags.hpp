#pragma once
#include "Color32.hpp"
#include "enums/grcMrt.hpp"

#include <cstdint>

namespace rage {
	struct grcResolveFlags {
		float Depth;
		float BlurKernelSize; // size of blur
		Color32 Color;
		uint32_t Stencil;
		int ColorExpBias;
		bool ClearColor;
		bool ClearDepthStencil;
		bool BlurResult;
		bool NeedResolve;
		bool MipMap;
	};
	typedef grcResolveFlags* grcResolveFlagsMrt [ grcmrtColorCount ];
}