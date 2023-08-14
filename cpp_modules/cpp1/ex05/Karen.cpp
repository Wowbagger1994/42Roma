/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:57:51 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/21 01:53:16 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

void Karen::debug(void)
{
	std::cout << "\033[1;32m[DEBUG]\033[0m\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "\033[1;36m[INFO]\033[0m\n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "\033[1;33m[WARNING]\033[0m\n" << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "\033[1;31m[ERROR]\033[0m\n" <<"This is unacceptable! I want to speak to the manager now." << std::endl;
}


void	Karen::complain(std::string level)
{
	std::string keyword[4] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	void (Karen::*funcptr[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	for (int i = 0; i < 4; i++)
		if (level == keyword[i])
			(this->*funcptr[i])();
}
