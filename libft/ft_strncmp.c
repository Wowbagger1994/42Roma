/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:37:57 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 12:37:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (i == n)
		i--;
	res = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
	return (res);
}
