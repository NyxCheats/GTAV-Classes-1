#pragma once
#include <cstdint>

class CPlayerCardStats {
public:
	uint32_t m_access_flags;   //0x0000
	float m_kd_ratio;          //0x0004
	float m_unk_ratio;         //0x0008
	float m_rank;              //0x000C
	float m_can_spectate;      //0x0010
	float m_is_spectating;     //0x0014
	float m_current_crew_rank; //0x0018
	float m_overall_badsport;  //0x001C
	float m_stamina;           //0x0020
	float m_strength;          //0x0024
	float m_shooting_ability;  //0x0028
	float m_stealth_ability;   //0x002C
	float m_flying_ability;    //0x0030
	float m_wheelie_ability;   //0x0034
	float m_mental_state;      //0x0038
}; //Size: 0x003C
static_assert(sizeof(CPlayerCardStats) == 0x3C);