#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

#include "tests.hpp"

#pragma region Stackmap

// test construct
template <class T>
std::vector<int> stack_constructor_test_std()
{
	std::stack<T> stk;
	std::vector<int> v;
	std::deque<int> deque;
	for (int i = 0; i < 1000000; ++i)
		deque.push_back(i);
	for (int i = 1000000; i < 2000000; ++i)
		stk.push(i);
	start1 = timer();
	std::stack<int> stack(deque);
	std::stack<int> stack2(stk);
	std::stack<int> stack3;
	stack3 = stack2;
	end1 = timer();
	while (stack.size() > 0)
	{
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0)
	{
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

template <class T>
std::vector<int> stack_constructor_test_ft()
{
	ft::stack<T> stk;
	std::vector<int> v;
	ft::vector<int> deque;
	for (int i = 0; i < 1000000; ++i)
		deque.push_back(i);
	for (int i = 1000000; i < 2000000; ++i)
		stk.push(i);
	start2 = timer();
	ft::stack<int> stack(deque);
	ft::stack<int> stack2(stk);
	ft::stack<int> stack3;
	stack3 = stack2;
	end2 = timer();
	while (stack.size() > 0)
	{
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0)
	{
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

// test push
template <class T>
std::vector<int> stack_push_test_std()
{
	std::stack<T> stk;
	std::vector<int> v;
	start1 = timer();
	for (int i = 0; i < 8000000; ++i)
		stk.push(i);
	end1 = timer();
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> stack_push_test_ft()
{
	ft::stack<T> stk;
	std::vector<int> v;
	start2 = timer();
	for (int i = 0; i < 8000000; ++i)
		stk.push(i);
	end2 = timer();
	v.push_back(stk.size());
	return v;
}

// test top
template <class T>
std::vector<int> stack_top_test_std()
{
	std::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	start1 = timer();
	v.push_back(stk.top());
	end1 = timer();
	stk.pop();
	v.push_back(stk.top());
	stk.push(7);
	v.push_back(stk.top());
	return v;
}

template <class T>
std::vector<int> stack_top_test_ft()
{
	ft::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	start2 = timer();
	v.push_back(stk.top());
	end2 = timer();
	stk.pop();
	v.push_back(stk.top());
	stk.push(7);
	v.push_back(stk.top());
	return v;
}

// test pop
template <class T>
std::vector<int> stack_pop_test_std()
{
	std::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	start1 = timer();
	while (stk.size() > 0)
		stk.pop();
	end1 = timer();
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> stack_pop_test_ft()
{
	ft::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	start2 = timer();
	while (stk.size() > 0)
		stk.pop();
	end2 = timer();
	v.push_back(stk.size());
	return v;
}

// test size
template <class T>
std::vector<int> stack_size_test_std()
{
	std::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	start1 = timer();
	v.push_back(stk.size());
	end1 = timer();
	stk.pop();
	v.push_back(stk.size());
	stk.push(7);
	v.push_back(stk.size());
	return v;
}

template <class T>
std::vector<int> stack_size_test_ft()
{
	ft::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	start2 = timer();
	v.push_back(stk.size());
	end2 = timer();
	stk.pop();
	v.push_back(stk.size());
	stk.push(7);
	v.push_back(stk.size());
	return v;
}

// test empty
template <class T>
std::vector<int> stack_empty_test_std()
{
	std::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	v.push_back(stk.empty());
	while (stk.size() > 0)
		stk.pop();
	start1 = timer();
	v.push_back(stk.empty());
	end1 = timer();
	return v;
}

template <class T>
std::vector<int> stack_empty_test_ft()
{
	ft::stack<T> stk;
	std::vector<int> v;
	for (int i = 0; i < 2000000; ++i)
		stk.push(i);
	v.push_back(stk.empty());
	while (stk.size() > 0)
		stk.pop();
	start2 = timer();
	v.push_back(stk.empty());
	end2 = timer();
	return v;
}

// test operator ==
bool stack_stack_equal_test();

// test operator !=
bool stack_stack_not_equal_test();

// test operator <
bool stack_stack_less_than_test();

// test operator >
bool stack_stack_more_than_test();

// test operator <=
bool stack_less_or_equal_test();

// test operator >=
bool stack_more_or_equal_test();

#pragma endregion

#endif
