#ifndef TEST_MAP_HPP
#define TEST_MAP_HPP

#include "tests.hpp"

#pragma region Map

// test constructor
template <class T, class V>
std::vector<int> map_copy_constructor_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;

	for (int i = 0, j = 10; i < 300000; ++i, ++j)
	{
		mp.insert(std::make_pair(i, j));
	}
	start1 = timer();
	std::map<int, int> mp2(mp.begin(), mp.end());
	end1 = timer();
	std::map<int, int>::iterator it = mp2.begin();
	for (int i = 0; i < 300000; ++i, it++)
	{
		v.push_back(it->first);
		v.push_back(it->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> map_copy_constructor_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;

	for (int i = 0, j = 10; i < 300000; ++i, ++j)
	{
		mp.insert(ft::make_pair(i, j));
	}
	start2 = timer();
	ft::map<int, int> mp2(mp.begin(), mp.end());
	end2 = timer();
	ft::map<int, int>::iterator it = mp2.begin();
	for (int i = 0; i < 300000; ++i, it++)
	{
		v.push_back(it->first);
		v.push_back(it->second);
	}
	return v;
}

// test operator =
template <class T, class V>
std::vector<int> map_assign_overload_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 10; i < 200000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	std::map<T, V> mp2;
	for (int i = 200000, j = 200010; i < 400000; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	start1 = timer();
	mp2 = mp;
	end1 = timer();
	typename std::map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); it++)
	{
		v.push_back(it->first);
		v.push_back(it->second);
	}
	v.push_back(mp2.size());
	return v;
}

template <class T, class V>
std::vector<int> map_assign_overload_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 10; i < 200000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	ft::map<T, V> mp2;
	for (int i = 200000, j = 200010; i < 400000; ++i, ++j)
		mp2.insert(ft::make_pair(i, j));
	start2 = timer();
	mp2 = mp;
	end2 = timer();
	typename ft::map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); it++)
	{
		v.push_back(it->first);
		v.push_back(it->second);
	}
	v.push_back(mp2.size());
	return v;
}

// test iterators
template <class T, class V>
std::vector<int> map_iterators_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	std::map<T, V> mpp;
	fillMap(mpp);
	for (typename std::map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int> mp0;
	std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
	ii++;
	v.push_back((--ii)->first);
	for (int i = 0, j = 10; i < 5; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	typename std::map<T, V>::iterator it2 = mp.end();
	start1 = timer();
	v.push_back(it->first);
	it++;
	it++;
	it++;
	it++;
	v.push_back(it->first);
	it++;
	it--;
	v.push_back(it->first);
	it2--;
	v.push_back(it2->first);
	v.push_back(it2 == it);
	v.push_back((--it2)->first);
	v.push_back((it2--)->first);
	v.push_back((it2++)->first);
	v.push_back((++it2)->first);
	end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> map_iterators_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	ft::map<T, V> mpp;
	fillMap(mpp);
	for (typename ft::map<T, V>::iterator it = mpp.begin(); it != mpp.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename ft::map<T, V>::iterator it = --mpp.end(); it != mpp.begin(); it--)
	{
		v.push_back(it->first);
	}
	ft::map<int, int> mp0;
	ft::map<int, int>::iterator ii = mp0.insert(ft::make_pair(3, 3)).first;
	ii++;
	v.push_back((--ii)->first);
	for (int i = 0, j = 10; i < 5; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	typename ft::map<T, V>::iterator it = mp.begin();
	typename ft::map<T, V>::iterator it2 = mp.end();
	start2 = timer();
	v.push_back(it->first);
	it++;
	it++;
	it++;
	it++;
	v.push_back(it->first);
	it++;
	it--;
	v.push_back(it->first);
	it2--;
	v.push_back(it2->first);
	v.push_back(it2 == it);
	v.push_back((--it2)->first);
	v.push_back((it2--)->first);
	v.push_back((it2++)->first);
	v.push_back((++it2)->first);
	end2 = timer();
	return v;
}

// test reverse iterators
template <class T, class V>
std::vector<int> map_reverse_iterators_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;

	start1 = end1 = timer();
	mp.insert(std::make_pair(5, 5));
	mp.insert(std::make_pair(3, 3));
	mp.insert(std::make_pair(7, 7));
	typename std::map<T, V>::reverse_iterator rit = mp.rbegin();
	typename std::map<T, V>::reverse_iterator rit2 = mp.rend();
	v.push_back(rit->first);
	rit++;
	rit2--;
	v.push_back(rit->first);
	v.push_back(rit2->first);
	rit++;
	v.push_back(*rit == *rit2);
	rit2--;
	v.push_back(rit->first);
	v.push_back(rit2->first);
	v.push_back(*rit2 > *rit);
	v.push_back(*rit2 < *rit);
	v.push_back((--rit)->first);
	v.push_back((++rit2)->first);
	v.push_back((rit--)->first);
	v.push_back((rit2++)->first);
	return v;
}

template <class T, class V>
std::vector<int> map_reverse_iterators_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;

	start2 = end2 = timer();
	mp.insert(ft::make_pair(5, 5));
	mp.insert(ft::make_pair(3, 3));
	mp.insert(ft::make_pair(7, 7));
	typename ft::map<T, V>::reverse_iterator rit = mp.rbegin();
	typename ft::map<T, V>::reverse_iterator rit2 = mp.rend();
	v.push_back(rit->first);
	rit++;
	rit2--;
	v.push_back(rit->first);
	v.push_back(rit2->first);
	rit++;
	v.push_back(*rit == *rit2);
	rit2--;
	v.push_back(rit->first);
	v.push_back(rit2->first);
	v.push_back(*rit2 > *rit);
	v.push_back(*rit2 < *rit);
	v.push_back((--rit)->first);
	v.push_back((++rit2)->first);
	v.push_back((rit--)->first);
	v.push_back((rit2++)->first);
	return v;
}

