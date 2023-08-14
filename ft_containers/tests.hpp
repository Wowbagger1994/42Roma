#ifndef TEST_HPP
#define TEST_HPP

#include <vector>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <string>
#include "utility.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "set.hpp"
#include "pair.hpp"

extern time_t start1, start2, end1, end2;

time_t timer();

void print_green_result(std::string s);

void print_red_result(std::string s);

int run_unit_test(std::string test_name, std::vector<int>(func1)(), std::vector<int>(func2)());

int run_bool_unit_test(std::string test_name, bool(func1)());

template <class T>
typename ft::enable_if< std::is_unsigned<T>::value >::type foo(T) {
	start1 = -20;
}

template <class T>
typename ft::enable_if< std::is_signed<T>::value >::type foo(T) {
	start2 = -20;
}

template <class InputIterator1, class InputIterator2>
bool comp_iter(InputIterator1 it1, InputIterator2 it2) { return it1 == it2; }

class B
{
public:
	char *l;
	int i;
	B() : l(nullptr), i(1){};
	B(const int &ex);
	virtual ~B();
};

class A : public B
{
public:
	A() : B(){};
	A(const B *ex);
	~A();
};

class StackBoolTest
{
public:
	std::stack<int> s1, s2, s3, s4;
	std::stack<std::string> s5, s6, s7, s8, s9;
	ft::stack<int> st1, st2, st3, st4;
	ft::stack<std::string> st5, st6, st7, st8, st9;

	StackBoolTest();
};

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp)
{
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

template <class T, class V, class C>
void fillMap(ft::map<T, V, C> &mp)
{
	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
}

class MapBoolTest
{
public:
	std::map<int, int> m1, m2, m3, m4;
	std::map<std::string, std::string> m5, m6, m7, m8, m9;
	ft::map<int, int> mp1, mp2, mp3, mp4;
	ft::map<std::string, std::string> mp5, mp6, mp7, mp8, mp9;

	MapBoolTest();
};

template <class T, class C>
void fillSet(std::set<T, C> &mp)
{
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	mp.insert(19);
	mp.insert(29);
	mp.insert(41);
	mp.insert(4);
	mp.insert(11);
}

template <class T, class C>
void fillSet(ft::set<T, C> &mp)
{
	mp.insert(16);
	mp.insert(8);
	mp.insert(23);
	mp.insert(7);
	mp.insert(19);
	mp.insert(29);
	mp.insert(41);
	mp.insert(4);
	mp.insert(11);
}

class SetBoolTest
{
public:
	std::set<int> s1, s2, s3, s4;
	std::set<std::string> s5, s6, s7, s8, s9;
	ft::set<int> st1, st2, st3, st4;
	ft::set<std::string> st5, st6, st7, st8, st9;

	SetBoolTest();
};

# endif
