#pragma once
#include "parTreeNode.hpp"
#include <cstdint>

namespace rage {
	class parTree {
	public:
		parTreeNode* m_Root;
		parNameTable m_NameTable;
		parTreeNode* m_Current;
		parTreeNode* m_Sibling;
	};
}