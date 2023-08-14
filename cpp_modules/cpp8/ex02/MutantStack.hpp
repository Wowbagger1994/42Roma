/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:46:08 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/26 00:00:46 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

    public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack<T> &mutantStack);
		MutantStack &operator= (const MutantStack<T> &mutantStack);

		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
};

#include "MutantStack.tpp"

#endif
