/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testListC.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:40:43 by smago             #+#    #+#             */
/*   Updated: 2021/05/14 17:53:27 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testListC()
{
	ft::list<int> A(5, 4);
	std::list<int> B(5, 4);
	
	std::cout << "\n----TEST ASSIGN FUNCTIONS----\n";
	myPrint(A);
	stPrint(B);

	A.assign(3, 5);
	B.assign(3, 5);

	int myints[] = { 1776, 7, 4 };
	A.assign(myints, myints + 3);
	B.assign(myints, myints + 3);

	myPrint(A);
	stPrint(B);
	
	ft::list<int> C;
	std::list<int> D;
	for (int i = 11; i <= 20; i++)
	{
		C.push_back(i);
		D.push_back(i);
	}
	A.assign(C.begin(), C.end());
	B.assign(D.begin(), D.end());
	
	myPrint(A);
	stPrint(B);

	std::cout << "\n----TEST POP BACK AND POP FRONT----\n";
	A.pop_back();
	A.pop_front();
	B.pop_front();
	B.pop_back();
	myPrint(A);
	stPrint(B);

	std::cout << "\n----TEST ERASE----\n";
	ft::list<int>::iterator xi = A.begin();
	xi++;
	xi++;
	xi++;
	xi = A.erase(xi);
	std::cout << *xi << std::endl;
	std::list<int>::iterator xs = B.begin();
	xs++;
	xs++;
	xs++;
	xs = B.erase(xs);
	std::cout << *xs << std::endl;

	myPrint(A);
	stPrint(B);

	xi = A.erase(++++A.begin(), ++xi);
	xs = B.erase(++++B.begin(), ++xs);
	
	std::cout << *xi << std::endl;
	std::cout << *xs << std::endl;

	myPrint(A);
	stPrint(B);

	std::cout << "\n----TEST INSERT----\n";
	A.insert(A.end(), 20);
	B.insert(B.end(), 20);
	A.insert(A.begin(), 5, 0);
	B.insert(B.begin(), 5, 0);
	
	myPrint(A);
	stPrint(B);

	ft::list<int>::iterator Ai = ------A.end();
	std::list<int>::iterator Bi = ------B.end();
	xi = --A.end();
	xs = --B.end();
	A.insert(++++A.begin(), Ai, xi);
	B.insert(++++B.begin(), Bi, xs);

	myPrint(A);
	stPrint(B);
}
