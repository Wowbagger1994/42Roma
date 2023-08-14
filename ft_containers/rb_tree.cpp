#include "rb_tree.hpp"

ft::Rb_tree_node *ft::Rb_tree_increment(ft::Rb_tree_node *x) throw()
{
	if (x->right != 0)
	{
		x = x->right;
		while (x->left != 0)
			x = x->left;
	}
	else
	{
		ft::Rb_tree_node *y = x->parent;
		while (x == y->right)
		{
			x = y;
			y = y->parent;
		}
		if (x->right != y)
			x = y;
	}
	return x;
}

const ft::Rb_tree_node *ft::Rb_tree_increment(const ft::Rb_tree_node *x) throw()
{
	return Rb_tree_increment(const_cast<ft::Rb_tree_node *>(x));
}

ft::Rb_tree_node *ft::Rb_tree_decrement(ft::Rb_tree_node *x) throw()
{
	if (x->color == ft::red && x->parent->parent == x)
		x = x->right;
	else if (x->left != 0)
	{
		ft::Rb_tree_node *y = x->left;
		while (y->right != 0)
			y = y->right;
		x = y;
	}
	else
	{
		ft::Rb_tree_node *y = x->parent;
		while (x == y->left)
		{
			x = y;
			y = y->parent;
		}
		x = y;
	}
	return x;
}

const ft::Rb_tree_node *ft::Rb_tree_decrement(const ft::Rb_tree_node *x) throw()
{
	return Rb_tree_decrement(const_cast<ft::Rb_tree_node *>(x));
}

