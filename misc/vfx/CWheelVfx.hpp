#pragma once
#include "script/types.hpp"

#include <cstdint>

namespace rage {
	struct CWheelVfx {
		float m_slip_min;               //0x0004
		float m_slip_max;               //0x0008
		float m_pressure_min;           //0x000C
		float m_pressure_max;           //0x0010
		int m_decal_id;                 //0x0014
		BOOL m_unk1;                    //0x0018
		int m_decal_id2;                //0x001c
		BOOL m_unk2;                    //0x0010
		int m_decal_id3;                //0x0024
		BOOL m_unk3;                    //0x0028
		int m_decal_id4;                //0x002c
		BOOL m_unk4;                    //0x0030
		uint8_t m_tint_r;               //0x0034
		uint8_t m_tint_g;               //0x0035
		uint8_t m_tint_b;               //0x0036
		char unk_something [ 1 ];       //0x0037
		float m_friction_thresh_min;    //0x0038
		float m_friction_thresh_max;    //0x003C
		uint32_t m_friction_fx1;        //0x0040
		uint32_t m_friction_fx2;        //0x0044
		uint32_t m_friction_fx3;        //0x0048
		float m_disp_thresh_min;        //0x004C
		float m_disp_thresh_max;        //0x0050
		uint32_t m_displacement_fx1;    //0x0054
		uint32_t m_displacement_fx2;    //0x0058
		uint32_t m_displacement_fx3;    //0x005C
		uint32_t m_displacement_fx_lod; //0x0060
		float m_burn_friction_evo_min;  //0x0064
		float m_burn_friction_evo_max;  //0x0068
		float m_burn_friction_temp_min; //0x006C
		float m_burn_friction_temp_max; //0x0070
		uint32_t m_burnout_fx1;         //0x0074
		uint32_t m_burnout_fx2;         //0x0078
		uint32_t m_burnout_fx3;         //0x007C
		bool m_lights_on;               //0x0080
		uint8_t m_lights_col_min_r;     //0x0081
		uint8_t m_lights_col_min_g;     //0x0082
		uint8_t m_lights_col_min_b;     //0x0083
		uint8_t m_lights_col_max_r;     //0x0084
		uint8_t m_lights_col_max_g;     //0x0085
		uint8_t m_lights_col_max_b;     //0x0086
		char unk_something2 [ 1 ];      //0x0087
		float m_lights_intensity_min;   //0x0088
		float m_lights_intensity_max;   //0x008C
		float m_lights_range_min;       //0x0090
		float m_lights_range_max;       //0x0094
		float m_lights_falloff_min;     //0x0098
		float m_lights_falloff_max;     //0x009C$
	};
}