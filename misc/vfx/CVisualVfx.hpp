#pragma once
#include <cstdint>

namespace rage {
	struct CVisualVfx { // emm
		char pad_0000 [ 0x2874 ];
		float m_shadow_light;
		float m_reflection;
		float m_gamma;
		float m_blur;
		float m_blur2;
		float m_sky_intensity;
		float m_saturation;
		float unk1;
		float unk2;
		float unk3;
		float distorsion;
	};
}