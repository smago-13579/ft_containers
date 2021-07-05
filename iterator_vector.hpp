/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:34:33 by smago             #+#    #+#             */
/*   Updated: 2021/05/14 15:22:52 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
# define ITERATOR_VECTOR_HPP

# include "iterator.hpp"

namespace ft
{
	template<class T>
	class iterator_vector: public ft::iterator<ft::iterator_vector_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::iterator_vector_tag, T>::value_type				value_type;
		typedef typename ft::iterator<ft::iterator_vector_tag, T>::iterator_category		iterator_category;
		typedef typename ft::iterator<ft::iterator_vector_tag, T>::difference_type			difference_type;
		typedef T*																			pointer;
		typedef T&																			reference;
		
		/*			ITERATOR CONSTRUCTORS							*/ 
		iterator_vector(): str(NULL) {}
		iterator_vector(pointer str): str(str) {}
		iterator_vector(const iterator_vector& A): str(A.str) {}

		iterator_vector&	operator=(const iterator_vector& A)
		{
			if (&A != this)
				this->str = A.str;
			return (*this);
		}

		/*						OPERATORS										*/
		reference	operator*() { return (*str); }
	
		pointer 	operator->() { return &(this->operator*()); }

		iterator_vector		operator++(int) 
		{
			iterator_vector tmp(*this);
			this->str++;
			return (tmp); 
		}

		iterator_vector&	operator++(void)
		{ 
			this->str++;
			return (*this); 
		}

		iterator_vector		operator+(difference_type n)
		{
			iterator_vector tmp = *this;
			while (n-- )
				++tmp;
			return (tmp);
		}

		iterator_vector&	operator+=(difference_type n)
		{
			while (n--)
				(*this)++;
			return (*this);
		}

		iterator_vector		operator--(int)
		{
			iterator_vector tmp(*this);
			this->str--;
			return (tmp);
		}

		iterator_vector&	operator--(void)
		{
			this->str--;
			return (*this);
		}

		iterator_vector		operator-(difference_type n)
		{
			iterator_vector tmp = *this;
			while (n-- )
				--tmp;
			return (tmp);
		}

		iterator_vector&	operator-=(difference_type n)
		{
			while (n--)
				(*this)--;
			return (*this);
		}

		difference_type		operator-(iterator_vector tmp)
		{
			return (this->str - tmp.str);
		}

		reference			operator[](difference_type n)
		{
			return *(this->operator+(n));
		}

		friend	bool	operator<(const iterator_vector<T>& A, const iterator_vector<T>& B)
		{
			return (A.str < B.str);
		}

		friend	bool	operator>(const iterator_vector<T>& A, const iterator_vector<T>& B)
		{
			return (A.str > B.str);
		}

		friend	bool	operator<=(const iterator_vector<T>& A, const iterator_vector<T>& B)
		{
			return (A.str <= B.str);
		}

		friend	bool	operator>=(const iterator_vector<T>& A, const iterator_vector<T>& B)
		{
			return (A.str >= B.str);
		}

		friend	bool	operator==(const iterator_vector<T>& A, const iterator_vector<T>& B)
		{
			return (A.str == B.str);
		}

		friend	bool	operator!=(const iterator_vector<T>& A, const iterator_vector<T>& B)
		{
			return (A.str != B.str);
		}
		friend class ft::const_iterator_vector<T>;

		/* 				Virtual Destructor										*/
		virtual ~iterator_vector() {}
		
	private:
		pointer str;
	};

	template<class T>
	class const_iterator_vector: public ft::iterator<ft::iterator_vector_tag, T>
	{
	public:
		typedef typename ft::iterator<ft::iterator_vector_tag, T>::value_type				value_type;
		typedef typename ft::iterator<ft::iterator_vector_tag, T>::iterator_category		iterator_category;
		typedef typename ft::iterator<ft::iterator_vector_tag, T>::difference_type			difference_type;
		typedef const T*																	pointer;
		typedef const T&																	reference;
		
		/*			CONST_ITERATOR CONSTRUCTORS							*/ 		
		const_iterator_vector(): str(NULL) {}
		const_iterator_vector(pointer str): str(str) {}
		const_iterator_vector(const iterator_vector<T>& A): str(A.str) {}
		const_iterator_vector(const const_iterator_vector& A): str(A.str) {}

		const_iterator_vector&	operator=(const const_iterator_vector& A)
		{
			if (&A != this)
				this->str = A.str;
			return (*this);
		}

		/*						OPERATORS										*/
		reference	operator*() { return (*str); }
	
		pointer 	operator->() { return &(this->operator*()); }

		const_iterator_vector		operator++(int) 
		{
			const_iterator_vector tmp(*this);
			this->str++;
			return (tmp); 
		}

		const_iterator_vector&		operator++(void)
		{ 
			this->str++;
			return (*this); 
		}

		const_iterator_vector		operator+(difference_type n)
		{
			const_iterator_vector tmp = *this;
			while (n-- )
				++tmp;
			return (tmp);
		}

		const_iterator_vector&		operator+=(difference_type n)
		{
			while (n--)
				(*this)++;
			return (*this);
		}

		const_iterator_vector		operator--(int)
		{
			const_iterator_vector tmp(*this);
			this->str--;
			return (tmp);
		}

		const_iterator_vector&		operator--(void)
		{
			this->str--;
			return (*this);
		}

		const_iterator_vector		operator-(difference_type n)
		{
			const_iterator_vector tmp = *this;
			while (n-- )
				--tmp;
			return (tmp);
		}

		const_iterator_vector&		operator-=(difference_type n)
		{
			while (n--)
				(*this)--;
			return (*this);
		}

		difference_type		operator-(const_iterator_vector tmp)
		{
			return (this->str - tmp.str);
		}

		reference			operator[](difference_type n)
		{
			return *(this->operator+(n));
		}

		friend	bool	operator<(const const_iterator_vector<T>& A, const const_iterator_vector<T>& B)
		{
			return (A.str < B.str);
		}

		friend	bool	operator>(const const_iterator_vector<T>& A, const const_iterator_vector<T>& B)
		{
			return (A.str > B.str);
		}

		friend	bool	operator<=(const const_iterator_vector<T>& A, const const_iterator_vector<T>& B)
		{
			return (A.str <= B.str);
		}

		friend	bool	operator>=(const const_iterator_vector<T>& A, const const_iterator_vector<T>& B)
		{
			return (A.str >= B.str);
		}

		friend	bool	operator==(const const_iterator_vector<T>& A, const const_iterator_vector<T>& B)
		{
			return (A.str == B.str);
		}

		friend	bool	operator!=(const const_iterator_vector<T>& A, const const_iterator_vector<T>& B)
		{
			return (A.str != B.str);
		}

		/* 				Virtual Destructor										*/
		virtual ~const_iterator_vector() {}
		
	private:
		pointer str;
	};
	
}

#endif
