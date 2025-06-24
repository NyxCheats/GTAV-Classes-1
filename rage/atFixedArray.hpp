#pragma once

namespace rage {
	template<typename DataT, int32_t Capacity>
	class atFixedArray {
	public:
		DataT* begin() {
			return m_Elements;
		}
		DataT* end() {
			return m_Elements + m_Count;
		}
		const DataT* begin() const {
			return m_Elements;
		}
		const DataT* end() const {
			return m_Elements + m_Count;
		}
		DataT* data() {
			return m_Elements;
		}
		const DataT* data() const {
			return m_Elements;
		}
		int32_t size() const {
			return m_Count;
		}
		int32_t capacity() const {
			return Capacity;
		}
		DataT& operator[](int32_t index) {
			return m_Elements [ index ];
		}
		const DataT& operator[](int32_t index) const {
			return m_Elements [ index ];
		}

	private:
		DataT* m_Elements;
		int32_t m_Count = Capacity;
	};
}