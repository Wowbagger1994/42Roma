#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "pair.hpp"
#include "reverse_iterator.hpp"

namespace ft
{

	enum Rb_tree_color
	{
		red = false,
		black = true
	};

	struct Rb_tree_node
	{
		Rb_tree_color color;
		Rb_tree_node *parent;
		Rb_tree_node *left;
		Rb_tree_node *right;

		static Rb_tree_node *minimum(Rb_tree_node *x)
		{
			while (x->left != 0)
				x = x->left;
			return x;
		}

		static const Rb_tree_node *minimum(const Rb_tree_node *x)
		{
			while (x->left != 0)
				x = x->left;
			return x;
		}

		static Rb_tree_node *maximum(Rb_tree_node *x)
		{
			while (x->right != 0)
				x = x->right;
			return x;
		}

		static const Rb_tree_node *maximum(const Rb_tree_node *x)
		{
			while (x->right != 0)
				x = x->right;
			return x;
		}
	};

	template <typename Value>
	struct Rb_tree_node_pointer : public Rb_tree_node
	{
		typedef Rb_tree_node_pointer<Value>*	node_pointer;

		Rb_tree_node_pointer(Value x) : value_field((x)) {}
		Value value_field;

		Value *valptr() { return std::addressof(value_field); }
		const Value *valptr() const { return std::addressof(value_field); }
	};

	template <typename KeyCompare>
	struct Rb_tree_keyCompare
	{
		KeyCompare keyCompare;

		Rb_tree_keyCompare() : keyCompare() {}

		Rb_tree_keyCompare(const KeyCompare &comp) : keyCompare(comp) {}
	};

	struct Rb_tree_header
	{
		Rb_tree_node _header;
		size_t _size;
		Rb_tree_header()
		{
			_header.color = red;
			reset();
		}

		void move_data(Rb_tree_header &from)
		{
			_header.color = from._header.color;
			_header.parent = from._header.parent;
			_header.left = from._header.left;
			_header.right = from._header.right;
			_header.parent->parent = &_header;
			_size = from._size;

			from.reset();
		}

		void reset()
		{
			_header.parent = 0;
			_header.left = &_header;
			_header.right = &_header;
			_size = 0;
		}
	};

	Rb_tree_node *Rb_tree_increment(Rb_tree_node *x) throw();

	const Rb_tree_node *Rb_tree_increment(const Rb_tree_node *x) throw();

	Rb_tree_node *Rb_tree_decrement(Rb_tree_node *x) throw();

	const Rb_tree_node *Rb_tree_decrement(const Rb_tree_node *x) throw();

	template <typename T>
	struct Rb_tree_iterator
	{
		typedef std::bidirectional_iterator_tag							iterator_category;
		typedef typename ft::iterator_traits<T*>::value_type  			value_type;
		typedef typename ft::iterator_traits<T*>::reference 			reference;
		typedef typename ft::iterator_traits<T*>::pointer 				pointer;
		typedef typename ft::iterator_traits<T*>::difference_type 		difference_type;
		typedef Rb_tree_node_pointer<T>* 								node_pointer;

		Rb_tree_node *node;

		Rb_tree_iterator() : node(NULL) {}
		template <class Node>
		Rb_tree_iterator(Node x) : node((Rb_tree_node *)x) {}
		template <class Type>
		Rb_tree_iterator(const Rb_tree_iterator<Type> & x) : node(x.node) {}

		reference operator*() const { return *static_cast<node_pointer>(node)->valptr(); }

		pointer operator->() const { return static_cast<node_pointer>(node)->valptr(); }

		Rb_tree_iterator<T> &operator++()
		{
			node = Rb_tree_increment(node);
			return *this;
		}

		Rb_tree_iterator<T> operator++(int)
		{
			Rb_tree_iterator<T> tmp = *this;
			node = Rb_tree_increment(node);
			return tmp;
		}

