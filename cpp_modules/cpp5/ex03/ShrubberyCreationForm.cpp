/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:18:46 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 03:28:23 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubberyCreation", 145, 137),
												 _target("No specific target")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("shrubberyCreation", 145, 137),
																		  _target(target)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm) : Form("shrubberyCreation", 145, 137)
{
	*this = shrubberyCreationForm;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	if (this != &shrubberyCreationForm)
	{
		_target = shrubberyCreationForm.getTarget();
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::executeAction() const
{
	std::string fileName = getTarget() + "_shrubbery";
	std::ofstream shrubberyFile(fileName.c_str());

	shrubberyFile
		<< "				,@@@@@@@, " << std::endl
		<< "		,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl
		<< "		,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl
		<< "	,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' " << std::endl
		<< "	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " << std::endl
		<< "	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' " << std::endl
		<< "	`&%\\ ` /%&'    |.|        \\ '|8' " << std::endl
		<< "	|o|        | |         | | " << std::endl
		<< "		|.|        | |         | | " << std::endl
		<< "		\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	shrubberyFile.close();
}
