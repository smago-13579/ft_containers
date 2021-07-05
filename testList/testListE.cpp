/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testListE.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:49:27 by smago             #+#    #+#             */
/*   Updated: 2021/05/01 14:49:28 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

bool divided_by_three (const int& value) { return (value % 3 == 0); }

bool same_integral_part (double first, double second)
{
	return ( int(first) == int(second));
}

void	testListE()
{
	std::cout << "\n----SPLICE----\n";
	ft::list<int> A(5, 200);
	ft::list<int> B(3, 100);

	std::list<int> C(5, 200);
	std::list<int> D(3, 100);
	
	A.splice(++A.begin(), B);
	C.splice(++C.begin(), D);

	myPrint(A);
	stPrint(C);
	myPrint(B);
	stPrint(D);

	B.splice(B.end(), A, A.begin());
	D.splice(D.end(), C, C.begin());

	myPrint(A);
	stPrint(C);
	myPrint(B);
	stPrint(D);

	A.splice(A.end(), A, A.begin());
	C.splice(C.end(), C, C.begin());
	myPrint(A);
	stPrint(C);

	B.splice(B.end(), A, ++A.begin(), ----A.end());
	D.splice(D.end(), C, ++C.begin(), ----C.end());
	myPrint(A);
	stPrint(C);
	myPrint(B);
	stPrint(D);

	std::cout << "\n----REMOVE----\n";
	A.remove(200);
	B.remove(200);
	C.remove(200);
	D.remove(200);

	myPrint(A);
	stPrint(C);
	myPrint(B);
	stPrint(D);

	ft::list<int> x;
	std::list<int> y;
	for (int i = 0; i <= 15; i++)
	{
		x.push_back(i*2);
		y.push_back(i*2);
	}
	myPrint(x);
	stPrint(y);
	x.remove_if(divided_by_three);
	y.remove_if(divided_by_three);
	myPrint(x);
	stPrint(y);

	std::cout << "\n----UNIQUE----\n";
	y.push_front(2);
	y.push_back(28);
	y.push_back(28);
	x.push_front(2);
	x.push_back(28);
	x.push_back(28);
	myPrint(x);
	stPrint(y);
	x.unique();
	y.unique();
	myPrint(x);
	stPrint(y);

	ft::list<double> Q;
	std::list<double> T;
	for (double i = 1.27; i < 10; i += 0.4)
	{
		Q.push_back(i);
		T.push_back(i);
	}
	myPrint(Q);
	stPrint(T);
	Q.unique(same_integral_part);
	T.unique(same_integral_part);
	myPrint(Q);
	stPrint(T);
}