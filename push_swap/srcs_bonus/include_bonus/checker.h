/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:28:47 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 15:50:59 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

void	swap(int **stack, int dim);
void	push(int **s1, int **s2, int dim);
void	rotate(int	**stack, int dim);
void	reverse_rotate(int **stack, int dim);
char	**ft_split(char const *s, char c);
void	parse_numbers(int argc, char **argv, int **stack_a, int **stack_b);
int		is_ordered(int *stack, int dim);
void	parse_numbers(int argc, char **argv, int **stack_a, int **stack_b);
int		parse_string(char *str, int **stack_a, int **stack_b);
int		*simplify_stack(int *stack, int dim);
void	print_error(void);
int		ft_atoi(const char *str);
int		stack_len(int *stack, int dim);
void	exec_move(char *line, int **stack_a, int **stack_b, int dim);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

#endif
