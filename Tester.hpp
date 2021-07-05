/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:12:48 by smago             #+#    #+#             */
/*   Updated: 2021/05/11 15:07:01 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include "list.hpp"
# include "vector.hpp"
# include "stack.hpp"
# include "queue.hpp"
# include "map.hpp"

# include "unistd.h"

void	testListA();
void	testListB();
void	testListC();
void	testListD();
void	testListE();
void	testListF();
void	testListG();

void	testVectorA();
void	testVectorB();
void	testVectorC();
void	testVectorD();

void	testStackA();

void	testQueueA();

void	testMapA();
void	testMapB();
void	testMapC();


template<class T>
void	myPrint(ft::list<T>& A)
{
	std::cout << "My list: ";
	for (typename ft::list<T>::iterator it = A.begin(); it != A.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<class T>
void	stPrint(std::list<T>& C)
{
	std::cout << "St list: ";
	for (typename std::list<T>::iterator it = C.begin(); it != C.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<class T>
void	myPrint(ft::vector<T>& A)
{
	std::cout << "My vector: ";
	for (typename ft::vector<T>::iterator it = A.begin(); it != A.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<class T>
void	stPrint(std::vector<T>& C)
{
	std::cout << "St vector: ";
	for (typename std::vector<T>::iterator it = C.begin(); it != C.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template<class Tn, class Tp>
void	myPrint(ft::map<Tn, Tp>& A)
{
	std::cout << "My map: ";
	for (typename ft::map<Tn, Tp>::iterator it = A.begin(); it != A.end(); it++)
		std::cout << it->first << " -> " << it->second << "; ";
	std::cout << std::endl;
}

template<class Tn, class Tp>
void	myPrintRev(ft::map<Tn, Tp>& A)
{
	std::cout << "My map: ";
	typename ft::map<Tn, Tp>::iterator it = --A.end();
	for ( ; it != A.begin(); it--)
		std::cout << it->first << " -> " << it->second << "; ";
	std::cout << it->first << " -> " << it->second << "; ";
	std::cout << std::endl;
}

template<class Tn, class Tp>
void	stPrint(std::map<Tn, Tp>& C)
{
	std::cout << "St map: ";
	for (typename std::map<Tn, Tp>::iterator it = C.begin(); it != C.end(); it++)
		std::cout << it->first << " -> " << it->second << "; ";
	std::cout << std::endl;
}


#endif
