#pragma once
#include "atStringHash.hpp"
#include "datGrowBuffer.hpp"

#include <cstdint>

namespace rage {
	template<typename DataT, int32_t MaxCount>
	class atRangeArray {
	public:
		DataT* begin() {
			return m_Elements;
		}
		DataT* end() {
			return m_Elements + MaxCount;
		}
		const DataT* begin() const {
			return m_Elements;
		}
		const DataT* end() const {
			return m_Elements + MaxCount;
		}
		DataT* data() {
			return m_Elements;
		}
		const DataT* data() const {
			return m_Elements;
		}
		int32_t size() const {
			return MaxCount;
		}
		int32_t capacity() const {
			return size();
		}
		DataT& operator[](int32_t index) {
			return m_Elements [ index ];
		}
		const DataT& operator[](int32_t index) const {
			return m_Elements [ index ];
		}

	private:
		DataT m_Elements [ MaxCount ];
	};
}