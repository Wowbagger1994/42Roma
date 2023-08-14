#ifndef MAP_HPP
# define MAP_HPP

#include <map>
#include "rb_tree.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class map
{
	public:
		typedef Key																					key_type;
		typedef T																					mapped_type;
		typedef	pair<const Key, T>																	value_type;
		typedef	Compare																				key_compare;
		typedef Alloc																				allocator_type;
		typedef typename allocator_type::reference													reference;
		typedef typename allocator_type::const_reference											const_reference;
		typedef typename allocator_type::pointer													pointer;
		typedef typename allocator_type::const_pointer												const_pointer;
		typedef Rb_tree<key_type, value_type, Select1st<value_type>, key_compare, allocator_type>	tree_type;
		typedef typename tree_type::iterator														iterator;
		typedef typename tree_type::const_iterator													const_iterator;
		typedef reverse_iterator<const_iterator>													const_reverse_iterator;
		typedef reverse_iterator<iterator>															reverse_iterator;
		typedef ptrdiff_t																			difference_type;
		typedef size_t																				size_type;

		class value_compare : std::binary_function<value_type,value_type,bool>
		{
		friend class map<Key,T,Compare,Alloc>;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
		public:
			typedef bool 				result_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};
	private:
		key_compare _comp;
		allocator_type _alloc;
		Rb_tree<key_type, value_type, Select1st<value_type>, key_compare, allocator_type> _tree;
	public:
// constructor
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree(comp, alloc) { return; }
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree(first, last, comp, alloc)
		{ return; }
		map (const map& x)  : _comp(x._comp) { *this = x; }
// destructor
		~map() {}
// operator
		map& operator= (const map& x)
		{
			_tree = x._tree;
			return *this;
		}
// Iterators
		iterator begin() { return _tree.begin(); }
		const_iterator begin() const { return _tree.begin(); }
		iterator end() { return _tree.end(); }
		const_iterator end() const { return _tree.end(); }
		reverse_iterator rbegin() { return _tree.rbegin(); }
		const_reverse_iterator rbegin() const { return _tree.rbegin(); }
		reverse_iterator rend() { return _tree.rend(); }
		const_reverse_iterator rend() const { return _tree.rend(); }
// Capacity
		bool empty() const { return _tree.empty(); }
		size_type size() const { return _tree.size(); }
		size_type max_size() const {{ return _tree.max_size(); }}
// Element access
		mapped_type& operator[] (const key_type& k)
		{
			iterator i = lower_bound(k);
			if (i == end() || key_comp()(k, (*i).first))
				i = insert(i, value_type(k, mapped_type()));
			return (*i).second;
			// return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
		}
		mapped_type& at (const key_type& k)
		{
			iterator i = _tree.find(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw std::out_of_range("map::at: key not found");
			return i->second;
		}
		const mapped_type& at (const key_type& k) const
		{
			const_iterator i = _tree.find(k);
			if (i == end() || key_comp()(k, (*i).first))
				throw std::out_of_range("map::at: key not found");
			return i->second;
		}
// Modifiers
		pair<iterator,bool> insert (const value_type& val)
		{
			return _tree.insert(val);
		}
		iterator insert (iterator position, const value_type& val)
		{
			return _tree.insert(position, val);
		}
		template <class InputIterator>
 		void insert (InputIterator first, InputIterator last)
		{
			return _tree.insert(first, last);
		}
		void erase (iterator position)
		{
			_tree.erase(position);
		}
		size_type erase (const key_type& k)
		{
			return _tree.erase(k);
		}
		void erase (iterator first, iterator last)
		{
			_tree.erase(first, last);
		}
		void swap (map& x) { _tree.swap(x._tree); }
		void clear() { _tree.clear(); }
// Observers
		key_compare key_comp() const { return _comp; }
		value_compare value_comp() const { return value_compare(_tree.key_comp());}
// Operations
		iterator find (const key_type& k) { return _tree.find(k); }
		const_iterator find (const key_type& k) const { return _tree.find(k); }
		size_type count (const key_type& k) const { return _tree.count(k); }
		iterator lower_bound (const key_type& k) { return _tree.lower_bound(k); }
		const_iterator lower_bound (const key_type& k) const { return _tree.lower_bound(k); }
		iterator upper_bound (const key_type& k) { return _tree.upper_bound(k); }
		const_iterator upper_bound (const key_type& k) const { return _tree.upper_bound(k); }
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return _tree.equal_range(k); }
		pair<iterator,iterator> equal_range (const key_type& k) { return _tree.equal_range(k); }
// Allocator
		allocator_type get_allocator() const { return _tree.get_allocator(); }

		friend bool operator==(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (lhs._tree == rhs._tree); }

		friend bool operator!=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return !(lhs == rhs); }

		friend bool operator<(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (lhs._tree < rhs._tree); }

		friend bool operator>(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (rhs < lhs); }

		friend bool operator<=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return !(lhs > rhs); }

		friend bool operator>=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs){ return !(lhs < rhs); }

		friend void swap(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs) { lhs.swap(rhs); }

	};

}

#endif
