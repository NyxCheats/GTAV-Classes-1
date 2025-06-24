#pragma once

namespace rage {
	enum class PostState : int32_t {
		CLEANUP           = 7,
		DATA_RCVD         = 3,
		ERRORS            = 8,
		NONE              = 0,
		RCVD              = 5,
		REQUESTED         = 1,
		SHOWN             = 6,
		WAITING           = 2,
		WAITING_FOR_IMAGE = 4
	};

	class ImageInfo {
	public:
		char m_cloud_path [ 128 ]; // 0x0000
		int32_t m_cloud_presize;   // 0x0080
	}; // Size: 0x0084

	class CNetworkSCNewsStoryRequest {
	public:
		char pad_0000 [ 8 ];                // 0x0000
		PostState m_state;                  // 0x0008
		int32_t m_cloud_request_id;         // 0x000C
		char pad_0010 [ 56 ];               // 0x0010
		char* m_bigfeed;                    // 0x0048
		char pad_0050 [ 16 ];               // 0x0050
		char* m_news_key;                   // 0x0060
		char pad_0068 [ 136 ];              // 0x0068
		char* m_title;                      // 0x00F0
		char pad_00F8 [ 8 ];                // 0x00F8
		char* m_subtitle;                   // 0x0100
		char pad_0108 [ 8 ];                // 0x0108
		char* m_description;                // 0x0110
		char pad_0118 [ 8 ];                // 0x0118
		char* m_url;                        // 0x0120
		char pad_0128 [ 8 ];                // 0x0128
		char* m_footer;                     // 0x0130
		char pad_0138 [ 48 ];               // 0x0138
		char m_texture [ 64 ];              // 0x0168
		class ImageInfo m_cloud_path [ 2 ]; // 0x01A8
		bool m_failed_last_request;         // 0x02B0
		bool m_do_image_request;            // 0x02B1
		char pad_02B2 [ 3888 ];             // 0x02B2
	}; // Size: 0x11E2
}