#pragma once

#include "../rage/rlGamerInfo.hpp"
#include "../rage/rlSessionInfo.hpp"
#include "MatchmakingAttributes.hpp"

#pragma pack(push, 1)
namespace rage {
	class netConnectionManager;
	class sysMemAllocator;

	class snPlayer {
	public:
		uint64_t m_msg_id;                     //0x0000
		class rage::rlGamerInfo m_player_data; //0x0008
		char pad_00F8 [ 8 ];                   //0x00F8
	}; //Size: 0x0100
	static_assert(sizeof(rage::snPlayer) == 0x100);

	class snPeer {
	public:
		class rage::rlGamerInfo m_peer_data; //0x0000
		char pad_0098 [ 40 ];                //0x0098
	}; //Size: 0x00C0
	static_assert(sizeof(rage::snPeer) == 0x118);

	class rlRemoteGamer {
	public:
		rage::rlGamerHandle m_handle;
		char pad_0010 [ 4 ];     //0x0010
		uint32_t m_timeout_time; //0x0014
		uint32_t m_time_unk;     //0x0018
		char pad_001C [ 4 ];     //0x001C
	}; //Size: 0x0020
	static_assert(sizeof(rage::rlRemoteGamer) == 0x20);


	class rlSession {
	public:
		char pad_0008 [ 248 ];                    //0x0008
		class rage::rlSessionInfo m_session_info; //0x0100
		char pad_01D0 [ 296 ];                    //0x01D0
		uint64_t m_session_id;                    //0x02F8
		char pad_0300 [ 1136 ];                   //0x0300

		virtual ~rlSession() = default;
	}; //Size: 0x0770
	static_assert(sizeof(rage::rlSession) == 0x770);

	class rlSessionConfig {
	public:
		char m_pad [ 0x4 ];                             // 0x00
		int m_public_slots;                             // 0x04
		int m_private_slots;                            // 0x08
		MatchmakingAttributes m_matchmaking_attributes; // 0x0C
		char m_pad2 [ 0x18 ];                           // 0x10C
	};
	static_assert(sizeof(rage::rlSessionConfig) == 0x130);

	class rlSessionDetail {
	public:
		class rage::rlGamerInfoBase m_base_gamer_info; // 0x00
		std::uint64_t m_host_token;                    // 0xC0
		class rage::rlSessionInfo m_session_info;      // 0xC8
		class rage::rlSessionConfig m_session_config;  // 0x198
		rage::rlGamerHandle m_handle;                  // 0x2C8
		char m_name [ 0x14 ];                          // 0x2D8
		uint32_t m_player_count;                       // 0x2EC
		uint32_t m_spectator_count;                    // 0x2F0
		uint16_t m_session_data_struct_size;           // 0x2F4
		char m_session_data_struct [ 0x100 ]; // 0x2F6 likely a union of two structs, sizes 0x44 and 0x28
		uint16_t m_matchmaking_data_struct_size; // 0x3F6
		char m_matchmaking_data_struct [ 0x80 ]; // 0x3F8 stores matchmaking tunable data?
	}; //Size: 0x03CA
	static_assert(sizeof(rlSessionDetail) == 0x478);

	class rlSessionDetailMsg {
	public:
		int m_status;
		int m_required_version;
		int m_request_token;
		int m_unk;
		rlSessionDetail m_detail;
	};
	static_assert(sizeof(rlSessionDetailMsg) == 0x488);

	class rlMatchmakingFindResult {
	public:
		class rage::rlSessionDetail m_result_session_details [ 15 ]; //0x0000
		char pad_37C8 [ 168 ];                                       //0x37C8
	}; //Size: 0x3870
	static_assert(sizeof(rage::rlMatchmakingFindResult) == 0x43B0);

