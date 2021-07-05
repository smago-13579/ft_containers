/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:16:38 by smago             #+#    #+#             */
/*   Updated: 2021/04/27 17:20:44 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "vector.hpp"
# include "list.hpp"

namespace ft
{
	template <class T, class Container = std::deque<T> > 
	class queue
	{
	public:
		typedef T										value_type;
		typedef Container 								container_type;
		typedef size_t									size_type;

		/*						Constructor							*/
		explicit queue(const container_type& ctnr = container_type()): cont(ctnr) {}
		
		/*						Empty								*/
		bool empty() const { return (cont.empty()); }

		/*						Size								*/
		size_type size() const { return cont.size(); }

		/*						Front								*/
		value_type& front() { return cont.front(); }
		const value_type& front() const { return cont.front(); }	

		/*						Back								*/
		value_type& back() { return cont.back(); }
		const value_type& back() const { return cont.back(); }

		/*						Push								*/
		void push (const value_type& val) { cont.push_back(val); }

		/*						Pop									*/
		void pop() { cont.pop_front(); }

		/*						Prototypes							*/
		template <class Tn, class Containern>
		friend bool operator==(const queue<Tn, Containern>& lhs, const queue<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator!=(const queue<Tn, Containern>& lhs, const queue<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator<(const queue<Tn, Containern>& lhs, const queue<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator<=(const queue<Tn, Containern>& lhs, const queue<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator>(const queue<Tn, Containern>& lhs, const queue<Tn, Containern>& rhs);	

		template <class Tn, class Containern>
		friend bool operator>=(const queue<Tn, Containern>& lhs, const queue<Tn, Containern>& rhs);	

	private:
		container_type cont;
	};
	template <class T, class Container>
	bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{ return (lhs.cont == rhs.cont); }

	template <class T, class Container>
	bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return (lhs.cont != rhs.cont); }

	template <class T, class Container>
	bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return (lhs.cont < rhs.cont); }

	template <class T, class Container>
	bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return (lhs.cont <= rhs.cont); }

	template <class T, class Container>
	bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return (lhs.cont > rhs.cont); }

	template <class T, class Container>
	bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{ return (lhs.cont >= rhs.cont); }
}


#endif
