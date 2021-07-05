/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testListB.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:17:20 by smago             #+#    #+#             */
/*   Updated: 2021/04/22 17:50:18 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testListB()
{
	{
		std::cout << "\n----TEST PUSH_FRONT AND PUSH_BACK----\n";
		ft::list<int> A;
		std::list<int> B;
		for (int i = 10; i != 0; i--)
		{
			A.push_front(i);
			B.push_front(i);
		}
		
		myPrint(A);
		stPrint(B);
	
		for (int i = 10; i != 0; i--)
		{
			A.push_back(i);
			B.push_back(i);
		}
	
		myPrint(A);
		stPrint(B);
		
		ft::list<int> C(1, 2);
		std::list<int> D(1, 2);
		C = A;
		D = B;
		
		std::cout << "\n----ASSIGN OPERATOR----\n";
		myPrint(C);
		stPrint(D);

		std::cout << "\n----TEST EMPTY, SIZE AND MAX_SIZE----\n";

		ft::list<int> X;
		std::list<int> Y;
		std::cout << "My list: " << X.empty() << " " << X.size() << " " << X.max_size() << std::endl;
		std::cout << "St list: " << Y.empty() << " " << Y.size() << " " << Y.max_size() << std::endl;
		std::cout << "My list: " << A.empty() << " " << A.size() << " " << A.max_size() << std::endl;
		std::cout << "St list: " << B.empty() << " " << B.size() << " " << B.max_size() << std::endl;

		std::cout << "\n/*REVERSE ITERATOR*/\n";
		std::cout << "My list: ";
		for (ft::list<int>::reverse_iterator it = C.rbegin(); it != C.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "St list: ";
		for (std::list<int>::reverse_iterator it = D.rbegin(); it != D.rend(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "\nUSE CONST ITERATOR AND CONST REVERSE ITERATOR	\n";
		std::cout << "My list: ";
		for (ft::list<int>::const_iterator it = C.begin(); it != C.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "St list: ";
		for (std::list<int>::const_iterator it = D.begin(); it != D.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "My list: ";
		for (ft::list<int>::const_reverse_iterator it = C.rbegin(); it != C.rend(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "St list: ";
		for (std::list<int>::const_reverse_iterator it = D.rbegin(); it != D.rend(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\nUSE CONST LIST\n";
		const ft::list<int> A(5, 5);
		std::cout << "My list: ";
		for (ft::list<int>::const_iterator it = A.begin(); it != A.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		

		const std::list<int> B(5, 5);
		std::cout << "St list: ";
		for (std::list<int>::const_iterator it = B.begin(); it != B.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}