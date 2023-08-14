/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:42:58 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:01:24 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		buildin_env(t_list *env, t_control *control);

int		builtin_unset(t_list **env_head, char **argv, t_control *control);

int		builtin_export(t_list **head, char **argv, t_control *control);
void	builtin_export_no_arg(t_list **head, t_control *control);

int		buildin_echo(char **argv, t_control *control);
int		builtin_pwd(t_control *control);
int		builtin_cd(t_list *env, char **argv, t_control *control);
int		builtin_exit(char **argv, t_control *control);

#endif
