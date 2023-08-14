/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:05:33 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/25 16:20:26 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

# define C_RED "\033[1;31m"
# define C_END "\033[0m"

int main(int, char**)
{
    std::cout << "\n======== SUBJECT TEST CASE ========" << std::endl;
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    std::cout << "\n======== ADDING TOO MANY NUMBERS ========" << std::endl;
    {
        Span sp = Span(4);

        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception & e) {
            std::cerr << C_RED << "[ERROR] " << C_END << e.what() << std::endl;
        }
    }

    std::cout << "\n======== ADDIG ONLY 1 NUMBER ========" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);

        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::exception & e) {
            std::cerr << C_RED << "[ERROR] " << C_END << e.what() << std::endl;
        }
        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception & e) {
            std::cerr << C_RED << "[ERROR] " << C_END << e.what() << std::endl;
        }

        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    std::cout << "\n======== ADDIG WITH ITERATORS - SMALL ========" << std::endl;
    {
        Span sp = Span(10);
        int ints[] = { 10, 20, 30, 20 };
        std::vector<int> myVector (ints, ints + sizeof(ints) / sizeof(int));

        try {
            sp.addNumber(myVector.begin(), myVector.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.addNumber(myVector.begin(), myVector.end());
            sp.addNumber(myVector.begin(), myVector.end());
            sp.addNumber(myVector.begin(), myVector.end());
        } catch (std::exception & e) {
            std::cerr << C_RED << "[ERROR] " << C_END << e.what() << std::endl;
        }
    }

    std::cout << "\n======== ADDIG WITH ITERATORS - SAME SIZE ========" << std::endl;
    {
        Span sp = Span(10);
        int ints[] = { 10, 20, 30, -40, 50, -60, 70, -80, 900, 10000 };
        std::vector<int> myVector (ints, ints + sizeof(ints) / sizeof(int));

        try {
            sp.addNumber(myVector.begin(), myVector.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.addNumber(1);
        } catch (std::exception & e) {
            std::cerr << C_RED << "[ERROR] " << C_END << e.what() << std::endl;
        }
    }

    std::cout << "\n======== ADDIG WITH ITERATORS - BIGGER SIZE ========" << std::endl;
    {
        Span sp = Span(5);
        int ints[] = { 10, 20, 30, -40, 50, -60, 70, -80, 900, 10000 };
        std::vector<int> myVector (ints, ints + sizeof(ints) / sizeof(int));

        try {
            sp.addNumber(myVector.begin(), myVector.end());
        } catch (std::exception & e) {
            std::cerr << C_RED << "[ERROR] " << C_END << e.what() << std::endl;
        }
    }

    std::cout << "\n======== ADDIG WITH ITERATORS - HUGE SPAN SIZE ========" << std::endl;
    {
        Span sp = Span(100000);
        std::vector<int> myVector (50000);
        std::vector<int> myVector2 (50000);
        std::vector<int>::iterator it;

        srand(time(NULL));
        for (it = myVector.begin(); it != myVector.end(); it++)
		    *it = rand();
        for (it = myVector2.begin(); it != myVector2.end(); it++)
		    *it = rand();

        try {
            sp.addNumber(myVector.begin(), myVector.end());
            sp.addNumber(myVector2.begin(), myVector2.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.addNumber(42);
        } catch (std::exception & e) {
            std::cerr << C_RED << "[ERROR] " << C_END << e.what() << std::endl;
        }
    }

    std::cout << std::endl;
    return 0;
}
