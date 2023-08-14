#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "utility.hpp"

namespace ft
{

template <class Iterator>
class reverse_iterator
{
	public:
		typedef Iterator 												iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

	private:
		iterator_type _ptr;

	public:
// Member functions
		reverse_iterator() : _ptr(nullptr) {}
		explicit reverse_iterator (iterator_type it) : _ptr(it) {}
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) { _ptr = rev_it.base(); }

		iterator_type base() const { return _ptr;};
		reference operator*() const { iterator_type tmp = _ptr; return (*--tmp); }
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(_ptr - n); }
		reverse_iterator& operator++()
		{
			--_ptr;
			return (*this);
		}
		reverse_iterator  operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}
		reverse_iterator& operator+=(difference_type n) { _ptr -= n; return *this; }
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(_ptr + n); }
		reverse_iterator& operator--()
		{
			++_ptr;
			return (*this);
		}
		reverse_iterator  operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}
		reverse_iterator& operator-=(difference_type n) { _ptr += n; return *this; }
		pointer operator->() const { return &(operator*()); }
		reference operator[] (difference_type n) const { return base()[-n-1]; }
};
// Non-member function overloads

	template<class T1, class T2>
	bool operator==( const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs )
	{
		return (lhs.base() == rhs.base());
	};

	template<class T1, class T2>
	bool operator!=( const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs )
	{
		return (lhs.base() != rhs.base());
	};

	template<class T1, class T2>
	bool operator<( const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs )
	{
		return (lhs.base() > rhs.base());
	};

	template<class T1, class T2>
	bool operator<=( const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs )
	{
		return (lhs.base() >= rhs.base());
	};

	template<class T1, class T2>
	bool operator>( const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs )
	{
		return (lhs.base() < rhs.base());
	};

	template<class T1, class T2>
	bool operator>=( const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs )
	{
		return (lhs.base() <= rhs.base());
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}
		template <class Iterator>
	reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() + n);
	}

	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type
	operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return y.base() - x.base();
	}

}

#endif
