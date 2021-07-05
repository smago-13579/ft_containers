/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVectorD.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:13:42 by smago             #+#    #+#             */
/*   Updated: 2021/05/07 00:05:18 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testVectorD()
{
	std::cout << "\n----TEST ERASE----\n";
	ft::vector<int> A;
	std::vector<int> B;

	for (int i = 0; i < 10; i++)
	{
		A.push_back(i);
		B.push_back(i);
	}
	std::cout << "my: " << *(A.erase(A.end() - 5)) << std::endl;
	std::cout << "st: " << *(B.erase(B.end() - 5)) << std::endl;
	myPrint(A);
	stPrint(B);
	std::cout << "my: " << A.capacity() << " " << A.size() << std::endl;
	std::cout << "st: " << B.capacity() << " " << B.size() << std::endl;

	std::cout << "my: " << *(A.erase(A.begin() + 2, A.end() - 3)) << std::endl;
	std::cout << "st: " << *(B.erase(B.begin() + 2, B.end() - 3)) << std::endl;
	myPrint(A);
	stPrint(B);
	std::cout << "my: " << A.capacity() << " " << A.size() << std::endl;
	std::cout << "st: " << B.capacity() << " " << B.size() << std::endl;

	std::cout << "\n----TEST SWAP----\n";
	ft::vector<int> C;
	std::vector<int> D;
	for (int i = 10; i < 20; i++)
	{
		C.push_back(i);
		D.push_back(i);
	}
	A.swap(C);
	B.swap(D);
	myPrint(A);
	stPrint(B);
	myPrint(C);
	stPrint(D);

	std::cout << "\n----TEST CLEAR----\n";

	C.clear();
	D.clear();
	myPrint(C);
	stPrint(D);

	std::cout << "\n----TEST NON-MEMBER SWAP----\n";
	ft::swap(A, C);
	std::swap(B, D);
	myPrint(A);
	stPrint(B);
	myPrint(C);
	stPrint(D);

	std::cout << "\n----NON-MEMBER FUNCTION OVERLOADS----\n";
	std::cout << "\n----OPERATORS '== != < <= > >=' ----\n";
	
	ft::vector<int> a(3, 3);
	ft::vector<int> b(3, 3);
	std::vector<int> c(3, 3);
	std::vector<int> d(3, 3);

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
	std::cout << "my: " << (a > b) << std::endl;
	std::cout << "st: " << (c > d) << std::endl << std::endl;

	std::cout << "my: " << (b <= a) << std::endl;
	std::cout << "st: " << (d <= c) << std::endl;
	std::cout << "my: " << (b >= a) << std::endl;
	std::cout << "st: " << (d >= c) << std::endl << std::endl;

	b.push_back(1);
	d.push_back(1);
	std::cout << "my: " << (b <= a) << std::endl;
	std::cout << "st: " << (d <= c) << std::endl;
	std::cout << "my: " << (b >= a) << std::endl;
	std::cout << "st: " << (d >= c) << std::endl;
}
