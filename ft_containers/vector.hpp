#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utility.hpp"
#include "reverse_iterator.hpp"

namespace ft
{


template < class T, class Alloc = std::allocator<T> >
class vector
{

template<typename IterT>
class RandomAccessIterator
{
	public:
		typedef	typename iterator_traits<IterT*>::value_type		value_type;
		typedef	typename iterator_traits<IterT*>::pointer			pointer;
		typedef	typename iterator_traits<IterT*>::reference			reference;
		typedef	typename iterator_traits<IterT*>::difference_type	difference_type;
		typedef	typename iterator_traits<IterT*>::iterator_category	iterator_category;
		typedef	pointer												iterator_type;

	private:
		pointer _ptr;

	public:
		RandomAccessIterator() : _ptr(nullptr) {}
		RandomAccessIterator(pointer rhs) : _ptr(rhs) {}
		RandomAccessIterator(const RandomAccessIterator<typename ft::remove_const<value_type>::type > & src) : _ptr(&(*src)) {}
		RandomAccessIterator<value_type> & operator=(RandomAccessIterator<typename ft::remove_const<value_type>::type > const & src) {
			_ptr = &(*src);
			return *this;
		}
		inline RandomAccessIterator& operator+=(difference_type rhs) {_ptr += rhs; return *this;}
		inline RandomAccessIterator& operator-=(difference_type rhs) {_ptr -= rhs; return *this;}
		inline reference operator*() const {return *_ptr;}
		inline pointer operator->() const {return _ptr;}
		inline reference operator[](difference_type rhs) const {return _ptr[rhs];}

		inline RandomAccessIterator& operator++() {++_ptr; return *this;}
		inline RandomAccessIterator& operator--() {--_ptr; return *this;}
		inline RandomAccessIterator operator++(int) {RandomAccessIterator tmp(*this); ++_ptr; return tmp;}
		inline RandomAccessIterator operator--(int) {RandomAccessIterator tmp(*this); --_ptr; return tmp;}
		inline difference_type operator-(const RandomAccessIterator& rhs) const {return _ptr-rhs._ptr;}
		inline RandomAccessIterator operator+(difference_type rhs) const {return RandomAccessIterator(_ptr+rhs);}
		inline RandomAccessIterator operator-(difference_type rhs) const {return RandomAccessIterator(_ptr-rhs);}

};


	public:
		template<class A, class B>
		friend inline bool operator==(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator<B>& rhs) {return &(*lhs) == &(*rhs);}
		template<class A, class B>
		friend inline bool operator!=(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator<B>& rhs) {return &(*lhs) != &(*rhs);}
		template<class A, class B>
		friend inline bool operator>(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator<B>& rhs) {return &(*lhs) > &(*rhs);}
		template<class A, class B>
		friend inline bool operator<(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator<B>& rhs) {return &(*lhs) < &(*rhs);}
		template<class A, class B>
		friend inline bool operator>=(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator<B>& rhs) {return &(*lhs) >= &(*rhs);}
		template<class A, class B>
		friend inline bool operator<=(const vector::template RandomAccessIterator<A>& lhs, const vector::template RandomAccessIterator<B>& rhs) {return &(*lhs) <= &(*rhs);}
		template<class A, class B>
		friend typename vector::template RandomAccessIterator<A>::difference_type operator-(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs){
			return &(*lhs) - &(*rhs);
		}

		template<class A, class B>
		friend typename vector::template RandomAccessIterator<A>::difference_type operator+(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs){
			return &(*lhs) + &(*rhs);
		}

		template<class L>
		friend vector::template RandomAccessIterator<L> operator +(const typename vector::template RandomAccessIterator<L>::difference_type & a, const vector::template RandomAccessIterator<L> & iter){
			return	(iter + a);
		}

		template<class L>
		friend vector::template RandomAccessIterator<L> operator -(const typename vector::template RandomAccessIterator<L>::difference_type & a, const vector::template RandomAccessIterator<L> & iter){
			return	(iter - a);
		}

