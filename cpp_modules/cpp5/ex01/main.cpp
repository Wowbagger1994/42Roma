/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:59:40 by ebraho            #+#    #+#             */
/*   Updated: 2022/08/18 18:11:06 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {

	Bureaucrat bureaucrat("Pippo", 65);
	Form form("G12", 150, 150);
	Form form2("F28", 64, 150);

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n===== SIGNING =====" << std::endl;
	try {
		bureaucrat.signForm(form);
		bureaucrat.signForm(form2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n===== INCREMENT AND SIGNING =====" << std::endl;
	try {
		bureaucrat.incrementGrade();
		bureaucrat.signForm(form);
		bureaucrat.signForm(form2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== PRINTING =====" << std::endl;
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n===== END =====" << std::endl;
}
