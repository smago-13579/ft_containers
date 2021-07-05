/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testListF.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:22:14 by smago             #+#    #+#             */
/*   Updated: 2021/04/14 15:14:42 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

bool	compare(double first, double second) 
{ 
	return (first < second); 
}

void	testListF()
{
	std::cout << "\n----MERGE----\n";
	ft::list<double> A, B;
	std::list<double> first, second;

	A.push_back (3.1);
	A.push_back (2.2);
	A.push_back (2.9);
	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	B.push_back (3.1);
	B.push_back (7.1);
	B.push_back (1.4);
	second.push_back (3.1);
	second.push_back (7.1);
	second.push_back (1.4);

	A.merge(B);
	first.merge(second);

	myPrint(A);
	stPrint(first);

	for (double i = 2.1; i < 10; i += 0.5)
	{
		B.push_back(i);
		second.push_back(i);
	}
	myPrint(B);
	stPrint(second);
	
	A.merge(B, compare);
	first.merge(second, compare);

	myPrint(A);
	stPrint(first);

	std::cout << "\n----SORT----\n";
	A.sort(compare);
	first.sort(compare);
	myPrint(A);
	stPrint(first);

	std::cout << "\n----REVERSE----\n";
	A.reverse();
	first.reverse();
	myPrint(A);
	stPrint(first);
}