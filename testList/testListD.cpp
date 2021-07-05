/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testListD.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:12:27 by smago             #+#    #+#             */
/*   Updated: 2021/04/14 15:14:20 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testListD()
{
	ft::list<int> A(3, 100);
	ft::list<int> B(5, 200);

	std::list<int> C(3, 100);
	std::list<int> D(5, 200);
	A.swap(B);
	C.swap(D);

	std::cout << "\n----TEST SWAP----\n";

	myPrint(A);
	stPrint(C);
	myPrint(B);
	stPrint(D);

	ft::list<int> X;
	std::list<int> Y;
	
	X.swap(A);
	Y.swap(C);

	myPrint(X);
	stPrint(Y);

	myPrint(A);
	stPrint(C);

	std::cout << "\n----TEST RESIZE----\n";
	X.resize(7, 50);
	Y.resize(7, 50);

	myPrint(X);
	stPrint(Y);

	X.resize(4, 50);
	Y.resize(4, 50);

	myPrint(X);
	stPrint(Y);
}
