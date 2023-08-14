/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:51:40 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 12:53:29 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c < 'a' || c > 'z')
		&& ((c < 'A' || c > 'Z'))
		&& ((c < '0' || c > '9')))
		return (0);
	return (c);
}
