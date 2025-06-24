#pragma once
#include "rage/strDynamicIndex.hpp"
#include "fwAssetDef.hpp"
#include "base/pgDictionary.hpp"
#include "grcTexture.hpp"
#include <cstdint>

namespace rage {
	typedef pgDictionary<grcTexture> fwTxd;
	class fwTxdDef : public fwAssetDef<fwTxd> {
	public:
		strLocalIndex GetParentId() const {
			return strLocalIndex(m_parentId);
		}
		int32_t m_parentId;
		uint16_t m_isDummy : 1;
		uint16_t m_bIsBeingDefragged : 1;
		uint16_t m_bHasHD : 1;
		uint16_t m_bIsBoundHD : 1;
		uint16_t m_padding : 12;
	};
}