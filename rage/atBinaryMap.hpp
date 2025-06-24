#pragma once
#include "atArray.hpp"

namespace rage {
	template<typename _T, typename _KeyType>
	class atBinaryMap {
	public:
		class Iterator {
		public:
			Iterator() : Map(NULL), CurIdx(0) {
			}
			explicit Iterator(atBinaryMap<_T, _KeyType>& themap) :
			    Map(&themap), CurIdx(0) {
			}
			Iterator& operator++() {
				if (++CurIdx >= Map->Data.GetCount())
					*this = Map->End();
				return *this;
			}
			Iterator operator++(const int) {
				Iterator result(*this);
				++(*this);
				return result;
			}
			_T& operator*() const {
				return Map->Data [ CurIdx ].data;
			}
			_T* operator->() const {
				return &Map->Data [ CurIdx ].data;
			}
			bool operator==(const Iterator& comp) const {
				return (CurIdx == comp.CurIdx) && (Map == comp.Map);
			}
			bool operator!=(const Iterator& comp) const {
				return !((CurIdx == comp.CurIdx) && (Map == comp.Map));
			}
			Iterator& operator=(const Iterator& rhs) {
				Map    = rhs.Map;
				CurIdx = rhs.CurIdx;
				return *this;
			}
			const _KeyType& GetKey() {
				return Map->Data [ CurIdx ].key;
			}

		private:
			atBinaryMap<_T, _KeyType>* Map;
			int CurIdx;
		};
		class ConstIterator {
		public:
			ConstIterator() : Map(NULL), CurIdx(0) {
			}
			explicit ConstIterator(const atBinaryMap<_T, _KeyType>& themap) :
			    Map(&themap), CurIdx(0) {
			}
			ConstIterator& operator++() {
				if (++CurIdx >= Map->Data.GetCount())
					*this = Map->end();
				return *this;
			}
			ConstIterator operator++(const int) {
				ConstIterator result(*this);
				++(*this);
				return result;
			}
			const _T& operator*() const {
				return Map->Data [ CurIdx ].data;
			}
			const _T* operator->() const {
				return &Map->Data [ CurIdx ].data;
			}
			bool operator==(const ConstIterator& comp) const {
				return (CurIdx == comp.CurIdx) && (Map == comp.Map);
			}
			bool operator!=(const ConstIterator& comp) const {
				return !((CurIdx == comp.CurIdx) && (Map == comp.Map));
			}
			ConstIterator& operator=(const ConstIterator& rhs) {
				Map    = rhs.Map;
				CurIdx = rhs.CurIdx;
				return *this;
			}
			const _KeyType& GetKey() {
				return Map->Data [ CurIdx ].key;
			}

		private:
			const atBinaryMap<_T, _KeyType>* Map;
			int CurIdx;
		};
		friend class Iterator;
		friend class ConstIterator;
		Iterator begin() {
			if (Data.size() > 0)
				return Iterator(*this);
			else
				return end();
		}
		Iterator end() {
			return Iterator();
		}
		ConstIterator end() const {
			return ConstIterator();
		}
		enum ePlaceNoneInitializer {
			PLACE_NONE
		};
		enum ePlaceKeyInitializer {
			PLACE_KEY
		};
		enum ePlaceDataInitializer {
			PLACE_DATA
		};
		enum ePlaceKeyDataInitializer {
			PLACE_KEY_AND_DATA
		};
		int GetCount() const {
			return Data.size();
		}
		_T* GetItem(int i) {
			return &Data [ i ].data;
		}
		const _T* GetItem(int i) const {
			return &Data [ i ].data;
		}
		_KeyType* GetKey(int i) {
			return &Data [ i ].key;
		}
		const _KeyType* GetKey(int i) const {
			return &Data [ i ].key;
		}
		struct DataPair {
			_KeyType key;
			_T data;
		};

	protected:
		bool Sorted;
		char Pad [ 3 ];
		atArray<DataPair> Data;
	};
}