// test compare class
template <class T, class V>
std::vector<int> map_comparator_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	fillMap(mp);
	for (typename std::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int, std::greater<int> > mp1;
	fillMap(mp1);
	v.push_back(mp1.begin()->first);
	mp1.erase(41);
	v.push_back(mp1.begin()->first);
	mp1.erase(29);
	v.push_back(mp1.begin()->first);
	std::map<int, int, std::greater<int> > mp2;
	mp2.insert(std::make_pair(3, 3));
	v.push_back(mp2.begin()->first);
	mp2.erase(3);
	if (mp2.begin() == mp2.end())
		v.push_back(1);
	std::map<int, int, std::plus<int> > mp3;
	fillMap(mp3);
	for (typename std::map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int, std::minus<int> > mp4;
	fillMap(mp4);
	for (typename std::map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int, std::greater_equal<int> > mp5;
	fillMap(mp5);
	for (typename std::map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int, std::multiplies<int> > mp6;
	fillMap(mp6);
	for (typename std::map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int, std::bit_xor<int> > mp7;
	fillMap(mp7);
	for (typename std::map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int, std::logical_and<int> > mp8;
	fillMap(mp8);
	for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--)
	{
		v.push_back(it->first);
	}
	start1 = timer();
	end1 = timer();
	v.push_back(mp1.size());
	return v;
}

template <class T, class V>
std::vector<int> map_comparator_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	fillMap(mp);
	for (typename ft::map<T, V>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename ft::map<T, V>::iterator it = --mp.end(); it != mp.begin(); it--)
	{
		v.push_back(it->first);
	}
	ft::map<int, int, std::greater<int> > mp1;
	fillMap(mp1);
	v.push_back(mp1.begin()->first);
	mp1.erase(41);
	v.push_back(mp1.begin()->first);
	mp1.erase(29);
	v.push_back(mp1.begin()->first);
	ft::map<int, int, std::greater<int> > mp2;
	mp2.insert(ft::make_pair(3, 3));
	v.push_back(mp2.begin()->first);
	mp2.erase(3);
	if (mp2.begin() == mp2.end())
		v.push_back(1);
	ft::map<int, int, std::plus<int> > mp3;
	fillMap(mp3);
	for (typename ft::map<T, V>::iterator it = mp3.begin(); it != mp3.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename ft::map<T, V>::iterator it = --mp3.end(); it != mp3.begin(); it--)
	{
		v.push_back(it->first);
	}
	ft::map<int, int, std::minus<int> > mp4;
	fillMap(mp4);
	for (typename ft::map<T, V>::iterator it = mp4.begin(); it != mp4.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename ft::map<T, V>::iterator it = --mp4.end(); it != mp4.begin(); it--)
	{
		v.push_back(it->first);
	}
	ft::map<int, int, std::greater_equal<int> > mp5;
	fillMap(mp5);
	for (typename ft::map<T, V>::iterator it = mp5.begin(); it != mp5.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename ft::map<T, V>::iterator it = --mp5.end(); it != mp5.begin(); it--)
	{
		v.push_back(it->first);
	}
	ft::map<int, int, std::multiplies<int> > mp6;
	fillMap(mp6);
	for (typename ft::map<T, V>::iterator it = mp6.begin(); it != mp6.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename ft::map<T, V>::iterator it = --mp6.end(); it != mp6.begin(); it--)
	{
		v.push_back(it->first);
	}
	ft::map<int, int, std::bit_xor<int> > mp7;
	fillMap(mp7);
	for (typename ft::map<T, V>::iterator it = mp7.begin(); it != mp7.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename ft::map<T, V>::iterator it = --mp7.end(); it != mp7.begin(); it--)
	{
		v.push_back(it->first);
	}
	std::map<int, int, std::logical_and<int> > mp8;
	fillMap(mp8);
	for (typename std::map<T, V>::iterator it = mp8.begin(); it != mp8.end(); it++)
	{
		v.push_back(it->first);
	}
	for (typename std::map<T, V>::iterator it = --mp8.end(); it != mp8.begin(); it--)
	{
		v.push_back(it->first);
	}
	start1 = timer();
	end1 = timer();
	v.push_back(mp1.size());

	return v;
}

// test insert value
template <class T, class V>
std::vector<int> map_insert_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	std::pair<std::map<int, int>::iterator, bool> pair = mp.insert(std::make_pair(7, 7));
	std::map<int, int>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second);
	mp.insert(std::make_pair(9, 9));
	std::pair<std::map<int, int>::iterator, bool> pair2 = mp.insert(std::make_pair(9, 9));
	std::map<int, int>::iterator it2 = pair.first;
	v.push_back(it2->first);
	v.push_back(it2->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second);
	start1 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp.insert(std::make_pair(i, j));
	}
	end1 = timer();
	typename std::map<T, V>::iterator it3 = mp.begin();
	for (; it3 != mp.end(); ++it3)
	{
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	v.push_back(mp.size());
	return v;
}

template <class T, class V>
std::vector<int> map_insert_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	ft::pair<ft::map<int, int>::iterator, bool> pair = mp.insert(ft::make_pair(7, 7));
	ft::map<int, int>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second);
	mp.insert(ft::make_pair(9, 9));
	ft::pair<ft::map<int, int>::iterator, bool> pair2 = mp.insert(ft::make_pair(9, 9));
	ft::map<int, int>::iterator it2 = pair.first;
	v.push_back(it2->first);
	v.push_back(it2->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second);
	start2 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp.insert(ft::make_pair(i, j));
	}
	end2 = timer();
	typename ft::map<T, V>::iterator it3 = mp.begin();
	for (; it3 != mp.end(); ++it3)
	{
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	v.push_back(mp.size());
	return v;
}

