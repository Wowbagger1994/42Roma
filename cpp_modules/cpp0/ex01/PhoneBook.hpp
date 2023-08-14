#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
	int	_nContact;
	Contact _contacts[8];

	std::string truncate(std::string str, size_t width)
	{
		if (str.length() > width)
			return str.substr(0, width - 1) + ".";
		return str;
	}
	void	validate_field(std::string &contact)
	{
		while (contact.empty())
		{
			std::cout << "Empty field isn't valid, insert again:" << std::endl;
			std::cin >> contact;
		}
	}

public:

	PhoneBook(){ _nContact = 0; }
	void	add();
	void	search();
};

#endif
