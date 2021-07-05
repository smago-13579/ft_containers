/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:07:38 by smago             #+#    #+#             */
/*   Updated: 2021/04/27 16:14:39 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"
# include "list.hpp"

namespace ft
{
	template <class T, class Container = std::deque<T> > 
	class stack
	{
	public:
		typedef T								value_type;
		typedef Container						container_type;
		typedef size_t 							size_type;

		/*						Constructor							*/
		explicit stack (const container_type& ctnr = container_type()): cont(ctnr) {}
		
		/*						Empty								*/
		bool empty() const { return (cont.empty()); }

		/*						Size								*/
		size_type size() const { return cont.size(); }

		/*						Top									*/
		value_type& top() { return cont.back(); }
		const value_type& top() const { return cont.back(); }

		/*						Push								*/
		void push (const value_type& val) { cont.push_back(val); }

		/*						Pop									*/
		void pop() { cont.pop_back(); }

		/*						Prototypes							*/
		template <class Tn, class Containern>
		friend bool operator==(const stack<Tn, Containern>& lhs, const stack<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator!=(const stack<Tn, Containern>& lhs, const stack<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator<(const stack<Tn, Containern>& lhs, const stack<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator<=(const stack<Tn, Containern>& lhs, const stack<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator>(const stack<Tn, Containern>& lhs, const stack<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator>=(const stack<Tn, Containern>& lhs, const stack<Tn, Containern>& rhs);	
	private:
		container_type cont;
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{ return (lhs.cont == rhs.cont); }

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.cont != rhs.cont); }

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.cont < rhs.cont); }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.cont <= rhs.cont); }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.cont > rhs.cont); }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.cont >= rhs.cont); }
}

#endif