// test insert input iterator
template <class T, class V>
std::vector<int> map_insert_it_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	std::map<int, int> mp2;
	start1 = timer();
	mp2.insert(mp.begin(), mp.end());
	end1 = timer();
	typename std::map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2)
	{
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> map_insert_it_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	ft::map<int, int> mp2;
	start2 = timer();
	mp2.insert(mp.begin(), mp.end());
	end2 = timer();
	typename ft::map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2)
	{
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

// test insert hint
template <class T, class V>
std::vector<int> map_insert_hint_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	typename std::map<T, V>::iterator it = mp.end();
	start1 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp.insert(it, std::make_pair(i, j));
	}
	end1 = timer();
	typename std::map<T, V>::iterator it2 = mp.begin();
	for (; it2 != mp.end(); ++it2)
	{
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> map_insert_hint_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	typename ft::map<T, V>::iterator it = mp.end();
	start2 = timer();
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp.insert(it, ft::make_pair(i, j));
	}
	end2 = timer();
	typename ft::map<T, V>::iterator it2 = mp.begin();
	for (; it2 != mp.end(); ++it2)
	{
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

// test at
template <class T, class V>
std::vector<int> map_at_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 10; i < 700000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	start1 = timer();
	try
	{
		v.push_back(mp.at(400000));
		v.push_back(mp.at(400000 + 1));
	}
	catch (std::exception &e)
	{
		v.push_back(1);
	}
	end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> map_at_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 10; i < 700000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	start2 = timer();
	try
	{
		v.push_back(mp.at(400000));
		v.push_back(mp.at(400000 + 1));
	}
	catch (std::exception &e)
	{
		v.push_back(1);
	}
	end2 = timer();
	return v;
}

