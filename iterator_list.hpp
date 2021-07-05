/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:53:36 by smago             #+#    #+#             */
/*   Updated: 2021/05/14 15:48:43 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_LIST_HPP
# define ITERATOR_LIST_HPP

# include "iterator.hpp"
# include "list.hpp"

namespace ft
{
	template<class T>
	struct node_list 
	{
	public:
		node_list* 	prev;
		node_list* 	next;
		T			data;

		node_list() {}
		node_list(const T& data) { this->data = data; }
		~node_list() {}
	};

	template <class T>
	class iterator_list: public ft::iterator<ft::iterator_list_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::iterator_list_tag, T>::value_type				value_type;
		typedef typename ft::iterator<ft::iterator_list_tag, T>::iterator_category		iterator_category;
		typedef typename ft::iterator<ft::iterator_list_tag, T>::difference_type		difference_type;
		typedef T*																		pointer;
		typedef T&																		reference;
		

	private:
		/* 			pointer to struct node_list<T> 					*/
		ft::node_list<T>* node;
	
	public:
		/*			ITERATOR CONSTRUCTORS							*/ 
		iterator_list() { node = NULL; }
		iterator_list(ft::node_list<T>* list) { node = list; }
		iterator_list(const iterator_list<T>& A): node(A.node) {}

		iterator_list&	operator=(const iterator_list& A)
		{
			if (&A != this)
				this->node = A.node;
			return (*this);
		}
	
		/*			OPERATORS										*/
		reference		operator*() { return (node->data); }

		pointer			operator->(void) { return &(this->operator*()); }
	
		iterator_list&	operator++()
		{
			this->node = this->node->next;
			return (*this);
		}

		iterator_list	operator++(int)
		{
			iterator_list tmp(*this);
			operator++();
			return (tmp);
		}

		iterator_list&	operator--()
		{
			this->node = this->node->prev;
			return (*this);
		}

		iterator_list	operator--(int)
		{
			iterator_list tmp(*this);
			operator--();
			return (tmp);
		}

		friend bool	operator!=(const iterator_list<T> &A, const iterator_list<T> &B) 
		{
			return (A.node != B.node);
		}

		friend bool operator==(const iterator_list<T> &A, const iterator_list<T> &B)
		{
			return (A.node == B.node);
		}
		friend class ft::list<T>;
		friend class ft::const_iterator_list<T>;

		/*					Virtual Destructor				*/
		virtual ~iterator_list() {}
	};

	template<class T>
	class const_iterator_list: public ft::iterator<ft::iterator_list_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::iterator_list_tag, T>::value_type				value_type;
		typedef typename ft::iterator<ft::iterator_list_tag, T>::iterator_category		iterator_category;
		typedef typename ft::iterator<ft::iterator_list_tag, T>::difference_type		difference_type;
		typedef const T*																pointer;
		typedef const T&																reference;

	private:
		/* 			pointer to struct node_list<T> 						*/
		ft::node_list<T>* node;

	public:
		/*			CONST_ITERATOR CONSTRUCTORS							*/ 		
		const_iterator_list() { node = NULL; }
		const_iterator_list(ft::node_list<T>* list) { node = list; }
		const_iterator_list(const iterator_list<T>& A): node(A.node) {}
		const_iterator_list(const const_iterator_list& A): node(A.node) {}

		/*			OPERATORS										*/
		reference	operator*() { return (node->data); }

		pointer		operator->(void) { return &(this->operator*()); }

		const_iterator_list&	operator=(const const_iterator_list& A)
		{
			if (&A != this)
				this->node = A.node;
			return (*this);
		}

		const_iterator_list&	operator++()
		{
			this->node = this->node->next;
			return (*this);
		}
	
		const_iterator_list		operator++(int)
		{
			const_iterator_list tmp(*this);
			operator++();
			return (tmp);
		}

		const_iterator_list&	operator--()
		{
			this->node = this->node->prev;
			return (*this);
		}

		const_iterator_list		operator--(int)
		{
			const_iterator_list tmp(*this);
			operator--();
			return (tmp);
		}

		friend bool	operator!=(const const_iterator_list<T> &A, const const_iterator_list<T> &B) 
		{
			return (A.node != B.node);
		}

		friend bool operator==(const const_iterator_list<T> &A, const const_iterator_list<T> &B)
		{
			return (A.node == B.node);
		}
		friend class ft::list<T>;

		/*	Virtual 	Destructor   							*/
		virtual ~const_iterator_list() {}
	};
}

#endif

