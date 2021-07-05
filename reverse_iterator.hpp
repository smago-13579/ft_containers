/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:04:57 by smago             #+#    #+#             */
/*   Updated: 2021/05/03 15:20:19 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_list.hpp"
# include "iterator_vector.hpp"

namespace ft 
{
	template<class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		/* 			REVERSE_ITERATORS_CONSTRUCTORS						*/
		reverse_iterator(): rev_it() {};
		explicit	reverse_iterator(const iterator_type& it): rev_it(it) {};

		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter>& A): rev_it(A.base()) 
		{}

		iterator_type	base() const { return (rev_it); }

		/*			OPERATORS											*/
		reference	operator*() const 
		{
			iterator_type tmp = rev_it;
			return (*(--tmp));
		}

		reverse_iterator	operator+(difference_type n) const
		{
			reverse_iterator tmp(rev_it - n);
			return (tmp);
		}

		reverse_iterator&	operator++()
		{
			--rev_it;
			return (*this);
		}

		reverse_iterator	operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator&	operator+=(difference_type n)
		{
			rev_it -= n;
			return *this;
		}

		reverse_iterator	operator-(difference_type n) const
		{
			reverse_iterator tmp(rev_it + n);
			return (tmp);
		}
		
		reverse_iterator&	operator--()
		{
			++rev_it;
			return (*this);
		}

		reverse_iterator	operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return tmp;
		}

		reverse_iterator&	operator-=(difference_type n)
		{
			rev_it += n;
			return *this;
		}

		pointer		operator->() const { return &(operator*()); }

		reference operator[] (difference_type n) const
		{
			iterator_type it = rev_it;
			while (n-- > 0)
				--it;
			reverse_iterator tmp(it);
			return *tmp;
		}

		/* 			Virtual destructor									*/
		virtual	~reverse_iterator() {};
		

	private:
		iterator_type	rev_it;
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator== (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator_L, class Iterator_R>
	bool operator!= (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
}


#endif
