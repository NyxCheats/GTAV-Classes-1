#pragma once

namespace rage {
	template<typename ITER>
	class reverse_iterator {
	public:
		typedef typename ITER::iterator_category iterator_category;
		typedef typename ITER::value_type value_type;
		typedef typename ITER::difference_type difference_type;
		typedef typename ITER::pointer pointer;
		typedef typename ITER::reference reference;
		reverse_iterator() {
		}
		explicit reverse_iterator(const ITER& it) : m_It(it) {
		}
		template<typename OTHER>
		reverse_iterator(const reverse_iterator<OTHER>& that) :
		    m_It(that.base()) {
		}
		template<typename OTHER>
		reverse_iterator<ITER>& operator=(const reverse_iterator<OTHER>& that) {
			m_It = that.base();
			return *this;
		}
		ITER base() const {
			return m_It;
		}
		reverse_iterator operator++() {
			--m_It;
			return *this;
		}
		reverse_iterator operator--() {
			++m_It;
			return *this;
		}
		reverse_iterator operator++(const int) {
			reverse_iterator tmp = *this;
			--m_It;
			return tmp;
		}
		reverse_iterator operator--(const int) {
			reverse_iterator tmp = *this;
			++m_It;
			return tmp;
		}
		pointer operator->() const {
			ITER tmp = m_It;
			return (--tmp).operator->();
		}
		reference operator*() const {
			ITER tmp = m_It;
			return (--tmp).operator*();
		}
		bool operator==(const reverse_iterator& rhs) const {
			return m_It == rhs.m_It;
		}
		bool operator!=(const reverse_iterator& rhs) const {
			return m_It != rhs.m_It;
		}

	private:
		ITER m_It;
	};


	template<typename T>
	class inlist_node {
	public:
		inlist_node() : m_next(0), m_prev(0) {
		}
		//Copy constructor intentionally left empty.
		inlist_node(const inlist_node<T>&) : m_next(0), m_prev(0) {
		}
		//Assignment operator intentionally left empty.
		inlist_node<T>& operator=(const inlist_node<T>&) {
			return *this;
		}
		T* m_next;
		T* m_prev;
	};
	template<typename T, inlist_node<T> T::* NODE>
	class inlist {
		typedef inlist<T, NODE> ListType;

	public:
		class const_iterator;
		class iterator {
			friend class inlist<T, NODE>;
			friend class const_iterator;
			bool before_begin() const {
				return (((uint64_t)m_list) & ~0x01) && (((uint64_t)m_list) & 0x01);
			}
			void set_before_begin() {
				m_list = (ListType*)(((uint64_t)m_list) | 0x01);
			}
			void clear_before_begin() {
				m_list = (ListType*)(((uint64_t)m_list) & ~0x01);
			}
			ListType* list() {
				return (ListType*)(((uint64_t)m_list) & ~0x01);
			}
			ListType* list() const {
				return (ListType*)(((uint64_t)m_list) & ~0x01);
			}

		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef T* value_type;
			typedef ptrdiff_t difference_type;
			typedef value_type pointer;
			typedef const value_type* const_pointer;
			typedef value_type reference;
			iterator() : m_t(0), m_list(0) {
			}
			iterator operator++() {
				if (m_t) {
					m_t = (m_t->*NODE).m_next;
				} else if (this->before_begin()) {
					this->clear_before_begin();
					m_t = m_list->m_head;
				}
				return *this;
			}
			iterator operator--() {
				if (m_t) {
					m_t = (m_t->*NODE).m_prev;
					if (!m_t) {
						this->set_before_begin();
					}
				} else if (m_list && !this->before_begin()) {
					m_t = m_list->m_tail;
				}
				return *this;
			}
			iterator operator++(const int) {
				iterator tmp = *this;
				++*this;
				return tmp;
			}
			iterator operator--(const int) {
				iterator tmp = *this;
				--*this;
				return tmp;
			}
			pointer operator->() {
				return m_t;
			}
			const_pointer operator->() const {
				return m_t;
			}
			reference operator*() const {
				return m_t;
			}
			bool operator==(const iterator& rhs) const {
				return rhs.m_t == m_t;
			}
			bool operator!=(const iterator& rhs) const {
				return rhs.m_t != m_t;
			}
			bool operator==(const const_iterator& rhs) const {
				return rhs == *this;
			}
			bool operator!=(const const_iterator& rhs) const {
				return rhs != *this;
			}

