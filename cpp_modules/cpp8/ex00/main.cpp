/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:29:08 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/25 15:29:10 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>

#include "easyfind.hpp"

# define C_RED "\033[1;31m"
# define C_GREEN "\033[1;32m"
# define C_END "\033[0m"

void test(std::vector<int> myVector, int el)
{
    std::cout << "\n======== EASYFIND " << el << " ========" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(myVector, el);
        std::cout << C_GREEN << "Element found in myVector: " << *it << C_END << std::endl;
        *it = 42;
        std::cout << "Replacing by 42 => [" << myVector[0] << ", " << myVector[1] << ", " << myVector[2] << ", " << myVector[3] << "]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << C_RED << e.what() << C_END << '\n';
    }
}


int main(int, char**)
{

    std::cout << "\n======== MY VECTOR ========" << std::endl;
    {
        int ints[] = { 10, 20, 30, 40 };
        std::vector<int> myVector (ints, ints+4);
        std::cout << "[" << myVector[0] << ", " << myVector[1] << ", " << myVector[2] << ", " << myVector[3] << "]" << std::endl;
        test(myVector, 10);
        test(myVector, 20);
        test(myVector, 30);
        test(myVector, 40);
    }

    std::cout << "\n======== MY LIST ========" << std::endl;
    {
        std::list<int> myList;
        myList.push_back(10);
        myList.push_back(20);
        myList.push_back(30);
        myList.push_back(40);
        try
        {
            std::list<int>::iterator it = easyfind(myList, 20);
            std::cout << C_GREEN << "Element found in myList: " << *it << C_END << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << C_RED << e.what() << C_END << '\n';
        }
    }

    std::cout << "\n======== MY DEQUE ========" << std::endl;
    {
        std::deque<int> myDeque;
        myDeque.push_back(10);
        myDeque.push_back(20);
        myDeque.push_back(30);
        myDeque.push_back(40);
         try
        {
            std::deque<int>::iterator it = easyfind(myDeque, 30);
            std::cout << C_GREEN << "Element found in myDeque: " << *it << C_END << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << C_RED << e.what() << C_END << '\n';
        }
    }

    std::cout << std::endl;

    return 0;
}
