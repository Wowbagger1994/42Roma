#ifndef TEST_SET_HPP
#define TEST_SET_HPP

#include "tests.hpp"

#pragma region Set

// test constructor
template <class T>
std::vector<int> set_copy_constructor_test_std()
{
	std::set<T> st;
	std::vector<int> v;

	for (int i = 0; i < 300000; ++i)
	{
		st.insert(i);
	}
	start1 = timer();
	std::set<int> st2(st.begin(), st.end());
	end1 = timer();
	std::set<int>::iterator it = st2.begin();
	for (int i = 0; i < 300000; ++i, it++)
	{
		v.push_back(*it);
	}
	return v;
}

template <class T>
std::vector<int> set_copy_constructor_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;

	for (int i = 0; i < 300000; ++i)
		st.insert(i);
	start2 = timer();
	ft::set<int> st2(st.begin(), st.end());
	end2 = timer();
	ft::set<int>::iterator it = st2.begin();
	for (int i = 0; i < 300000; ++i, it++)
	{
		v.push_back(*it);
	}
	return v;
}

// test operator =
template <class T>
std::vector<int> set_assign_overload_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 200000; ++i)
		st.insert(i);
	std::set<T> st2;
	for (int i = 200000; i < 400000; ++i)
		st2.insert(i);
	start1 = timer();
	st2 = st;
	end1 = timer();
	typename std::set<T>::iterator it = st2.begin();
	for (; it != st2.end(); it++)
		v.push_back(*it);
	v.push_back(st2.size());
	return v;
}

template <class T>
std::vector<int> set_assign_overload_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 200000; ++i)
		st.insert(i);
	ft::set<T> st2;
	for (int i = 200000; i < 400000; ++i)
		st2.insert(i);
	start2 = timer();
	st2 = st;
	end2 = timer();
	typename ft::set<T>::iterator it = st2.begin();
	for (; it != st2.end(); it++)
		v.push_back(*it);
	v.push_back(st2.size());
	return v;
}

// test iterators
template <class T>
std::vector<int> set_iterators_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	std::set<T> stt;
	fillSet(stt);
	for (typename std::set<T>::iterator it = stt.begin(); it != stt.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --stt.end(); it != stt.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int> mp0;
	std::set<int>::iterator ii = mp0.insert(3).first;
	ii++;
	v.push_back(*(--ii));
	for (int i = 0; i < 5; ++i)
		st.insert(i);
	typename std::set<T>::iterator it = st.begin();
	typename std::set<T>::iterator it2 = st.end();
	start1 = timer();
	v.push_back(*it);
	it++;
	it++;
	it++;
	it++;
	v.push_back(*it);
	it++;
	it--;
	v.push_back(*it);
	it2--;
	v.push_back(*it2);
	v.push_back(it2 == it);
	v.push_back(*(--it2));
	v.push_back(*(it2--));
	v.push_back(*(it2++));
	v.push_back(*(++it2));
	end1 = timer();
	return v;
}

template <class T>
std::vector<int> set_iterators_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	ft::set<T> stt;
	fillSet(stt);
	for (typename ft::set<T>::iterator it = stt.begin(); it != stt.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename ft::set<T>::iterator it = --stt.end(); it != stt.begin(); it--)
	{
		v.push_back(*it);
	}
	ft::set<int> mp0;
	ft::set<int>::iterator ii = mp0.insert(3).first;
	ii++;
	v.push_back(*(--ii));
	for (int i = 0; i < 5; ++i)
		st.insert(i);
	typename ft::set<T>::iterator it = st.begin();
	typename ft::set<T>::iterator it2 = st.end();
	start2 = timer();
	v.push_back(*it);
	it++;
	it++;
	it++;
	it++;
	v.push_back(*it);
	it++;
	it--;
	v.push_back(*it);
	it2--;
	v.push_back(*it2);
	v.push_back(it2 == it);
	v.push_back(*(--it2));
	v.push_back(*(it2--));
	v.push_back(*(it2++));
	v.push_back(*(++it2));
	end2 = timer();
	return v;
}

