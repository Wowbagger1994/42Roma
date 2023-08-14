/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:05:34 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 15:51:14 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker.h"

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

char	*get_next_line(void)
{
	char	save[5];
	char	buff[1];
	char	*line;
	int		i;

	i = 0;
	save[i] = '\0';
	while (read(0, buff, 1) == 1 && i < 5)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	line = malloc(i + 1);
	i = -1;
	while (save[++i])
		line[i] = save[i];
	line[i] = '\0';
	return (line);
}

static void	parse_command(int **stack_a, int **stack_b, int dim)
{
	char	*line;

	while (1)
	{
		line = get_next_line();
		if (line == 0)
			break ;
		exec_move(line, stack_a, stack_b, dim);
	}
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		*new_stack_a;
	int		size;

	if (argc == 1)
		return (0);
	size = argc - 1;
	if (argc == 2)
		size = parse_string(argv[1], &stack_a, &stack_b);
	else
		parse_numbers(size, argv + 1, &stack_a, &stack_b);
	new_stack_a = simplify_stack(stack_a, size);
	free(stack_a);
	parse_command(&new_stack_a, &stack_b, size);
	if (is_ordered(new_stack_a, size))
		write(1, "OK\n", 3);
	else if (!is_ordered(new_stack_a, size))
		write(1, "KO\n", 3);
	free(new_stack_a);
	free(stack_b);
}
