/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:13:32 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 02:03:42 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Argument" << std::endl;
		return 0;
	}

	std::string text;
	std::ifstream oldFile;
	std::ofstream newFile;

	std::string newFileName = std::string(argv[1]) + ".replace";

	oldFile.open(argv[1],std::ios::in);
	if (!oldFile.is_open())
	{
		std::cout << "Error: file " << argv[1] << " does't exist" << std::endl;
		return 0;
	}
	newFile.open(newFileName);
	if (!newFile.is_open())
	{
		std::cout << "Error: during creation of file " << newFileName << std::endl;
		return 0;
	}

	for (char ch; oldFile.get(ch); text.push_back(ch));

	std::string wordToFind = std::string(argv[2]);
	size_t pos = text.find(wordToFind);
	while (pos != std::string::npos)
	{
		text.erase(pos, wordToFind.length());
		text.insert(pos, argv[3]);
		pos = text.find(wordToFind, pos + wordToFind.length() - 1);
	}
	newFile << text;

	oldFile.close();
	newFile.close();
}