// test operator[]
template <class T, class V>
std::vector<int> map_operator_sq_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	mp.insert(std::make_pair(3, 3));
	typename std::map<T, V>::iterator it = mp.begin();
	start1 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	mp[3] = 10;
	v.push_back(it->first);
	v.push_back(it->second);
	mp[2] = 9;
	it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	it++;
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(mp.size());
	end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> map_operator_sq_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	mp.insert(ft::make_pair(3, 3));
	typename ft::map<T, V>::iterator it = mp.begin();
	start2 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	mp[3] = 10;
	v.push_back(it->first);
	v.push_back(it->second);
	mp[2] = 9;
	it = mp.begin();
	v.push_back(it->first);
	v.push_back(it->second);
	it++;
	v.push_back(it->first);
	v.push_back(it->second);
	v.push_back(mp.size());
	end2 = timer();
	return v;
}

// test empty
template <class T, class V>
std::vector<int> map_empty_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	start1 = timer();
	v.push_back(mp.empty());
	mp.insert(std::make_pair(3, 3));
	v.push_back(mp.empty());
	end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> map_empty_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	start2 = timer();
	v.push_back(mp.empty());
	mp.insert(ft::make_pair(3, 3));
	v.push_back(mp.empty());
	end2 = timer();
	return v;
}

// test size
template <class T, class V>
std::vector<int> map_size_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 1000000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	start1 = timer();
	v.push_back(mp.size());
	end1 = timer();
	for (int i = 0; i < 430000; ++i)
		mp.erase(i);
	v.push_back(mp.size());
	return v;
}

template <class T, class V>
std::vector<int> map_size_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 1000000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	start2 = timer();
	v.push_back(mp.size());
	end2 = timer();
	for (int i = 0; i < 430000; ++i)
		mp.erase(i);
	v.push_back(mp.size());
	return v;
}

// test max_size
template <class T, class V>
std::vector<int> map_max_size_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	start1 = timer();
	v.push_back((mp.size() * 0) + 1);
	end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> map_max_size_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	std::map<int, int> std_mp;
	start2 = timer();
	if ((std_mp.max_size() / 2) < mp.max_size())
		v.push_back(1);
	end2 = timer();
	return v;
}

// test clear
template <class T, class V>
std::vector<int> map_clear_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	mp.clear();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	v.push_back(mp.size());
	start1 = timer();
	mp.clear();
	end1 = timer();
	v.push_back(mp.size());
	typename std::map<T, V>::iterator it = mp.begin();
	if (it == mp.end())
		v.push_back(1);
	return v;
}

template <class T, class V>
std::vector<int> map_clear_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	mp.clear();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	v.push_back(mp.size());
	start2 = timer();
	mp.clear();
	end2 = timer();
	v.push_back(mp.size());
	typename ft::map<T, V>::iterator it = mp.begin();
	if (it == mp.end())
		v.push_back(1);
	return v;
}

