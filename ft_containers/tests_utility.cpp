#include "tests.hpp"

#pragma region Utilities

bool enable_if_test()
{
	std::vector<int> v;
	bool res = 1;
	unsigned int xx = 5;
	int x = 5;
	foo(xx);
	foo(x);
	if (start1 != -20 && start2 != -20)
		res = 0;
	return res;
}

// test is_integral
bool is_integral_test()
{
	std::vector<int> v;
	bool res = 1;
	(ft::is_integral<float>() == std::is_integral<float>()) ? 0 : res = 0;
	(ft::is_integral<int>() == std::is_integral<int>()) ? 0 : res = 0;
	(ft::is_integral<bool>() == std::is_integral<bool>()) ? 0 : res = 0;
	(ft::is_integral<char>() == std::is_integral<char>()) ? 0 : res = 0;
	(ft::is_integral<signed char>() == std::is_integral<signed char>()) ? 0 : res = 0;
	(ft::is_integral<unsigned char>() == std::is_integral<unsigned char>()) ? 0 : res = 0;
	(ft::is_integral<wchar_t>() == std::is_integral<wchar_t>()) ? 0 : res = 0;
	(ft::is_integral<char16_t>() == std::is_integral<char16_t>()) ? 0 : res = 0;
	(ft::is_integral<short>() == std::is_integral<short>()) ? 0 : res = 0;
	(ft::is_integral<unsigned short>() == std::is_integral<unsigned short>()) ? 0 : res = 0;
	(ft::is_integral<unsigned int>() == std::is_integral<unsigned int>()) ? 0 : res = 0;
	(ft::is_integral<long>() == std::is_integral<long>()) ? 0 : res = 0;
	(ft::is_integral<unsigned long>() == std::is_integral<unsigned long>()) ? 0 : res = 0;
	(ft::is_integral<long long>() == std::is_integral<long long>()) ? 0 : res = 0;
	(ft::is_integral<unsigned long long>() == std::is_integral<unsigned long long>()) ? 0 : res = 0;
	return res;
}

// test iterator_traits
bool iterator_traits_test()
{
	std::vector<std::string> res;
	std::vector<std::string> res2;
	start1 = end1 = start2 = end2 = timer();

	res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::iterator::reference).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());

	res2.push_back(typeid(ft::vector<int>::iterator::iterator_category).name());
	res2.push_back(typeid(ft::vector<int>::iterator::value_type).name());
	res2.push_back(typeid(ft::vector<int>::iterator::difference_type).name());
	res2.push_back(typeid(ft::vector<int>::iterator::iterator_type).name());
	res2.push_back(typeid(ft::vector<int>::iterator::pointer).name());
	res2.push_back(typeid(ft::vector<int>::iterator::reference).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::iterator_category).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::value_type).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::difference_type).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::pointer).name());
	res2.push_back(typeid(ft::vector<int>::reverse_iterator::reference).name());

	return res == res2;
}

#pragma endregion
