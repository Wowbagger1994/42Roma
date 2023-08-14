/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:14:17 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 03:29:40 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("shrubberyCreation", 145, 137),
												 _target("No specific target")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("shrubberyCreation", 145, 137),
																		  _target(target)
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm) : Form("shrubberyCreation", 145, 137)
{
	*this = PresidentialPardonForm;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &PresidentialPardonForm)
{
	if (this != &PresidentialPardonForm)
	{
		_target = PresidentialPardonForm.getTarget();
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << getTarget() << " has pardoned by Zaphod Beeblebrox! 😽" << std::endl;
}