	class netGamePlayerData {
	public:
		class rlGamerHandle m_handle;
		bool m_is_activity_spectator; //0x0010
		char pad_0011 [ 7 ];          //0x0011
		uint64_t m_crew_id;           //0x0018
		uint16_t m_rank;              //0x0020
		uint16_t m_debug_unk;         //0x0022
		char pad_0024 [ 4 ];          //0x0024
		uint32_t m_nat_type;          //0x0028
		bool m_is_rockstar_dev;       //0x002C
		char pad_002D [ 3 ];          //0x002D
	}; //Size: 0x0030
	static_assert(sizeof(rage::netGamePlayerData) == 0x30);


	class snSession {
	public:
		uint64_t m_memory_allocator;                      //0x0000
		char pad_0008 [ 64 ];                             //0x0008
		rage::netConnectionManager* m_net_connection_mgr; //0x0048
		char pad_0050 [ 48 ];                             //0x0050
		class rage::rlSession m_rline_session;            //0x0080
		class rage::snPlayer m_local_player;              //0x07F0
		uint64_t m_host_token;                            //0x08F0
		char pad_08F8 [ 144 ];                            //0x08F8
		class rage::snPeer m_peer_storage [ 32 ];         //0x0988
		char pad_2C88 [ 24 ];                             //0x2C88
		class rage::snPeer* m_peers [ 32 ];               //0x2CA0
		uint32_t m_peer_count;                            //0x2DA0
		char pad_2DA4 [ 4 ];                              //0x2DA4
		class rage::snPlayer m_player_storage [ 32 ];     //0x2DA8
		char pad_4DA8 [ 24 ];                             //0x4DA8
		class rage::snPlayer* m_players [ 32 ];           //0x4DC0
		int32_t m_player_count;                           //0x4EC0
		char pad_4EC4 [ 4 ];                              //0x4EC4
		class rage::rlRemoteGamer m_remote_gamers [ 32 ]; //0x4EC8
		uint32_t m_num_remote_gamers;                     //0x52C8
		bool m_player_joining;                            //0x52CC
		char pad_52CD [ 107 ];                            //0x52CD
		uint32_t m_connection_identifier;                 //0x5338
		char pad_533C [ 4 ];                              //0x533C
		uint32_t m_profile_index;                         //0x5340
		char m_token_key [ 64 ];                          //0x5344
		char m_id_key [ 64 ];                             //0x5384
		char m_info_key [ 64 ];                           //0x53C4
		char m_host_key [ 64 ];                           //0x5404
		char m_join_key [ 64 ];                           //0x5444
		char pad_5484 [ 4 ];                              //0x5484

		inline bool is_host() {
			return m_local_player.m_player_data.m_host_token == m_host_token;
		}

		inline snPlayer* get_player_by_token(uint64_t token) {
			if (m_player_count <= 0)
				return nullptr;

			for (std::uint32_t i = 0; i < static_cast<std::uint32_t>(m_player_count); i++) {
				if (m_players [ i ]->m_player_data.m_host_token == token) {
					return m_players [ i ];
				}
			}

			return nullptr;
		}

		inline snPeer* get_peer_by_rockstar_id(uint64_t rid) {
			for (uint32_t i = 0; i < m_peer_count; i++) {
				if (m_peers [ i ]->m_peer_data.m_gamer_handle_2.m_rockstar_id == rid) {
					return m_peers [ i ];
				}
			}

			return nullptr;
		}

	}; //Size: 0x3E70
	static_assert(sizeof(rage::snSession) == 0x5488);

	class snMsgRemoveGamersFromSessionCmd {
	public:
		uint64_t m_session_id;                //0x0000
		rage::rlGamerHandle m_handles [ 32 ]; //0x0008
		int32_t m_unk = -1;                   //0x208
		uint32_t m_num_peers;                 //0x20C
	}; //Size: 0x0110
	static_assert(sizeof(rage::snMsgRemoveGamersFromSessionCmd) == 0x210);
}

class SessionSortEntry {
public:
	class rage::rlSessionDetail* m_session_detail; //0x0000
	char pad_0008 [ 4 ];                           //0x0008
	float m_score;                                 //0x000C
	char pad_0010 [ 8 ];                           //0x0010
}; //Size: 0x0018
static_assert(sizeof(SessionSortEntry) == 0x18);
#pragma pack(pop)
