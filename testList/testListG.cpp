/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testListG.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:51:05 by smago             #+#    #+#             */
/*   Updated: 2021/04/14 15:13:53 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testListG()
{
	std::cout << "\n----NON-MEMBER FUNCTION OVERLOADS----\n";
	std::cout << "\n----OPERATORS '== != < <= > >=' ----\n";

	ft::list<int> a(3, 3);
	ft::list<int> b(3, 3);
	std::list<int> c(3, 3);
	std::list<int> d(3, 3);

	std::cout << "my: " << (a == b) << std::endl;
	std::cout << "st: " << (c == d) << std::endl;
	std::cout << "my: " << (a != b) << std::endl;
	std::cout << "st: " << (c != d) << std::endl << std::endl;
	
	a.push_back(1);
	c.push_back(1);
	std::cout << "my: " << (a == b) << std::endl;
	std::cout << "st: " << (c == d) << std::endl;
	std::cout << "my: " << (a != b) << std::endl;
	std::cout << "st: " << (c != d) << std::endl << std::endl;

	std::cout << "my: " << (a < b) << std::endl;
	std::cout << "st: " << (c < d) << std::endl;
	std::cout << "my: " << (b >= a) << std::endl;
	std::cout << "st: " << (d >= c) << std::endl << std::endl;
	b.push_back(1);
	d.push_back(1);
	std::cout << "my: " << (b <= a) << std::endl;
	std::cout << "st: " << (d <= c) << std::endl;

	std::cout << "\n----SWAP----\n";

	ft::list<std::string> A(5, "Hello");
	ft::list<std::string> B(7, "World");

	std::list<std::string> C(5, "Hello");
	std::list<std::string> D(7, "World");

	A.swap(B);
	C.swap(D);

	myPrint(A);
	stPrint(C);
	myPrint(B);
	stPrint(D);
}