		Rb_tree_iterator<T> &operator--()
		{
			node = Rb_tree_decrement(node);
			return *this;
		}

		Rb_tree_iterator<T> operator--(int)
		{
			Rb_tree_iterator<T> tmp = *this;
			node = Rb_tree_decrement(node);
			return tmp;
		}

	};

	template <typename T>
	struct Rb_const_tree_iterator
	{
		typedef std::bidirectional_iterator_tag							iterator_category;
		typedef typename ft::iterator_traits<const T*>::value_type  			value_type;
		typedef typename ft::iterator_traits<const T*>::reference 			reference;
		typedef typename ft::iterator_traits<const T*>::pointer 				pointer;
		typedef typename ft::iterator_traits<const T*>::difference_type 		difference_type;
		typedef Rb_tree_node_pointer<T>* 								node_pointer;

		Rb_tree_node *node;

		Rb_const_tree_iterator() : node(NULL) {}
		template <class Node>
		Rb_const_tree_iterator(Node x) : node((Rb_tree_node *)x) {}
		template <class Type>
		Rb_const_tree_iterator(const Rb_tree_iterator<Type> & x) : node(x.node) {}
		template <class Type>
		Rb_const_tree_iterator(const Rb_const_tree_iterator<Type> & x) : node(x.node) {}

		reference operator*() const { return *static_cast<node_pointer>(node)->valptr(); }

		pointer operator->() const { return static_cast<node_pointer>(node)->valptr(); }

		Rb_const_tree_iterator<T> &operator++()
		{
			node = Rb_tree_increment(node);
			return *this;
		}

		Rb_const_tree_iterator<T> operator++(int)
		{
			Rb_const_tree_iterator<T> tmp = *this;
			node = Rb_tree_increment(node);
			return tmp;
		}

		Rb_const_tree_iterator<T> &operator--()
		{
			node = Rb_tree_decrement(node);
			return *this;
		}

		Rb_const_tree_iterator<T> operator--(int)
		{
			Rb_const_tree_iterator<T> tmp = *this;
			node = Rb_tree_decrement(node);
			return tmp;
		}

	};

	template<class A, class B>
	bool operator==(const Rb_tree_iterator<A> &x, const Rb_tree_iterator<B> &y) { return x.node == y.node; }
	template<class A, class B>
	bool operator==(const Rb_const_tree_iterator<A> &x, const Rb_const_tree_iterator<B> &y) { return x.node == y.node; }
	template<class A, class B>
	bool operator==(const Rb_const_tree_iterator<A> &x, const Rb_tree_iterator<B> &y) { return x.node == y.node; }
	template<class A, class B>
	bool operator==(const Rb_tree_iterator<A> &x, const Rb_const_tree_iterator<B> &y) { return x.node == y.node; }
	template<class A>
	bool operator!=(const Rb_tree_iterator<A> &x, const Rb_tree_iterator<A> &y) { return x.node != y.node; }
	template<class A>
	bool operator!=(const Rb_tree_iterator<A> &x, const Rb_const_tree_iterator<A> &y) { return x.node != y.node; }
	template<class A>
	bool operator!=(const Rb_const_tree_iterator <A> &x, const Rb_tree_iterator<A> &y) { return x.node != y.node; }
	template<class A>
	bool operator!=(const Rb_const_tree_iterator <A> &x, const Rb_const_tree_iterator<A> &y) { return x.node != y.node; }

	void Rb_tree_rotate_left(Rb_tree_node *const x, Rb_tree_node *&root);

	void Rb_tree_rotate_right(Rb_tree_node *const x, Rb_tree_node *&root);

	void tree_insert_and_rebalance(const bool __insert_left, Rb_tree_node *x, Rb_tree_node *p, Rb_tree_node &header) throw();

	Rb_tree_node *Rb_tree_rebalance_for_erase(Rb_tree_node *const z, Rb_tree_node &header) throw();

