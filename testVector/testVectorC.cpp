/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVectorC.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:30:16 by smago             #+#    #+#             */
/*   Updated: 2021/04/24 16:06:55 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testVectorC()
{
	std::cout << "\n----TEST OPERATOR[]----\n";
	const ft::vector<double> C(5, 0.5);
	const std::vector<double> D(5, 0.5);
	std::cout << "My: zero: " << C[0] << " ; 4th: " << C[3] << std::endl;
	std::cout << "St: zero: " << D[0] << " ; 4th: " << D[3] << std::endl;
	std::cout << std::endl;

	ft::vector<int> A;
	std::vector<int> B;

	for (int i = 0; i < 10; i++)
	{
		A.push_back(i);
		B.push_back(i);
	}
	std::cout << "My: 3d: " << A[2] << " ; 8th: " << A[7] << std::endl;
	std::cout << "St: 3d: " << B[2] << " ; 8th: " << B[7] << std::endl;
	std::cout << std::endl;

	std::cout << "\n----TEST AT()----\n";
	std::cout << "\n----exception AT()----\n";
	try {
		A.at(20);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << oor.what() << '\n';
	}
	try {
		B.at(20);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << oor.what() << '\n';
	}
	std::cout << "\n----last element - at(9)----\n";
	std::cout << "My: " << A.at(9) << std::endl;
	std::cout << "St: " << B.at(9) << std::endl;

	std::cout << "\n----TEST FRONT AND BACK----\n";
	std::cout << "My: " << A.front() << " " << A.back() << std::endl;
	std::cout << "St: " << B.front() << " " << B.back() << std::endl;
	A.front() = A.back();
	A.back() = A.back() * 10;
	B.front() = B.back();
	B.back() = B.back() * 10;
	myPrint(A);
	stPrint(B);

	std::cout << "\n----TEST ASSIGN----\n";
	ft::vector<int> X(1);
	std::vector<int> Y(1);
	X.assign(5, 77);
	Y.assign(5, 77);
	myPrint(X);
	stPrint(Y);
	X.assign(A.begin(), A.end());
	Y.assign(B.begin(), B.end());
	myPrint(X);
	stPrint(Y);

	std::cout << "\n----TEST POP_BACK----\n";
	X.pop_back();
	Y.pop_back();
	myPrint(X);
	stPrint(Y);
	while (!X.empty() && !Y.empty())
	{
		X.pop_back();
		Y.pop_back();
	}
	myPrint(X);
	stPrint(Y);

	std::cout << "\n----TEST INSERT----\n";
	X.insert(X.begin(), 13);
	Y.insert(Y.begin(), 13);
	myPrint(X);
	stPrint(Y);	

	std::cout << "My: " << *(A.insert(++++A.begin(), 13)) << std::endl;
	std::cout << "St: " << *(B.insert(++++B.begin(), 13)) << std::endl;
	A.insert(A.end(), 13);
	B.insert(B.end(), 13);
	myPrint(A);
	stPrint(B);

	A.insert(------A.end(), 8, 69);
	B.insert(------B.end(), 8, 69);
	myPrint(A);
	stPrint(B);

	std::cout << X.capacity() << std::endl;
	std::cout << Y.capacity() << std::endl;

	X.insert(X.begin(), A.begin(), A.end());
	Y.insert(Y.begin(), B.begin(), B.end());
	myPrint(X);
	stPrint(Y);

	std::cout << X.capacity() << std::endl;
	std::cout << Y.capacity() << std::endl;

	X.insert(X.begin() + 10, X.begin(), X.end());
	Y.insert(Y.begin() + 10, Y.begin(), Y.end());
	myPrint(X);
	stPrint(Y);

	std::cout << X.capacity() << std::endl;
	std::cout << Y.capacity() << std::endl;
}