// test reverse iterators
template <class T>
std::vector<int> set_reverse_iterators_test_std()
{
	std::set<T> st;
	std::vector<int> v;

	start1 = end1 = timer();
	st.insert(5);
	st.insert(3);
	st.insert(7);
	typename std::set<T>::reverse_iterator rit = st.rbegin();
	typename std::set<T>::reverse_iterator rit2 = st.rend();
	v.push_back(*rit);
	rit++;
	rit2--;
	v.push_back(*rit);
	v.push_back(*rit2);
	rit++;
	v.push_back(*rit == *rit2);
	v.push_back(rit == rit2);
	rit2--;
	v.push_back(*rit);
	v.push_back(*rit2);
	v.push_back(*rit2 > *rit);
	v.push_back(*rit2 < *rit);
	v.push_back(*(--rit));
	v.push_back(*(++rit2));
	v.push_back(*(rit--));
	v.push_back(*(rit2++));
	return v;
}

template <class T>
std::vector<int> set_reverse_iterators_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;

	start2 = end2 = timer();
	st.insert(5);
	st.insert(3);
	st.insert(7);
	typename ft::set<T>::reverse_iterator rit = st.rbegin();
	typename ft::set<T>::reverse_iterator rit2 = st.rend();
	v.push_back(*rit);
	rit++;
	rit2--;
	v.push_back(*rit);
	v.push_back(*rit2);
	rit++;
	v.push_back(*rit == *rit2);
	v.push_back(rit == rit2);
	rit2--;
	v.push_back(*rit);
	v.push_back(*rit2);
	v.push_back(*rit2 > *rit);
	v.push_back(*rit2 < *rit);
	v.push_back(*(--rit));
	v.push_back(*(++rit2));
	v.push_back(*(rit--));
	v.push_back(*(rit2++));
	return v;
}