// test erase key
template <class T, class V>
std::vector<int> map_erase_key_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	v.push_back(mp.erase(3));
	for (int i = 0, j = 0; i < 300000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(mp.erase(-5));
	v.push_back(mp.size());
	v.push_back(mp.erase(0));
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();
	start1 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4->first);
	end1 = timer();
	v.push_back(mp.erase(300000 - 1));
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	mp2.erase(2);
	mp2.erase(7);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3)
	{
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> map_erase_key_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	v.push_back(mp.erase(3));
	for (int i = 0, j = 0; i < 300000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	typename ft::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(mp.erase(-5));
	v.push_back(mp.size());
	v.push_back(mp.erase(0));
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename ft::map<T, V>::iterator it4 = mp.begin();
	start2 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4->first);
	end2 = timer();
	v.push_back(mp.erase(300000 - 1));
	v.push_back(mp.size());
	ft::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10; ++i, ++j)
		mp2.insert(ft::make_pair(i, j));
	mp2.erase(2);
	mp2.erase(7);
	typename ft::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3)
	{
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

// test erase position
template <class T, class V>
std::vector<int> map_erase_position_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 300000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	mp.erase(it);
	v.push_back(mp.size());
	it = mp.begin();
	mp.erase(++it);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();
	start1 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4);
	end1 = timer();
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator ittest = mp2.begin();
	for (int i = 0; i < 2; ++i)
		ittest++;
	mp2.erase(ittest);
	ittest = mp2.begin();
	for (int i = 0; i < 5; ++i)
		ittest++;
	mp2.erase(ittest);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3)
	{
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> map_erase_position_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 300000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	typename ft::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	mp.erase(it);
	v.push_back(mp.size());
	it = mp.begin();
	mp.erase(++it);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename ft::map<T, V>::iterator it4 = mp.begin();
	start2 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4);
	end2 = timer();
	v.push_back(mp.size());
	ft::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10; ++i, ++j)
		mp2.insert(ft::make_pair(i, j));
	typename ft::map<T, V>::iterator ittest = mp2.begin();
	for (int i = 0; i < 2; ++i)
		ittest++;
	mp2.erase(ittest);
	ittest = mp2.begin();
	for (int i = 0; i < 5; ++i)
		ittest++;
	mp2.erase(ittest);
	typename ft::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3)
	{
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

// test erase input iterator
template <class T, class V>
std::vector<int> map_erase_it_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(std::make_pair(i, j));

	start1 = timer();
	mp.erase(mp.begin(), --mp.end());
	end1 = timer();
	v.push_back(mp.begin()->first);
	return v;
}

template <class T, class V>
std::vector<int> map_erase_it_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));

	start2 = timer();
	mp.erase(mp.begin(), --mp.end());
	end2 = timer();
	v.push_back(mp.begin()->first);
	return v;
}

// test swap
template <class T, class V>
std::vector<int> map_swap_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	start1 = end1 = timer();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	std::map<T, V> mp2;
	for (int i = 250000, j = 0; i < 350000; ++i, --j)
		mp.insert(std::make_pair(i, j));
	long *adr1 = reinterpret_cast<long *>(&mp);
	long *adr2 = reinterpret_cast<long *>(&mp2);
	mp.swap(mp2);
	if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
		v.push_back(1);
	v.push_back(mp2.size());
	typename std::map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it)
	{
		v.push_back(it->first);
		v.push_back(it->second);
	}
	std::swap(mp, mp2);
	typename std::map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2)
	{
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> map_swap_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	start2 = end2 = timer();
	for (int i = 0, j = 0; i < 250000; ++i, ++j)
		mp.insert(ft::make_pair(i, j));
	ft::map<T, V> mp2;
	for (int i = 250000, j = 0; i < 350000; ++i, --j)
		mp.insert(ft::make_pair(i, j));
	long *adr1 = reinterpret_cast<long *>(&mp);
	long *adr2 = reinterpret_cast<long *>(&mp2);
	mp.swap(mp2);
	if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
		v.push_back(1);
	v.push_back(mp2.size());
	typename ft::map<T, V>::iterator it = mp2.begin();
	for (; it != mp2.end(); ++it)
	{
		v.push_back(it->first);
		v.push_back(it->second);
	}
	std::swap(mp, mp2);
	typename ft::map<T, V>::iterator it2 = mp2.begin();
	for (; it2 != mp2.end(); ++it2)
	{
		v.push_back(it2->first);
		v.push_back(it2->second);
	}
	return v;
}

// test count
template <class T, class V>
std::vector<int> map_count_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	start1 = end1 = timer();
	v.push_back(mp.count(0));
	mp.insert(std::make_pair(0, 0));
	v.push_back(mp.count(0));
	return v;
}