void ft::Rb_tree_rotate_left(ft::Rb_tree_node *const x, ft::Rb_tree_node *&root)
{
	ft::Rb_tree_node *const y = x->right;

	x->right = y->left;
	if (y->left != 0)
		y->left->parent = x;
	y->parent = x->parent;

	if (x == root)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

void ft::Rb_tree_rotate_right(ft::Rb_tree_node *const x, ft::Rb_tree_node *&root)
{
	ft::Rb_tree_node *const y = x->left;

	x->left = y->right;
	if (y->right != 0)
		y->right->parent = x;
	y->parent = x->parent;

	if (x == root)
		root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}

void ft::tree_insert_and_rebalance(const bool insert_left, ft::Rb_tree_node *x, ft::Rb_tree_node *p, ft::Rb_tree_node &header) throw()
{
	ft::Rb_tree_node *&root = header.parent;

	x->parent = p;
	x->left = 0;
	x->right = 0;
	x->color = ft::red;

	if (insert_left)
	{
		p->left = x;

		if (p == &header)
		{
			header.parent = x;
			header.right = x;
		}
		else if (p == header.left)
			header.left = x;
	}
	else
	{
		p->right = x;

		if (p == header.right)
			header.right = x;
	}
	while (x != root && x->parent->color == ft::red)
	{
		ft::Rb_tree_node *const xpp = x->parent->parent;

		if (x->parent == xpp->left)
		{
			ft::Rb_tree_node *const y = xpp->right;
			if (y && y->color == ft::red)
			{
				x->parent->color = ft::black;
				y->color = ft::black;
				xpp->color = ft::red;
				x = xpp;
			}
			else
			{
				if (x == x->parent->right)
				{
					x = x->parent;
					ft::Rb_tree_rotate_left(x, root);
				}
				x->parent->color = ft::black;
				xpp->color = ft::red;
				ft::Rb_tree_rotate_right(xpp, root);
			}
		}
		else
		{
			ft::Rb_tree_node *const y = xpp->left;
			if (y && y->color == ft::red)
			{
				x->parent->color = ft::black;
				y->color = ft::black;
				xpp->color = ft::red;
				x = xpp;
			}
			else
			{
				if (x == x->parent->left)
				{
					x = x->parent;
					ft::Rb_tree_rotate_right(x, root);
				}
				x->parent->color = ft::black;
				xpp->color = ft::red;
				ft::Rb_tree_rotate_left(xpp, root);
			}
		}
	}
	root->color = ft::black;
}

ft::Rb_tree_node *ft::Rb_tree_rebalance_for_erase(ft::Rb_tree_node *const z, ft::Rb_tree_node &header) throw()
{
	ft::Rb_tree_node *&root = header.parent;
	ft::Rb_tree_node *&leftmost = header.left;
	ft::Rb_tree_node *&rightmost = header.right;
	ft::Rb_tree_node *y = z;
	ft::Rb_tree_node *x = 0;
	ft::Rb_tree_node *parent = 0;

	if (y->left == 0)
		x = y->right;
	else if (y->right == 0)
		x = y->left;
	else
	{
		y = y->right;
		while (y->left != 0)
			y = y->left;
		x = y->right;
	}
	if (y != z)
	{
		z->left->parent = y;
		y->left = z->left;
		if (y != z->right)
		{
			parent = y->parent;
			if (x)
				x->parent = y->parent;
			y->parent->left = x;
			y->right = z->right;
			z->right->parent = y;
		}
		else
			parent = y;
		if (root == z)
			root = y;
		else if (z->parent->left == z)
			z->parent->left = y;
		else
			z->parent->right = y;
		y->parent = z->parent;
		std::swap(y->color, z->color);
		y = z;
	}
	else
	{
		parent = y->parent;
		if (x)
			x->parent = y->parent;
		if (root == z)
			root = x;
		else if (z->parent->left == z)
			z->parent->left = x;
		else
			z->parent->right = x;
		if (leftmost == z)
		{
			if (z->right == 0)
				leftmost = z->parent;
			else
				leftmost = ft::Rb_tree_node::minimum(x);
		}
		if (rightmost == z)
		{
			if (z->left == 0)
				rightmost = z->parent;
			else
				rightmost = ft::Rb_tree_node::maximum(x);
		}
	}
	if (y->color != ft::red)
	{
		while (x != root && (x == 0 || x->color == ft::black))
			if (x == parent->left)
			{
				ft::Rb_tree_node *w = parent->right;
				if (w->color == ft::red)
				{
					w->color = ft::black;
					parent->color = ft::red;
					ft::Rb_tree_rotate_left(parent, root);
					w = parent->right;
				}
				if ((w->left == 0 ||
						w->left->color == ft::black) &&
					(w->right == 0 ||
						w->right->color == ft::black))
				{
					w->color = ft::red;
					x = parent;
					parent = parent->parent;
				}
				else
				{
					if (w->right == 0 || w->right->color == ft::black)
					{
						w->left->color = ft::black;
						w->color = ft::red;
						ft::Rb_tree_rotate_right(w, root);
						w = parent->right;
					}
					w->color = parent->color;
					parent->color = ft::black;
					if (w->right)
						w->right->color = ft::black;
					ft::Rb_tree_rotate_left(parent, root);
					break;
				}
			}
			else
			{
				// same as above, with right <-> left.
				ft::Rb_tree_node *w = parent->left;
				if (w->color == ft::red)
				{
					w->color = ft::black;
					parent->color = ft::red;
					ft::Rb_tree_rotate_right(parent, root);
					w = parent->left;
				}
				if ((w->right == 0 ||
						w->right->color == ft::black) &&
					(w->left == 0 ||
						w->left->color == ft::black))
				{
					w->color = ft::red;
					x = parent;
					parent = parent->parent;
				}
				else
				{
					if (w->left == 0 || w->left->color == ft::black)
					{
						w->right->color = ft::black;
						w->color = ft::red;
						ft::Rb_tree_rotate_left(w, root);
						w = parent->left;
					}
					w->color = parent->color;
					parent->color = ft::black;
					if (w->left)
						w->left->color = ft::black;
					ft::Rb_tree_rotate_right(parent, root);
					break;
				}
			}
		if (x)
			x->color = ft::black;
	}
	return y;
}
