/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:57:00 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 17:42:11 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	while (*(s) != '\0')
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
