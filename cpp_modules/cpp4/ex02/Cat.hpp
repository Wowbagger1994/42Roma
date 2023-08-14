/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:50:44 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 12:11:43 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"


class Cat: public Animal {

private:
	Brain *_brain;

public:
	Cat();
	~Cat();
    Cat (const Cat &cat);
    Cat  &operator= (const Cat &cat);

	void makeSound() const;
};

#endif

