#pragma once
#include <cstdint>
#include <ctime>

namespace rage {
	template<typename T, bool mutate = true>
	class sysObfuscated {
	public:
		void Init() {
			// m_xor = sysObfuscatedTypes::obfRand();
			// if (mutate) {
			// 	m_mutate = sysObfuscatedTypes::obfRand();
			// }
		}
		T Get() {
			uint32_t xorVal = m_xor ^ (uint32_t)(size_t)this;
			uint32_t ret [ sizeof(T) / sizeof(uint32_t) ];
			uint32_t* src  = const_cast<uint32_t*>(&m_data [ 0 ]);
			uint32_t* dest = (uint32_t*)&ret;
			for (size_t i = 0; i < sizeof(T) / 4; ++i) {
				if (mutate) {
					// Extract valid data from two words of storage
					uint32_t a = *src & m_mutate;
					uint32_t b = src [ sizeof(T) / 4 ] & (~m_mutate);
					// Apply entropy in the unused bits: Just flip the two u16's in the uint32_t. We can't do a
					// huge amount more without knowledge of the mutation mask.
					uint32_t entropyA = ((*src & (~m_mutate)) << 16) | ((*src & (~m_mutate)) >> 16);
					uint32_t entropyB = ((src [ sizeof(T) / 4 ] & m_mutate) << 16) | ((src [ sizeof(T) / 4 ] & m_mutate) >> 16);
					*src = (*src & m_mutate) | entropyA;
					src [ sizeof(T) / 4 ] = (src [ sizeof(T) / 4 ] & (~m_mutate)) | entropyB;

					*dest++ = a | b;
					++src;
				} else {
					*dest++ = *src++ ^ xorVal;
				}
			}
			// Call Set() to reset the xor and mutate keys on every call to Get()
			if (mutate) {
				const_cast<sysObfuscated<T, mutate>*>(this)->Set(*(T*)&ret);
			}
			return *(T*)&ret;
		}
		void Set(T data) {
			Init();
			uint32_t xorVal = m_xor ^ (uint32_t)(size_t)this;
			uint32_t* src   = (uint32_t*)&data;
			uint32_t* dest  = &m_data [ 0 ];
			for (size_t i = 0; i < sizeof(T) / 4; ++i) {
				if (mutate) {
					uint32_t a = *src & m_mutate;
					uint32_t b = *src & (~m_mutate);
					++src;
					*dest                  = a;
					dest [ sizeof(T) / 4 ] = b;
					++dest;
				} else {
					*dest++ = *src++ ^ xorVal;
				}
			}
		}
		void operator=(T data) {
			Set(data);
		}
		operator T() {
			return Get();
		}

	private:
		uint32_t m_data [ (mutate ? sizeof(T) * 2 : sizeof(T)) / sizeof(uint32_t) ];
		// XOR and mutate keys for this type
		uint32_t m_xor;
		uint32_t m_mutate;
	};
}