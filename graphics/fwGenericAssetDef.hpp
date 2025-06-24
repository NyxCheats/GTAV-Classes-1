#pragma once
#include <cstdint>

namespace rage {
	template<typename T, typename S>
	class fwGenericAssetDef {
	public:
		typedef S strObjectNameType;
		T* m_pObject;
		int m_refCount;
		S m_name;
	};
}