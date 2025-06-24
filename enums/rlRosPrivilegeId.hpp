#pragma once

namespace rage {
	enum rlRosPrivilegeId {
		RLROS_PRIVILEGEID_NONE                = 0, // Unused
		RLROS_PRIVILEGEID_CREATE_TICKET       = 1, // Can create ROS tickets
		RLROS_PRIVILEGEID_PROFILE_STATS_WRITE = 2, // Can write profile stats
		RLROS_PRIVILEGEID_MULTIPLAYER = 3, // Can participate in MP sessions (currently not used)
		RLROS_PRIVILEGEID_LEADERBOARD_WRITE = 4, // Can write to leaderboards (currently not used)
		RLROS_PRIVILEGEID_CLOUD_STORAGE_READ = 5,  // Can write to cloud storage
		RLROS_PRIVILEGEID_CLOUD_STORAGE_WRITE = 6, // Can read from cloud storage
		RLROS_PRIVILEGEID_BANNED = 7, // Denies all other privileges except CREATE_TICKET
		RLROS_PRIVILEGEID_CLAN = 8,              // Can use clan functions
		RLROS_PRIVILEGEID_PRIVATE_MESSAGING = 9, // Can use private messaging system
		RLROS_PRIVILEGEID_SOCIAL_CLUB = 10, // Can login to SC site, and TBD other functionality
		RLROS_PRIVILEGEID_PRESENCE_WRITE = 11, // Can update presence
		RLROS_PRIVILEGEID_DEVELOPER = 12, // If true, user is considered a developer
		RLROS_PRIVILEGEID_HTTP_REQUEST_LOGGING = 13, // If true, user's HTTP request log to SCS gameservices and cloud is logged
		RLROS_PRIVILEGEID_UGCWRITE = 14, // If true, allows writing UGC
		RLROS_PRIVILEGEID_PURCHASEVC = 15, // If true, allows purchasing virtual currency
		RLROS_PRIVILEGEID_TRANSFERVC = 16, // If true, allows transferring virtual currency
		RLROS_PRIVILEGEID_CANBET = 17, // If true, player can place bets
		RLROS_PRIVILEGEID_CREATORS = 18, // If true, player can access the creators
		RLROS_PRIVILEGEID_CLOUD_TUNABLES = 19, // If true, player can download the cloud tunables
		RLROS_PRIVILEGEID_CHEATER_POOL = 20, // if true, player is in the cheater pool
		RLROS_PRIVILEGEID_COMMENTWRITE = 21, // If true, user can create comments
		RLROS_PRIVILEGEID_CANUSELOTTERY = 22, // If true, player can buy lottery tickets
		RLROS_PRIVILEGEID_ALLOW_MEMBER_REDIRECT = 23, // If true, allow member space re-directs
		RLROS_PRIVILEGEID_PLAYED_LAST_GEN = 24, // If true, grant played last gen privilege
		RLROS_PRIVILEGEID_UNLOCK_SPECIAL_EDITION = 25, // If true, grant special edition content
		RLROS_PRIVILEGEID_CONTENT_CREATOR = 26, // If true, allows user to create/update/delete Ugc content bypassing owner and profanity checks
		RLROS_PRIVILEGEID_CONDUCTOR = 27, // If true, allows user to access game servers (through conductor)
		RLROS_NUM_PRIVILEGEID
	};
}