// test compare class
template <class T>
std::vector<int> set_comparator_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	fillSet(st);
	for (typename std::set<T>::iterator it = st.begin(); it != st.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st.end(); it != st.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int, std::greater<int> > st1;
	fillSet(st1);
	v.push_back(*(st1.begin()));
	st1.erase(41);
	v.push_back(*(st1.begin()));
	st1.erase(29);
	v.push_back(*(st1.begin()));
	std::set<int, std::greater<int> > st2;
	st2.insert(3);
	v.push_back(*(st2.begin()));
	st2.erase(3);
	if (st2.begin() == st2.end())
		v.push_back(1);
	std::set<int, std::plus<int> > st3;
	fillSet(st3);
	for (typename std::set<T>::iterator it = st3.begin(); it != st3.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st3.end(); it != st3.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int, std::minus<int> > st4;
	fillSet(st4);
	for (typename std::set<T>::iterator it = st4.begin(); it != st4.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st4.end(); it != st4.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int, std::greater_equal<int> > st5;
	fillSet(st5);
	for (typename std::set<T>::iterator it = st5.begin(); it != st5.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st5.end(); it != st5.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int, std::multiplies<int> > st6;
	fillSet(st6);
	for (typename std::set<T>::iterator it = st6.begin(); it != st6.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st6.end(); it != st6.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int, std::bit_xor<int> > st7;
	fillSet(st7);
	for (typename std::set<T>::iterator it = st7.begin(); it != st7.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st7.end(); it != st7.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int, std::logical_and<int> > st8;
	fillSet(st8);
	for (typename std::set<T>::iterator it = st8.begin(); it != st8.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st8.end(); it != st8.begin(); it--)
	{
		v.push_back(*it);
	}
	start1 = timer();
	end1 = timer();
	v.push_back(st1.size());
	return v;
}

template <class T>
std::vector<int> set_comparator_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	fillSet(st);
	for (typename ft::set<T>::iterator it = st.begin(); it != st.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename ft::set<T>::iterator it = --st.end(); it != st.begin(); it--)
	{
		v.push_back(*it);
	}
	ft::set<int, std::greater<int> > st1;
	fillSet(st1);
	v.push_back(*(st1.begin()));
	st1.erase(41);
	v.push_back(*(st1.begin()));
	st1.erase(29);
	v.push_back(*(st1.begin()));
	ft::set<int, std::greater<int> > st2;
	st2.insert(3);
	v.push_back(*(st2.begin()));
	st2.erase(3);
	if (st2.begin() == st2.end())
		v.push_back(1);
	ft::set<int, std::plus<int> > st3;
	fillSet(st3);
	for (typename ft::set<T>::iterator it = st3.begin(); it != st3.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename ft::set<T>::iterator it = --st3.end(); it != st3.begin(); it--)
	{
		v.push_back(*it);
	}
	ft::set<int, std::minus<int> > st4;
	fillSet(st4);
	for (typename ft::set<T>::iterator it = st4.begin(); it != st4.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename ft::set<T>::iterator it = --st4.end(); it != st4.begin(); it--)
	{
		v.push_back(*it);
	}
	ft::set<int, std::greater_equal<int> > st5;
	fillSet(st5);
	for (typename ft::set<T>::iterator it = st5.begin(); it != st5.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename ft::set<T>::iterator it = --st5.end(); it != st5.begin(); it--)
	{
		v.push_back(*it);
	}
	ft::set<int, std::multiplies<int> > st6;
	fillSet(st6);
	for (typename ft::set<T>::iterator it = st6.begin(); it != st6.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename ft::set<T>::iterator it = --st6.end(); it != st6.begin(); it--)
	{
		v.push_back(*it);
	}
	ft::set<int, std::bit_xor<int> > st7;
	fillSet(st7);
	for (typename ft::set<T>::iterator it = st7.begin(); it != st7.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename ft::set<T>::iterator it = --st7.end(); it != st7.begin(); it--)
	{
		v.push_back(*it);
	}
	std::set<int, std::logical_and<int> > st8;
	fillSet(st8);
	for (typename std::set<T>::iterator it = st8.begin(); it != st8.end(); it++)
	{
		v.push_back(*it);
	}
	for (typename std::set<T>::iterator it = --st8.end(); it != st8.begin(); it--)
	{
		v.push_back(*it);
	}
	start1 = timer();
	end1 = timer();
	v.push_back(st1.size());

	return v;
}

// test insert value
template <class T>
std::vector<int> set_insert_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	std::pair<std::set<int>::iterator, bool> pair = st.insert(7);
	std::set<int>::iterator it = st.begin();
	v.push_back(*it);

	v.push_back(*(pair.first));
	v.push_back(pair.second);
	st.insert(9);
	std::pair<std::set<int>::iterator, bool> pair2 = st.insert(9);
	std::set<int>::iterator it2 = pair.first;
	v.push_back(*it2);
	v.push_back(*(pair2.first));
	v.push_back(pair2.second);
	start1 = timer();
	for (int i = 0; i < 500000; ++i)
	{
		st.insert(i);
	}
	end1 = timer();
	typename std::set<T>::iterator it3 = st.begin();
	for (; it3 != st.end(); ++it3)
	{
		v.push_back(*it3);
	}
	v.push_back(st.size());
	return v;
}

template <class T>
std::vector<int> set_insert_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	ft::pair<ft::set<int>::iterator, bool> pair = st.insert(7);
	ft::set<int>::iterator it = st.begin();
	v.push_back(*it);

	v.push_back(*(pair.first));
	v.push_back(pair.second);
	st.insert(9);
	ft::pair<ft::set<int>::iterator, bool> pair2 = st.insert(9);
	ft::set<int>::iterator it2 = pair.first;
	v.push_back(*it2);
	v.push_back(*(pair2.first));
	v.push_back(pair2.second);
	start2 = timer();
	for (int i = 0; i < 500000; ++i)
	{
		st.insert(i);
	}
	end2 = timer();
	typename ft::set<T>::iterator it3 = st.begin();
	for (; it3 != st.end(); ++it3)
	{
		v.push_back(*it3);
	}
	v.push_back(st.size());
	return v;
}

// test insert input iterator
template <class T>
std::vector<int> set_insert_it_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 500000; ++i)
		st.insert(i);
	std::set<int> st2;
	start1 = timer();
	st2.insert(st.begin(), st.end());
	end1 = timer();
	typename std::set<T>::iterator it2 = st2.begin();
	for (; it2 != st2.end(); ++it2)
	{
		v.push_back(*it2);
	}
	return v;
}

template <class T>
std::vector<int> set_insert_it_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 500000; ++i)
		st.insert(i);
	ft::set<int> st2;
	start2 = timer();
	st2.insert(st.begin(), st.end());
	end2 = timer();
	typename ft::set<T>::iterator it2 = st2.begin();
	for (; it2 != st2.end(); ++it2)
	{
		v.push_back(*it2);
	}
	return v;
}

