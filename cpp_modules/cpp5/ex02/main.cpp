/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:59:40 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 16:17:14 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_ok_all() {
	Bureaucrat bureaucrat("Philip", 1);
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("cat");
	PresidentialPardonForm presidential("arnold");

	std::cout << "*** SHRUBBERY ***" << std::endl;
	bureaucrat.signForm(shrubbery);
	bureaucrat.executeForm(shrubbery);

	std::cout << "*** ROBOTOMY ***" << std::endl;
	bureaucrat.signForm(robotomy);
	bureaucrat.executeForm(robotomy);

	std::cout << "*** PRESIDENTIAL ***" << std::endl;
	bureaucrat.signForm(presidential);
	bureaucrat.executeForm(presidential);
}

void	test_sign_no_exec() {
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("cat");
	PresidentialPardonForm presidential("arnold");

	std::cout << "*** SHRUBBERY ***" << std::endl;
	Bureaucrat b1("Theo", 145);
	b1.signForm(shrubbery);
	b1.executeForm(shrubbery);

	std::cout << "*** ROBOTOMY ***" << std::endl;
	Bureaucrat b2("Bob", 72);
	b2.signForm(robotomy);
	b2.executeForm(robotomy);

	std::cout << "*** PRESIDENTIAL ***" << std::endl;
	Bureaucrat b3("Billy", 25);
	b3.signForm(presidential);
	b3.executeForm(presidential);

}

void	test_no_sign_no_exec() {

	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("cat");
	PresidentialPardonForm presidential("arnold");

	std::cout << "*** SHRUBBERY ***" << std::endl;
	Bureaucrat b1("Theo", 146);
	b1.signForm(shrubbery);
	b1.executeForm(shrubbery);

	std::cout << "*** ROBOTOMY ***" << std::endl;
	Bureaucrat b2("Bob", 73);
	b2.signForm(robotomy);
	b2.executeForm(robotomy);

	std::cout << "*** PRESIDENTIAL ***" << std::endl;
	Bureaucrat b3("Billy", 26);
	b3.signForm(presidential);
	b3.executeForm(presidential);
}

void	test_no_exec() {
	Bureaucrat bureaucrat("Philip", 1);
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("cat");
	PresidentialPardonForm presidential("arnold");

	std::cout << "*** SHRUBBERY ***" << std::endl;
	bureaucrat.executeForm(shrubbery);

	std::cout << "*** ROBOTOMY ***" << std::endl;
	bureaucrat.executeForm(robotomy);

	std::cout << "*** PRESIDENTIAL ***" << std::endl;
	bureaucrat.executeForm(presidential);
}

int main () {

	std::cout << "\n===== TEST OK ALL =====" << std::endl;
	test_ok_all();

	std::cout << "\n===== TEST SIGN BUT CANT EXECUTE =====" << std::endl;
	test_sign_no_exec();

	std::cout << "\n===== TEST CAN'T SIGN NEITHER EXECUTE =====" << std::endl;
	test_no_sign_no_exec();

	std::cout << "\n===== TEST CAN'T EXECUTE IF NOT SIGNED =====" << std::endl;
	test_no_exec();

	std::cout << "\n===== END =====" << std::endl;
}
