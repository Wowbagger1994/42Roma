/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:21:09 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 15:27:36 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_moves
{
	int	ra_n;
	int	rra_n;
	int	rb_n;
	int	rrb_n;
	int	rrr;
	int	rr;
}		t_moves;

typedef struct s_stacks
{
	int	**a;
	int	**b;
	int	dim;
}		t_stacks;

void		run_of_3(int **a, int dim);
void		run_of_5(int **a, int **b, int dim);
void		parse_numbers(int argc, char **argv, int **stack_a, int **stack_b);
int			is_ordered(int *stack, int dim);
int			stack_len(int *stack, int dim);
int			ft_atoi(const char *str);
int			*simplify_stack(int *stack, int dim);
void		print_error(void);
void		sa(int **a, int dim);
void		pa(int **a, int **b, int dim);
void		ra(int **a, int dim);
void		rra(int **a, int dim);
void		sb(int **b, int dim);
void		pb(int **b, int **a, int dim);
void		rb(int **b, int dim);
void		rrb(int **b, int dim);
void		ss(int **a, int **b, int dim);
void		rr(int **a, int **b, int dim);
void		rrr(int **a, int **b, int dim);
void		swap(int **stack, int dim);
void		push(int **s1, int **s2, int dim);
void		rotate(int	**stack, int dim);
void		reverse_rotate(int **stack, int dim);
void		push_n(int **a, int **b, int dim, int n);
void		run_big_numbers(int **a, int **b, int dim);
int			get_lis(int *stack, int **lis, int dim);
int			is_in_lis(int *lis, int lis_lenght, int n);
char		**ft_split(char const *s, char c);
int			parse_string(char *str, int **stack_a, int **stack_b);
t_moves		*init_moves(void);
int			sum_moves(t_moves *moves);
void		move_to_first(t_stacks *stacks, int is_a, int n, t_moves *moves);
int			is_bt_rt(int *stack, int dim, int n, int print);
void		exec_moves(int **a, int **b, int dim, t_moves *moves);
void		check_stack_len(int **a, int **b, int dim);
void		push_to_b(int **a, int **b, int dim);
void		check_stack_len(int **a, int **b, int dim);
t_stacks	*copy_stacks(t_stacks *stacks);
int			find_min(int *stack, int dim, int n);
int			find_max(int *stack, int dim, int n);

#endif
