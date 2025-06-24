#pragma once
#include "rage/atArray.hpp"
#include "rage/atFixedBitSet.hpp"

#include <cstdint>

namespace rage {
	class parAttribute {
	public:
		enum Flags {
			FLAG_OWNS_NAME_STR,
			FLAG_OWNS_VALUE_STR,
			FLAG_HIGH_PRECISION,
			FLAG_UNSIGNED,
			FLAG_HEXADECIMAL,
		};
		const char* m_Name;
		union {
			const char* m_String;
			int64_t m_Int64;
			double m_Double;
			bool m_Bool;
		} m_Value;
		uint8_t m_Type;
		atFixedBitSet8 m_Flags;
	};
	class parAttributeList {
	public:
		atArray<parAttribute> m_Attributes;
		uint8_t m_UserData1, m_UserData2;
		atFixedBitSet16 m_Flags;
	};
	class parElement {
	public:
		const char* m_Name;
		parAttributeList m_Attributes;
	};
	class parTreeNode {
	public:
	protected:
		friend class parTree;
		parElement m_Element;
		parTreeNode* m_Parent;
		parTreeNode* m_Sibling;
		parTreeNode* m_Child;
		//atArray<char, uint32_t> m_DataArray;
	};
	typedef atArray<char*> parNameTable;
}