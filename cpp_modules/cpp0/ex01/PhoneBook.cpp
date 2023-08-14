#include "PhoneBook.hpp"

void	PhoneBook::add()
	{
		Contact contact;
		std::cout << "Insert First Name:" << std::endl;
		std::cin >> contact.firstName;
		validate_field(contact.firstName);
		std::cout << "Insert Last Name:" << std::endl;
		std::cin >> contact.lastName;
		validate_field(contact.lastName);
		std::cout << "Insert Nickname:" << std::endl;
		std::cin >> contact.nickName;
		validate_field(contact.nickName);
		std::cout << "Insert Phone Number:" << std::endl;
		std::cin >> contact.phoneNumber;
		validate_field(contact.phoneNumber);
		std::cout << "Insert Darkest Secret:" << std::endl;
		std::cin >> contact.darkestSecret;
		validate_field(contact.darkestSecret);
		for (int i = _nContact; i > 0; i--)
			_contacts[i] = _contacts[i - 1];
		_contacts[0] = contact;
		if (_nContact < 8)
			_nContact++;
			std::cout << "Contact Added Successfully!" << std::endl;
	}

	void	PhoneBook::search()
	{
		int index = -1;
		if (_nContact == 0)
		{
			std::cout << "PhoneBook is empty, add some contacts and try again" << std::endl;
			return ;
		}
		for (int i = 0; i < _nContact; i++)
		{
			std::cout << std::right << std::setfill(' ')
					<< std::setw(10) << std::to_string(i) << " | "
					<< std::setw(10) << truncate(_contacts[i].firstName, 10) << " | "
					<< std::setw(10) << truncate(_contacts[i].lastName, 10) << " | "
					<< std::setw(10) << truncate(_contacts[i].nickName, 10) << std::endl;
		}
		std::cout << "Select an index:" << std::endl;
		std::cin >> index;
		while (index < 0 || index > (int)_nContact - 1)
		{
			if(std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cout << "Index not valid...\nPlease try again:" << std::endl;
			std::cin >> index;
		}
		std::cout << _contacts[index].firstName << "\n"
				<< _contacts[index].lastName << "\n"
				<< _contacts[index].nickName << "\n"
				<< _contacts[index].phoneNumber << "\n"
				<< _contacts[index].darkestSecret << std::endl;
	}
