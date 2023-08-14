/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_matching_root.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:20:48 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:24:09 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pathname_matching(t_path_exp *tool,
				t_list *path_parts, char *path_start, char *open_me);

static char	*path_join(char *str, char *str2)
{
	char	*intermediate;
	char	*final;

	if (!str || !str2)
		return (NULL);
	intermediate = ft_strjoin(str, "/");
	if (!intermediate)
		return (NULL);
	final = ft_strjoin_free(intermediate, str2, 1);
	if (!final)
		return (NULL);
	return (final);
}

static int	pathname_matching_assist(t_path_exp *tool, t_list *path_parts,
		char *path_start, char *open_me)
{
	DIR				*dir_p;
	struct dirent	*entry;
	int				res;
	char			*pf;

	dir_p = opendir(open_me);
	if (!dir_p)
		return (0);
	entry = readdir(dir_p);
	while (entry != NULL)
	{
		if (match_path_part_root(path_parts, entry->d_name))
		{
			pf = path_join(path_start, entry->d_name);
			if (!pf)
				pathname_matching_closedir_return(dir_p, 2);
			res = pathname_matching(tool, path_parts->next, pf, pf);
			free(pf);
			if (res)
				pathname_matching_closedir_return(dir_p, res);
		}
		entry = readdir(dir_p);
	}
	closedir(dir_p);
	return (0);
}

static int	pathname_matching(t_path_exp *tool, t_list *path_parts,
		char *path_start, char *open_me)
{
	int		res;
	char	*path_fuller;
	DIR		*dir_p;

	if (!path_parts)
		return (pathname_matched_add_to_list(tool, path_start));
	if (!ft_strlen(((t_path_part *)path_parts->content)->path_part))
	{
		dir_p = opendir(open_me);
		if (!dir_p)
			return (0);
		path_fuller = ft_strjoin(path_start, "/");
		if (!path_fuller)
			return (2);
		res = pathname_matched_add_to_list(tool, path_fuller);
		free(path_fuller);
		closedir(dir_p);
		return (res);
	}
	return (pathname_matching_assist(tool, path_parts, path_start, open_me));
}

static int	pathname_matching_relative(t_path_exp *tool, t_list *path_parts)
{
	DIR				*dir_p;
	struct dirent	*entry;
	int				res;
	char			*ps;

	dir_p = opendir("./");
	if (!dir_p)
		return (0);
	entry = readdir(dir_p);
	while (entry != NULL)
	{
		if (match_path_part_root(path_parts, entry->d_name))
		{
			ps = ft_strdup(entry->d_name);
			if (!ps)
				return (2);
			res = pathname_matching(tool, path_parts->next, ps, ps);
			free(ps);
			if (res)
				return (res);
		}
		entry = readdir(dir_p);
	}
	closedir(dir_p);
	return (0);
}

int	pathname_matching_root(t_path_exp *tool, t_list *path_parts)
{
	char	*first_path_part;

	first_path_part = ((t_path_part *)(path_parts->content))->path_part;
	if (!ft_strlen(first_path_part))
		return (pathname_matching(tool, path_parts->next, "", "/"));
	else if (!ft_strcmp(first_path_part, "."))
		return (pathname_matching(tool, path_parts->next, ".", "./"));
	else if (!ft_strcmp(first_path_part, ".."))
		return (pathname_matching(tool, path_parts->next, "..", "../"));
	else
		return (pathname_matching_relative(tool, path_parts));
}