	template <typename Key, typename Value, typename KeyOfValue, typename Compare, typename Alloc>
	class Rb_tree
	{
		typedef typename Alloc::template rebind<Rb_tree_node_pointer<Value> >::other node_allocator;

	protected:
		typedef Rb_tree_node_pointer<Value>*		node_pointer;
		typedef const Rb_tree_node_pointer<Value>*	const_node_pointer;

	private:
		struct Reuse_or_alloc_node
		{
			Reuse_or_alloc_node(Rb_tree &tree) : _root(tree.root()), _nodes(tree.rightmost()), _tree(tree)
			{
				if (_root)
				{
					_root->parent = 0;

					if (_nodes->left)
						_nodes = _nodes->left;
				}
				else
					_nodes = 0;
			}

			~Reuse_or_alloc_node()
			{
				_tree.erase_without_rebalancing(static_cast<node_pointer>(_root));
			}

			template <typename Arg>
			node_pointer operator()(Arg arg)
			{
				node_pointer node = static_cast<node_pointer>(extract());
				if (node)
				{
					_tree.destroy_node(node);
					_tree.construct_node(node, arg);
					return node;
				}

				return _tree.create_node(arg);
			}

		private:
			Rb_tree_node *extract()
			{
				if (!_nodes)
					return _nodes;

				Rb_tree_node *node = _nodes;
				_nodes = _nodes->parent;
				if (_nodes)
				{
					if (_nodes->right == node)
					{
						_nodes->right = 0;

						if (_nodes->left)
						{
							_nodes = _nodes->left;

							while (_nodes->right)
								_nodes = _nodes->right;

							if (_nodes->left)
								_nodes = _nodes->left;
						}
					}
					else
						_nodes->left = 0;
				}
				else
					_root = 0;

				return node;
			}
			Rb_tree_node *_root;
			Rb_tree_node *_nodes;
			Rb_tree &_tree;

		};

		struct Alloc_node
		{
			Alloc_node(Rb_tree &tree) : _tree(tree) {}

			template <typename Arg>
			node_pointer operator()(Arg arg) const
			{
				return _tree.create_node(arg);
			}

		private:
			Rb_tree &_tree;
		};

	public:
		typedef Key 				key_type;
		typedef Value 				value_type;
		typedef value_type*			pointer;
		typedef const value_type*	const_pointer;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		typedef size_t				size_type;
		typedef ptrdiff_t			difference_type;
		typedef Alloc				allocator_type;

		node_allocator &get_node_allocator() { return this->impl; }

		const node_allocator &get_node_allocator() const { return this->impl; }

		allocator_type get_allocator() const { return allocator_type(get_node_allocator()); }

	protected:
		node_allocator _alloc_node;

		node_pointer get_node() { return _alloc_node.allocate(1); }

		void put_node(node_pointer p) { _alloc_node.deallocate(p, 1); }

		void construct_node(node_pointer node, const value_type &x)
		{
			try
			{
				get_node_allocator().construct(node, x);
			}
			catch(...)
			{
				put_node(node);
				throw;
			}
		}

		node_pointer create_node(const value_type &x)
		{
			node_pointer tmp = get_node();
			construct_node(tmp, x);
			return tmp;
		}
		void destroy_node(node_pointer p) { _alloc_node.destroy(p); }

		void drop_node(node_pointer p)
		{
			destroy_node(p);
			put_node(p);
		}

		template <bool MoveValue, typename NodeGen>
		node_pointer clone_node(const_node_pointer x, NodeGen &node_gen)
		{
			node_pointer tmp = node_gen(*x->valptr());
			tmp->color = x->color;
			tmp->left = 0;
			tmp->right = 0;
			return tmp;
		}

		template <typename KeyCompare>
		struct Rb_tree_impl : public node_allocator, public Rb_tree_keyCompare<KeyCompare>, public Rb_tree_header
		{
			typedef Rb_tree_keyCompare<KeyCompare> base_keyCompare;

