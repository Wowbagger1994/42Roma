/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:39:22 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/24 19:06:28 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {

private:
	T* _arr;
	unsigned int _size;

public:
	Array();
	~Array();
    Array (const Array &array);
    Array (unsigned int n);
    Array & operator= (const Array &array);
    T & operator[] (unsigned int index);
    const T & operator[] (unsigned int index) const;

	unsigned int size() const;

	class IndexOutOfBoundsException : public std::exception
	{
		public:
			 char const* what() const throw ();
	};
};

# include "Array.tpp"

#endif

