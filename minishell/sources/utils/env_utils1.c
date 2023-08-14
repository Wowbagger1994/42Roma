/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:28:47 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/18 22:41:15 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*env_init_struct(void)
{
	t_env	*new;

	new = (t_env *)ft_memalloc(sizeof(t_env));
	if (!(new))
		return (NULL);
	return (new);
}

t_list	*env_build_linked_list(char **env)
{
	t_list	*lst_head;
	t_list	*lst_link;
	t_env	*env_struct;
	int		i;

	i = 0;
	lst_head = NULL;
	while (env[i])
	{
		env_struct = env_build(env[i]);
		lst_link = ft_lstnew(env_struct);
		if (!env_struct || !lst_link)
		{
			if (!lst_link)
				env_del_struct(env_struct);
			ft_lstclear(&lst_head, env_del_struct);
			return (NULL);
		}
		ft_lstadd_back(&lst_head, lst_link);
		i++;
	}
	return (lst_head);
}

void	env_del_struct(void *env)
{
	free(((t_env *)env)->label);
	free(((t_env *)env)->value);
	free((t_env *)env);
}

t_env	*env_build(char *str)
{
	int		i;
	t_env	*new;

	i = ft_strichr(str, '=');
	if (i == -1)
		return (NULL);
	new = env_init_struct();
	if (!(new))
		return (NULL);
	new->label = ft_substr(str, 0, i++);
	new->value = ft_substr(str + i, 0, ft_strlen(str + i));
	if (!(new->label) || !(new->value))
	{
		env_del_struct(new);
		return (NULL);
	}
	return (new);
}

int	export_new_env(char *str, char *str2, t_list **head)
{
	t_env	*env;
	t_list	*new_link;

	env = ft_memalloc(sizeof(t_env));
	if (!env)
		return (0);
	env->label = ft_strdup(str);
	if (!(env->label))
	{
		free(env);
		return (0);
	}
	if (str2 != NULL)
		env->value = ft_strdup(str2);
	else
		env->value = NULL;
	new_link = ft_lstnew(env);
	if (!new_link)
	{
		env_del_struct(env);
		return (0);
	}
	ft_lstadd_back(head, new_link);
	return (1);
}
