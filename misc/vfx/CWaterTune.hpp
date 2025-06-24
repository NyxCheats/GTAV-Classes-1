#pragma once
#include "rage/vector.hpp"

#include <cstdint>
#include <minwindef.h>

namespace rage {
	struct CWaterTune {
		DWORD m_water_color;
		float m_ripple_scale;
		float m_ocean_foam_scale;
		float m_specular_falloff;
		float m_fog_pierce_intensity;
		float m_refraction_blend;
		float m_refraction_exponent;
		float m_water_cycle_depth;
		float m_water_cycle_fade;
		float m_water_lightning_depth;
		float m_water_lightning_fade;
		float m_deep_water_mod_depth;
		float m_deep_water_mod_fade;
		float m_god_rays_lerp_start;
		float m_god_rays_lerp_end;
		float m_disturb_foam_scale;
		rage::fvector2 m_fog_min;
		rage::fvector2 m_fog_max;
	};
}