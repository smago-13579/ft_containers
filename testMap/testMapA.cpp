/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMapA.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:40:08 by smago             #+#    #+#             */
/*   Updated: 2021/05/10 15:00:34 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testMapA()
{
	std::cout << "----MAP----\n";
	{
		std::cout << "----DEFAULT CONSTRUCTOR----\n\n";
		ft::map<std::string, double> S;
		ft::map<double, char> D;

		ft::map<int, std::string> A;
		std::map<int, std::string> B;
		myPrint(A);
		stPrint(B);

		std::cout << "----NOTHING TO DISPLAY----\n";
	}

	std::cout << "\n----TEST INSERT----\n";

	std::map<char,int> stmap;
	ft::map<char, int> mymap;

	stmap.insert ( std::pair<char,int>('a',100) );
	stmap.insert ( std::pair<char,int>('z',200) );
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator, bool> stret;
	stret = stmap.insert ( std::pair<char,int>('z', 500) );
	if (stret.second==false) 
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << stret.first->second << '\n';
	}

	std::pair<ft::map<char,int>::iterator, bool> myret;
	myret = mymap.insert ( std::pair<char,int>('z', 500) );
	if (myret.second==false) 
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << myret.first->second << '\n';
	}

	myPrint(mymap);
	stPrint(stmap);
	std::cout << std::endl;

	myret = mymap.insert ( std::pair<char,int>('Z', 500) );
	if (myret.second==true) 
	{
		std::cout << "element 'Z' created";
		std::cout << " with a value of " << myret.first->second << '\n';
	}

	stret = stmap.insert ( std::pair<char,int>('Z', 500) );
	if (stret.second==true) 
	{
		std::cout << "element 'Z' created";
		std::cout << " with a value of " << stret.first->second << '\n';
	}

	myPrint(mymap);
	stPrint(stmap);
	std::cout << std::endl;

	ft::map<char, int>::iterator myit = mymap.begin();
	std::map<char, int>::iterator stit = stmap.begin();

	myit = mymap.insert(myit, std::pair<char, int> ('b', 300));
	stit = stmap.insert(stit, std::pair<char, int> ('b', 300));

	std::cout << myit->first << " -> " << myit->second << std::endl;
	std::cout << stit->first << " -> " << stit->second << std::endl;
	myPrint(mymap);
	stPrint(stmap);
	
	myit = mymap.insert(myit, std::pair<char, int> ('c', 350));
	stit = stmap.insert(stit, std::pair<char, int> ('c', 350));
	std::cout << std::endl;

	std::cout << myit->first << " -> " << myit->second << std::endl;
	std::cout << stit->first << " -> " << stit->second << std::endl;
	myPrint(mymap);
	stPrint(stmap);
	std::cout << std::endl;

	ft::map<char, int> A;
	std::map<char, int> B;
	A.insert(mymap.begin()++, myit);
	B.insert(stmap.begin()++, stit);
	myPrint(A);
	stPrint(B);

	std::cout << "\n----RANGE CONSTRUCTOR----\n";
	ft::map<char, int> C(A.begin(), A.end());
	std::map<char, int> D(B.begin(), B.end());
	myPrint(C);
	stPrint(D);
	std::cout << std::endl;

	std::cout << "\n----COPY CONSTRUCTOR----\n";
	ft::map<char, int> E(mymap);
	std::map<char, int> F(stmap);
	myPrint(E);
	stPrint(F);
	std::cout << std::endl;

	std::cout << "\n----ASSIGN OPERATOR----\n";
	E = C;
	F = D;
	myPrint(E);
	stPrint(F);
	std::cout << std::endl;

}