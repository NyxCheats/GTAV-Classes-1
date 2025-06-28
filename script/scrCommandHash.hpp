#pragma once
#include "security/sysObfuscated.hpp"

#include <cstdint>

namespace rage {
	template<typename T>
	class scrCommandHash {
	private:
		static constexpr int ToplevelSize = 256; // Must be power of two
		static constexpr int PerBucket    = 7;
		struct Bucket {
			sysObfuscated<Bucket*, false> obf_Next;
			T Data [ PerBucket ];
			sysObfuscated<uint32_t, false> obf_Count;
			sysObfuscated<uint64_t, false> obf_Hashes [ PerBucket ];
			uint64_t plainText_Hashes [ PerBucket ];
		};

	public:
		void RegistrationComplete(bool val) {
			m_bRegistrationComplete = val;
		}
		void Init() {
			m_Occupancy             = 0;
			m_bRegistrationComplete = false;
			for (int i{}; i < ToplevelSize; i++)
				m_Buckets [ i ] = NULL;
		}
		void Kill() {
			for (int i = 0; i < ToplevelSize; i++) {
				Bucket* b = m_Buckets [ i ];
				while (b) {
					char* old = (char*)b;
					b         = b->obf_Next.Get();
					delete [] old;
				}
				m_Buckets [ i ] = NULL;
			}
			m_Occupancy = 0;
		}
		T Lookup(uint64_t hashcode) {
			Bucket* b = m_Buckets [ hashcode & (ToplevelSize - 1) ];
			while (b) {
				for (uint32_t i{}; i != b->obf_Count.Get(); i++)
					if (b->obf_Hashes [ i ].Get() == hashcode)
						return b->Data [ i ];
				b = b->obf_Next.Get();
			}
			return T{};
		}
		Bucket* m_Buckets [ ToplevelSize ];
		int m_Occupancy;
		bool m_bRegistrationComplete;
	};
}