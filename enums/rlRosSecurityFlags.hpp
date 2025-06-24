#pragma once

namespace rage {
	enum rlRosSecurityFlags {
		//The original encryption/signature settings. If using RLROS_ENCRYPTION_TITLE:
		//1. Response headers are not signed
		//2. A plaintext sha1 hash of the encrypted block is appended to each encrypted block
		RLROS_SECURITY_NONE = 0,
		//If present, the client will include a random challenge/nonce with the request, which
		//the server will include with the hmac for the response headers/body. This is intended
		//to be used with the HMAC_HEADERS and HMAC_BODY options and prevents replaying
		//server responses.
		RLROS_SECURITY_CHALLENGE = (1 << 0),
		//Server returns an hmac of certain key headers so that the client can detect any
		//tampering.
		RLROS_SECURITY_HMAC_HEADERS = (1 << 1),
		//Encrypted blocks are followed with an hmac instead of a hash
		RLROS_SECURITY_HMAC_BODY = (1 << 2),
		//If present, the client will request the server to respond with a content signature,
		//if it so chooses. If the server doesn't, then the request will not fail. If it does,
		//then the client will verify that the response body matches the server signature,
		//and fail the request if it doesn't. This is primarily useful for things like a redirect
		//to the CDN, and when used in conjunction with RLROS_SECURITY_HMAC_HEADERS
		//allows the server to determine whether or not to tell the client to verify the signature
		//against the file downloaded from the CDN
		RLROS_SECURITY_REQUEST_CONTENT_SIG = (1 << 3),
		//If present, the client will demand the server to respond with a content signature.
		//If it doesn't, the request should fail, otherwise the client will verify the server's
		//signature.
		RLROS_SECURITY_REQUIRE_CONTENT_SIG = (1 << 4),
		//If present, the client will expect the headers hmac to also include the http status code
		//so that it can't be tampered with
		RLROS_SECURITY_HMAC_STATUS_CODE = (1 << 5),
		//Similar to RLROS_SECURITY_HMAC_HEADERS, this protects the client request header from
		//being tampered with. If present, the client will include an hmac in its request header
		//that is an hmac of other important request headers. The server will verify that the
		//hmac matches expected based on the headers that it received from the client.
		//Likewise, the client will verify the server has done this by including the request
		//header hmac in the response header hmac.
		RLROS_SECURITY_HMAC_REQUEST_HEADERS = (1 << 6),
		//If present, the header hmac should be structured. The header hmac consists of several
		//pieces of the header glued together, allowing someone to move characters between pieces
		//without changing the hmac but potentially altering the meaning of the header. This
		//causes the header hmac to use a pre-defined structure to prevent thi
		RLROS_SECURITY_STRUCTURED_HEADER_HMAC = (1 << 7),
		RLROS_SECURITY_DEFAULT = RLROS_SECURITY_CHALLENGE | RLROS_SECURITY_HMAC_HEADERS | RLROS_SECURITY_HMAC_BODY | RLROS_SECURITY_REQUEST_CONTENT_SIG | RLROS_SECURITY_HMAC_STATUS_CODE | RLROS_SECURITY_HMAC_REQUEST_HEADERS | RLROS_SECURITY_STRUCTURED_HEADER_HMAC
	};
}