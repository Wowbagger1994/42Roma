/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:52:33 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 12:10:41 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "../libft/libft.h"
# include "../btree/btree.h"
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <term.h>

# include <termios.h>

# include "structures.h"

# include "lexing.h"
# include "builtin.h"
# include "parser.h"
# include "terminfo.h"
# include "exe.h"

# define BUFFER_SIZE 32

# define B_ECHO 1
# define B_CD 2
# define B_PWD 3
# define B_EXPORT 4
# define B_UNSET 5
# define B_ENV 6
# define B_EXIT 7

# define SIGCAUGHT 128

int	g_sig;

void	ft_fork(pid_t *pid);
void	ft_fork_pipe(t_pipe *pipe);
void	ft_exit(char *cmd, char *param, char *str, int status);
int		ft_perror(char *cmd, char *param, char *str);
void	ft_ambiguous_redirect(char *str, int fd);

void	ft_sigquit_cmd(int sig);
void	ft_sigint_cmd(int sig);
void	ft_sigquit(int sig);
void	ft_sigint(int sig);
void	ft_signalhandler_enable_cmd(void);
void	ft_signalhandler_enable(void);
void	ft_signalhandler_disable(void);

int		reset_prompts(t_list *env, t_term *term);

char	*env_get(char *str, size_t len, t_list *env);
char	**env_get_addr(char *str, size_t len, t_list *env);
int		env_shlvl_update(t_list **env, t_control *control);
t_list	*env_build_linked_list(char **env);
t_env	*env_build(char *str);
void	env_del_struct(void *env);
int		is_identifier_valid(char *identifier, char *command);
void	unset_in_env_list(t_list **env_head, char *str);
int		export_new_env(char *str, char *str2, t_list **head);

#endif
