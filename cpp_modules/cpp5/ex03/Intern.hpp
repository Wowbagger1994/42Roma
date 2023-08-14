/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:08:16 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 16:14:32 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum t_form {
	formPres,
	formRobo,
	formShru
};

class Intern {

private:
	Form* MakePresidentialPardonForm(const std::string &target);
	Form* MakeRobotomyRequestForm(const std::string &target);
	Form* MakeShrubberyCreationForm(const std::string &target);

public:
	Intern();
	~Intern();
	Intern(const Intern &intern);
	Intern & operator= (const Intern &intern);

	Form* makeForm(const std::string &formName, const std::string &target);
};

#endif
