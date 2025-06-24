#pragma once
#include <cstdint>

namespace rage {
	class CGameVisuals {
	public:
		float m_fog_level;         //0x0000
		float m_distance_from_sun; //0x0004
		float m_unk_0x8;           //0x0008
		float m_fov;               //0x000C
		float m_unk_0x16;          //0x0010
		float m_unk_0x20;
		float m_chaos;
		float m_weird_gravity;
		float m_weird_gravity2;
		float m_wind;
		float m_sun_placement;
	};
}