/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:29:52 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/21 03:32:49 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_ast(t_btree **node)
{
	btree_clear(node, NULL);
}

void	ast_add(t_btree **ast, t_btree *add)
{
	if (add == NULL)
		return ;
	if (*ast == NULL)
		*ast = add;
	else if ((*ast)->left == NULL)
		(*ast)->left = add;
	else if ((*ast)->item == NULL)
	{
		(*ast)->item = add->item;
		ft_free((void **)&add);
	}
	else if ((*ast)->right == NULL)
		(*ast)->right = add;
	else
	{
		add->left = *ast;
		*ast = add;
	}
}

static void	parser_btree_reverse_pipe(t_btree **ast)
{
	int		id;
	t_btree	*lchild;

	lchild = (*ast)->left;
	while (btree_id(lchild) == PIPE)
		lchild = lchild->left;
	id = btree_id(lchild);
	if ((id) == -1)
		return ;
	if (id == LIST || id == SUBSHELL)
		return ;
	(*ast)->left = lchild->right;
	lchild->right = *ast;
	*ast = lchild;
}

void	parser_pipe_priority(t_btree **ast)
{
	if (!ast || !*ast)
		return ;
	parser_pipe_priority(&(*ast)->left);
	parser_pipe_priority(&(*ast)->right);
	if (btree_id(*ast) == PIPE)
		parser_btree_reverse_pipe(ast);
}
