/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:36:01 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/24 02:11:04 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
	Base() {};
	virtual ~Base() {};
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
