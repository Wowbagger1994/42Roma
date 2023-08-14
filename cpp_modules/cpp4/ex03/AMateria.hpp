/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:52:27 by ebraho            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
	std::string _type;

public:
	AMateria();
	virtual ~AMateria();
    AMateria (const AMateria &aMateria);
    AMateria (std::string const  &type);
    AMateria  &operator= (const AMateria &aMateria);

	std::string const  &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);

};

#endif
