#include "tests_vector.hpp"

#pragma region Vector

// test operator ==
bool vector_operator_equal_test()
{
	start2 = timer();
	end2 = timer();
	start1 = timer();
	end1 = timer();
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 == v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 == v_int2);
	result.push_back(v_int1 == v_int3);
	result.push_back(v_str1 == v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 == V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 == V_int2);
	result_2.push_back(V_int1 == V_int3);
	result_2.push_back(V_str1 == V_str2);
	return result == result_2;
}

// test operator !=
bool vector_operator_not_equal_test()
{
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 != v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 != v_int2);
	result.push_back(v_int1 != v_int3);
	result.push_back(v_str1 != v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 != V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 != V_int2);
	result_2.push_back(V_int1 != V_int3);
	result_2.push_back(V_str1 != V_str2);
	return result == result_2;
}

// test operator <
bool vector_operator_less_test()
{
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 < v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 < v_int2);
	result.push_back(v_int1 < v_int3);
	result.push_back(v_str1 < v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 < V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 < V_int2);
	result_2.push_back(V_int1 < V_int3);
	result_2.push_back(V_str1 < V_str2);
	return result == result_2;
}

// test operator >
bool vector_operator_more_test()
{
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 > v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 > v_int2);
	result.push_back(v_int1 > v_int3);
	result.push_back(v_str1 > v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 > V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 > V_int2);
	result_2.push_back(V_int1 > V_int3);
	result_2.push_back(V_str1 > V_str2);
	return result == result_2;
}

// test operator <=
bool vector_operator_less_equal_test()
{
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 <= v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 <= v_int2);
	result.push_back(v_int1 <= v_int3);
	result.push_back(v_str1 <= v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 <= V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 <= V_int2);
	result_2.push_back(V_int1 <= V_int3);
	result_2.push_back(V_str1 <= V_str2);
	return result == result_2;
}

// test operator >=
bool vector_operator_more_equal_test()
{
	std::vector<int> result, result_2;
	std::vector<int> v_int1, v_int2, v_int3;
	std::vector<std::string> v_str1, v_str2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2;
	v_int1.push_back(1);
	v_int3.push_back(1);
	v_str1.push_back("aa");
	v_str2.push_back("ab");
	result.push_back(v_int1 >= v_int2);
	v_int2.push_back(2);
	result.push_back(v_int1 >= v_int2);
	result.push_back(v_int1 >= v_int3);
	result.push_back(v_str1 >= v_str2);
	V_int1.push_back(1);
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	result_2.push_back(V_int1 >= V_int2);
	V_int2.push_back(2);
	result_2.push_back(V_int1 >= V_int2);
	result_2.push_back(V_int1 >= V_int3);
	result_2.push_back(V_str1 >= V_str2);
	return result == result_2;
}

#pragma endregion
