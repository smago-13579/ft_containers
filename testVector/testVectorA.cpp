/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVectorA.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:48:43 by smago             #+#    #+#             */
/*   Updated: 2021/04/22 18:17:13 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testVectorA()
{
	std::cout << "\n----VECTOR----\n";
	{
		std::cout << "----DEFAULT CONSTRUCTOR----\n\n";
		ft::vector<int> A;
		ft::vector<std::string> S;
		ft::vector<double> D;
		for (ft::vector<int>::iterator it = A.begin(); it != A.end(); it++)
			std::cout << *it << " ";
		std::cout << "----NOTHING TO DISPLAY----\n\n";
	}
	
	std::cout << "----FILL CONSTRUCTOR----\n";

	ft::vector<int> A(5);
	myPrint(A);

	std::vector<int> C(5);
	stPrint(C);

	ft::vector<int> B(5, 4);
	myPrint(B);

	std::vector<int> D(5, 4);
	stPrint(D);

	{
		std::cout << "\n----COPY CONSTRUCTOR----\n";

		ft::vector<int> X(B);
		myPrint(X);

		std::vector<int> Y(D);
		stPrint(Y);
	}
	{
		std::cout << "\n----RANGE CONSTRUCTOR----\n";
		ft::vector<int> X(B.begin(), B.end());
		myPrint(X);

		std::vector<int> Y(D.begin(), D.end());
		stPrint(Y);
	}
}