			Rb_tree_impl() : node_allocator() {}

			Rb_tree_impl(const Rb_tree_impl &x) : node_allocator(), base_keyCompare(x.keyCompare), Rb_tree_header() {}

			Rb_tree_impl(const KeyCompare &comp, const node_allocator &allocator) : node_allocator(allocator), base_keyCompare(comp) {}
		};

		Rb_tree_impl<Compare> impl;

		Rb_tree_node *&root() { return this->impl._header.parent; }

		const Rb_tree_node *root() const { return this->impl._header.parent; }

		Rb_tree_node *&leftmost() { return this->impl._header.left; }

		const Rb_tree_node *leftmost() const { return this->impl._header.left; }

		Rb_tree_node *&rightmost() { return this->impl._header.right; }

		const Rb_tree_node *rightmost() const { return this->impl._header.right; }

		static const Key &key(const_node_pointer x) { return KeyOfValue()(x->value_field); }

		static node_pointer left(Rb_tree_node *x) { return static_cast<node_pointer>(x->left); }

		static const_node_pointer left(const Rb_tree_node *x) { return static_cast<const_node_pointer>(x->left); }

		static node_pointer right(Rb_tree_node *x) { return static_cast<node_pointer>(x->right); }

		static const_node_pointer right(const Rb_tree_node *x) { return static_cast<const_node_pointer>(x->right); }

		static const Key &key(const Rb_tree_node *x) { return key(static_cast<const_node_pointer>(x)); }

		static Rb_tree_node *minimum(Rb_tree_node *x) { return Rb_tree_node::minimum(x); }

		static const Rb_tree_node *minimum(const Rb_tree_node *x) { return Rb_tree_node::minimum(x); }

		static Rb_tree_node *maximum(Rb_tree_node *x) { return Rb_tree_node::maximum(x); }

		static const Rb_tree_node *maximum(const Rb_tree_node *x) { return Rb_tree_node::maximum(x); }

	public:
		typedef Rb_tree_iterator<value_type>		iterator;
		typedef Rb_const_tree_iterator<value_type>	const_iterator;

		typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef reverse_iterator<iterator>			reverse_iterator;

		pair<Rb_tree_node *, Rb_tree_node *> get_insert_unique_pos(const key_type &k)
		{
			typedef pair<Rb_tree_node *, Rb_tree_node *> Res;
			node_pointer x = static_cast<node_pointer>(impl._header.parent);
			Rb_tree_node *y = &impl._header;
			bool comp = true;
			while (x != 0)
			{
				y = x;
				comp = impl.keyCompare(k, key(x));
				x = comp ? left(x) : right(x);
			}

			iterator j = iterator(y);
			if (comp)
			{
				if (j == begin())
					return Res(x, y);
				else
					--j;
			}
			if (impl.keyCompare(key(j.node), k))
				return Res(x, y);
			return Res(j.node, 0);
		}

		pair<Rb_tree_node *, Rb_tree_node *> get_insert_hint_unique_pos(const_iterator &position, const key_type &k)
		{
			typedef pair<Rb_tree_node *, Rb_tree_node *> Res;

			if (position == end())
			{
				if (size() > 0 && impl.keyCompare(key(rightmost()), k))
					return Res(0, rightmost());
				else
					return get_insert_unique_pos(k);
			}
			else if (impl.keyCompare(k, key(position.node)))
			{
				const_iterator before = position;
				if (position.node == leftmost())
					return Res(leftmost(), leftmost());
				else if (impl.keyCompare(key((--before).node), k))
				{
					if (right(before.node) == 0)
						return Res(0, before.node);
					else
						return Res(position.node, position.node);
				}
				else
					return get_insert_unique_pos(k);
			}
			else if (impl.keyCompare(key(position.node), k))
			{
				const_iterator after = position;
				if (position.node == rightmost())
					return Res(0, rightmost());
				else if (impl.keyCompare(k, key((++after).node)))
				{
					if (right(position.node) == 0)
						return Res(0, position.node);
					else
						return Res(after.node, after.node);
				}
				else
					return get_insert_unique_pos(k);
			}
			else
				return Res(position.node, 0);
		}

