/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:52:33 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_INVENTORY 4
class Character : public ICharacter {

private:
	std::string _name;
	AMateria *_inventory[MAX_INVENTORY];

public:
	Character();
	Character(const std::string name);
	~Character();
    Character (const Character &character);
    Character  &operator= (const Character &character);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);


};

#endif

