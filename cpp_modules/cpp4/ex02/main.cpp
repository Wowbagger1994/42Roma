/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:35:29 by ebraho            #+#    #+#             */
/*   Updated: 2022/08/11 04:13:48 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define MAX_SIZE 8

int main()
{
	Animal *cat = new Cat;
	Animal *dog = new Dog;

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;

	return 0;
}
