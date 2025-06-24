#pragma once
#include "fwGenericAssetDef.hpp"
#include "rage/atHashString.hpp"

#include <cstdint>

namespace rage {
	template<typename T>
	class fwAssetDef : public fwGenericAssetDef<T, strStreamingObjectName> {};
}