	public:
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef RandomAccessIterator<value_type>							iterator;
		typedef RandomAccessIterator<const value_type>						const_iterator;
		typedef reverse_iterator<const_iterator>							const_reverse_iterator;
		typedef reverse_iterator<iterator>									reverse_iterator;
		typedef ptrdiff_t													difference_type;
		typedef size_t														size_type;

	private:
		allocator_type _alloc;
		size_type _capacity;
		size_type _size;
		pointer	_first;

	public:
// constructor
		explicit vector	(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _first(0) { return ; }
		explicit vector	(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n), _size(n)
		{
			_first = _alloc.allocate(n);

			for (size_type i = 0; i < n; i++)
				_alloc.construct(_first + i, val);
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _alloc(alloc)
		{
			difference_type n = std::distance(first, last);
			_size = static_cast<size_type>(n);
			_capacity = _size;
			_first = _alloc.allocate(n);

			for (difference_type i = 0; i < n; ++i, ++first)
				_alloc.construct(_first + i, *first);
		}
		vector (const vector& x) : _capacity(0), _size(0) { *this = x; }
// destructor
		~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_first + i);
			if (_capacity)
				_alloc.deallocate(_first, _capacity);
		}
// operator
		vector& operator= (const vector& x)
		{
			if (this == &x)
				return *this;

			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_first + i);
			if (_capacity < x._size)
			{
				if (_capacity)
					_alloc.deallocate(_first, _capacity);
				this->_first = this->_alloc.allocate(x._size);
			}
			this->_size = x._size;
			this->_capacity = x._capacity;
			for (size_type i = 0; i < _size; i++)
				this->_alloc.construct(this->_first + i, x[i]);
			return *this;
		}
// Iterators
		iterator begin() { return iterator(_first); }
		const_iterator begin() const { return const_iterator(_first); }
		iterator end() { return iterator(_first + _size); }
		const_iterator end() const { return const_iterator(_first + _size); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
// Capacity
		size_type size() const { return	this->_size; }
		size_type max_size() const { return this->_alloc.max_size(); }
		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_first + i);
			}
			else if (n > _size)
			{
				if (n > _capacity)
				{
					pointer new_vec = _alloc.allocate(_capacity * 2 > n ? _capacity * 2 : n);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(new_vec + i, *(_first + i));
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_first + i);
					if (_capacity)
						_alloc.deallocate(_first, _capacity);
					_first = new_vec;
					_capacity = _capacity * 2 > n ? _capacity * 2 : n;
				}
				for (size_type i = _size; i < n; i++)
						_alloc.construct(_first + i, val);
			}
			_size = n;
		}
		size_type capacity() const { return this->_capacity; }
		bool empty() const
		{
			if (!_size)
				return true;
			return false;
		}
		void reserve (size_type n)
		{
			if (n <= _capacity)
				return;
			pointer new_vec = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(new_vec + i, *(_first + i));
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_first + i);
			if (_capacity)
				_alloc.deallocate(_first, _capacity);
			_first = new_vec;
			_capacity = n;
		}
// Element access
		reference operator[] (size_type n)
		{
			return *(_first + n);
		}
		const_reference operator[] (size_type n) const
		{
			return *(_first + n);
		}
		reference at (size_type n)
		{
			if (n < _capacity)
				return *(_first + n);
			throw std::out_of_range("vector");
		}
		const_reference at (size_type n) const
		{
			if (n < _capacity)
				return *(_first + n);
			throw std::out_of_range("vector");
		}
		reference front()
		{
			return *_first;
		}
		const_reference front() const
		{
			return *_first;
		}
		reference back()
		{
			return *(_first + _size - 1);
		}
		const_reference back() const
		{
			return *(_first + _size - 1);
		}
