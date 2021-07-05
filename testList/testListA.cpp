/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testListA.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:10:52 by smago             #+#    #+#             */
/*   Updated: 2021/04/15 15:47:53 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testListA()
{
	std::cout << "----LIST----\n";
	{
		std::cout << "----DEFAULT CONSTRUCTOR----\n\n";
		ft::list<int> A;
		ft::list<std::string> S;
		ft::list<double> D;
		for (ft::list<int>::iterator it = A.begin(); it != A.end(); it++)
			std::cout << *it << " ";
		std::cout << "----NOTHING TO DISPLAY----\n\n";
	}
	
	std::cout << "----FILL CONSTRUCTOR----\n";

	ft::list<int> A(5);
	myPrint(A);

	std::list<int> C(5);
	stPrint(C);

	ft::list<int> B(5, 4);
	myPrint(B);

	std::list<int> D(5, 4);
	stPrint(D);

	{
		std::cout << "\n----COPY CONSTRUCTOR----\n";

		ft::list<int> X(B);
		myPrint(X);

		std::list<int> Y(D);
		stPrint(Y);
	}
	{
		std::cout << "\n----RANGE CONSTRUCTOR----\n";
		ft::list<int> X(B.begin(), B.end());
		myPrint(X);

		std::list<int> Y(D.begin(), D.end());
		stPrint(Y);
	}

}