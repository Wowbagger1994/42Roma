#include "tests_utility.hpp"
#include "tests_vector.hpp"
#include "tests_stack.hpp"
#include "tests_map.hpp"
#include "tests_set.hpp"

int main()
{

	std::cout << "\x1B[1;32m @@@@@@@  @@@@@@@@   @@@@@@   @@@@@@@     @@@  @@@  @@@@@@@  @@@  @@@       @@@  @@@@@@@  @@@  @@@@@@@@   @@@@@@ " << std::endl;
	std::cout << " @@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@     @@@  @@@  @@@@@@@  @@@  @@@       @@@  @@@@@@@  @@@  @@@@@@@@  @@@@@@@ " << std::endl;
	std::cout << "   @@!    @@!       !@@         @@!       @@!  @@@    @@!    @@!  @@!       @@!    @@!    @@!  @@!       !@@     " << std::endl;
	std::cout << "   !@!    !@!       !@!         !@!       !@!  @!@    !@!    !@!  !@!       !@!    !@!    !@!  !@!       !@!     " << std::endl;
	std::cout << "   @!!    @!!!:!    !!@@!!      @!!       @!@  !@!    @!!    !!@  @!!       !!@    @!!    !!@  @!!!:!    !!@@!!  " << std::endl;
	std::cout << "   !!!    !!!!!:     !!@!!!     !!!       !@!  !!!    !!!    !!!  !!!       !!!    !!!    !!!  !!!!!:     !!@!!! " << std::endl;
	std::cout << "   !!:    !!:            !:!    !!:       !!:  !!!    !!:    !!:  !!:       !!:    !!:    !!:  !!:            !:!" << std::endl;
	std::cout << "   :!:    :!:           !:!     :!:       :!:  !:!    :!:    :!:   :!:      :!:    :!:    :!:  :!:           !:! " << std::endl;
	std::cout << "    ::     :: ::::  :::: ::      ::       ::::: ::     ::     ::   :: ::::   ::     ::     ::   :: ::::  :::: :: " << std::endl;
	std::cout << "    :     : :: ::   :: : :       :         : :  :      :     :    : :: : :  :       :     :    : :: ::   :: : :  \033[0m" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << std::endl;

	run_bool_unit_test("enable_if()", &enable_if_test);
	run_bool_unit_test("is_integral()", &is_integral_test);
	run_bool_unit_test("iterator_traits", &iterator_traits_test);
	run_bool_unit_test("equal()", &equal_test<char, char>);
	run_bool_unit_test("lexicographical_compare()", &lexicographical_test<char, char>);

	std::cout << std::endl
			  << std::endl
			  << std::endl;
	std::cout << "\x1B[1;32m @@@@@@@  @@@@@@@@   @@@@@@   @@@@@@@     @@@  @@@  @@@@@@@@   @@@@@@@  @@@@@@@   @@@@@@   @@@@@@@ " << std::endl;
	std::cout << " @@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@     @@@  @@@  @@@@@@@@  @@@@@@@@  @@@@@@@  @@@@@@@@  @@@@@@@@ " << std::endl;
	std::cout << "   @@!    @@!       !@@         @@!       @@!  @@@  @@!       !@@         @@!    @@!  @@@  @@!  @@@ " << std::endl;
	std::cout << "   !@!    !@!       !@!         !@!       !@!  @!@  !@!       !@!         !@!    !@!  @!@  !@!  @!@ " << std::endl;
	std::cout << "   @!!    @!!!:!    !!@@!!      @!!       @!@  !@!  @!!!:!    !@!         @!!    @!@  !@!  @!@!!@!  " << std::endl;
	std::cout << "   !!!    !!!!!:     !!@!!!     !!!       !@!  !!!  !!!!!:    !!!         !!!    !@!  !!!  !!@!@!   " << std::endl;
	std::cout << "   !!:    !!:            !:!    !!:       :!:  !!:  !!:       :!!         !!:    !!:  !!!  !!: :!!  " << std::endl;
	std::cout << "   :!:    :!:           !:!     :!:        ::!!:!   :!:       :!:         :!:    :!:  !:!  :!:  !:! " << std::endl;
	std::cout << "    ::     :: ::::  :::: ::      ::         ::::     :: ::::   ::: :::     ::    ::::: ::  ::   ::: " << std::endl;
	std::cout << "    :     : :: ::   :: : :       :           :      : :: ::    :: :: :     :      : :  :    :   : : \033[0m" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << std::endl;

	run_unit_test("constructor", &vector_constructor_test_std<int>, &vector_constructor_test_ft<int>);
	run_unit_test("constructor input iterator", &vector_constructor_it_test_std<int>, &vector_constructor_it_test_ft<int>);
	run_unit_test("iterator", &vector_iterator_test_std<int>, &vector_iterator_test_ft<int>);
	run_unit_test("begin()", &vector_begin_test_std<int>, &vector_begin_test_ft<int>);
	run_unit_test("end()", &vector_end_test_std<int>, &vector_end_test_ft<int>);
	run_unit_test("rbegin()", &vector_rbegin_test_std<int>, &vector_rbegin_test_ft<int>);
	run_unit_test("rend()", &vector_rend_test_std<int>, &vector_rend_test_ft<int>);
	run_unit_test("size()", &vector_size_test_std<int>, &vector_size_test_ft<int>);
	run_unit_test("max_size()", &vector_maxsize_test_std<int>, &vector_maxsize_test_ft<int>);
	run_unit_test("resize()", &vector_resize_test_std<int>, &vector_resize_test_ft<int>);
	run_unit_test("capacity()", &vector_capacity_test_std<int>, &vector_capacity_test_ft<int>);
	run_unit_test("empty()", &vector_empty_test_std<int>, &vector_empty_test_ft<int>);
	run_unit_test("reserve()", &vector_reserve_test_std<int>, &vector_reserve_test_ft<int>);
	run_unit_test("operator []", &vector_operator_assign_test_std<int>, &vector_operator_assign_test_ft<int>);
	run_unit_test("at()", &vector_at_test_std<int>, &vector_at_test_ft<int>);
	run_unit_test("front()", &vector_front_test_std<int>, &vector_front_test_ft<int>);
	run_unit_test("back()", &vector_back_test_std<int>, &vector_back_test_ft<int>);
	run_unit_test("assign()", &vector_assign_test_std<int>, &vector_assign_test_ft<int>);
	run_unit_test("assign() iterator", &vector_assign_it_test_std<int>, &vector_assign_it_test_ft<int>);
	run_unit_test("push_back()", &vector_push_back_test_std<int>, &vector_push_back_test_ft<int>);
	run_unit_test("pop_back()", &vector_pop_back_test_std<int>, &vector_pop_back_test_ft<int>);
	run_unit_test("insert(value)", &vector_insert_value_test_std<int>, &vector_insert_value_test_ft<int>);
	run_unit_test("insert(fill)", &vector_insert_fill_test_std<int>, &vector_insert_fill_test_ft<int>);
	run_unit_test("insert(range)", &vector_insert_range_test_std<int>, &vector_insert_range_test_ft<int>);
	run_unit_test("insert(iterator)", &vector_insert_it_test_std<int>, &vector_insert_it_test_ft<int>);
	run_unit_test("erase(value)", &vector_erase_value_test_std<int>, &vector_erase_value_test_ft<int>);
	run_unit_test("erase(range)", &vector_erase_range_test_std<int>, &vector_erase_range_test_ft<int>);
	run_unit_test("swap()", &vector_swap_test_std<int>, &vector_swap_test_ft<int>);
	run_unit_test("clear()", &vector_clear_test_std<int>, &vector_clear_test_ft<int>);
	run_bool_unit_test("operator ==", &vector_operator_equal_test);
	run_bool_unit_test("operator !=", &vector_operator_not_equal_test);
	run_bool_unit_test("operator <", &vector_operator_less_test);
	run_bool_unit_test("operator >", &vector_operator_more_test);
	run_bool_unit_test("operator <=", &vector_operator_less_equal_test);
	run_bool_unit_test("operator >=", &vector_operator_more_equal_test);

	std::cout << std::endl
			  << std::endl
			  << std::endl;
	std::cout << "\x1B[1;32m @@@@@@@  @@@@@@@@   @@@@@@   @@@@@@@      @@@@@@   @@@@@@@   @@@@@@    @@@@@@@  @@@  @@@ " << std::endl;
	std::cout << " @@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@     @@@@@@@   @@@@@@@  @@@@@@@@  @@@@@@@@  @@@  @@@ " << std::endl;
	std::cout << "   @@!    @@!       !@@         @@!       !@@         @@!    @@!  @@@  !@@       @@!  !@@ " << std::endl;
	std::cout << "   !@!    !@!       !@!         !@!       !@!         !@!    !@!  @!@  !@!       !@!  @!! " << std::endl;
	std::cout << "   @!!    @!!!:!    !!@@!!      @!!       !!@@!!      @!!    @!@!@!@!  !@!       @!@@!@!  " << std::endl;
	std::cout << "   !!!    !!!!!:     !!@!!!     !!!        !!@!!!     !!!    !!!@!!!!  !!!       !!@!!!   " << std::endl;
	std::cout << "   !!:    !!:            !:!    !!:            !:!    !!:    !!:  !!!  :!!       !!: :!!  " << std::endl;
	std::cout << "   :!:    :!:           !:!     :!:           !:!     :!:    :!:  !:!  :!:       :!:  !:! " << std::endl;
	std::cout << "    ::     :: ::::  :::: ::      ::       :::: ::      ::    ::   :::   ::: :::   ::  ::: " << std::endl;
	std::cout << "    :     : :: ::   :: : :       :        :: : :       :      :   : :   :: :: :   :   ::: \033[0m" << std::endl;
		std::cout << std::endl
			  << std::endl
			  << std::endl;

	run_unit_test("constructor", &stack_constructor_test_std<int>, &stack_constructor_test_ft<int>);
	run_unit_test("push()", &stack_push_test_std<int>, &stack_push_test_ft<int>);
	run_unit_test("top()", &stack_top_test_std<int>, &stack_top_test_ft<int>);
	run_unit_test("pop()", &stack_pop_test_std<int>, &stack_pop_test_ft<int>);
	run_unit_test("size()", &stack_size_test_std<int>, &stack_size_test_ft<int>);
	run_unit_test("empty()", &stack_empty_test_std<int>, &stack_empty_test_ft<int>);
	run_bool_unit_test("operator ==", &stack_stack_equal_test);
	run_bool_unit_test("operator !=", &stack_stack_not_equal_test);
	run_bool_unit_test("operator <", &stack_stack_less_than_test);
	run_bool_unit_test("operator >", &stack_stack_more_than_test);
	run_bool_unit_test("operator <=", &stack_less_or_equal_test);
	run_bool_unit_test("operator >=", &stack_more_or_equal_test);

std::cout << std::endl
			  << std::endl
			  << std::endl;
std::cout << "\x1B[1;32m @@@@@@@  @@@@@@@@   @@@@@@   @@@@@@@     @@@@@@@@@@    @@@@@@   @@@@@@@ " << std::endl;
std::cout << " @@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@     @@@@@@@@@@@  @@@@@@@@  @@@@@@@@  " << std::endl;
std::cout << "   @@!    @@!       !@@         @@!       @@! @@! @@!  @@!  @@@  @@!  @@@  " << std::endl;
std::cout << "   !@!    !@!       !@!         !@!       !@! !@! !@!  !@!  @!@  !@!  @!@  " << std::endl;
std::cout << "   @!!    @!!!:!    !!@@!!      @!!       @!! !!@ @!@  @!@!@!@!  @!@@!@!   " << std::endl;
std::cout << "   !!!    !!!!!:     !!@!!!     !!!       !@!   ! !@!  !!!@!!!!  !!@!!!    " << std::endl;
std::cout << "   !!:    !!:            !:!    !!:       !!:     !!:  !!:  !!!  !!:       " << std::endl;
std::cout << "   :!:    :!:           !:!     :!:       :!:     :!:  :!:  !:!  :!:       " << std::endl;
std::cout << "    ::     :: ::::  :::: ::      ::       :::     ::   ::   :::   ::       " << std::endl;
std::cout << "    :     : :: ::   :: : :       :         :      :     :   : :   :     \033[0m" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << std::endl;

run_unit_test("construcot", &map_copy_constructor_test_std<int, int>, &map_copy_constructor_test_ft<int, int>);
run_unit_test("operator =", &map_assign_overload_test_std<int, int>, &map_assign_overload_test_ft<int, int>);
run_unit_test("iterators", &map_iterators_test_std<int, int>, &map_iterators_test_ft<int, int>);
run_unit_test("reverse iterators ", &map_reverse_iterators_test_std<int, int>, &map_reverse_iterators_test_ft<int, int>);
run_unit_test("compare class   ", &map_comparator_test_std<int, int>, &map_comparator_test_ft<int, int>);
run_unit_test("intert(value)", &map_insert_test_std<int, int>, &map_insert_test_ft<int, int>);
run_unit_test("insert(InputIterator", &map_insert_it_test_std<int, int>, &map_insert_it_test_ft<int, int>);
run_unit_test("insert(hint", &map_insert_hint_test_std<int, int>, &map_insert_hint_test_ft<int, int>);
run_unit_test("at()", &map_at_test_std<int, int>, &map_at_test_ft<int, int>);
run_unit_test("operator []", &map_operator_sq_test_std<int, int>, &map_operator_sq_test_ft<int, int>);
run_unit_test("empty()", &map_empty_test_std<int, int>, &map_empty_test_ft<int, int>);
run_unit_test("size()", &map_size_test_std<int, int>, &map_size_test_ft<int, int>);
run_unit_test("max_size()", &map_max_size_test_std<int, int>, &map_max_size_test_ft<int, int>);
run_unit_test("clear()", &map_clear_test_std<int, int>, &map_clear_test_ft<int, int>);
run_unit_test("erase(key)", &map_erase_key_test_std<int, int>, &map_erase_key_test_ft<int, int>);
run_unit_test("erase(pos)", &map_erase_position_test_std<int, int>, &map_erase_position_test_ft<int, int>);
run_unit_test("erase(iterator)", &map_erase_it_test_std<int, int>, &map_erase_it_test_ft<int, int>);
run_unit_test("swap()", &map_swap_test_std<int, int>, &map_swap_test_ft<int, int>);
run_unit_test("count()", &map_count_test_std<int, int>, &map_count_test_ft<int, int>);
run_unit_test("find()", &map_find_test_std<int, int>, &map_find_test_ft<int, int>);
run_unit_test("lower_bound()", &map_lower_bound_test_std<int, int>, &map_lower_bound_test_ft<int, int>);
run_unit_test("upper_bound()", &map_upper_bound_test_std<int, int>, &map_upper_bound_test_ft<int, int>);
run_unit_test("equal_range()", &map_equal_range_test_std<int, int>, &map_equal_range_test_ft<int, int>);
run_unit_test("key_compare()", &map_key_comp_test_std<int, int>, &map_key_comp_test_ft<int, int>);
run_bool_unit_test("operator ==", &map_equal_test);
run_bool_unit_test("operator !=", &map_not_equal_test);
run_bool_unit_test("operator <", &map_less_than_test);
run_bool_unit_test("operator >", &map_more_than_test);
run_bool_unit_test("operator <=", &map_less_or_equal_test);
run_bool_unit_test("operator >=", &map_more_or_equal_test);

std::cout << std::endl
			  << std::endl
			  << std::endl;
std::cout << "\x1B[1;32m @@@@@@@  @@@@@@@@   @@@@@@   @@@@@@@      @@@@@@   @@@@@@@@  @@@@@@@  " << std::endl;
std::cout << " @@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@     @@@@@@@   @@@@@@@@  @@@@@@@ " << std::endl;
std::cout << "   @@!    @@!       !@@         @@!       !@@       @@!         @@! " << std::endl;
std::cout << "   !@!    !@!       !@!         !@!       !@!       !@!         !@! " << std::endl;
std::cout << "   @!!    @!!!:!    !!@@!!      @!!       !!@@!!    @!!!:!      @!! " << std::endl;
std::cout << "   !!!    !!!!!:     !!@!!!     !!!        !!@!!!   !!!!!:      !!! " << std::endl;
std::cout << "   !!:    !!:            !:!    !!:            !:!  !!:         !!: " << std::endl;
std::cout << "   :!:    :!:           !:!     :!:           !:!   :!:         :!: " << std::endl;
std::cout << "    ::     :: ::::  :::: ::      ::       :::: ::    :: ::::     :: " << std::endl;
std::cout << "    :     : :: ::   :: : :       :        :: : :    : :: ::      : \033[0m" << std::endl;
	std::cout << std::endl
			  << std::endl
			  << std::endl;

run_unit_test("construcot", &set_copy_constructor_test_std<int>, &set_copy_constructor_test_ft<int>);
run_unit_test("operator =", &set_assign_overload_test_std<int>, &set_assign_overload_test_ft<int>);
run_unit_test("iterators", &set_iterators_test_std<int>, &set_iterators_test_ft<int>);
run_unit_test("reverse iterators ", &set_reverse_iterators_test_std<int>, &set_reverse_iterators_test_ft<int>);
run_unit_test("compare class   ", &set_comparator_test_std<int>, &set_comparator_test_ft<int>);
run_unit_test("intert(value)", &set_insert_test_std<int>, &set_insert_test_ft<int>);
run_unit_test("insert(InputIterator", &set_insert_it_test_std<int>, &set_insert_it_test_ft<int>);
run_unit_test("insert(hint", &set_insert_hint_test_std<int>, &set_insert_hint_test_ft<int>);
run_unit_test("empty()", &set_empty_test_std<int>, &set_empty_test_ft<int>);
run_unit_test("size()", &set_size_test_std<int>, &set_size_test_ft<int>);
run_unit_test("max_size()", &set_max_size_test_std<int>, &set_max_size_test_ft<int>);
run_unit_test("clear()", &set_clear_test_std<int>, &set_clear_test_ft<int>);
run_unit_test("erase(value)", &set_erase_value_test_std<int>, &set_erase_value_test_ft<int>);
run_unit_test("erase(pos)", &set_erase_position_test_std<int>, &set_erase_position_test_ft<int>);
run_unit_test("erase(iterator)", &set_erase_it_test_std<int>, &set_erase_it_test_ft<int>);
run_unit_test("swap()", &set_swap_test_std<int>, &set_swap_test_ft<int>);
run_unit_test("count()", &set_count_test_std<int>, &set_count_test_ft<int>);
run_unit_test("find()", &set_find_test_std<int>, &set_find_test_ft<int>);
run_unit_test("lower_bound()", &set_lower_bound_test_std<int>, &set_lower_bound_test_ft<int>);
run_unit_test("upper_bound()", &set_upper_bound_test_std<int>, &set_upper_bound_test_ft<int>);
run_unit_test("equal_range()", &set_equal_range_test_std<int>, &set_equal_range_test_ft<int>);
run_unit_test("key_compare()", &set_key_comp_test_std<int>, &set_key_comp_test_ft<int>);
run_bool_unit_test("operator ==", &set_equal_test);
run_bool_unit_test("operator !=", &set_not_equal_test);
run_bool_unit_test("operator <", &set_less_than_test);
run_bool_unit_test("operator >", &set_more_than_test);
run_bool_unit_test("operator <=", &set_less_or_equal_test);
run_bool_unit_test("operator >=", &set_more_or_equal_test);

}