		private:
			iterator(T* t, inlist<T, NODE>* l) : m_t(t), m_list(l) {
			}
			T* m_t;
			inlist<T, NODE>* m_list;
		};
		class const_iterator {
			friend class inlist<T, NODE>;
			bool before_begin() const {
				return (((uint64_t)m_list) & ~0x01) && (((uint64_t)m_list) & 0x01);
			}
			void set_before_begin() {
				m_list = (ListType*)(((uint64_t)m_list) | 0x01);
			}
			void clear_before_begin() {
				m_list = (ListType*)(((uint64_t)m_list) & ~0x01);
			}
			ListType* list() {
				return (ListType*)(((uint64_t)m_list) & ~0x01);
			}
			ListType* list() const {
				return (ListType*)(((uint64_t)m_list) & ~0x01);
			}

		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef const T* value_type;
			typedef ptrdiff_t difference_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type reference;
			const_iterator() : m_t(0), m_list(0) {
			}
			const_iterator(const iterator& it) :
			    m_t(it.m_t), m_list(it.m_list) {
			}
			const_iterator operator++() {
				if (m_t) {
					m_t = (m_t->*NODE).m_next;
				} else if (this->before_begin()) {
					this->clear_before_begin();
					m_t = m_list->m_head;
				}
				return *this;
			}
			const_iterator operator--() {
				if (m_t) {
					m_t = (m_t->*NODE).m_prev;
					if (!m_t) {
						this->set_before_begin();
					}
				} else if (m_list && !this->before_begin()) {
					m_t = m_list->m_tail;
				}
				return *this;
			}
			const_iterator operator++(const int) {
				const_iterator tmp = *this;
				++*this;
				return tmp;
			}
			const_iterator operator--(const int) {
				const_iterator tmp = *this;
				--*this;
				return tmp;
			}
			pointer operator->() {
				return m_t;
			}
			const_pointer operator->() const {
				return m_t;
			}
			reference operator*() const {
				return m_t;
			}
			bool operator==(const const_iterator& rhs) const {
				return rhs.m_t == m_t;
			}
			bool operator!=(const const_iterator& rhs) const {
				return rhs.m_t != m_t;
			}