// test insert hint
template <class T>
std::vector<int> set_insert_hint_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	typename std::set<T>::iterator it = st.end();
	start1 = timer();
	for (int i = 0; i < 500000; ++i)
	{
		st.insert(it, i);
	}
	end1 = timer();
	typename std::set<T>::iterator it2 = st.begin();
	for (; it2 != st.end(); ++it2)
	{
		v.push_back(*it2);
	}
	return v;
}

template <class T>
std::vector<int> set_insert_hint_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	typename ft::set<T>::iterator it = st.end();
	start2 = timer();
	for (int i = 0; i < 500000; ++i)
	{
		st.insert(it, i);
	}
	end2 = timer();
	typename ft::set<T>::iterator it2 = st.begin();
	for (; it2 != st.end(); ++it2)
	{
		v.push_back(*it2);
	}
	return v;
}

// test empty
template <class T>
std::vector<int> set_empty_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	start1 = timer();
	v.push_back(st.empty());
	st.insert(3);
	v.push_back(st.empty());
	end1 = timer();
	return v;
}

template <class T>
std::vector<int> set_empty_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	start2 = timer();
	v.push_back(st.empty());
	st.insert(3);
	v.push_back(st.empty());
	end2 = timer();
	return v;
}

// test size
template <class T>
std::vector<int> set_size_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 1000000; ++i)
		st.insert(i);
	start1 = timer();
	v.push_back(st.size());
	end1 = timer();
	for (int i = 0; i < 43; ++i)
		st.erase(i);
	v.push_back(st.size());
	return v;
}

template <class T>
std::vector<int> set_size_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 1000000; ++i)
		st.insert(i);
	start2 = timer();
	v.push_back(st.size());
	end2 = timer();
	for (int i = 0; i < 43; ++i)
		st.erase(i);
	v.push_back(st.size());
	return v;
}

// test max_size
template <class T>
std::vector<int> set_max_size_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	start1 = timer();
	v.push_back((st.size() * 0) + 1);
	end1 = timer();
	return v;
}

template <class T>
std::vector<int> set_max_size_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	std::set<int> std_st;
	start2 = timer();
	if ((std_st.max_size() / 2) < st.max_size())
		v.push_back(1);
	end2 = timer();
	return v;
}

// test clear
template <class T>
std::vector<int> set_clear_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	st.clear();
	for (int i = 0; i < 250000; ++i)
		st.insert(i);
	v.push_back(st.size());
	start1 = timer();
	st.clear();
	end1 = timer();
	v.push_back(st.size());
	typename std::set<T>::iterator it = st.begin();
	if (it == st.end())
		v.push_back(1);
	return v;
}

template <class T>
std::vector<int> set_clear_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	st.clear();
	for (int i = 0; i < 250000; ++i)
		st.insert(i);
	v.push_back(st.size());
	start2 = timer();
	st.clear();
	end2 = timer();
	v.push_back(st.size());
	typename ft::set<T>::iterator it = st.begin();
	if (it == st.end())
		v.push_back(1);
	return v;
}

// test erase value
template <class T>
std::vector<int> set_erase_value_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	v.push_back(st.erase(3));
	for (int i = 0; i < 300000; ++i)
		st.insert(i);
	typename std::set<T>::iterator it = st.begin();
	v.push_back(*it);
	v.push_back(st.erase(-5));
	v.push_back(st.size());
	v.push_back(st.erase(0));
	v.push_back(st.size());
	typename std::set<T>::iterator it4 = st.begin();
	start1 = timer();
	for (; it4 != st.end(); it4 = st.begin())
		st.erase(*it4);
	end1 = timer();
	v.push_back(st.erase(300000 - 1));
	v.push_back(st.size());
	std::set<int> st2;
	for (int i = 0; i < 10; ++i)
		st2.insert(i);
	st2.erase(2);
	st2.erase(7);
	typename std::set<T>::iterator it3 = st2.begin();
	for (; it3 != st2.end(); ++it3)
	{
		v.push_back(*it3);
	}
	return v;
}

