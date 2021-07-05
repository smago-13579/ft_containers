/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:44:12 by smago             #+#    #+#             */
/*   Updated: 2021/05/16 13:40:36 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "iterator_map.hpp"
# include "reverse_iterator.hpp"
# include "vector.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, \
		class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef const Key											key_type;
		typedef T													mapped_type;
		typedef std::pair<key_type, mapped_type>					value_type;
		typedef Compare 											key_compare;									
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;

		typedef ft::iterator_map<value_type, key_compare>			iterator;
		typedef ft::const_iterator_map<value_type, key_compare>		const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef size_t												size_type;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

		class value_compare
		{
		friend class map;
		protected:
			Compare com;
			value_compare (Compare c) : com(c) {}
		public:
			typedef bool result;
			typedef value_type firstArg;
			typedef value_type secondArg;
			bool operator() (const value_type& lhs, const value_type& rhs) const
			{
				return com(lhs.first, rhs.first);
			}
		};
		/*						MAP  CONSTRUCTORS						*/
		explicit map (const key_compare& comp = key_compare(), \
			const allocator_type& alloc = allocator_type()): 
		comp(comp), alloc(alloc), root(NULL) 
		{
			_create_last_node();
		}
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last, \
			const key_compare& comp = key_compare(), \
			const allocator_type& alloc = allocator_type(), \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0): 
		comp(comp), alloc(alloc), root(NULL)
		{
			_create_last_node();
			while (first != last)
			{
				root = _create_node(*first, root, root);
				root = _balance_all_nodes(root);
				first++;
			}
			if (root)
				_last_node_init();
		}

		map (const map& x): comp(x.comp), alloc(x.alloc), root(NULL)
		{
			_create_last_node();
			*this = x; 
		}

		/*				assign operator									*/
		map&	operator=(const map& x)
		{
			if (this != &x)
			{
				this->_destroy_map();
				for (const_iterator it = x.begin(); it != x.end(); it++)
				{
					root = _create_node(*it, root, root);
					root = _balance_all_nodes(root);
				}
				if (root)
					_last_node_init();
			}
			return (*this);
		}
		
		/*		iterator begin() 										*/
		iterator	begin()
		{
			if (!root)
				return (this->end());
	
			node_map* tmp = root;
			while (tmp->left)
				tmp = tmp->left;
			return (iterator(tmp, root, last_node));
		}

		/*			iterator end()										*/
		iterator	end() { return (iterator(last_node, root, last_node)); }

		/*			const_iterator begin()								*/
		const_iterator	begin() const 
		{
			if (!root)
				return (this->end());
	
			node_map* tmp = root;
			while (tmp->left)
				tmp = tmp->left;
			return (const_iterator(tmp, root, last_node));
		}

		/*			const_iterator end()								*/
		const_iterator	end() const { return (const_iterator(last_node, root, last_node)); }

		/*			reverse_iterator	rbegin()						*/
		reverse_iterator	rbegin() 
		{
			return (reverse_iterator(end()));
		}

		/*			reverse_iterator	rend()							*/
		reverse_iterator	rend()	{ return (reverse_iterator(begin())); }

		/*			const_reverse_iterator	rbegin()					*/
		const_reverse_iterator	rbegin() const 
		{
			return (const_reverse_iterator(end()));
		}

		/*			const_reverse_iterator	rend()						*/
		const_reverse_iterator	rend()	const
		{
			return (const_reverse_iterator(begin()));
		}

		/*				----EMPTY----									*/
		bool empty() const { return (root == NULL); }

		/*				SIZE && MAX_SIZE								*/
		size_type		size() const
		{
			size_type i = 0;
			for (const_iterator it = begin(); it != end(); it++)
				i++;
			return (i);
		}

		size_type		max_size() const
		{
			size_type i = std::numeric_limits<size_type>::max() / (sizeof(ft::node_map<T>));
			return (i);
		}

		/*				OPERATOR[]										*/
		mapped_type&	operator[] (const key_type& k)
		{
			return (*((this->insert(std::make_pair(k, mapped_type()))).first)).second;
		}

		/*				INSERT FUNCTIONS								*/
		std::pair<iterator, bool>	insert (const value_type& val)
		{
			node_map* tmp = _create_node(val, root, root);
			root = _balance_all_nodes(root);
	
			if (tmp)
			{
				tmp = _find_key(val, root);
				return (std::make_pair(iterator(tmp, root, last_node), true));
			}
			else
			{
				tmp = _find_key(val, root);
				return (std::make_pair(iterator(tmp, root, last_node), false));
			}
		}

		iterator	insert (iterator position, const value_type& val)
		{
			position = this->insert(val).first;
			return (position);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last,\
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			InputIterator it = first;
			while (it != last)
			{
				this->insert(it, *it);
				it++;
			}
		}

		/*						----ERASE----							*/
		void 	erase(iterator position)
		{
			node_map* tmp = _find_key(*position, root);
			if (tmp)
			{
				_destroy_node(tmp);
			}
		}

		size_type	erase(const key_type& k)
		{
			iterator it = find(k);
			if (it != end())
			{
				erase(it);
				return (1);
			}
			return (0);
		}

		void	erase(iterator first, iterator last)
		{
			ft::vector<Key> A;
			while (first != last)
			{
				A.push_back(first->first);
				first++;
			}
			while (A.size())
			{
				erase(A.back());
				A.pop_back();
			}
		}

		/*						void	swap()							*/
		void	swap(map& x)
		{
			key_compare 			tmp_comp = this->comp;
			allocator_type 			tmp_alloc = this->alloc;
			allocNode 				tmp_n_alloc = this->n_alloc;
			node_map* 				tmp_root = this->root;
			node_map*				tmp_last_node = this->last_node;
			
			this->comp = x.comp;
			this->alloc = x.alloc;
			this->n_alloc = x.n_alloc;
			this->root = x.root;
			this->last_node = x.last_node;

			x.comp = tmp_comp;
			x.alloc = tmp_alloc;
			x.n_alloc = tmp_n_alloc;
			x.root = tmp_root;
			x.last_node = tmp_last_node;
		}

		/*						void clear()							*/
		void	clear() { this->_destroy_map(); }

		/*						key_compare 							*/
		key_compare 	key_comp() const { return this->comp; }

		/*						value_compare							*/
		value_compare	value_comp() const
		{
			return (value_compare(comp));
		}

		/*						----FIND----							*/
		iterator	find(const key_type& k)
		{
			node_map* tmp = root;
			while (tmp && tmp->data.first != k && tmp != last_node)
			{				
				if (comp(k, tmp->data.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (tmp == last_node || tmp == NULL)
				return (end());
			return (iterator(tmp, root, last_node));
		}

		const_iterator	find(const key_type& k) const
		{
			node_map* tmp = root;
			while (tmp && tmp->data.first != k && tmp != last_node)
			{				
				if (comp(k, tmp->data.first))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			if (tmp == last_node || tmp == NULL)
				return (end());
			return (const_iterator(tmp, root, last_node));
		}

		/*						----COUNT---- 							*/
		size_type count (const key_type& k) const
		{
			node_map* tmp = _find_key(std::make_pair(k, mapped_type()), root);
			if (tmp)
				return (1);
			return (0);
		}

		/*						----LOWER_BOUND----						*/
		iterator	lower_bound(const key_type& k)
		{
			iterator it = begin();
			while (this->comp(it->first, k) && it != end())
				it++;
			return (it);
		}

		const_iterator	lower_bound(const key_type& k) const
		{
			const_iterator it = begin();
			while (this->comp(it->first, k) && it != end())
				it++;
			return (it);
		}

		/*						----UPPER_BOUND----						*/
		iterator	upper_bound(const key_type& k)
		{
			iterator it = begin();
			while (!this->comp(k, it->first) && it != end())
				it++;
			return (it);
		}

		const_iterator	upper_bound(const key_type& k) const
		{
			const_iterator it = begin();
			while (!this->comp(k, it->first) && it != end())
				it++;
			return (it);
		}

		/*						----EQUAL_RANGE----						*/
		std::pair<iterator, iterator>	equal_range(const key_type& k)
		{
			iterator it = lower_bound(k);
			iterator itz = upper_bound(k);
			return ( std::make_pair(it, itz) );
		}

		std::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
		{
			const_iterator it = lower_bound(k);
			const_iterator itz = upper_bound(k);
			return ( std::make_pair(it, itz) );
		}

		/*						----ALLOCATOR----						*/
		allocator_type	get_allocator() const
		{
			return (this->alloc);
		}

		/*						----PRINT TREE----						*/
		/** These methods are not included in the 
		*** container map. They can be used to 
		***	check the balance of a tree.
		**/
		/**
		void	treeprint()
		{
			int i = 0;
			while (i <= _height(root) - 1)
			{
				printlv(i);
				i++;
				std::cout << std::endl;
			}
		}

		void	printlv(int n) 
		{
			node_map* temp =root;
			int val = pow(2, _height(root) - n + 1);
			std::cout << std::setw(val) << "";
			dispLV(temp, n, val);
		}

		void	dispLV(node_map<value_type>* p, int lv, int d)
		{
			int disp = 2 * d;
			if (lv == 0)
			{
				if (p == NULL)
				{

					std::cout << " x ";
					std::cout << std::setw(disp - 3) << "";
					return;
				}
				else 
				{
					// int result = ((p->data.first <= 1) ? 1 : log10(p->data.first) + 1);
					std::cout << " " << p->data.first << " ";
					std::cout << std::setw(disp - 3) << "";
				}
			}
			else
			{
				if (p == NULL && lv >= 1)
				{
					dispLV(NULL, lv - 1, d);
					dispLV(NULL, lv - 1, d);
				}
				else
				{
					dispLV(p->left, lv - 1, d);
					dispLV(p->right, lv - 1, d);
				}
			}
		}
		**/

		/*					----Destructor----						*/
		~map() 
		{
			_destroy_map();
			_destroy_last_node();
		}

		/*					----PRIVATE----							*/
	private:
		typedef ft::node_map<value_type>							node_map;
		typedef typename allocator_type::template 
			rebind<node_map>::other									allocNode;

		key_compare 			comp;
		allocator_type 			alloc;
		allocNode 				n_alloc;
		node_map* 				root;
		node_map*				last_node;

		/*		--------------PRIVATE FUNCTIONS--------------			*/

		node_map*		_create_node(const value_type& val, node_map* tmp, node_map* last)
		{
			if (tmp == NULL)
			{
				if (!root)
					tmp = _create_root(val);
				else
				{
					tmp = n_alloc.allocate(1);
					n_alloc.construct(tmp, node_map(val));
					tmp->left = NULL;
					tmp->right = NULL;
					tmp->prev = last;
				}
			}
			else if (comp(val.first, tmp->data.first))
			{
				last = tmp->left;
				tmp->left = _create_node(val, tmp->left, tmp);
				if (!tmp->left)
				{
					tmp->left = last;
					return (NULL);
				}
			}
			else if (tmp->right == last_node && comp(tmp->data.first, val.first))
			{
				tmp->right = NULL;
				tmp->right = _create_node(val, tmp->right, tmp);
				_last_node_init();
			}
			else if (comp(tmp->data.first, val.first))
			{
				last = tmp->right;
				tmp->right = _create_node(val, tmp->right, tmp);
				if (!tmp->right)
				{
					tmp->right = last;
					return (NULL);
				}
			}
			else 
				return (NULL);
			return (tmp);
		}

		int				_height_diff(node_map* tmp)
		{
			return _height(tmp->right) - _height(tmp->left);
		}

		node_map*		_rotate_right(node_map* tmp)
		{
			node_map* p = tmp->left;
			tmp->left = p->right;
			if (p->right)
				p->right->prev = tmp;
			p->right = tmp;
			
			p->prev = tmp->prev;
			tmp->prev = p;
		
			return p;
		}

		node_map*		_rotate_left(node_map* tmp)
		{
			node_map* p = tmp->right;
			tmp->right = p->left;
			if (p->left)
				p->left->prev = tmp;
			p->left = tmp;
			
			p->prev = tmp->prev;
			tmp->prev = p;
		
			return p;
		}

		node_map* 		_balance_all_nodes(node_map* tmp)
		{
			tmp = _nodes_balance(tmp);
			if (tmp->left && tmp->right && tmp->right != last_node)
			{
				tmp->left = _balance_all_nodes(tmp->left);
				tmp->right = _balance_all_nodes(tmp->right);
			}
			else if (tmp->left)
				tmp->left = _balance_all_nodes(tmp->left);
			else if (tmp->right && tmp->right != last_node)
				tmp->right = _balance_all_nodes(tmp->right);
			return (tmp);
		}

		node_map*		_nodes_balance(node_map* tmp)
		{
			if (_height_diff(tmp) >= 2)
			{
				if (_height_diff(tmp->right) < 0)
					tmp->right = _rotate_right(tmp->right);
				return _rotate_left(tmp);
			}
			if (_height_diff(tmp) <= -2)
			{
				if (_height_diff(tmp->left) > 0)
					tmp->left = _rotate_left(tmp->left);
				return _rotate_right(tmp);
			}
			return (tmp);
		}

		int				_height(node_map* tmp, int i = 1)
		{
			int x;
			int y;
			if (tmp && tmp != last_node)
			{
				if (tmp->left && tmp->right && tmp->right != last_node)
				{
					x = _height(tmp->left, i + 1);
					y = _height(tmp->right, i + 1);
					i = (x > y) ? x : y;
				}
				else if (tmp->left)
					i = _height(tmp->left, i + 1);
				else if (tmp->right && tmp->right != last_node)
					i = _height(tmp->right, i + 1);
			}
			else
				return (0);
			
			return (i);
		}

		node_map*		_find_key(const value_type& val, node_map* tmp) const
		{
			while (tmp && val.first != tmp->data.first && tmp != last_node)
			{
				if (comp(val.first, tmp->data.first))
					tmp = tmp->left;
				else 
					tmp = tmp->right;
			}
			if (tmp == last_node)
				return (NULL);
			return (tmp);
		}

		node_map*		_create_root(const value_type& val)
		{
			root = n_alloc.allocate(1);
			n_alloc.construct(root, node_map(val));
			root->left = NULL;
			root->right = last_node;
			root->prev = NULL;
			_last_node_init();
			return (root);
		}

		void			_create_last_node()
		{
			last_node = n_alloc.allocate(1);
			n_alloc.construct(last_node, node_map());
			last_node->right = last_node;
			last_node->left = last_node;
			last_node->prev = last_node;
		}

		void			_last_node_init()
		{
			last_node->right = last_node;

			node_map* tmp = root;
			while (tmp->right && tmp->right != last_node)
				tmp = tmp->right;
			last_node->left = tmp;
			tmp->right = last_node;

			last_node->prev = root;
		}

		void			_transfer_node(node_map* d, node_map* n)
		{
			if (n->prev)
			{
				if (n->prev->left == n)
					n->prev->left = NULL;
				else if (n->prev->right == n)
					n->prev->right = NULL;
			}

			n->prev = d->prev;
			if (d->prev)
			{
				if (d->prev->right == d)
					d->prev->right = n;
				else if (d->prev->left == d)
					d->prev->left = n;
			}
			
			n->left = d->left;
			if (n->left)
				n->left->prev = n;

			n->right = d->right;
			if (n->right)
				n->right->prev = n;
			
			d->prev = NULL;
			d->left = NULL;
			d->right = NULL;
			
			if (d == root)
				root = n;
			_last_node_init();
		}
		
		void			_destroy_node(node_map* tmp)
		{
			node_map* tmp_new = tmp;
			if (tmp->right && tmp->right != last_node)
			{
				tmp_new = tmp->right;
				while (tmp_new->left)
					tmp_new = tmp_new->left;
				if (tmp_new->right && tmp_new->right != last_node)
					_transfer_node(tmp_new, tmp_new->right);
				_transfer_node(tmp, tmp_new);
			}
			else if (tmp->left)
			{
				tmp_new = tmp->left;
				_transfer_node(tmp, tmp_new);
			}
			else if (tmp == root)
				root = NULL;
			else if (tmp->prev->left == tmp)
					tmp->prev->left = NULL;
			else if (tmp->prev->right == tmp)
				tmp->prev->right = NULL;
			n_alloc.destroy(tmp);
			n_alloc.deallocate(tmp, 1);
			if (root)
			{
				_last_node_init();
				root = _balance_all_nodes(root);
			}
		}

		void			_destroy_last_node()
		{
			n_alloc.destroy(last_node);
			n_alloc.deallocate(last_node, 1);
			last_node = NULL;
		}

		void			_destroy_map()
		{
			while (root)
				_destroy_node(root);
		}
	};

}



#endif 
