/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:02:01 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/24 18:36:42 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T>
void incrementElement (T &el) {
	el++;
}

template <class T>
void printGeneric (T &el) {
	std::cout << el << std::endl;
}

template <typename T>
void iter(T *arr, int size, void (*f)(T&))
{
	for (int i = 0; i < size; i++)
		f(arr[i]);
}

#endif
