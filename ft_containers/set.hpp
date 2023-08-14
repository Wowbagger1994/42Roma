#ifndef SET_HPP
# define SET_HPP

#include "rb_tree.hpp"

namespace ft
{

template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set
{
	public:
		typedef T																					key_type;
		typedef T																					value_type;
		typedef	Compare																				key_compare;
		typedef	Compare																				value_compare;
		typedef Alloc																				allocator_type;
		typedef typename allocator_type::reference													reference;
		typedef typename allocator_type::const_reference											const_reference;
		typedef typename allocator_type::pointer													pointer;
		typedef typename allocator_type::const_pointer												const_pointer;
		typedef Rb_tree<key_type, value_type, Select1st<value_type>, key_compare, allocator_type>	tree_type;
		typedef typename tree_type::const_iterator													iterator;
		typedef typename tree_type::const_iterator													const_iterator;
		typedef reverse_iterator<const_iterator>													const_reverse_iterator;
		typedef reverse_iterator<iterator>															reverse_iterator;
		typedef ptrdiff_t																			difference_type;
		typedef size_t																				size_type;
	private:
		key_compare _comp;
		allocator_type _alloc;
		Rb_tree<key_type, value_type, Identity<key_type> ,key_compare, allocator_type> _tree;
	public:
// constructor
		explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree(comp, alloc) { return; }
		template <class InputIterator>
		set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _tree(first, last, comp, alloc)
		{ return; }
		set (const set& x)  : _comp(x._comp) { *this = x; }
// destructor
		~set() {}
// operator
		set& operator= (const set& x)
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
		void swap (set& x) { _tree.swap(x._tree); }
		void clear() { _tree.clear(); }
// Observers
		key_compare key_comp() const { return _comp; }
		value_compare value_comp() const { return value_compare(_tree.key_comp());}
// Operations
		iterator find (const key_type& k) const { return _tree.find(k); }
		size_type count (const key_type& k) const { return _tree.count(k); }
		iterator lower_bound (const key_type& k) const { return _tree.lower_bound(k); }
		iterator upper_bound (const key_type& k) const { return _tree.upper_bound(k); }
		pair<iterator,iterator> equal_range (const key_type& k) const { return _tree.equal_range(k); }
// Allocator
		allocator_type get_allocator() const { return _tree.get_allocator(); }

		friend bool operator==(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs) { return (lhs._tree == rhs._tree); }

		friend bool operator!=(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs) { return !(lhs == rhs); }

		friend bool operator<(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs) { return (lhs._tree < rhs._tree); }

		friend bool operator>(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs) { return (rhs < lhs); }

		friend bool operator<=(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs) { return !(lhs > rhs); }

		friend bool operator>=(const set<T, Compare, Alloc> & lhs, const set<T, Compare, Alloc> & rhs){ return !(lhs < rhs); }
};

}

#endif