template <class T>
std::vector<int> set_erase_value_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	v.push_back(st.erase(3));
	for (int i = 0; i < 300000; ++i)
		st.insert(i);
	typename ft::set<T>::iterator it = st.begin();
	v.push_back(*it);
	v.push_back(st.erase(-5));
	v.push_back(st.size());
	v.push_back(st.erase(0));
	v.push_back(st.size());
	typename ft::set<T>::iterator it4 = st.begin();
	start2 = timer();
	for (; it4 != st.end(); it4 = st.begin())
		st.erase(*it4);
	end2 = timer();
	v.push_back(st.erase(300000 - 1));
	v.push_back(st.size());
	ft::set<int> st2;
	for (int i = 0; i < 10; ++i)
		st2.insert(i);
	st2.erase(2);
	st2.erase(7);
	typename ft::set<T>::iterator it3 = st2.begin();
	for (; it3 != st2.end(); ++it3)
	{
		v.push_back(*it3);
	}
	return v;
}

// test erase position
template <class T>
std::vector<int> set_erase_position_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 300000; ++i)
		st.insert(i);
	typename std::set<T>::iterator it = st.begin();
	v.push_back(*it);
	st.erase(it);
	v.push_back(st.size());
	it = st.begin();
	st.erase(++it);
	v.push_back(st.size());
	it = st.begin();
	v.push_back(*it);
	typename std::set<T>::iterator it4 = st.begin();
	start1 = timer();
	for (; it4 != st.end(); it4 = st.begin())
		st.erase(it4);
	end1 = timer();
	v.push_back(st.size());
	std::set<int> st2;
	for (int i = 0; i < 10; ++i)
		st2.insert(i);
	typename std::set<T>::iterator ittest = st2.begin();
	for (int i = 0; i < 2; ++i)
		ittest++;
	st2.erase(ittest);
	ittest = st2.begin();
	for (int i = 0; i < 5; ++i)
		ittest++;
	st2.erase(ittest);
	typename std::set<T>::iterator it3 = st2.begin();
	for (; it3 != st2.end(); ++it3)
	{
		v.push_back(*it3);
	}
	return v;
}

template <class T>
std::vector<int> set_erase_position_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 300000; ++i)
		st.insert(i);
	typename ft::set<T>::iterator it = st.begin();
	v.push_back(*it);
	st.erase(it);
	v.push_back(st.size());
	it = st.begin();
	st.erase(++it);
	v.push_back(st.size());
	it = st.begin();
	v.push_back(*it);
	typename ft::set<T>::iterator it4 = st.begin();
	start2 = timer();
	for (; it4 != st.end(); it4 = st.begin())
		st.erase(it4);
	end2 = timer();
	v.push_back(st.size());
	ft::set<int> st2;
	for (int i = 0; i < 10; ++i)
		st2.insert(i);
	typename ft::set<T>::iterator ittest = st2.begin();
	for (int i = 0; i < 2; ++i)
		ittest++;
	st2.erase(ittest);
	ittest = st2.begin();
	for (int i = 0; i < 5; ++i)
		ittest++;
	st2.erase(ittest);
	typename ft::set<T>::iterator it3 = st2.begin();
	for (; it3 != st2.end(); ++it3)
	{
		v.push_back(*it3);
	}
	return v;
}

// test erase input iterator
template <class T>
std::vector<int> set_erase_it_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 500000; ++i)
		st.insert(i);
	start1 = timer();
	st.erase(st.begin(), --st.end());
	end1 = timer();
	v.push_back(*(st.begin()));
	return v;
}

template <class T>
std::vector<int> set_erase_it_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	for (int i = 0; i < 500000; ++i)
		st.insert(i);
	start2 = timer();
	st.erase(st.begin(), --st.end());
	end2 = timer();
	v.push_back(*(st.begin()));
	return v;
}

// test swap
template <class T>
std::vector<int> set_swap_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	start1 = end1 = timer();
	for (int i = 0; i < 250000; ++i)
		st.insert(i);
	std::set<T> st2;
	for (int i = 250000; i < 350000; ++i)
		st.insert(i);
	long *adr1 = reinterpret_cast<long *>(&st);
	long *adr2 = reinterpret_cast<long *>(&st2);
	st.swap(st2);
	if (reinterpret_cast<long *>(&st) == adr1 && reinterpret_cast<long *>(&st2) == adr2)
		v.push_back(1);
	v.push_back(st2.size());
	typename std::set<T>::iterator it = st2.begin();
	for (; it != st2.end(); ++it)
	{
		v.push_back(*it);
	}
	std::swap(st, st2);
	typename std::set<T>::iterator it2 = st2.begin();
	for (; it2 != st2.end(); ++it2)
	{
		v.push_back(*it2);
	}
	return v;
}