	private:
		enum
		{
			lvalue,
			rvalue
		};

		iterator upper_bound(node_pointer x, Rb_tree_node *y, const key_type &k)
		{
			while (x != 0)
				if (impl.keyCompare(k, key(x)))
					y = x, x = left(x);
				else
					x = right(x);
			return iterator(y);
		}

		const_iterator upper_bound(node_pointer x, const Rb_tree_node *y, const key_type &k) const
		{
			while (x != 0)
				if (impl.keyCompare(k, key(x)))
					y = x, x = left(x);
				else
					x = right(x);
			return const_iterator(y);
		}

		iterator lower_bound(node_pointer x, Rb_tree_node *y, const key_type &k)
		{
			while (x != 0)
				if (!impl.keyCompare(key(x), k))
					y = x, x = left(x);
				else
					x = right(x);
			return iterator(y);
		}

		const_iterator lower_bound(node_pointer x, const Rb_tree_node *y, const key_type &k) const
		{
			while (x != 0)
				if (!impl.keyCompare(key(x), k))
					y = x, x = left(x);
				else
					x = right(x);
			return const_iterator(y);
		}

		template <bool MoveValues, typename NodeGen>
		node_pointer copy_tree(const_node_pointer x, Rb_tree_node* p, NodeGen &node_gen)
		{
			node_pointer top = clone_node<MoveValues>(x, node_gen);
			top->parent = p;

			try
			{
				if (x->right)
					top->right = copy_tree<MoveValues>(right(x), top, node_gen);
				p = top;
				x = left(x);

				while (x != 0)
				{
					node_pointer y = clone_node<MoveValues>(x, node_gen);
					p->left = y;
					y->parent = p;
					if (x->right)
						y->right = copy_tree<MoveValues>(right(x), y, node_gen);
					p = y;
					x = left(x);
				}
			}
			catch(...)
			{
				erase_without_rebalancing(top);
				throw;
			}
			return top;
		}

		template <bool MoveValues, typename NodeGen>
		node_pointer copy_tree(const Rb_tree &x, NodeGen &gen)
		{
			node_pointer root = copy_tree<MoveValues>(static_cast<const_node_pointer>(x.impl._header.parent), end().node, gen);
			leftmost() = minimum(root);
			rightmost() = maximum(root);
			impl._size = x.impl._size;
			return root;
		}

		node_pointer copy_tree(const Rb_tree &x)
		{
			Alloc_node alloc_node(*this);
			return copy_tree<lvalue>(x, alloc_node);
		}

		template <typename NodeGen>
		iterator insert(Rb_tree_node *x, Rb_tree_node *p, const Value &v, NodeGen &node_gen)
		{
			bool insert_left = (x != 0 || p == static_cast<node_pointer>(&impl._header) || impl.keyCompare(KeyOfValue()(v), key(p)));

			node_pointer z = node_gen(v);

			tree_insert_and_rebalance(insert_left, z, p, this->impl._header);
			++impl._size;
			return iterator(z);
		}

		template <typename NodeGen>
		iterator insert_unique(const_iterator &position, const Value &v, NodeGen &node_gen)
		{
			pair<Rb_tree_node *, Rb_tree_node *> res = get_insert_hint_unique_pos(position, KeyOfValue()(v));

			if (res.second)
				return insert(res.first, res.second, v, node_gen);
			return iterator(res.first);
		}

		void erase_without_rebalancing(node_pointer x)
		{
			while (x != 0)
			{
				erase_without_rebalancing(right(x));
				node_pointer y = left(x);
				drop_node(x);
				x = y;
			}
		}

