/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:59:40 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 16:20:49 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main () {

	Bureaucrat bureaucrat("Theo", 1);
	Intern erick;
	Form *formPres;
	Form *formRobo;
	Form *formShru;

	std::cout << "\n===== INTERN CREATE FORMS =====" << std::endl;
	formPres = erick.makeForm("Presidential Pardon Form", "Philip");
	formRobo = erick.makeForm("Robotomy Request Form", "Sheldon");
	formShru = erick.makeForm("Shrubbery Creation Form", "Garden");
	erick.makeForm("Game of Thrones Form", "Daenerys Targaryen");

	std::cout << "\n===== TESTING =====" << std::endl;
	bureaucrat.signForm(*formPres);
	bureaucrat.executeForm(*formPres);
	bureaucrat.signForm(*formRobo);
	bureaucrat.executeForm(*formRobo);
	bureaucrat.signForm(*formShru);
	bureaucrat.executeForm(*formShru);

	delete formPres;
	delete formRobo;
	delete formShru;

	return (0);
}