template <class T>
std::vector<int> set_swap_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	start2 = end2 = timer();
	for (int i = 0; i < 250000; ++i)
		st.insert(i);
	ft::set<T> st2;
	for (int i = 250000; i < 350000; ++i)
		st.insert(i);
	long *adr1 = reinterpret_cast<long *>(&st);
	long *adr2 = reinterpret_cast<long *>(&st2);
	st.swap(st2);
	if (reinterpret_cast<long *>(&st) == adr1 && reinterpret_cast<long *>(&st2) == adr2)
		v.push_back(1);
	v.push_back(st2.size());
	typename ft::set<T>::iterator it = st2.begin();
	for (; it != st2.end(); ++it)
	{
		v.push_back(*it);
	}
	std::swap(st, st2);
	typename ft::set<T>::iterator it2 = st2.begin();
	for (; it2 != st2.end(); ++it2)
	{
		v.push_back(*it2);
	}
	return v;
}

// test count
template <class T>
std::vector<int> set_count_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	start1 = end1 = timer();
	v.push_back(st.count(0));
	st.insert(0);
	v.push_back(st.count(0));
	return v;
}

template <class T>
std::vector<int> set_count_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	start2 = end2 = timer();
	v.push_back(st.count(0));
	st.insert(0);
	v.push_back(st.count(0));
	return v;
}

// test find
template <class T>
std::vector<int> set_find_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	for (int i = -750000; i < 750000; ++i)
	{
		st.insert(i);
	}
	start1 = timer();
	typename std::set<T>::iterator it = st.find(340000);
	end1 = timer();
	v.push_back(*it);

	it = st.find(-340000);
	v.push_back(*it);

	it = st.find(-987654321);
	if (it == st.end())
		v.push_back(1);
	return v;
}

template <class T>
std::vector<int> set_find_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	for (int i = -750000; i < 750000; ++i)
	{
		st.insert(i);
	}
	start2 = timer();
	typename ft::set<T>::iterator it = st.find(340000);
	end2 = timer();
	v.push_back(*it);

	it = st.find(-340000);
	v.push_back(*it);

	it = st.find(-987654321);
	if (it == st.end())
		v.push_back(1);
	return v;
}

// test lower_bound
template <class T>
std::vector<int> set_lower_bound_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	std::set<int, std::greater<int> > st2;
	st.insert(10);
	st2.insert(10);
	if (st.lower_bound(11) == st.end())
		v.push_back(1);
	if (st2.lower_bound(1) == st2.end())
		v.push_back(1);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);
	st.insert(60);
	st2.insert(20);
	st2.insert(30);
	st2.insert(40);
	st2.insert(50);
	st2.insert(60);
	std::set<int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = st.lower_bound(i);
		v.push_back(*it);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = st2.lower_bound(i);
		v.push_back(*it);
	}
	std::set<int> st3;
	for (int i = 0; i < 500000; ++i)
	{
		st3.insert(i);
	}
	start1 = timer();
	st3.lower_bound(490000);
	end1 = timer();
	return v;
}

template <class T>
std::vector<int> set_lower_bound_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	ft::set<int, std::greater<int> > st2;
	st.insert(10);
	st2.insert(10);
	if (st.lower_bound(11) == st.end())
		v.push_back(1);
	if (st2.lower_bound(1) == st2.end())
		v.push_back(1);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);
	st.insert(60);
	st2.insert(20);
	st2.insert(30);
	st2.insert(40);
	st2.insert(50);
	st2.insert(60);
	ft::set<int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = st.lower_bound(i);
		v.push_back(*it);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = st2.lower_bound(i);
		v.push_back(*it);
	}
	ft::set<int> st3;
	for (int i = 0; i < 500000; ++i)
	{
		st3.insert(i);
	}
	start2 = timer();
	st3.lower_bound(490000);
	end2 = timer();
	return v;
}

