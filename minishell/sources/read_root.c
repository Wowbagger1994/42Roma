/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:11:29 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 18:56:15 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_dir_name(void)
{
	char	*fulldir;
	char	*dir;
	int		dirlen;
	int		i;

	fulldir = malloc(sizeof(char) * PATH_MAX);
	if (fulldir == NULL)
		return (NULL);
	getcwd(fulldir, PATH_MAX);
	dirlen = ft_strlen(fulldir);
	i = dirlen - 1;
	while (fulldir[i] != '/')
		i--;
	i++;
	dir = ft_substr(fulldir, i, dirlen - i);
	free(fulldir);
	return (dir);
}

void	read_root(t_control *control)
{
	size_t	prompt_len;
	char	*prompt;

	prompt_len = ft_strlen("\b\b\x1b[36m\x1b[1m")
		+ ft_strlen(get_dir_name()) + ft_strlen(">\x1b[0m ") + 1;
	prompt = malloc(prompt_len + 1);
	*prompt = '\0';
	ft_strlcat(prompt, "\x1b[36m\x1b[1m", prompt_len);
	ft_strlcat(prompt, get_dir_name(), prompt_len);
	ft_strlcat(prompt, ">\x1b[0m ", prompt_len);
	control->term->line = readline(prompt);
	if (!control->term->line)
		builtin_exit(NULL, control);
	control->term->line_len = ft_strlen(control->term->line);
	if (control->term->line && control->term->line[0] != '\0')
		add_history(control->term->line);
}
