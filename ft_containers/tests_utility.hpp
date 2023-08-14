#ifndef TEST_UTILITY_HPP
#define TEST_UTILITY_HPP

#include "tests.hpp"

#pragma region Utilities

bool enable_if_test();

// test is_integral
bool is_integral_test();

// test iterator_traits
bool iterator_traits_test();

// test equal
template <class InputIterator1, class InputIterator2>
bool equal_test()
{
	std::string s = "approvjvorppa";
	bool res = 0;
	bool res2 = 0;
	bool (*pred)(InputIterator1, InputIterator2) = &comp_iter;
	start1 = timer();
	if (std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()) == 1
		&& std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin(), pred) == 1)
		res = 1;
	end1 = timer();
	start2 = timer();
	if (ft::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()) == 1
		&& ft::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin(), pred) == 1)
		res2 = 1;
	end2 = timer();
	return res && res2;
}

// test lexicographical_compare
template <class InputIterator1, class InputIterator2>
bool lexicographical_test()
{
	std::vector<int> result, result2;
	std::vector<char> v1, v2;
	std::vector<char> b1, b2;
	bool (*pred)(InputIterator1, InputIterator2) = &comp_iter;
	v1.assign(50000000, 'f');
	v1.push_back('e');
	v2.assign(50000000, 'f');
	v2.push_back('e');
	b1.assign(50000000, 'f');
	b1.push_back('e');
	b2.assign(50000000, 'f');
	b2.push_back('e');
	start1 = timer();
	result.push_back(std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
	result.push_back(std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), pred));
	end1 = timer();
	start2 = timer();
	result2.push_back(ft::lexicographical_compare(b1.begin(), b1.end(), b2.begin(), b2.end()));
	result2.push_back(ft::lexicographical_compare(b1.begin(), b1.end(), b2.begin(), b2.end(), pred));
	end2 = timer();
	return result == result2;
}

#pragma endregion

#endif
