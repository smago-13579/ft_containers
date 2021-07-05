/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:39:56 by smago             #+#    #+#             */
/*   Updated: 2021/07/05 16:09:07 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "iterator_list.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc> 
	class list
	{
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef ft::iterator_list<T> 						iterator;
		typedef ft::const_iterator_list<T>					const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef size_t										size_type;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
		
		/*			LIST  CONSTRUCTORS									*/
		explicit list (const allocator_type& alloc = allocator_type()): head_alloc(alloc) 
		{
			_create_last_node();
		}

		explicit list (size_type n, const value_type& val = value_type(),\
                const allocator_type& alloc = allocator_type()): head_alloc(alloc)
		{
			_create_last_node();
			this->insert(this->end(), n, val);
		}

		template<class InputIterator>
		list (InputIterator first, InputIterator last, \
			const allocator_type& alloc = allocator_type(), \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		: head_alloc(alloc)
		{
			_create_last_node();
			while (first != last)
			{
				_addBefore(_create_node(*first), last_node);
				first++;
			}
		}

		list (const list& x): head_alloc(x.head_alloc)
		{
			_create_last_node();
			this->insert(this->end(), x.begin(), x.end());
		}

		/*				assign operator									*/
		list&	operator=(const list& A)
		{
			if (&A != this)
			{
				this->clear();
				this->insert(this->end(), A.begin(), A.end());
			}
			return (*this);
		}

		/*		iterator begin() 										*/
		iterator	begin() { return (iterator(last_node->next)); }

		/*		iterator end()											*/
		iterator	end() { return (iterator(last_node)); }

		/*			const_iterator begin()								*/
		const_iterator	begin() const { return (const_iterator(last_node->next)); }

		/*			const_iterator end()								*/
		const_iterator	end() const { return (const_iterator(last_node)); }

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

		/*				bool	empty()							*/
		bool	empty()	const { return (last_node->next == last_node); }

		/*				size_type	size()						*/
		size_type	size()	const
		{
			size_type i = 0;
			node_list* tmp = last_node->next;
			while (tmp != last_node)
			{
				tmp = tmp->next;
				i++;
			}
			return (i);
		}
		
		/*				size_type	max_size()					*/
		size_type	max_size()	const 
		{
			size_type i = std::numeric_limits<size_type>::max() / sizeof(ft::node_list<T>);
			return (i);
		}

		/*				FRONT AND BACK							*/
		reference	front()
		{
			T&	tmp = last_node->next->data;
			return (tmp);
		}

		const_reference	front() const 
		{
			const T& tmp = last_node->next->data;
			return (tmp);
		}

		reference	back()
		{
			T& tmp = last_node->prev->data;
			return (tmp);
		}

		const_reference	back() const
		{
			const T& tmp = last_node->prev->data;
			return (tmp);
		}

		/*		ASSIGN FUNCTIONS									*/
		template<class InputIterator>
		void	assign(InputIterator first, InputIterator last, \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			this->clear();
			while (first != last)
			{
				_addBefore(_create_node(*first), last_node);
				first++;
			}
		}
		
		void	assign(size_type n, const value_type& val)
		{
			this->clear();
			insert(end(), n, val);
		}

		/*		PUSH_FRONT 	POP_FRONT AND  PUSH_BACK POP_BACK			*/
		void	push_front(const value_type& val)
		{
			_addBefore(_create_node(val), last_node->next);
		}

		void	pop_front() { _delete(last_node->next); }

		void	push_back(const value_type& val)
		{
			_addBefore(_create_node(val), last_node);
		}

		void	pop_back() { _delete(last_node->prev); }

		/*		INSERT FUNCTIONS										*/
		iterator	insert(iterator position, const value_type& val)
		{
			_addBefore(_create_node(val), position.node);
			return (iterator(position.node->prev));
		}

		void		insert(iterator position, size_type n, const value_type& val)
		{
			for (size_t i = 0; i < n; i++)
			{
				_addBefore(_create_node(val), position.node);
			}
		}

		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last,\
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			while (first != last)
			{
				_addBefore(_create_node(*first), position.node);
				first++;
			}
		}

		/*				----ERASE----									*/
		iterator	erase(iterator position) 
		{ 
			node_list* tmp = position.node->next;
			_delete(position.node);
			return (iterator(tmp));
		}
	
		iterator	erase(iterator first, iterator last)
		{
			node_list* tmp = first.node;
			node_list* tmp_n = tmp->next;
			while (tmp != last.node)
			{
				_delete(tmp);
				tmp = tmp_n;
				tmp_n = tmp_n->next;
			}
			return (last);
		}

		/*				void	swap()									*/
		void	swap(list& A)
		{
			allocator_type 		tmp_head_alloc = head_alloc;
			allocNode			tmp_n_alloc = n_alloc;
			node_list* 			tmp = last_node;
	
			head_alloc = A.head_alloc;
			n_alloc = A.n_alloc;	
			last_node = A.last_node;

			A.head_alloc = tmp_head_alloc;
			A.n_alloc = tmp_n_alloc;
			A.last_node = tmp;
		}

		/*				void	resize()								*/
		void	resize(size_type n, value_type val = value_type())
		{
			while (n > this->size())
			{
				this->_addBefore(_create_node(val), last_node);
			}
			while (n < this->size())
				this->pop_back();
		}

		/*				void	clear()									*/
		void	clear()
		{
			node_list	*tmp;
			node_list	*tmp_clear = last_node->next;
			while (tmp_clear != last_node)
			{
				tmp = tmp_clear->next;
				n_alloc.destroy(tmp_clear);
				n_alloc.deallocate(tmp_clear, 1);
				tmp_clear = tmp;
			}
			last_node->next = last_node;
			last_node->prev = last_node;
		}

		/*					----SPLICE----								*/
		void	splice(iterator position, list& x)
		{
			if (this != &x)
			{
				node_list* tmp = x.last_node->next;
				while (tmp != x.last_node)
				{
					x._unchain(tmp);
					_addBefore(tmp, position.node);
					tmp = x.last_node->next;
				}
			}
		}

		void	splice(iterator position, list& x, iterator i)
		{
			node_list* tmp = x.last_node->next;
			while (tmp != x.last_node && tmp != i.node)
				tmp = tmp->next;
			if (tmp == i.node)
			{
				x._unchain(i.node);
				_addBefore(i.node, position.node);
			}
		}

		void	splice(iterator position, list& x, iterator first, iterator last)
		{
			node_list *tmp = first.node;
			node_list *tmp_n = tmp;
			while (tmp != last.node)
			{
				tmp_n = tmp_n->next;
				x._unchain(tmp);
				_addBefore(tmp, position.node);
				tmp = tmp_n;
			}
		}

		/*					----REMOVE AND REMOVE_IF----				*/
		void	remove(const value_type& val)
		{
			iterator tmp = begin();
			iterator tmp_n = begin();
			while (tmp != end())
			{
				tmp_n++;
				if (val == *tmp)
					_delete(tmp.node);
				tmp = tmp_n;
			}
		}

		template <class Predicate>
		void remove_if (Predicate pred)
		{
			iterator tmp = begin();
			for (iterator it = begin(); it != end(); it = tmp)
			{
				tmp++;
				if (pred(*it))
					_delete(it.node);
			}
		}

		/*					----UNIQUE----								*/
		void	unique()
		{
			iterator tmp = ++begin();
			iterator tmp_n = ++begin();
			while (tmp != end())
			{
				tmp_n++;
				if (tmp.node->prev->data == *tmp)
					_delete(tmp.node);
				tmp = tmp_n;
			}
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator tmp = ++begin();
			iterator tmp_n = begin();
			while (tmp != end())
			{
				if (binary_pred(*tmp, *tmp_n))
				{
					_delete(tmp.node);
					tmp = tmp_n;
				}
				else 
					tmp_n++;
				tmp++;
			}
		}

		/*				----MERGE----								*/
		void	merge(list& x) { merge(x, ft::compare<value_type>()); }

		template <class Compare>
		void merge (list& x, Compare comp)
		{
			if (this == &x)
				return ;
			node_list* tmp = last_node->next;
			node_list* tmp_x = x.last_node->next;
			node_list* tmp_x_n;
			while (tmp_x != x.last_node)
			{
				if (!comp(tmp_x->data, tmp->data) && tmp != last_node)
					tmp = tmp->next;
				else
				{
					tmp_x_n = tmp_x->next;
					x._unchain(tmp_x);
					_addBefore(tmp_x, tmp);
					tmp_x = tmp_x_n;
				}
			}
		}

		/*				----SORT----								*/
		void	sort() { sort(ft::compare<value_type>()); }

		template <class Compare>
		void sort (Compare comp)
		{
			node_list* tmp = last_node->next;
			node_list* tmp_n = tmp->next;
			value_type data;
			while (tmp_n != last_node)
			{
				while (tmp!= last_node && comp(tmp_n->data, tmp->data))
				{
					data = tmp->data;
					tmp->data = tmp_n->data;
					tmp_n->data = data;
					tmp = tmp->prev;
					tmp_n = tmp_n->prev;
				}
				tmp = tmp_n;
				tmp_n = tmp_n->next;
			}
		}

		/*				----REVERSE----								*/
		void	reverse()
		{
			node_list* tmp;
			node_list* tmp_n = last_node;
			for (size_type i = size(); i > 0; i--)
			{
				tmp = last_node->next;
				_unchain(tmp);
				_addBefore(tmp, tmp_n);
				tmp_n = tmp_n->prev;
			}
		}

		/*				----GET ALLOCATOR----						*/
		allocator_type get_allocator() const { return head_alloc; }

		~list()
		{
			this->clear();
			n_alloc.destroy(last_node);
			n_alloc.deallocate(last_node, 1);
		}


	private:
		typedef ft::node_list<T>							node_list;
		typedef typename allocator_type::template 
			rebind<node_list>::other						allocNode;

		allocator_type 								head_alloc;
		allocNode									n_alloc;
		node_list									*last_node;
		
		/*		--------------PRIVATE FUNCTIONS--------------			*/

		void		_connect(node_list* tmp, node_list* end)
		{
			tmp->next = end;
			if (end->prev == last_node)
			{
				last_node->next = tmp;
				tmp->prev = last_node;
			}
			else
			{
				tmp->prev = end->prev;
				end->prev->next = tmp;
			}
			end->prev = tmp;
		}

		void		_addBefore(node_list* tmp, node_list* end)
		{
			tmp->next = end;
			if (end->prev == last_node)
			{
				last_node->next = tmp;
				tmp->prev = last_node;
			}
			else
			{
				tmp->prev = end->prev;
				end->prev->next = tmp;
			}
			end->prev = tmp;
		}

		node_list*	_create_node(const value_type& val)
		{
			node_list* tmp;
			tmp = n_alloc.allocate(1);
			n_alloc.construct(tmp, node_list(val));
			tmp->next = tmp;
			tmp->prev = tmp;
			return (tmp);
		}

		node_list*	_create_node()
		{
			node_list* tmp;
			tmp = n_alloc.allocate(1);
			n_alloc.construct(tmp, node_list());
			tmp->next = tmp;
			tmp->prev = tmp;
			return (tmp);
		}
		
		void		_create_last_node()
		{
			last_node = n_alloc.allocate(1);
			n_alloc.construct(last_node, node_list());
			last_node->next = last_node;
			last_node->prev = last_node;
		}

		void		_delete(node_list* tmp)
		{
			if (tmp != last_node)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				n_alloc.destroy(tmp);
				n_alloc.deallocate(tmp, 1);
			}
		}

		void		_unchain(node_list* tmp)
		{
			if (tmp != last_node)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				tmp->next = tmp;
				tmp->prev = tmp;
			}
		}
	};

	/*			NON-MEMBER FUNCTION OVERLOADS				*/
	template <class T, class Alloc>
	bool operator==(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		ft::const_iterator_list<T> a = lhs.begin();
		ft::const_iterator_list<T> b = rhs.begin();
		while (a != lhs.end() && b != rhs.end())
		{
			if (*a != *b)
				return (false);
			a++;
			b++;
		}
		return (true);
	}

	template <class T, class Alloc>
	bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		ft::const_iterator_list<T> a = lhs.begin();
		ft::const_iterator_list<T> b = rhs.begin();
		while (a != lhs.end())
		{
			if (*b < *a || b == rhs.end())
				return (false);
			else if (*a < *b)
				return (true);
			a++;
			b++;
		}
		if (b == rhs.end())
			return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (list<T, Alloc>& x, list<T, Alloc>& y)
	{
		x.swap(y);
	}
}

#endif 
