/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:52:30 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Anonymous") {
	for (int i = 0; i < MAX_INVENTORY; i++)
		_inventory[i] = 0;
	return;
}

Character::Character(const std::string name) : _name(name) {
	for (int i = 0; i < MAX_INVENTORY; i++)
		_inventory[i] = 0;
	return;
}

Character::~Character() {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
	return;
}

Character::Character(const Character &character) {
	*this = character;
	return;
}

Character  &Character::operator= (const Character &character) {
	if (this != &character) {
		_name = character._name;
		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = character._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const  &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_INVENTORY)
		return ;
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= MAX_INVENTORY || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
}

