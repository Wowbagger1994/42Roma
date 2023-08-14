/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:08:49 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 12:01:31 by Wowbagger        ###   ########.fr       */
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
