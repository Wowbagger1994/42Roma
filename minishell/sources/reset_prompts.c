/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_prompts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:09:58 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:50:44 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	reset_prompt(char **ref_from_env, char **term_ps)
{
	if (!ref_from_env || !*ref_from_env)
	{
		if (!*term_ps || !ft_strlen(*term_ps))
		{
			ft_free((void **)term_ps);
			*term_ps = ft_strdup("");
			if (!(*term_ps))
				return (0);
		}
	}
	else if (!*term_ps || ft_strcmp(*ref_from_env, *term_ps))
	{
		ft_free((void **)term_ps);
		*term_ps = ft_strdup(*ref_from_env);
		if (!(*term_ps))
			return (0);
	}
	return (1);
}

int	reset_prompts(t_list *env, t_term *term)
{
	char	**ps1;
	char	**ps2;

	ps2 = env_get_addr("PS2", 3, env);
	ps1 = env_get_addr("PS1", 3, env);
	if (!reset_prompt(ps1, &term->ps1))
		return (0);
	return (reset_prompt(ps2, &term->ps2));
}
