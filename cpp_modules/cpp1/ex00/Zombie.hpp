/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:01:29 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/23 01:12:48 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string n);
	~Zombie();
	void announce( void );
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

#endif
