/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:14:26 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 03:28:44 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("shrubberyCreation", 145, 137),
												 _target("No specific target")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("shrubberyCreation", 145, 137),
																		  _target(target)
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm) : Form("shrubberyCreation", 145, 137)
{
	*this = RobotomyRequestForm;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &RobotomyRequestForm)
{
	if (this != &RobotomyRequestForm)
	{
		_target = RobotomyRequestForm.getTarget();
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::executeAction() const
{
	std::srand(time(0));
	bool success = std::rand() % 2;

	std::cout << "* zZzzzZZZZzzZZZz PIIIIII PPOOOO TUCTUCTZZZZZZZ *" << std::endl;
	if (success)
		std::cout << getTarget() << " has been robotomized successfully! 😸" << std::endl;
	else
		std::cout << getTarget() << " died in the operation! 🙀" << std::endl;
}