	public:
		Rb_tree() {}

		Rb_tree(const Compare &comp, const allocator_type &allocator = allocator_type()) : _alloc_node(node_allocator()), impl(comp, allocator_type(allocator)) {}

		template <typename InputIterator>
		Rb_tree(InputIterator first, InputIterator last, const Compare &comp, const allocator_type &allocator = allocator_type()) : _alloc_node(node_allocator()), impl(comp, allocator_type(allocator))
		{
			insert(first, last);
		}

		Rb_tree(const Rb_tree &x) : impl(x.impl)
		{
			if (x.root() != 0)
				root() = copy_tree(x);
		}

		~Rb_tree()
		{
			erase_without_rebalancing(static_cast<node_pointer>(impl._header.parent));
		}

		Rb_tree &operator=(const Rb_tree &x)
		{
			if (this != std::addressof(x))
			{
				Reuse_or_alloc_node roan(*this);
				impl.reset();
				impl.keyCompare = x.impl.keyCompare;
				if (x.root() != 0)
					root() = copy_tree<lvalue>(x, roan);
			}

			return *this;
		}

		Compare key_comp() const { return impl.keyCompare; }

		iterator begin() { return iterator(impl._header.left); }

		const_iterator begin() const { return const_iterator(impl._header.left); }

		iterator end() { return iterator(&impl._header); }