template <class T, class V>
std::vector<int> map_count_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	start2 = end2 = timer();
	v.push_back(mp.count(0));
	mp.insert(ft::make_pair(0, 0));
	v.push_back(mp.count(0));
	return v;
}

// test find
template <class T, class V>
std::vector<int> map_find_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	for (int i = -750000, j = 0; i < 750000; ++i, ++j)
	{
		mp.insert(std::make_pair(i, j));
	}
	start1 = timer();
	typename std::map<T, V>::iterator it = mp.find(340000);
	end1 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-340000);
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-750000);
	if (it == mp.end())
		v.push_back(1);
	return v;
}

template <class T, class V>
std::vector<int> map_find_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	for (int i = -750000, j = 0; i < 750000; ++i, ++j)
	{
		mp.insert(ft::make_pair(i, j));
	}
	start2 = timer();
	typename ft::map<T, V>::iterator it = mp.find(340000);
	end2 = timer();
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-340000);
	v.push_back(it->first);
	v.push_back(it->second);
	it = mp.find(-750000);
	if (it == mp.end())
		v.push_back(1);
	return v;
}

// test lower_bound
template <class T, class V>
std::vector<int> map_lower_bound_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	std::map<int, int, std::greater<int> > mp2;
	mp.insert(std::make_pair(10, 10));
	mp2.insert(std::make_pair(10, 10));
	if (mp.lower_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.lower_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	mp2.insert(std::make_pair(20, 20));
	mp2.insert(std::make_pair(30, 30));
	mp2.insert(std::make_pair(40, 40));
	mp2.insert(std::make_pair(50, 50));
	mp2.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = mp.lower_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = mp2.lower_bound(i);
		v.push_back(it->first);
	}
	std::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp3.insert(std::make_pair(i, j));
	}
	start1 = timer();
	mp3.lower_bound(490000);
	end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> map_lower_bound_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	ft::map<int, int, std::greater<int> > mp2;
	mp.insert(ft::make_pair(10, 10));
	mp2.insert(ft::make_pair(10, 10));
	if (mp.lower_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.lower_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(ft::make_pair(20, 20));
	mp.insert(ft::make_pair(30, 30));
	mp.insert(ft::make_pair(40, 40));
	mp.insert(ft::make_pair(50, 50));
	mp.insert(ft::make_pair(60, 60));
	mp2.insert(ft::make_pair(20, 20));
	mp2.insert(ft::make_pair(30, 30));
	mp2.insert(ft::make_pair(40, 40));
	mp2.insert(ft::make_pair(50, 50));
	mp2.insert(ft::make_pair(60, 60));
	ft::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = mp.lower_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = mp2.lower_bound(i);
		v.push_back(it->first);
	}
	ft::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp3.insert(ft::make_pair(i, j));
	}
	start2 = timer();
	mp3.lower_bound(490000);
	end2 = timer();
	return v;
}

// test upper_bound
template <class T, class V>
std::vector<int> map_upper_bound_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	std::map<int, int, std::greater<int> > mp2;
	mp.insert(std::make_pair(10, 10));
	mp2.insert(std::make_pair(10, 10));
	if (mp.upper_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.upper_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	mp2.insert(std::make_pair(20, 20));
	mp2.insert(std::make_pair(30, 30));
	mp2.insert(std::make_pair(40, 40));
	mp2.insert(std::make_pair(50, 50));
	mp2.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = mp.upper_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = mp2.upper_bound(i);
		v.push_back(it->first);
	}
	std::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp3.insert(std::make_pair(i, j));
	}
	std::map<int, int> mp4;
	mp.insert(std::make_pair(-10, 10));
	mp.insert(std::make_pair(-20, 20));
	v.push_back((--mp.upper_bound(0))->first);
	start1 = timer();
	mp3.upper_bound(490000);
	end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> map_upper_bound_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	ft::map<int, int, std::greater<int> > mp2;
	mp.insert(ft::make_pair(10, 10));
	mp2.insert(ft::make_pair(10, 10));
	if (mp.upper_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.upper_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(ft::make_pair(20, 20));
	mp.insert(ft::make_pair(30, 30));
	mp.insert(ft::make_pair(40, 40));
	mp.insert(ft::make_pair(50, 50));
	mp.insert(ft::make_pair(60, 60));
	mp2.insert(ft::make_pair(20, 20));
	mp2.insert(ft::make_pair(30, 30));
	mp2.insert(ft::make_pair(40, 40));
	mp2.insert(ft::make_pair(50, 50));
	mp2.insert(ft::make_pair(60, 60));
	ft::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10)
	{
		it = mp.upper_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10)
	{
		it = mp2.upper_bound(i);
		v.push_back(it->first);
	}
	ft::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j)
	{
		mp3.insert(ft::make_pair(i, j));
	}
	ft::map<int, int> mp4;
	mp.insert(ft::make_pair(-10, 10));
	mp.insert(ft::make_pair(-20, 20));
	v.push_back((--mp.upper_bound(0))->first);
	start2 = timer();
	mp3.upper_bound(490000);
	end2 = timer();
	return v;
}

