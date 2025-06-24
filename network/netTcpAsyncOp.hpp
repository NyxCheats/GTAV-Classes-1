#pragma once
#include "netSocketAddress.hpp"
#include "netStatus.hpp"
#include "rage/inlist.hpp"
#include "enums/ConnectReason.hpp"
#include "WOLFSSL_CTX.hpp"

namespace rage {
	class netTcpAsyncOp {
		friend class netTcp;
		friend class netHttpRequest;

	public:
		enum OpType {
			OP_INVALID = -1,
			OP_CONNECT,
			OP_SSL_CONNECT,
			OP_RECV_BUFFER,
			OP_SEND_BUFFER,
			OP_NUM_TYPES
		};
		OpType m_Type;
		int m_SktId;
		int m_LastError;
		enum ConnectState {
			STATE_SOCKET_CONNECT,
			STATE_SSL_CONNECT
		};
		enum SslSocketOp {
			SSL_SOCKET_OP_READ,
			SSL_SOCKET_OP_WRITE
		};
		union {
			struct {
				uint8_t m_AddrBuf [ sizeof(netSocketAddress) ];
				netSocketAddress* m_Addr;
				int* m_CallerSktId;
				ConnectReason m_ConnectReason;
				ConnectState m_State;
			} m_Connect;
			struct {
				uint8_t m_AddrBuf [ sizeof(netSocketAddress) ];
				netSocketAddress* m_Addr;
				int* m_CallerSktId;
				ConnectState m_State;
				SslSocketOp m_NextSocketOp;
				SSL_CTX* m_SslCtx;
				const char* m_DomainName;
				ConnectReason m_ConnectReason;
			} m_SslConnect;
			struct {
				void* m_Buf;
				uint32_t m_SizeofBuf;
				uint32_t m_NumRcvd;
			} m_RcvBuf;
			struct {
				const void* m_Buf;
				uint32_t m_SizeofBuf;
				uint32_t m_NumSent;
			} m_SndBuf;
		} m_Data;
		int m_TimeoutMs;
		netStatus m_MyStatus;
		uint32_t m_Id;
		inlist_node<netTcpAsyncOp> m_ListLink;
	};
}