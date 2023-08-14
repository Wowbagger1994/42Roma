/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:43:28 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/04 03:38:43 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("NoName"), _gradeSignIn(150), _gradeExecute(150)
{
	_isSigned = false;
}

Form::Form(Form &target) : _name(target.getName()), _gradeSignIn(target.getGradeSignIn()), _gradeExecute(target.getGradeExecute())
{
	_isSigned = target.getIsSigned();
}

Form::Form(const std::string &name, const int &gradeSignIn, const int &gradeExecute) : _name(name), _gradeSignIn(gradeSignIn), _gradeExecute(gradeExecute)
{
	if (gradeSignIn < 1 || gradeExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeSignIn > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
	this->_isSigned =false;
	return;
}

Form &Form::operator=(Form &target)
{
	this->_isSigned = target.getIsSigned();
	return *this;
}

Form::~Form()
{}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeSignIn() const
{
	return this->_gradeSignIn;
}

int Form::getGradeExecute() const
{
	return this->_gradeExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSignIn)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

void Form::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw Form::GradeTooLowException();
	if (!getIsSigned())
		throw Form::FormNotSignException();
	executeAction();
}

char const* Form::GradeTooLowException ::what() const throw ()
{
	return ("Form: Grade can't be that low!");
}
char const* Form::GradeTooHighException::what() const throw ()
{
	return ("Form: Grade can't be highter than 1!");
}
char const* Form::FormNotSignException::what() const throw ()
{
	return ("Form: Big boss haven't authorized yet!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " <<  form.getName()
	<< " | Grade to Sign: " << form.getGradeSignIn()
	<< " | Grade to Sign: " << form.getGradeExecute()
	<< " | Is signed ? " << (form.getIsSigned() ? "Yeeep!" : "Nooup!");

	return (os);
}
