#pragma once
#include <cstdint>

namespace rage {
	enum ImageType {
		STANDARD, // 2D image (still supports mipmaps, and texture array layers)
		CUBE, // Cube map image (+x,-x,+y,-y,+z,-z, stored as a 6-layer 2D image)
		DEPTH,  // Depth map image
		VOLUME, // Volume texture
		FORCETYPE32 = 0x7FFFFFFF
	};
}