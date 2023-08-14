/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:03:44 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 17:02:35 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*builtin_export_check_label(char *str, t_control *control,
	int *plus)
{
	int	i;

	if (is_identifier_valid(str, "export"))
	{
		control->exit_status = 1;
		return (NULL);
	}
	i = ft_strichr(str, '=');
	if (i > 0 && str[i - 1] == '+')
	{
		*plus = 1;
		i--;
	}
	else
		*plus = 0;
	if (i == -1)
		return (str);
	str[i] = '\0';
	return (str + i + 1);
}

static int	try_export_new_env(char *arg, char *sep2, t_list **head, int *plus)
{
	char	**str_addr;
	char	*temp;

	if (sep2 && sep2 == arg
		&& env_get_addr(arg, ft_strlen(arg), *head) == NULL)
		export_new_env(arg, NULL, head);
	else if (sep2 && sep2 != arg)
	{
		str_addr = env_get_addr(arg, ft_strlen(arg), *head);
		if (str_addr)
		{
			temp = *str_addr;
			if (*plus == 1)
				*str_addr = ft_strjoin(*str_addr, sep2 + 1);
			else
				*str_addr = ft_strdup(sep2);
			free(temp);
			if (!(*str_addr))
				return (0);
		}
		else if (!export_new_env(arg, sep2, head))
			return (0);
	}
	return (1);
}

static int	builtin_export2(t_list **head, char **argv, t_control *control)
{
	int		i;
	int		plus;

	i = 1;
	control->exit_status = 0;
	while (argv[i])
	{
		if (try_export_new_env(argv[i],
				builtin_export_check_label(argv[i], control, &plus),
				head, &plus) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	builtin_export(t_list **head, char **argv, t_control *control)
{
	if (argv[1] == NULL)
		builtin_export_no_arg(head, control);
	else if (!builtin_export2(head, argv, control))
	{
		control->quit = 1;
		control->exit_status = errno;
		return (0);
	}
	return (1);
}