// test upper_bound
template <class T>
std::vector<int> set_upper_bound_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	std::set<int, std::greater<int> > st2;
	st.insert(10);
	st2.insert(10);
	if (st.upper_bound(11) == st.end())
		v.push_back(1);
	if (st2.upper_bound(1) == st2.end())
		v.push_back(1);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);
	st.insert(60);
	st2.insert(20);
	st2.insert(30);
	st2.insert(40);
	st2.insert(50);
	st2.insert(60);
	std::set<int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = st.upper_bound(i);
		v.push_back(*it);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = st2.upper_bound(i);
		v.push_back(*it);
	}
	std::set<int> st3;
	for (int i = 0; i < 500000; ++i)
	{
		st3.insert(i);
	}
	std::set<int> st4;
	st.insert(-10);
	st.insert(-20);
	v.push_back(*(--st.upper_bound(0)));
	start1 = timer();
	st3.upper_bound(490000);
	end1 = timer();
	return v;
}

template <class T>
std::vector<int> set_upper_bound_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	ft::set<int, std::greater<int> > st2;
	st.insert(10);
	st2.insert(10);
	if (st.upper_bound(11) == st.end())
		v.push_back(1);
	if (st2.upper_bound(1) == st2.end())
		v.push_back(1);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);
	st.insert(60);
	st2.insert(20);
	st2.insert(30);
	st2.insert(40);
	st2.insert(50);
	st2.insert(60);
	ft::set<int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = st.upper_bound(i);
		v.push_back(*it);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = st2.upper_bound(i);
		v.push_back(*it);
	}
	ft::set<int> st3;
	for (int i = 0; i < 500000; ++i)
	{
		st3.insert(i);
	}
	ft::set<int> st4;
	st.insert(-10);
	st.insert(-20);
	v.push_back(*(--st.upper_bound(0)));
	start2 = timer();
	st3.upper_bound(490000);
	end2 = timer();
	return v;
}

// test equal_range
template <class T>
std::vector<int> set_equal_range_test_std()
{
	std::set<T> st;
	std::vector<int> v;
	st.insert(10);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);
	st.insert(60);
	start1 = timer();
	const std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> &pair = st.equal_range(10);
	const std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> &pair2 = st.equal_range(11);
	const std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> &pair3 = st.equal_range(1);
	end1 = timer();
	v.push_back(*(pair.first));
	v.push_back(*(pair.second));
	v.push_back(*(pair2.first));
	v.push_back(*(pair2.second));
	v.push_back(*(pair3.first));
	v.push_back(*(pair3.second));
	return v;
}

template <class T>
std::vector<int> set_equal_range_test_ft()
{
	ft::set<T> st;
	std::vector<int> v;
	st.insert(10);
	st.insert(20);
	st.insert(30);
	st.insert(40);
	st.insert(50);
	st.insert(60);
	start2 = timer();
	const ft::pair<ft::set<int>::const_iterator, ft::set<int>::const_iterator> &pair = st.equal_range(10);
	const ft::pair<ft::set<int>::const_iterator, ft::set<int>::const_iterator> &pair2 = st.equal_range(11);
	const ft::pair<ft::set<int>::const_iterator, ft::set<int>::const_iterator> &pair3 = st.equal_range(1);
	end2 = timer();
	v.push_back(*(pair.first));
	v.push_back(*(pair.second));
	v.push_back(*(pair2.first));
	v.push_back(*(pair2.second));
	v.push_back(*(pair3.first));
	v.push_back(*(pair3.second));
	return v;
}

// test key_comp
template <class T>
std::vector<int> set_key_comp_test_std()
{
	std::set<T> st;

	std::vector<int> v;
	start1 = end1 = timer();
	std::set<int, std::greater<int> > st2;
	std::set<int, std::equal_to<int> > st3;
	v.push_back(st.key_comp()(1, 2));
	v.push_back(st2.key_comp()(1, 2));
	v.push_back(st3.key_comp()(1, 2));
	return v;
}

template <class T>
std::vector<int> set_key_comp_test_ft()
{
	ft::set<T> st;

	std::vector<int> v;
	start2 = end2 = timer();
	ft::set<int, std::greater<int> > st2;
	ft::set<int, std::equal_to<int> > st3;
	v.push_back(st.key_comp()(1, 2));
	v.push_back(st2.key_comp()(1, 2));
	v.push_back(st3.key_comp()(1, 2));
	return v;
}

// test operator ==
bool set_equal_test();

// test operator !=
bool set_not_equal_test();

// test operator <
bool set_less_than_test();

// test operator >
bool set_more_than_test();

// test operator <=
bool set_less_or_equal_test();

// test operator >=
bool set_more_or_equal_test();

#pragma endregion

#endif
