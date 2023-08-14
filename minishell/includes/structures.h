/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:56:29 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 19:23:44 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_term
{
	char			*line;
	int				line_len;
	int				inline_position;
	int				prompt_ps1;
	char			*ps1;
	char			*ps2;
	int				prompt_len;
}				t_term;

typedef struct s_lexer_end
{
	unsigned int	other:1;
	unsigned int	quote:1;
	unsigned int	backslash:1;
	unsigned int	brace:1;
	unsigned int	add_semi:1;
	unsigned int	unexpected;
}				t_lexer_end;

typedef struct s_token
{
	char			*str;
	int				id;
	int				is_filename;
	unsigned int	open_quote:1;
	unsigned int	esc_next:1;
	int				unquote_protected;
	int				protect_s;
	int				protect_e;
}				t_token;

typedef struct s_control
{
	unsigned int	quit;
	int				exit_status;
	pid_t			parent_pid;
	t_term			*term;
	t_list			*env;
	t_lexer_end		lexer_end;
	int				truefd[3];
	struct termios	termios_default;
	char			*cwd;
}				t_control;

typedef struct s_simple_cmd
{
	t_list	*arrows;
	char	**argv;
}				t_simple_cmd;

typedef struct s_arrow
{
	char	*src;
	char	*dest;
	int		id;
}				t_arrow;

typedef struct s_env
{
	char	*label;
	char	*value;
	int		tmpdeclare;
}				t_env;

typedef struct s_expansion
{
	int			start;
	int			end;
	char		quoted;
	int			is_filename;
	char		*ifs;
}				t_expansion;

typedef struct s_path_part
{
	char		*path_part;
	t_list		*star_index;
	char		quoted;
}				t_path_part;

typedef struct s_path_exp
{
	t_list		*path_parts;
	int			is_filename;
	int			first_match;
	t_list		*matched_paths;
}				t_path_exp;

typedef struct s_no_unquote
{
	int	start;
	int	end;
}				t_no_unquote;

typedef struct s_strings
{
	char	*str;
	char	*ref;
}				t_strings;

typedef struct s_exe
{
	int		id;
	int		(*fct)(t_btree *, t_control *);
}				t_exe;

typedef struct s_pipe
{
	int	pid;
	int	fildes[2];
	int	status;
}				t_pipe;

#endif