// Modifiers
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			difference_type n = std::distance(first, last);
			if ((size_type)n > _capacity)
			{
				pointer new_vec = _alloc.allocate(n);
				for (difference_type i = 0; i < n; ++i, ++first)
					_alloc.construct(new_vec + i, *first);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_first + i);
				if (_capacity)
					_alloc.deallocate(_first, _capacity);
				_first = new_vec;
				_capacity = n;
			}
			else
			{
				for (difference_type i = 0; i < n; i++)
					_alloc.destroy(_first + i);
				for (difference_type i = 0; i < n; i++, first++)
					_alloc.construct(_first + i, *first);
			}
			_size = n;
		}
		void assign (size_type n, const value_type& val)
		{
			if (_size < n)
			{
				pointer new_vec = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(new_vec + i, val);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_first + i);
				if (_capacity)
					_alloc.deallocate(_first, _capacity);
				_first = new_vec;
				_capacity = n;
			}
			else
			{
				for (size_type i = 0; (i < n && i < _size); i++)
					_alloc.destroy(_first + i);
				for (size_type i = 0; (i < n && i < _size); i++)
					_alloc.construct(_first + i, val);
			}
			_size = n;
		}
		void push_back (const value_type& val)
		{
			size_type new_cap = _capacity == 0 ? 1 : _capacity * 2;
			if(_size == _capacity)
				this->reserve(new_cap);
			_alloc.construct(_first + _size, val);
			_size++;
		}
		void pop_back()
		{
			_alloc.destroy(_first + _size - 1);
			_size--;
		}
		iterator insert (iterator position, const value_type& val)
		{
			if (position < begin() || position > end())
				throw std::logic_error("vector");
			difference_type n = std::distance(begin(), position);
			if (_size == _capacity)
			{
				pointer new_vec = _alloc.allocate(_capacity * 2 + (_capacity == 0));
				for (difference_type i = 0; i < n; i++)
					_alloc.construct(new_vec + i, *(_first + i));
				for (size_type i = n + 1; i <= _size; i++)
					_alloc.construct(new_vec + i, *(_first + i - 1));
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_first + i);
				if (_capacity)
					_alloc.deallocate(_first, _capacity);
				_first = new_vec;
				_capacity = _capacity * 2 + (_capacity == 0);
			}
			else
			{
				for (difference_type i = _size; i > n; i--)
				{
					_alloc.construct(_first + i, *(_first + i - 1));
					_alloc.destroy(_first + i - 1);
				}
				_alloc.destroy(_first + n);
			}
			_alloc.construct(_first + n, val);
			_size++;
			return begin() + n;
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n == 0)
				return ;
			else if (max_size() - _size < n)
				throw std::length_error("vector");
			difference_type pos = std::distance(begin(), position);
			if (_size + n > _capacity)
			{
				pointer new_vec = _alloc.allocate(_capacity + n);
				for (difference_type i = 0; i < pos; i++)
					_alloc.construct(new_vec + i, *(_first + i));
				for (size_type i = pos; i < pos + n; i++)
					_alloc.construct(new_vec + i, val);
				for (size_type i = pos + n; i < _capacity + n; i++)
					_alloc.construct(new_vec + i, *(_first + i - n));
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_first + i);
				if (_capacity)
					_alloc.deallocate(_first, _capacity);
				_first = new_vec;
				_capacity += n;
			}
			else
			{
				for (size_type i = _size + n - 1; (difference_type)i >= pos; i--)
				{
					_alloc.construct(_first + i, *(_first + i - n));
					_alloc.destroy(_first + i - n);
				}
				for (size_type i = pos; i < pos + n; i++)
				{
					_alloc.destroy(_first + i);
					_alloc.construct(_first + i, val);
				}
			}
			_size += n;
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			if (position < begin() || position > end())
				throw std::logic_error("vector");
			difference_type n = std::distance(first, last);
			difference_type pos = std::distance(begin(), position);

			if (_size + n > _capacity)
			{
				size_type new_cap = _capacity * 2 >= _size + n ? _capacity * 2 : _size + n;
				pointer new_vec = _alloc.allocate(new_cap);
				for (difference_type i = 0; i < pos; i++)
					_alloc.construct(new_vec + i, *(_first + i));
				try
				{
					for (difference_type i = pos; i < pos + n; ++i, ++first)
						_alloc.construct(new_vec + i, *(first));
				}
				catch(...)
				{
					for (difference_type i = 0; i < pos + n; i++)
						_alloc.destroy(new_vec + i);
					_alloc.deallocate(new_vec, new_cap);
					throw;
				}

				for (size_type i = pos + n; i < _size + n; i++)
					_alloc.construct(new_vec + i, *(_first + i - n));
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_first + i);
				if (_capacity)
					_alloc.deallocate(_first, _capacity);
				_first = new_vec;
				_capacity = new_cap;
			}
			else
			{
				for (difference_type i = _capacity; i >= n; i--)
				{
					_alloc.construct(_first + i + n - 1, *(_first + i - 1));
					_alloc.destroy(_first + i - 1);
				}
				for (difference_type i = 0; i < n + 1; i++, first++);
				for (difference_type i = pos - 1; i < pos + n - 1; ++i, ++first)
				{
					_alloc.destroy(_first + i);
					_alloc.construct(_first + i, *first);
				}
			}
			_size += n;
		}
		iterator erase (iterator position)
		{
			difference_type pos = std::distance(begin(), position);
			for (size_type i = (size_type)pos; i < _size - 1; i++)
			{
				_alloc.destroy(_first + i);
				_alloc.construct(_first + i, *(_first + i + 1));
			}
			_alloc.destroy(_first + _size - 1);
			_size--;
			return begin() + pos;
		}
		iterator erase (iterator first, iterator last)
		{
			difference_type pos = std::distance(begin(), first);
			size_type n = (size_type)std::distance(first, last);

			for (size_type i = pos; i < pos + n + 1 && i + n < _size; i++)
			{
				_alloc.destroy(_first + i);
				_alloc.construct(_first + i, *(_first + i + n));
			}
			for (size_type i = pos + n; i < _size; i++)
				_alloc.destroy(_first + i);
			_size -= n;

			return begin() + pos;
		}
		void swap (vector& x)
		{
			std::swap(_first, x._first);
			std::swap(_size, x._size);
			std::swap(_capacity, x._capacity);
			std::swap(_alloc, x._alloc);
		}
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_first + i);
			_size = 0;
		}