		const_iterator end() const { return const_iterator(&impl._header); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		bool empty() const { return impl._size == 0; }

		size_type size() const { return impl._size; }

		size_type max_size() const { return _alloc_node.max_size(); }

		void swap(Rb_tree &tree)
		{
			if (root() == 0)
			{
				if (tree.root() != 0)
					impl.move_data(tree.impl);
			}
			else if (tree.root() == 0)
				tree.impl.move_data(impl);
			else
			{
				std::swap(root(), tree.root());
				std::swap(leftmost(), tree.leftmost());
				std::swap(rightmost(), tree.rightmost());

				root()->parent = end().node;
				tree.root()->parent = tree.end().node;
				std::swap(this->impl._size, tree.impl._size);
			}
			std::swap(this->impl.keyCompare, tree.impl.keyCompare);
			std::swap(this->_alloc_node, tree._alloc_node);
		}

		pair<iterator, bool> insert(const value_type &v)
		{
			typedef pair<iterator, bool> Res;
			pair<Rb_tree_node *, Rb_tree_node *> res = get_insert_unique_pos(KeyOfValue()(v));

			if (res.second)
			{
				Alloc_node alloc_node(*this);
				return Res(insert(res.first, res.second, v, alloc_node), true);
			}
			return Res(iterator(res.first), false);
		}

		iterator insert(const_iterator pos, const value_type &x)
		{
			Alloc_node alloc_node(*this);
			return insert_unique(pos, x, alloc_node);
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			const_iterator pos = end();
			Alloc_node alloc_node(*this);
			for (; first != last; ++first)
				insert_unique(pos, *first, alloc_node);
		}

		void erase(iterator position)
		{
			node_pointer y = static_cast<node_pointer>(Rb_tree_rebalance_for_erase(const_cast<Rb_tree_node *>(position.node), this->impl._header));
			drop_node(y);
			--impl._size;
		}

		void erase(const_iterator position)
		{
			node_pointer y = static_cast<node_pointer>(Rb_tree_rebalance_for_erase(const_cast<Rb_tree_node *>(position.node), this->impl._header));
			drop_node(y);
			--impl._size;
		}

		size_type erase(const key_type &k)
		{
			pair<iterator, iterator> p = equal_range(k);
			const size_type old_size = size();
			erase(p.first, p.second);
			return old_size - size();
		}

		void erase(iterator first, iterator last)
		{
			if (first == begin() && last == end())
				clear();
			else
				while (first != last) erase(first++);
		}

		void erase(const_iterator first, const_iterator last)
		{
			if (first == begin() && last == end())
				clear();
			else
				while (first != last) erase(first++);
		}

		void clear()
		{
			erase_without_rebalancing(static_cast<node_pointer>(impl._header.parent));
			impl.reset();
		}

		// Set operations.
		iterator find(const key_type &k)
		{
			iterator j = lower_bound(k);
			return (j == end() || impl.keyCompare(k, key(j.node))) ? end() : j;
		}

		const_iterator find(const key_type &k) const
		{
			const_iterator j = lower_bound(k);
			return (j == end() || impl.keyCompare(k, key(j.node))) ? end() : j;
		}

		size_type count(const key_type &k) const
		{
			pair<const_iterator, const_iterator> p = equal_range(k);
			const size_type __n = std::distance(p.first, p.second);
			return __n;
		}

		iterator lower_bound(const key_type &k)
		{
			node_pointer x = static_cast<node_pointer>(impl._header.parent);;
			Rb_tree_node *y = end().node;
			while (x != 0)
				if (!impl.keyCompare(key(x), k))
				{
					y = x;
					x = left(x);
				}
				else
					x = right(x);
			return iterator(y);
		}

		const_iterator lower_bound(const key_type &k) const
		{
			node_pointer x = static_cast<node_pointer>(impl._header.parent);;
			const Rb_tree_node *y = end().node;
			while (x != 0)
				if (!impl.keyCompare(key(x), k))
				{
					y = x;
					x = left(x);
				}
				else
					x = right(x);
			return const_iterator(y);
		}

		iterator upper_bound(const key_type &k)
		{
			node_pointer x = static_cast<node_pointer>(impl._header.parent);;
			Rb_tree_node *y = end().node;
			while (x != 0)
				if (impl.keyCompare(k, key(x)))
				{
					y = x;
					x = left(x);
				}
				else
					x = right(x);
			return iterator(y);
		}

		const_iterator upper_bound(const key_type &k) const
		{
			node_pointer x = static_cast<node_pointer>(impl._header.parent);;
			Rb_tree_node *y = end().node;
			while (x != 0)
				if (impl.keyCompare(k, key(x)))
					y = x, x = left(x);
				else
					x = right(x);
			return const_iterator(y);
		}

		pair<iterator, iterator> equal_range(const key_type &k)
		{
			node_pointer x = static_cast<node_pointer>(impl._header.parent);;
			Rb_tree_node *y = end().node;
			while (x != 0)
			{
				if (impl.keyCompare(key(x), k))
					x = right(x);
				else if (impl.keyCompare(k, key(x)))
					y = x, x = left(x);
				else
				{
					node_pointer xu(x);
					Rb_tree_node *yu(y);
					y = x;
					x = left(x);
					xu = right(xu);
					return pair<iterator,iterator>(lower_bound(x, y, k),  upper_bound(xu, yu, k));
				}
			}
			return pair<iterator, iterator>(iterator(y), iterator(y));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			node_pointer x = static_cast<node_pointer>(impl._header.parent);;
			const Rb_tree_node *y = end().node;
			while (x != 0)
			{
				if (impl.keyCompare(key(x), k))
					x = right(x);
				else if (impl.keyCompare(k, key(x)))
					y = x, x = left(x);
				else
				{
					node_pointer xu(x);
					const Rb_tree_node *yu(y);
					y = x, x = left(x);
					xu = right(xu);
					return pair<const_iterator, const_iterator>(lower_bound(x, y, k), upper_bound(xu, yu, k));
				}
			}
			return pair<const_iterator, const_iterator>(const_iterator(y), const_iterator(y));
		}

		friend bool operator==(const Rb_tree &x, const Rb_tree &y)
		{
			return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
		}

		friend bool operator<(const Rb_tree &x, const Rb_tree &y)
		{
			return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
		}

	};
}

#endif
