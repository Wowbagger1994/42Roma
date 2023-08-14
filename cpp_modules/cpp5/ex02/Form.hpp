/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:42:56 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 03:33:56 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _isSigned;
	int _gradeSignIn;
	int _gradeExecute;

public:
	Form();
	Form(Form &target);
	Form(const std::string &name, const int &gradeSignIn, const int &gradeExecute);
	Form &operator=(Form &target);
	virtual ~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeSignIn() const;
	int getGradeExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;
	virtual void executeAction() const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		char const* what() const throw ();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		char const* what() const throw ();
	};
	class FormNotSignException : public std::exception
	{
	public:
		char const* what() const throw ();
	};
};

std::ostream operator<<(std::ostream os, Form const &form);


#endif
