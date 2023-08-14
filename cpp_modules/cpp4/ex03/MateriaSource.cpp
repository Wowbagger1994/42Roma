/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:53:21 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:40 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < MAX_MATERIA; i++)
		_materias[i] = 0;
	return;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_materias[i])
			delete _materias[i];
	}
	return;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	*this = materiaSource;
	return;
}

MateriaSource  &MateriaSource::operator= (const MateriaSource &materiaSource) {
	if (this != &materiaSource) {
		for (int i = 0; i < MAX_MATERIA; i++) {
			if (_materias[i])
				delete _materias[i];
			_materias[i] = materiaSource._materias[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const  &type)
{
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (0);
}
