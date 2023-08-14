/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:11:15 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 16:15:30 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define FORM_PRES "Presidential Pardon Form"
#define FORM_ROBO "Robotomy Request Form"
#define FORM_SHRU "Shrubbery Creation Form"

Intern::Intern()
{
	return;
}

Intern::~Intern()
{
	return;
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
	return;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
	Form *form = NULL;
	Form *(Intern::*arr_functions[])(const std::string &target) = {
		&Intern::MakePresidentialPardonForm,
		&Intern::MakeRobotomyRequestForm,
		&Intern::MakeShrubberyCreationForm};

	(formName == FORM_PRES) && (form = (this->*arr_functions[formPres])(target));
	(formName == FORM_ROBO) && (form = (this->*arr_functions[formRobo])(target));
	(formName == FORM_SHRU) && (form = (this->*arr_functions[formShru])(target));

	form &&std::cout << "Intern created a " << formName << std::endl;
	!form &&std::cout << "You should fire this intern! " << formName << " never ever EVER existed!" << std::endl;

	return (form);
}

Form *Intern::MakePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::MakeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::MakeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
