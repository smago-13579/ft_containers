/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVectorB.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:57:58 by smago             #+#    #+#             */
/*   Updated: 2021/04/22 18:35:14 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testVectorB()
{
	{
		std::cout << "\n----TEST PUSH_BACK----\n";
		ft::vector<int> A;
		std::vector<int> B;
		
		myPrint(A);
		stPrint(B);

		for (int i = 10; i != 0; i--)
		{
			A.push_back(i);
			B.push_back(i);
		}

		myPrint(A);
		stPrint(B);

		ft::vector<int> C(1, 2);
		std::vector<int> D(1, 2);
		C = A;
		D = B;
		
		std::cout << "\n----ASSIGN OPERATOR----\n";
		myPrint(C);
		stPrint(D);

		std::cout << "\n----TEST EMPTY, SIZE, MAX_SIZE, RESIZE AND CAPACITY----\n";

		ft::vector<int> X;
		std::vector<int> Y;
		std::cout << "My vector: " << X.empty() << " " << X.size() << " " << X.max_size() << std::endl;
		std::cout << "St vector: " << Y.empty() << " " << Y.size() << " " << Y.max_size() << std::endl;
		std::cout << "My vector: " << A.empty() << " " << A.size() << " " << A.max_size() << std::endl;
		std::cout << "St vector: " << B.empty() << " " << B.size() << " " << B.max_size() << std::endl;

		X.resize(10, 99);
		Y.resize(10, 99);
		myPrint(X);
		stPrint(Y);
		std::cout << "My vector: " << X.empty() << " " << X.size() << " " << X.capacity() << std::endl;
		std::cout << "St vector: " << Y.empty() << " " << Y.size() << " " << Y.capacity() << std::endl;
		std::cout << "My vector: " << A.empty() << " " << A.size() << " " << A.capacity() << std::endl;
		std::cout << "St vector: " << B.empty() << " " << B.size() << " " << B.capacity() << std::endl;

		std::cout << "\n----RESIZE TO 11 ELEMENTS THEN RESERVE 50 ELEMENTS----\n";
		X.resize(11, 5);
		Y.resize(11, 5);

		myPrint(X);
		stPrint(Y);
		std::cout << "My vector capacity: " << X.capacity() << std::endl;
		std::cout << "St vector capacity: " << Y.capacity() << std::endl;

		X.reserve(50);
		Y.reserve(50);
		myPrint(X);
		stPrint(Y);
		std::cout << "My vector capacity: " << X.capacity() << std::endl;
		std::cout << "St vector capacity: " << Y.capacity() << std::endl;

		std::cout << "\n/*REVERSE ITERATOR*/\n";
		std::cout << "My vector: ";
		for (ft::vector<int>::reverse_iterator it = C.rbegin(); it != C.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "St vector: ";
		for (std::vector<int>::reverse_iterator it = D.rbegin(); it != D.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "\nUSE CONST ITERATOR AND CONST REVERSE ITERATOR	\n";
		std::cout << "My vector: ";
		for (ft::vector<int>::const_iterator it = C.begin(); it != C.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "St vector: ";
		for (std::vector<int>::const_iterator it = D.begin(); it != D.end(); it++)
		std::cout << *it << " ";
		std::cout << std::endl;


		std::cout << "My vector: ";
		for (ft::vector<int>::const_reverse_iterator it = C.rbegin(); it != C.rend(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "St vector: ";
		for (std::vector<int>::const_reverse_iterator it = D.rbegin(); it != D.rend(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}	
	{
		std::cout << "\nUSE CONST VECTOR && CONST ITERATORS\n";
		const ft::vector<std::string> A(5, "hi");
		std::cout << "My vector: ";
		for (ft::vector<std::string>::const_iterator it = A.begin(); it != A.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		const std::vector<std::string> B(5, "hi");
		std::cout << "St vector: ";
		for (std::vector<std::string>::const_iterator it = B.begin(); it != B.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "My vector: ";
		for (ft::vector<std::string>::const_reverse_iterator it = A.rbegin(); it != A.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	
		std::cout << "St vector: ";
		for (std::vector<std::string>::const_reverse_iterator it = B.rbegin(); it != B.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}