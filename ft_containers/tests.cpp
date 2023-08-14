#include "tests.hpp"

time_t start1, start2, end1, end2 = 0;

time_t timer()
{
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

void print_green_result(std::string s)
{
	s = std::string("\x1B[1;32m") + s + std::string("\033[0m");
	std::cout << std::left << std::setw(30) << std::setfill(' ') << s;
}

void print_red_result(std::string s)
{
	s = std::string("\x1B[1;31m") + s + std::string("\033[0m");
	std::cout << std::left << std::setw(30) << std::setfill(' ') << s;
}

int run_unit_test(std::string test_name, std::vector<int>(func1)(), std::vector<int>(func2)())
{
	int result;
	time_t t1;
	time_t t2;
	std::vector<int> res1;
	std::vector<int> res2;

	std::cout << std::left << std::setw(30) << std::setfill(' ') << test_name;
	res1 = func1();
	res2 = func2();
	if (res1 == res2)
	{
		print_green_result(std::string("OK"));
		result = 0;
	}
	else
	{
		print_red_result("FAILED");
		result = 1;
	}
	t1 = end1 - start1, t2 = end2 - start2;
	(t1 >= t2 / 20) ? print_green_result(std::to_string(t2) + "ms") : print_green_result(std::to_string(t2) + "ms");
	(t1 > t2 / 20) ? print_red_result(std::to_string(t1) + "ms") : print_red_result(std::to_string(t1) + "ms");
	std::cout << std::endl;

	return !result;
}

int run_bool_unit_test(std::string test_name, bool(func1)())
{
	int ret = 0;
	time_t t1;
	time_t t2;
	bool res;

	start1 = start2 = end1 = end2 = 0;
	std::cout << std::left << std::setw(30) << std::setfill(' ') << test_name;
	res = func1();
	if (res)
	{
		print_green_result(std::string("OK"));
		ret = 0;
	}
	else
	{
		print_red_result(std::string("FAILED"));
		ret = 1;
	}
	t1 = end1 - start1, t2 = end2 - start2;
	(t1 >= t2 / 20) ? print_green_result(std::to_string(t2) + "ms") : print_red_result(std::to_string(t2) + "ms");
	(t1 >= t2 / 20) ? print_red_result(std::to_string(t1) + "ms") : print_green_result(std::to_string(t1) + "ms");
	std::cout << std::endl;

	return ret;
}

B::B(const int &ex)
{
	this->i = ex;
	this->l = new char('a');
};
B::~B()
{
	delete this->l;
	this->l = nullptr;
};

A::A(const B *ex)
{
	this->l = new char(*(ex->l));
	this->i = ex->i;
	if (ex->i == -1)
		throw "n";
}
A::~A()
{
	delete this->l;
	this->l = nullptr;
};

StackBoolTest::StackBoolTest()
{
	s1.push(2);
	st1.push(2);
	s2.push(3);
	st2.push(3);
	s3.push(3);
	st3.push(3);
	s4.push(4);
	st4.push(4);
	s4.push(4);
	st4.push(4);
	s5.push("122");
	st5.push("122");
	s6.push("123");
	st6.push("123");
	s7.push("124");
	st7.push("124");
	s8.push("12");
	st8.push("12");
	s9.push("123");
	st9.push("123");
};

MapBoolTest::MapBoolTest()
{
	m1.insert(std::make_pair(2, 3));
	mp1.insert(ft::make_pair(2, 3));
	m2.insert(std::make_pair(3, 3));
	mp2.insert(ft::make_pair(3, 3));
	m3.insert(std::make_pair(3, 4));
	mp3.insert(ft::make_pair(3, 4));
	m4.insert(std::make_pair(4, 4));
	mp4.insert(ft::make_pair(4, 4));
	m4.insert(std::make_pair(4, 5));
	mp4.insert(ft::make_pair(4, 5));
	m5.insert(std::make_pair("123", "123"));
	mp5.insert(ft::make_pair("123", "123"));
	m6.insert(std::make_pair("123", "124"));
	mp6.insert(ft::make_pair("123", "124"));
	m7.insert(std::make_pair("124", "123"));
	mp7.insert(ft::make_pair("124", "123"));
	m8.insert(std::make_pair("12", "123"));
	mp8.insert(ft::make_pair("12", "123"));
	m9.insert(std::make_pair("123", "12"));
	mp9.insert(ft::make_pair("123", "12"));
}

SetBoolTest::SetBoolTest()
{
	s1.insert(2);
	st1.insert(2);
	s2.insert(3);
	st2.insert(3);
	s3.insert(3);
	st3.insert(3);
	s4.insert(4);
	st4.insert(4);
	s4.insert(4);
	st4.insert(4);
	s5.insert("122");
	st5.insert("122");
	s6.insert("123");
	st6.insert("123");
	s7.insert("124");
	st7.insert("124");
	s8.insert("12");
	st8.insert("12");
	s9.insert("123");
	st9.insert("123");
}
