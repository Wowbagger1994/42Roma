/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:08:38 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/25 22:51:52 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class NoOccurenceException : public std::exception
{
	public:
			char const* what() const throw ();
};

char const *NoOccurenceException::what() const throw() {
	return ("No occurence is found!");
}

template<typename T>
typename T::iterator	easyfind(T &container, int find)
{
	typename T::iterator n = std::find(container.begin(), container.end(), find);

	if (*n != find)
		throw NoOccurenceException();
	return (n);
}

#endif
