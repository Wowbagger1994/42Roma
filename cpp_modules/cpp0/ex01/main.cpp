/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:54:58 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/16 12:55:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command = "";

	while (1)
	{
		std::cout << "Insert a command:" << std::endl;
		std::cin >> command;
		if (command.compare("ADD") == 0)
			phoneBook.add();
		else if (command.compare("SEARCH") == 0)
			phoneBook.search();
		else if (command.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Command not valid\nThe commands are ADD, SEARCH and EXIT\nPlease try again..." << std::endl;
	}
}