// Allocator
		allocator_type get_allocator() const
		{
			return _alloc;
		}
// Non-member function overloads
		friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs._size == rhs._size)
			{
				for (size_type i = 0; i < rhs._size; i++)
					if (lhs[i] != rhs[i])
						return false;
				return true;
			}
			return false;
		}
		friend bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs._size != rhs._size)
				return true;
			for (size_type i = 0; i < rhs._size; i++)
				if (lhs[i] != rhs[i])
					return true;
			return false;
		}
		friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			size_type size = lhs._size < rhs._size ? lhs._size : rhs._size;
			for (size_type i = 0; i < size; i++)
			{
				if (lhs[i] != rhs[i])
				{
					if (lhs[i] < rhs[i])
						return true;
					else
						return false;
				}
			}
			if (lhs._size < rhs._size)
				return true;
			else
				return false;
		}
		friend bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			size_type size = lhs._size < rhs._size ? lhs._size : rhs._size;
			for (size_type i = 0; i < size; i++)
			{
				if (lhs[i] != rhs[i])
				{
					if (lhs[i] < rhs[i])
						return true;
					else
						return false;
				}
			}
			if (lhs._size <= rhs._size)
				return true;
			else
				return false;
		}
		friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			size_type size = lhs._size < rhs._size ? lhs._size : rhs._size;
			for (size_type i = 0; i < size; i++)
			{
				if (lhs[i] != rhs[i])
				{
					if (lhs[i] > rhs[i])
						return true;
					else
						return false;
				}
			}
			if (lhs._size > rhs._size)
				return true;
			else
				return false;
		}
		friend bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			size_type size = lhs._size < rhs._size ? lhs._size : rhs._size;
			for (size_type i = 0; i < size; i++)
			{
				if (lhs[i] != rhs[i])
				{
					if (lhs[i] > rhs[i])
						return true;
					else
						return false;
				}
			}
			if (lhs._size >= rhs._size)
				return true;
			else
				return false;
		}
  		friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			std::swap(y._first, x._first);
			std::swap(y._size, x._size);
			std::swap(y._capacity, x._capacity);
			std::swap(y._alloc, x._alloc);
		}

};

}

#endif
