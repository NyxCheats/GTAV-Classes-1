#pragma once
#include <cstdint>

namespace rage {
	enum {
		RLROS_MAX_PLATFORM_NAME_SIZE = 16, //Length including terminating null
		RLROS_MAX_TICKET_SIZE = 512, //String length of base64 ticket data, including terminating null.
		RLROS_MAX_SESSION_TICKET_SIZE = 128, //String length of base64 session ticket data, including terminating null.
		RLROS_MAX_TITLE_NAME_SIZE      = 16, //Length including terminating null
		RLROS_MAX_TITLE_DIRECTORY_SIZE = 64, //Length including terminating null
		RLROS_MAX_USER_NAME_SIZE = 64, //Max length of a ROS PA UserName, including terminating null.
		RLROS_MAX_USERID_SIZE = 64, //Max length of a ROS PA UserId, including terminating null.
		RLROS_MAX_RSA_ENCRYPTED_SIZE = 128, //Max size (in bytes) of an encrypted RSA message (size of modulus)
		RLROS_MAX_SERVICE_ACCESS_TOKEN_SIZE = 2048, //Max size of an Scs Service Access Token, not including terminating null.
		RLROS_MAX_SERVICE_SERVER_URL_SIZE = 128
	};
}