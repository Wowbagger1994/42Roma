/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Caster.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:09:30 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/24 01:32:46 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Caster.hpp"

Caster::Caster()
{
	return;
}

Caster::~Caster()
{
	return;
}

Caster::Caster(std::string const &input) : _input(input)
{
	_type = this->getType();
	this->setValue();
}

Caster::Caster(const Caster &caster)
{
	*this = caster;
	return;
}

Caster &Caster::operator=(const Caster &caster)
{
	if (this != &caster)
	{
		_value = caster._value;
		_type = caster._type;
		_input = caster._input;
	}
	return (*this);
}

type Caster::getType()
{
	std::istringstream iss(_input);

	/* CHAR_TEST */
	if (_input.length() == 1 && !std::isdigit(_input[0]))
		return (T_CHAR);

	/* INT TEST */
	int num;
	iss >> num;
	if (iss.eof() && !iss.fail())
		return (T_NUM);

	iss.clear();
	iss.seekg(0, std::istringstream::beg);

	/* FLOAT TEST */
	int num_f;
	char dot;
	int num_dec;
	std::string f;

	iss >> num_f;
	iss >> dot;
	iss >> num_dec;
	iss >> f;
	if (f == "f" && dot == '.' && iss.eof() && !iss.fail())
		return (T_FLOAT);

	iss.clear();
	iss.seekg(0, std::istringstream::beg);

	/* DOUBLE TEST */
	double num_d;
	iss >> num_d;
	if (iss.eof() && !iss.fail())
		return (T_NUM);

	/* SPECIAL TEST */
	std::string strings[] = {"-inf", "+inf", "nan", "-inff", "+inff", "nanf"};
	for (int i = 0; i < 6; i++)
	{
		if (strings[i] == _input)
			return (i < 3 ? T_SPECIAL : T_SPECIAL_F);
	}

	return (T_IMPOSSIBLE);
}

void Caster::setValue()
{
	std::istringstream iss(_input);
	char c;
	int num_f;
	int num_dec;
	double num_dec_double;

	if (_type == T_CHAR)
	{
		iss >> c;
		_value = c;
		return;
	}
	if (_type == T_FLOAT)
	{
		iss >> num_f;
		iss >> c;		// dot
		iss >> num_dec; // decimal part
		_value = num_f;
		num_dec_double = num_dec;
		while (num_dec_double > 1)
			num_dec_double /= 10;
		_value += num_dec_double;
		return;
	}
	iss >> _value;
}

void Caster::printConversions()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void Caster::printChar()
{
	std::cout << "char: ";

	if (_type == T_IMPOSSIBLE || _type == T_SPECIAL || _type == T_SPECIAL_F)
		std::cout << "impossible";
	else if (std::isprint(static_cast<char>(_value)))
		std::cout << "\'" << static_cast<char>(_value) << "\'";
	else if (!std::isprint(static_cast<char>(_value)))
		std::cout << "Non displayable";
	else
		std::cout << "impossible";
	std::cout << std::endl;
}
void Caster::printInt()
{
	std::cout << "int: ";

	if (_type == T_IMPOSSIBLE || _type == T_SPECIAL || _type == T_SPECIAL_F)
		std::cout << "impossible";
	else if (static_cast<int>(_value) == std::numeric_limits<int>::min() && _input != "-2147483648")
		std::cout << "overflow";
	else
		std::cout << static_cast<int>(_value);
	std::cout << std::endl;
}
void Caster::printFloat()
{
	std::cout << "float: ";

	if (_type == T_SPECIAL)
		std::cout << _input << "f";
	else if (_type == T_SPECIAL_F)
		std::cout << _input;
	else if (_type == T_IMPOSSIBLE)
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_value) << "f";
	std::cout << std::endl;
}
void Caster::printDouble()
{
	std::cout << "double: ";

	if (_type == T_SPECIAL)
		std::cout << _input;
	else if (_type == T_SPECIAL_F)
		std::cout << _input.substr(0, _input.size() - 1);
	else if (_type == T_IMPOSSIBLE)
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(_value);

	if (_type == T_IMPOSSIBLE && (_value == -1 * std::numeric_limits<double>::max() || _value == std::numeric_limits<double>::max()))
		std::cout << " (even less!)";

	std::cout << std::endl;
}