// test equal_range
template <class T, class V>
std::vector<int> map_equal_range_test_std()
{
	std::map<T, V> mp;
	std::vector<int> v;
	mp.insert(std::make_pair(10, 10));
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	start1 = timer();
	const std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator> &pair = mp.equal_range(10);
	const std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator> &pair2 = mp.equal_range(11);
	const std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator> &pair3 = mp.equal_range(1);
	end1 = timer();
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second->first);
	v.push_back(pair.second->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second->first);
	v.push_back(pair2.second->second);
	v.push_back(pair3.first->first);
	v.push_back(pair3.first->second);
	v.push_back(pair3.second->first);
	v.push_back(pair3.second->second);
	return v;
}

template <class T, class V>
std::vector<int> map_equal_range_test_ft()
{
	ft::map<T, V> mp;
	std::vector<int> v;
	mp.insert(ft::make_pair(10, 10));
	mp.insert(ft::make_pair(20, 20));
	mp.insert(ft::make_pair(30, 30));
	mp.insert(ft::make_pair(40, 40));
	mp.insert(ft::make_pair(50, 50));
	mp.insert(ft::make_pair(60, 60));
	start2 = timer();
	const ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> &pair = mp.equal_range(10);
	const ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> &pair2 = mp.equal_range(11);
	const ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> &pair3 = mp.equal_range(1);
	end2 = timer();
	v.push_back(pair.first->first);
	v.push_back(pair.first->second);
	v.push_back(pair.second->first);
	v.push_back(pair.second->second);
	v.push_back(pair2.first->first);
	v.push_back(pair2.first->second);
	v.push_back(pair2.second->first);
	v.push_back(pair2.second->second);
	v.push_back(pair3.first->first);
	v.push_back(pair3.first->second);
	v.push_back(pair3.second->first);
	v.push_back(pair3.second->second);
	return v;
}

// test key_comp
template <class T, class V>
std::vector<int> map_key_comp_test_std()
{
	std::map<T, V> mp;

	std::vector<int> v;
	start1 = end1 = timer();
	std::map<int, int, std::greater<int> > mp2;
	std::map<int, int, std::equal_to<int> > mp3;
	v.push_back(mp.key_comp()(1, 2));
	v.push_back(mp2.key_comp()(1, 2));
	v.push_back(mp3.key_comp()(1, 2));
	return v;
}

template <class T, class V>
std::vector<int> map_key_comp_test_ft()
{
	ft::map<T, V> mp;

	std::vector<int> v;
	start2 = end2 = timer();
	ft::map<int, int, std::greater<int> > mp2;
	ft::map<int, int, std::equal_to<int> > mp3;
	v.push_back(mp.key_comp()(1, 2));
	v.push_back(mp2.key_comp()(1, 2));
	v.push_back(mp3.key_comp()(1, 2));
	return v;
}

// test operator ==
bool map_equal_test();

// test operator !=
bool map_not_equal_test();

// test operator <
bool map_less_than_test();

// test operator >
bool map_more_than_test();

// test operator <=
bool map_less_or_equal_test();

// test operator >=
bool map_more_or_equal_test();

#pragma endregion

#endif
