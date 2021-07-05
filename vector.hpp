/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:50:29 by smago             #+#    #+#             */
/*   Updated: 2021/05/15 20:03:56 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator_vector.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T 											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		
		typedef ft::iterator_vector<T>						iterator;
		typedef ft::const_iterator_vector<T>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef size_t										size_type;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;


		/*					VECTOR CONSTRUCTORS					*/
		explicit vector (const allocator_type& alloc = allocator_type()): 
		v_alloc(alloc)
		{
			v_capacity = 0;
			v_start = NULL;
			v_end = v_start;
		}

		explicit vector (size_type n, const value_type& val = value_type(), \
        	const allocator_type& alloc = allocator_type()):
		v_alloc(alloc)
		{
			this->create(n);
			while (n-- > 0)
				v_alloc.construct(v_end++, val);
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, \
			const allocator_type& alloc = allocator_type(), \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0): 
		v_alloc(alloc)
		{
			InputIterator tmp = first;
			size_type n = 0;
			for ( ; tmp != last; n++)
				tmp++;
			this->create(n);
			tmp = first;
			while (n-- > 0)
			{
				v_alloc.construct(v_end++, *tmp);
				tmp++;
			}
		}

		vector (const vector& x): v_alloc(x.v_alloc)
		{
			size_type n = x.size();

			if (n > 0)
			{
				this->create(n);
				pointer tmp = x.v_start;
				while (n-- > 0)
				{
					v_alloc.construct(v_end++, *tmp);
					tmp++;
				}
			}
			else 
			{
				v_capacity = 0;
				v_start = NULL;
				v_end = v_start;				
			}
		}

		/*				assign operator						*/
		vector&		operator=(const vector& x)
		{
			if (this != &x)
			{
				this->clear();
				if (this->v_capacity < x.v_capacity)
					this->reallocate(x.v_capacity);
				for (pointer tmp = x.v_start; tmp != x.v_end; tmp++)
				{
					v_alloc.construct(v_end++, *tmp);
				}
			}
			return (*this);
		}
		
		/*				iterator begin()						*/
		iterator	begin() { return (iterator(v_start)); }

		/*				iterator end()							*/
		iterator	end() { return (iterator(v_end)); }

		/*				const_iterator begin()					*/
		const_iterator	begin() const { return (const_iterator(v_start)); }

		/*				const_iterator end()					*/
		const_iterator	end()	const { return (const_iterator(v_end)); }
	
		/*				reverse_iterator rbegin()				*/
		reverse_iterator	rbegin() { return reverse_iterator(end()); }

		const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }

		/*				reverse_iterator rend()					*/
		reverse_iterator	rend() { return reverse_iterator(begin()); }

		const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

		/*				----CAPACITY----						*/
		/*				size_type	size()						*/
		size_type	size() const { return (v_end - v_start); }
	
		/*				size_type	max_size()					*/
		size_type	max_size()	const 
		{
			size_type i = std::numeric_limits<size_type>::max() / sizeof(T);
			return (i);
		}

		/*				void	resize()						*/
		void		resize (size_type n, value_type val = value_type())
		{
			if (this->size() > n)
			{
				while (this->size() != n)
					v_alloc.destroy(--v_end);
			}
			else if (this->size() < n)
			{
				if (this->v_capacity < n)
				{
					if (this->v_capacity * 2 < n)
						this->reallocate_and_copy(n);
					else 
						this->reallocate_and_copy(this->v_capacity * 2);
				}
				while (this->size() != n)
					v_alloc.construct(v_end++, val);
			}
		}		

		/*				size_type	capacity() 					*/
		size_type 	capacity() const { return this->v_capacity; }

		/*				bool	empty()							*/
		bool	empty() const { return (v_start == v_end); }

		/*				void	reserve()						*/
		void	reserve (size_type n)
		{
			if (n > this->v_capacity)
				this->reallocate_and_copy(n);
		}

		/*				----ELEMENT ACCESS----					*/
		/*				OPERATOR[]								*/
		reference	operator[] (size_type n)
		{
			pointer tmp = v_start + n;
			return *tmp;
		}

		/*				CONST OPERATOR[]						*/
		const_reference operator[] (size_type n) const
		{
			pointer tmp = v_start + n;
			return *tmp;
		}

		/*				reference at()							*/
		reference	at(size_type n)
		{
			if (n >= this->size())
				throw std::out_of_range("Element out of range: " + ft::itoa(n));
			return (*this)[n];
		}

		/* 				const_reference at()					*/
		const_reference at(size_type n) const
		{
			if (n >= this->size())
				throw std::out_of_range("Element out of range: " + ft::itoa(n));
			return (*this)[n];
		}

		/*				reference front()						*/
		reference		front() { return (*v_start); }

		/*				const_reference front() const			*/
		const_reference front() const { return (*v_start); }

		/*				reference back()						*/
		reference 		back() { return *(v_end - 1); }

		/*				const_reference back() const			*/
		const_reference back() const { return *(v_end - 1); }

		/*				----MODIFIERS----						*/
		/*				ASSIGN									*/
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			InputIterator tmp = first;
			size_type n = 0;
			for (; tmp != last; n++)
				tmp++;
			if (n > this->v_capacity)
			{
				destroy_vector();
				create(n);
			}
			else 
				clear();
			for (tmp = first; tmp != last; tmp++)
				this->push_back(*tmp);
		}
		
		void assign (size_type n, const value_type& val)
		{
			if (n > this->v_capacity)
			{
				destroy_vector();
				create(n);
			}
			else 
				clear();
			while (n-- > 0)
				v_alloc.construct(v_end++, val);
		}

		/*				PUSH_BACK	AND		POP_BACK			*/
		void		push_back (const value_type& val)
		{
			if (this->v_capacity == 0)
				this->create();
			else if (this->v_capacity == this->size())
				this->reallocate_and_copy(this->v_capacity * 2);
			v_alloc.construct(v_end++, val);
		}

		void 		pop_back()
		{
			if (this->size())
				v_alloc.destroy(--v_end);
		}

		/*				----INSERT----							*/
		iterator	insert (iterator position, const value_type& val)
		{
			T tmp;
		
			if (this->size() == 0 || position == end())
			{
				push_back(val);
				return (begin());
			}
			iterator last = end();
			iterator first = --end();
			tmp = *first;
			while (first != position)
			{
				--last;
				--first;
				*last = *first;
			}
			*first = val;
			push_back(tmp);
			return (first);
		}

		void		insert(iterator position, size_type n, const value_type& val)
		{
			difference_type pos = position - begin();
		
			if (this->capacity() < this->size() + n)
			{
				if (this->size() < n)
					this->reserve(this->size() + n);
				else 
					this->reserve(this->size() * 2);
			}
			iterator it = begin() + pos;
			while (n--)
				this->insert(it, val);
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, \
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			vector Tmp(first, last);
			difference_type pos = position - begin();
			size_type len = last - first;
			
			if (this->capacity() < this->size() + len)
			{
				if (this->size() < len)
					this->reserve(this->size() + len);
				else 
					this->reserve(this->size() * 2);
			}
			for (iterator it = Tmp.begin(); it != Tmp.end(); it++)
			{
				iterator itz = begin() + pos;
				pos++;
				insert(itz, *it);
			}
		}
		/*				----ERASE----							*/
		iterator	erase(iterator position)
		{
			difference_type pos = position - begin();
			pointer first = v_start + pos;
			pointer last = first + 1;
			
			while (last != v_end)
			{
				*first = *last;
				first++;
				last++;
			}
			v_alloc.destroy(--v_end);
			return (begin() + pos);
		}

		iterator	erase(iterator first, iterator last)
		{
			difference_type pos = first - begin();
			difference_type len = last - first;

			while (len--)
				this->erase(begin() + pos);
			return (begin() + pos);
		}

		/*				void swap ()							*/
		void 		swap(vector& x)
		{
			allocator_type 	tmp_alloc = this->v_alloc;
			pointer 		tmp_start = this->v_start;
			pointer 		tmp_end = this->v_end;
			size_type 		tmp_capacity = this->v_capacity;

			this->v_alloc = x.v_alloc;
			this->v_start = x.v_start;
			this->v_end = x.v_end;
			this->v_capacity = x.v_capacity;

			x.v_alloc = tmp_alloc;
			x.v_start = tmp_start;
			x.v_end = tmp_end;
			x.v_capacity = tmp_capacity;
		}

		/*				void 	clear()							*/
		void		clear()
		{
			for (size_type n = this->size(); n > 0; n--)
			{
				v_alloc.destroy(--v_end);
			}
		}

		/*				----GET ALLOCATOR----						*/
		allocator_type get_allocator() const { return v_alloc; }
		
		~vector() { destroy_vector(); }

	private:
		allocator_type		v_alloc;
		pointer				v_start;
		pointer				v_end;
		size_type			v_capacity;

		/*				void	create()						*/
		void		create(size_type n = 1)
		{
			this->v_capacity = n;
			this->v_start = this->v_alloc.allocate(v_capacity);
			this->v_end = this->v_start;
		}
		
		/*				void	reallocate()					*/
		void		reallocate(size_type n)
		{
			this->v_alloc.deallocate(v_start, this->v_capacity);
			this->create(n);
		}

		/*				void	reallocate_and_copy()			*/
		void		reallocate_and_copy(size_type n)
		{
			pointer tmp_start = this->v_alloc.allocate(n);
			pointer tmp_end = tmp_start;
			for (pointer save = this->v_start; save != this->v_end; save++)
			{
				v_alloc.construct(tmp_end++, *save);
			}
			this->destroy_vector();
			this->v_capacity = n;
			v_start = tmp_start;
			v_end = tmp_end;
		}

		/*				void	destroy_vector()				*/
		void		destroy_vector()
		{
			this->clear();
			this->v_alloc.deallocate(v_start, this->v_capacity);
			this->v_start = NULL;
			this->v_end = this->v_start;
			this->v_capacity = 0;
		}
	};
	
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		ft::const_iterator_vector<T> itl = lhs.begin();
		ft::const_iterator_vector<T> itr = rhs.begin();

		if (lhs.size() == rhs.size())
		{
			while (itl != lhs.end())
			{
				if (*itl != *itr)
					return (false);
				itl++;
				itr++;
			}
			if (itl == lhs.end())
				return (true);
		}
		return (false);
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		ft::const_iterator_vector<T> itl = lhs.begin();
		ft::const_iterator_vector<T> itr = rhs.begin();

		while (itr != rhs.end())
		{
			if (*itl < *itr || itl == lhs.end())
				return (true);
			if (*itr < *itl)
				return (false);
			itl++;
			itr++;
		}
		return (false);
	}

	template <class T, class Alloc>
	bool 	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool 	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool 	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap (vector<T, Alloc>& x, vector<T, Alloc>& y) 
	{ 
		x.swap(y); 
	}
}

#endif 
