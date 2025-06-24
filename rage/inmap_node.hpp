#pragma once
#include <cstdint>

namespace rage {
	template<typename K, typename T>
	class inmap_node {
	public:
		inmap_node() : m_right(0), m_left(0), m_parent(0) {
		}

		//Copy constructor intentionally left empty.
		inmap_node(const inmap_node<K, T>&) :
		    m_right(0), m_left(0), m_parent(0) {
		}
		//Assigment operator intentionally left empty.
		inmap_node<K, T>& operator=(const inmap_node<K, T>&) {
			return *this;
		}
		// WARNING!!!! Be careful when changing the size of inmap_nodes
		// inmap_nodes are used in resourced objects, though they themselves don't
		// get fixed up.
		// Changing the size will likely mean having to rebuild resources.
		T* m_right;
		T* m_left;
		T* m_parent;
		K m_key;
	};
}