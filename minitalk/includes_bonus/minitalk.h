/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:11:26 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/13 12:27:35 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		send_char(char c, int pid);
int		send_str(char *s, int pid);

#endif
