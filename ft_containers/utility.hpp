#ifndef UTILITY_HPP
# define UTILITY_HPP

#include <iterator>
#include <memory>

namespace ft
{

template <bool Cond, class T = void>
struct enable_if;

template<typename T>
struct enable_if<true, T>
{
	public:
		typedef T	type;
};

template <class T, T v>
struct integral_constant
{
	public:
		typedef T					value_type;
		typedef integral_constant	type;

		static const T value = v;

		operator value_type const()
		{
			return value;
		}
};

template<class T> struct remove_const { typedef T type; };

template<class T> struct remove_const <const T> { typedef T type; };

typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;

template <class T>
struct is_integral
{
	public:
		typedef bool			value_type;
		typedef false_type		type;

		static const bool value = false;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<bool>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<char>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<wchar_t>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<char16_t>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<signed char>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<short int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<long int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<long long int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<unsigned char>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<unsigned short int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<unsigned int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<unsigned long int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <>
struct is_integral<unsigned long long int>
{
	public:
		typedef bool			value_type;
		typedef true_type		type;

		static const bool value = true;

		operator value_type()
		{
			return	value;
		}
};

template <class Iterator>
class iterator_traits
{
	public:
		typedef typename Iterator::difference_type			difference_type;
		typedef typename Iterator::value_type				value_type;
		typedef typename Iterator::pointer					pointer;
		typedef typename Iterator::reference				reference;
		typedef typename Iterator::iterator_category		iterator_category;
};

template <class T>
class iterator_traits<T*>
{
	public:
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
	public:
		typedef ptrdiff_t						difference_type;
		typedef const T							value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1) return false;
		else if (*first1 < *first2) return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}
template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	while (first1 != last1)
	{
		if (first2 == last2 || !comp(*first1, *first2)) return false;
		else if (comp(*first1, *first2)) return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1) {
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
	}
	return true;
}
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1) {
		if (!pred(*first1, *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template<typename T>
struct Identity : public std::unary_function<T, T>
{
	T&
	operator()(T& x) const
	{ return x; }

	const T&
	operator()(const T& x) const
	{ return x; }
};

template<typename T> struct Identity<const T> : Identity<T> { };

template<typename Pair>
struct Select1st
: public std::unary_function<Pair, typename Pair::first_type>
{
	typename Pair::first_type&
	operator()(Pair& x) const
	{ return x.first; }

	const typename Pair::first_type&
	operator()(const Pair& x) const
	{ return x.first; }
};

}

#endif
