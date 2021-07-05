/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:11:16 by smago             #+#    #+#             */
/*   Updated: 2021/05/16 13:40:25 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

# include "iterator.hpp"
# include "map.hpp"

namespace ft
{
	template<class T>
	struct node_map 
	{
		bool isRed;
		node_map*	prev;
		node_map* 	left;
		node_map* 	right;
		T			data;

		node_map() {}
		node_map(const T& data):data(data) { isRed = true; }
		~node_map() {}
	};

	template <class T, class key_compare>
	class iterator_map: public ft::iterator<ft::iterator_map_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::iterator_map_tag, T>::value_type				value_type;
		typedef typename ft::iterator<ft::iterator_map_tag, T>::iterator_category		iterator_category;
		typedef typename ft::iterator<ft::iterator_map_tag, T>::difference_type			difference_type;
		typedef T*																		pointer;
		typedef T&																		reference;
		
	private:
		/* 			pointer to struct node_map<T> 					*/
		ft::node_map<T>* 	node;
		ft::node_map<T>* 	root;
		ft::node_map<T>*	last_node;
		key_compare 		comp;
	
	public:
		/*			ITERATOR CONSTRUCTORS							*/ 
		iterator_map(): node(NULL), root(NULL), last_node(NULL) {}

		iterator_map(ft::node_map<T>* node, ft::node_map<T>* root, ft::node_map<T>* last): 
		node(node), root(root), last_node(last)
		{}
		
		iterator_map(const iterator_map& A): node(A.node), root(A.root), last_node(A.last_node)
		{}

		iterator_map&	operator=(const iterator_map& A)
		{
			if (&A != this)
			{
				this->node = A.node;
				this->root = A.root;
				this->last_node = A.last_node;
			}
			return (*this);
		}
	
		/*			OPERATORS										*/
		reference		operator*() { return (node->data); }

		pointer			operator->(void) { return &(this->operator*()); }
	
		iterator_map&	operator++()
		{
			ft::node_map<T>* tmp = node;
			if (node->right)
			{
				node = node->right;
				while (node->left && node != last_node)
					node = node->left;
			}
			else if (node == root)
				node = node->right;
			else if (node->prev->left == node)
				node = node->prev;
			else
			{	
				tmp = tmp->prev->prev;
				while (comp(tmp->data.first, node->data.first))
					tmp = tmp->prev;
				node = tmp;
			}
			return (*this);
		}

		iterator_map	operator++(int)
		{
			iterator_map tmp(*this);
			operator++();
			return (tmp);
		}

		iterator_map&	operator--()
		{
			ft::node_map<T>* tmp = node;
			if (node->left)
			{
				node = node->left;
				while (node->right && node->right != last_node)
					node = node->right;
			}
			else if (node == root)
				node = node->left;
			else if (node->prev->right == node)
				node = node->prev;
			else
			{
				tmp = tmp->prev->prev;
				while (comp(node->data.first, tmp->data.first))
					tmp = tmp->prev;
				node = tmp;
			}
			return (*this);
		}

		iterator_map	operator--(int)
		{
			iterator_map tmp(*this);
			operator--();
			return (tmp);
		}

		friend bool	operator!=(const iterator_map<T, key_compare> &A, const iterator_map<T, key_compare> &B) 
		{
			return (A.node != B.node);
		}

		friend bool operator==(const iterator_map<T, key_compare> &A, const iterator_map<T, key_compare> &B)
		{
			return (A.node == B.node);
		}
		friend class ft::const_iterator_map<T, key_compare>;

		/*					Virtual Destructor				*/
		virtual ~iterator_map() {}
	};

	template <class T, class key_compare>
	class const_iterator_map: public ft::iterator<ft::iterator_map_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::iterator_map_tag, T>::value_type				value_type;
		typedef typename ft::iterator<ft::iterator_map_tag, T>::iterator_category		iterator_category;
		typedef typename ft::iterator<ft::iterator_map_tag, T>::difference_type			difference_type;
		typedef const T*																pointer;
		typedef const T&																reference;

	private:
		/* 			pointer to struct node_map<T> 						*/
		ft::node_map<T>* 	node;
		ft::node_map<T>* 	root;
		ft::node_map<T>*	last_node;
		key_compare 		comp;

	public:
		/*			CONST_ITERATOR CONSTRUCTORS							*/ 		
		const_iterator_map(): node(NULL), root(NULL), last_node(NULL) {}

		const_iterator_map(ft::node_map<T>* node, ft::node_map<T>* root, ft::node_map<T>* last): 
		node(node), root(root), last_node(last)
		{}
		const_iterator_map(const iterator_map<T, key_compare>& A): 
		node(A.node), root(A.root), last_node(A.last_node)
		{}
		const_iterator_map(const const_iterator_map& A): node(A.node), root(A.root), last_node(A.last_node)
		{}

		/*			OPERATORS										*/
		reference	operator*() { return (node->data); }

		pointer		operator->(void) { return &(this->operator*()); }

		const_iterator_map&		operator=(const const_iterator_map& A)
		{
			if (&A != this)
			{
				this->node = A.node;
				this->root = A.root;
				this->last_node = A.last_node;
			}
			return (*this);
		}

		const_iterator_map&		operator++()
		{
			ft::node_map<T>* tmp = node;
			if (node->right)
			{
				node = node->right;
				while (node->left && node != last_node)
					node = node->left;
			}
			else if (node == root)
				node = node->right;
			else if (node->prev->left == node)
				node = node->prev;
			else
			{	
				tmp = tmp->prev->prev;
				while (comp(tmp->data.first, node->data.first))
					tmp = tmp->prev;
				node = tmp;
			}
			return (*this);
		}

		const_iterator_map		operator++(int)
		{
			const_iterator_map tmp(*this);
			operator++();
			return (tmp);
		}

		const_iterator_map&		operator--()
		{
			ft::node_map<T>* tmp = node;
			if (node->left)
			{
				node = node->left;
				while (node->right && node->right != last_node)
					node = node->right;
			}
			else if (node == root)
				node = node->left;
			else if (node->prev->right == node)
				node = node->prev;
			else
			{
				tmp = tmp->prev->prev;
				while (comp(node->data.first, tmp->data.first))
					tmp = tmp->prev;
				node = tmp;
			}
			return (*this);
		}

		const_iterator_map		operator--(int)
		{
			const_iterator_map tmp(*this);
			operator--();
			return (tmp);
		}

		friend bool	operator!=(const const_iterator_map<T, key_compare> &A, const const_iterator_map<T, key_compare> &B) 
		{
			return (A.node != B.node);
		}

		friend bool operator==(const const_iterator_map<T, key_compare> &A, const const_iterator_map<T, key_compare> &B)
		{
			return (A.node == B.node);
		}

		/*	Virtual 	Destructor   							*/
		virtual ~const_iterator_map() {}
	};
}

#endif