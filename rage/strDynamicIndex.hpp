#pragma once
#include <cstdint>

#define STRINDEX_INVALID 0xFFFFFFFF
#define STRLOCALINDEX_INVALID 0xFFFFFFFF

namespace rage {
	template<typename T>
	struct strDynamicIndex {
		enum eInvalidIndex {
			INVALID_INDEX = STRLOCALINDEX_INVALID
		};
		inline T Get() const {
			return m_Index;
		}
		inline void Set(T i) {
			m_Index = i;
		}
		inline bool IsValid() const {
			return m_Index != STRLOCALINDEX_INVALID;
		}
		inline bool IsInvalid() const {
			return m_Index == STRLOCALINDEX_INVALID;
		}
		inline operator T() {
			return Get();
		}
		inline void operator=(const T other) {
			Set(other);
		}
		inline void operator=(const strDynamicIndex<T>& other) {
			m_Index = other.m_Index;
		}
		inline bool operator==(const strDynamicIndex<T>& other) const {
			return m_Index == other.m_Index;
		}
		inline bool operator==(const T& other) const {
			return m_Index == other;
		}
		inline bool operator!=(const strDynamicIndex<T>& other) const {
			return m_Index != other.m_Index;
		}
		inline bool operator!=(const T& other) const {
			return m_Index != other;
		}
		inline bool operator>(const strDynamicIndex<T>& other) const {
			return m_Index > other.m_Index;
		}
		inline bool operator>(const T& other) const {
			return m_Index > other;
		}
		inline bool operator>=(const strDynamicIndex<T>& other) const {
			return m_Index >= other.m_Index;
		}
		inline bool operator>=(const T& other) const {
			return m_Index >= other;
		}
		inline bool operator<=(const strDynamicIndex<T>& other) const {
			return m_Index <= other.m_Index;
		}
		inline bool operator<=(const T& other) const {
			return m_Index <= other;
		}
		inline bool operator<(const strDynamicIndex<T>& other) const {
			return m_Index < other.m_Index;
		}
		inline bool operator<(const T& other) const {
			return m_Index < other;
		}
		T m_Index;
	};

	typedef strDynamicIndex<uint32_t> strIndex;
	typedef strDynamicIndex<int32_t> strLocalIndex;
}