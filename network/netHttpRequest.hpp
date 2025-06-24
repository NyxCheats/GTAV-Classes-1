#pragma once
#include "enums/netHttpAbortReason.hpp"
#include "enums/netHttpVerb.hpp"
#include "enums/netTcpResult.hpp"
#include "inlist.hpp"
#include "netIpAddress.hpp"
#include "netIpV4Address.hpp"
#include "netSocketAddress.hpp"
#include "netStatus.hpp"
#include "netTcpAsyncOp.hpp"
#include "netTimeout.hpp"
#include "rage/datGrowBuffer.hpp"
#include "rage/atStringBuilder.hpp"
#include "rage/sysMemAllocator.hpp"


namespace rage {
    class fiDevice;
	class netHttpRequest {
	public:
		static constexpr uint32_t DEFAULT_BOUNCE_BUFFER_MAX_LENGTH = 1044;
		enum TransferEncoding {
			TRANSFER_ENCODING_NORMAL,
			TRANSFER_ENCODING_CHUNKED,
		};
		enum UriScheme {
			URISCHEME_INVALID,
			URISCHEME_HTTP,
			URISCHEME_HTTPS,
		};
		struct Chunk {
			datGrowBuffer m_Data;
			netTcpAsyncOp m_TcpOp;
			netStatus m_Status; // when not using m_TcpOp, such as when IXHR2 is used.
			inlist_node<Chunk> m_ListLink;
		};
		enum SendState {
			SENDSTATE_NONE,
			SENDSTATE_WAIT_UNTIL_READY,
			SENDSTATE_RESOLVE_HOST,
			SENDSTATE_RESOLVING_HOST,
			SENDSTATE_CONNECT,
			SENDSTATE_CONNECTING,
			SENDSTATE_SEND_HEADER,
			SENDSTATE_SENDING_CONTENT,
			SENDSTATE_SENDING_TERM_CHUNK,
			SENDSTATE_SUCCEEDED,
			SENDSTATE_ERROR
		};
		enum RecvState {
			RECVSTATE_NONE,
			RECVSTATE_RECEIVING_HEADER,
			RECVSTATE_RECEIVED_HEADER,
			RECVSTATE_RECEIVING_NORMAL_CONTENT,
			RECVSTATE_RECEIVING_CHUNKED_CONTENT,
			RECVSTATE_FINISH_CONSUMING_CONTENT,
			RECVSTATE_SUCCEEDED,
			RECVSTATE_ERROR
		};
		Chunk* m_CurChunk;
		typedef inlist<Chunk, &Chunk::m_ListLink> ChunkList;
		ChunkList m_QueuedChunks;
		Chunk* m_InFlightChunk;
		datGrowBuffer m_InBuf;
		atStringBuilder m_InHeader;
		atStringBuilder m_OutHeader;
		class netHttpFilter* m_Filter;
		fiHandle m_ResponseHandle;
		const fiDevice* m_ResponseDevice;
		char m_DefaultBounceBuf [ DEFAULT_BOUNCE_BUFFER_MAX_LENGTH ];
		char* m_BounceBuf;
		uint32_t m_BounceBufMaxLen;
		uint32_t m_BounceBufLen;
		uint32_t m_RequestId;
		netHttpVerb m_HttpVerb;
		mutable int m_HttpStatusCode;
		UriScheme m_UriScheme;
		char* m_RawUri;
		const char* m_RawHost;
		const char* m_RawPath;
		mutable char* m_EncodedUri;
		atStringBuilder m_QueryString;
		atStringBuilder m_UserAgentString;
		uint32_t m_InContentLen;
		uint32_t m_InContentBytesRcvd;
		uint32_t m_OutContentBytesSent;
		uint32_t m_OutChunksBytesSent;
		netSocketAddress m_ProxyAddr;
		bool m_IgnoreProxy;
		netTimeout m_Timeout;
		int m_RedirectCount;
		int m_Skt;
		SendState m_SendState;
		RecvState m_RecvState;
		sysMemAllocator* m_Allocator;
		uint32_t m_Options;
		uint32_t m_ByteRangeLow;
		uint32_t m_ByteRangeHigh;
		uint32_t m_NumFormParams;
		uint32_t m_NumQueryParams;
		int m_NumListParamValues;
		netIpAddress m_HostIp;
		uint16_t m_HostPort;
		netTcpAsyncOp m_ConnectTcpOp;
		// Diagnostics
		netHttpAbortReason m_AbortReason;
		bool m_ChunkAllocationError;
		netTcpResult m_TcpOpResult;
		int m_TcpOpError;
		TransferEncoding m_OutboundTransferEncoding;
		netStatus* m_Status;
		netStatus m_MyStatus;
		netStatus m_HostResolutionStatus;
		//For managing a linked list of requests.
		netHttpRequest* m_Next;
		netHttpRequest* m_Prev;
		WOLFSSL_CTX* m_SslCtx;
	};
}