/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:05:47 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/25 14:15:24 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array():
	_arr(new T[0]),
	_size(0)
{
	std::cout << "[ARRAY] Default constructor called" << std::endl;
	return;
}

template <typename T>
Array<T>::Array(unsigned int n):
	_arr(new T[n]),
	_size(n)
{
	std::cout << "[ARRAY] Default constructor with parameters called" << std::endl;

	return;
}

template <typename T>
Array<T>::~Array() {
	std::cout << "[ARRAY] Destructor called" << std::endl;
	delete[] _arr;

	return;
}

template <typename T>
Array<T>::Array(const Array &array) :
	_arr(new T[array.size()]),
	_size(array.size())
{
	std::cout << "[ARRAY] Copy constructor called" << std::endl;
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = array._arr[i];
	return;
}

template <typename T>
Array<T> & Array<T>::operator= (const Array<T> &array) {
	std::cout << "[ARRAY] Copy assignment operator called" << std::endl;
	if (this == &array)
		return (*this);

	delete[] _arr;
	_size = array.size();
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = array[i];
	return (*this);
}

template <typename T>
T & Array<T>::operator[] (unsigned int index) {
	if (index >= _size)
		throw Array<T>::IndexOutOfBoundsException();
	return (_arr[index]);
}

template <typename T>
const T & Array<T>::operator[] (unsigned int index) const {
	if (index >= _size)
		throw Array<T>::IndexOutOfBoundsException();
	return (_arr[index]);
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

template <typename T>
char const * Array<T>::IndexOutOfBoundsException::what() const throw() {
	return ("Index way out of the limits!");
}
