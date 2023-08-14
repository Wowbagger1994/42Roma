/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:32:40 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/18 22:59:45 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get(char *str, size_t len, t_list *env)
{
	while (env)
	{
		if (((t_env *)env->content)->label)
		{
			if (ft_strlen(((t_env *)env->content)->label) == len \
					&& !ft_strncmp(str, ((t_env *)env->content)->label, len))
				return (((t_env *)env->content)->value);
		}
		env = env->next;
	}
	return (NULL);
}

char	**env_get_addr(char *str, size_t len, t_list *env)
{
	while (env)
	{
		if (((t_env *)env->content)->label)
		{
			if (ft_strlen(((t_env *)env->content)->label) == len \
					&& !ft_strncmp(str, ((t_env *)env->content)->label, len))
				return (&((t_env *)env->content)->value);
		}
		env = env->next;
	}
	return (NULL);
}

int	env_shlvl_update(t_list **env, t_control *control)
{
	int		shlvl;
	char	*nbr;
	char	*argv[3];

	nbr = env_get("SHLVL", 5, *env);
	if (!nbr)
		nbr = "0";
	shlvl = ft_atoi(nbr) + 1;
	argv[0] = "export";
	argv[1] = NULL;
	argv[2] = NULL;
	nbr = ft_itoa(shlvl);
	argv[1] = ft_strjoin_free("SHLVL=", nbr, 2);
	if (!nbr || !argv[1])
		return (0);
	builtin_export(env, argv, control);
	free(argv[1]);
	return (1);
}

int	is_identifier_valid(char *identifier, char *command)
{
	if (!identifier[0] || ft_stristr(identifier, "0123456789@~%^*+=\\/?,.") == 0)
	{
		ft_perror(command, identifier, "not a valid identifier");
		return (1);
	}
	return (0);
}

void	unset_in_env_list(t_list **env_head, char *str)
{
	t_list	**ptr;
	t_list	*extra;

	ptr = env_head;
	while (*ptr)
	{
		if (!ft_strncmp(str, ((t_env *)((*ptr)->content))->label, \
					ft_strlen(str) + 1))
		{
			extra = *ptr;
			*ptr = (*ptr)->next;
			env_del_struct(extra->content);
			free(extra);
			return ;
		}
		ptr = &(*ptr)->next;
	}
}
