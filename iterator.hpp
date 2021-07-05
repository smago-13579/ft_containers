/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:44:42 by smago             #+#    #+#             */
/*   Updated: 2021/05/16 04:19:13 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <cctype>
# include <string>
# include <iostream>
# include <memory>
# include <limits>
# include <list>
# include <vector>
# include <stack>
# include <deque>
# include <queue>
# include <map>
# include <utility>
# include <functional>
# include <iomanip>
# include <cmath>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,\
			class Pointer = T*, class Reference = T&>
	class iterator {
	public:
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;
		typedef Category		iterator_category;
	};

	template<class Iterator> 
	class iterator_traits
	{
	public:
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category 	iterator_category;
	};

	/*	Empty class. Used to identify the category of an
	**	"iterator_list"
	*/
	class iterator_list_tag {};

	/*	Empty class. Used to identify the category of an
	**	"iterator_vector"
	*/
	class iterator_vector_tag {};

	/*	Empty class. Used to identify the category of an
	**	"iterator_map"
	*/
	class iterator_map_tag {};

	/*	Enable_if struct. In my containers it is used to define 
	**	iterators.
	*/
	template<bool Cond, class T = void> 
	struct enable_if {};
	template<class T> 
	struct enable_if<true, T> 
	{
		typedef T type; 
	};

	/* is_integral struct. In my containers, it is used to identify
	** whether T is an integral type. Original std::is_integral (c++11);
	*/
	template <class T>
	struct is_integral 
	{
		static const bool value = false;
	};

	template<>
	struct is_integral<bool>
	{
		static const bool value = true;
	};
	
	template<>
	struct is_integral<char>
	{
		static const bool value = true;
	};	

	template<>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<signed char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<short int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<long long int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned short int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long long int>
	{
		static const bool value = true;
	};	

	template <class T>
	std::string itoa(T n)
	{
		std::string str;
		if (n == 0)
			str.push_back('0');
		while (n != 0)
		{
			str.insert(str.begin(), (n % 10 + 48));
			n /= 10;
		}
		return str;
	}

	template <class T>
	struct compare
	{
		bool	operator() (T first, T second) 
		{
			return (first < second); 
		}
	};

	/*
	** 		---All Prototypes---
	*/

	template <class T, class key_compare>
	class const_iterator_map;

	template <class T, class key_compare>
	class iterator_map;

	template <class Key, class T, class Compare, class Alloc>
	class map;

	template<class T>
	struct node_map;

	template<class T>
	class const_iterator_vector;

	template<class T>
	class iterator_vector;

	template <class T, class Alloc>
	class vector;

	template < class T, class Alloc = std::allocator<T> > 
	class list;

	template<class T>
	class const_iterator_list;

	template<class T>
	struct node_list;

	template <class T>
	class iterator_list;

	template<class Iterator>
	class reverse_iterator;

	template <class T, class Container> 
	class stack;

	template <class T, class Container> 
	class queue;
}

#endif