		private:
			const_iterator(const T* t, const inlist<T, NODE>* l) :
			    m_t(t), m_list(l) {
			}
			const T* m_t;
			const inlist<T, NODE>* m_list;
		};
		typedef typename iterator::reference reference;
		typedef typename const_iterator::reference const_reference;
		typedef typename iterator::pointer pointer;
		typedef typename const_iterator::pointer const_pointer;
		typedef typename iterator::value_type value_type;
		typedef typename iterator::difference_type difference_type;
		inlist() : m_head(0), m_tail(0), m_size(0) {
		}
		~inlist() {
			this->clear();
		}
		void push_front(T* item) {
			this->insert(this->begin(), item);
		}
		void push_back(T* item) {
			this->insert(this->end(), item);
		}
		iterator insert(iterator where, T* item) {
			return this->insert(where.m_t, item);
		}
		iterator insert(T* where, T* item) {
			if (0 == where) {
				if (m_tail) {
					next(m_tail) = item;
					prev(item)   = m_tail;
					m_tail       = item;
					if (!m_head)
						m_head = item;
				} else {
					m_head = m_tail = item;
				}
			} else if (where == m_head) {
				next(item)   = m_head;
				prev(m_head) = item;
				m_head       = item;
			} else {
				next(item)        = where;
				prev(item)        = prev(where);
				next(prev(where)) = item;
				prev(where)       = item;
			}
			++m_size;
			return iterator(item, this);
		}
		void pop_front() {
			if (m_head) {
				this->erase(this->front());
			}
		}
		void pop_back() {
			if (m_tail) {
				this->erase(this->back());
			}
		}
		reference front() {
			return m_head;
			;
		}
		const_reference front() const {
			return m_head;
		}
		reference back() {
			return m_tail;
		}
		const_reference back() const {
			return m_tail;
		}
		iterator begin() {
			return iterator(m_head, this);
		}
		const_iterator begin() const {
			return const_iterator(m_head, this);
		}
		iterator end() {
			return iterator(0, this);
		}
		const_iterator end() const {
			return const_iterator(0, this);
		}
		void clear() {
			while (!this->empty()) {
				this->pop_front();
			}
		}
		bool empty() const {
			return !m_size;
		}
		iterator erase(iterator where) {
			iterator next = where;
			++next;
			this->erase(*where);
			return next;
		}
		iterator erase(iterator first, iterator last) {
			if (this->begin() == first && this->end() == last) {
				this->clear();
				first = this->end();
			} else {
				while (first != last) {
					first = this->erase(first);
				}
			}
			return first;
		}
		void erase(T* item) {
			if (item == m_head) {
				m_head     = next(m_head);
				next(item) = 0;
				if (m_head) {
					prev(m_head) = 0;
				} else {
					m_tail = 0;
				}
			} else if (item == m_tail) {
				m_tail     = prev(m_tail);
				prev(item) = 0;
				if (m_tail) {
					next(m_tail) = 0;
				}
			} else {
				next(prev(item)) = next(item);
				prev(next(item)) = prev(item);
				prev(item) = next(item) = 0;
			}
			--m_size;
		}
		bool is_present_unsafe(T* item) const {
			return prev(item) || next(item) || item == m_head;
		}
		bool try_erase_unsafe(T* item) {
			if (is_present_unsafe(item)) {
				erase(item);
				return true;
			}
			return false;
		}
		uint64_t size() const {
			return m_size;
		}
		uint64_t max_size() const {
			return uint64_t(-1);
		}
		template<typename Pred>
		void merge(inlist<T, NODE>& rhs, Pred pred) {
			if (&rhs != this) {
				iterator it0   = this->begin();
				iterator stop0 = this->end();
				iterator it1   = rhs.begin();
				iterator stop1 = rhs.end();
				while (it0 != stop0 && it1 != stop1) {
					if (pred(*it1, *it0)) {
						T* item1 = it1.m_t;
						it1      = rhs.erase(it1);
						this->insert(it0, item1);
					} else {
						++it0;
					}
				}
				while (it1 != stop1) {
					T* item1 = it1.m_t;
					it1      = rhs.erase(it1);
					this->insert(stop0, item1);
				}
			}
		}

	private:
		struct Less {
			bool operator()(const T* t0, const T* t1) {
				return t0 < t1;
			}
		};

	public:
		void merge(inlist<T, NODE>& rhs) {
			this->merge(rhs, Less());
		}
		void splice(iterator where, inlist<T, NODE>& right) {
			this->splice(where, right, right.begin(), right.end());
		}
		void splice(iterator where, inlist<T, NODE>& right, iterator first) {
			this->splice(where, right, first, right.end());
		}
		void splice(iterator where, inlist<T, NODE>& right, iterator first, iterator stop) {
			for (iterator it = first; it != stop;) {
				T* item = it.m_t;
				it      = right.erase(it);
				this->insert(where, item);
			}
		}
		void swap(inlist<T, NODE>& right) {
			const uint64_t thisSize  = this->size();
			const uint64_t rightSize = right.size();
			for (uint64_t i = 0; i < thisSize; ++i) {
				iterator it = this->begin();
				T* item     = it.m_t;
				it          = this->erase(it);
				right.push_back(item);
			}
			for (uint64_t i = 0; i < rightSize; ++i) {
				iterator it = right.begin();
				T* item     = it.m_t;
				it          = right.erase(it);
				this->push_back(item);
			}
		}

	private:
		//Declare as non-copy-able
		inlist(const inlist<T, NODE>&);
		inlist<T, NODE>& operator=(const inlist<T, NODE>&);
		static T*& prev(T* t) {
			return (t->*NODE).m_prev;
		}
		static T*& next(T* t) {
			return (t->*NODE).m_next;
		}
		T* m_head;
		T* m_tail;
		uint64_t m_size;
	};
}