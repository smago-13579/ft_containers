/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMapB.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 01:38:53 by smago             #+#    #+#             */
/*   Updated: 2021/05/16 13:50:00 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testMapB()
{
	std::cout << "\n----CONST ITERATORS----\n";
	ft::map<int, int> S;
	std::map<int, int> Z;

	S.insert(std::make_pair(0, 0));
	S.insert(std::make_pair(10, 0));
	S.insert(std::make_pair(20, 0));
	Z.insert(std::make_pair(0, 0));
	Z.insert(std::make_pair(10, 0));
	Z.insert(std::make_pair(20, 0));
	for (int i = 1; i <= 5; i += 1)
	{
		S.insert(std::make_pair(-i, i));
		S.insert(std::make_pair(i + 20, i));
		Z.insert(std::make_pair(-i, i));
		Z.insert(std::make_pair(i + 20, i));
	}

	std::cout << "my: ";
	for (ft::map<int, int>::const_iterator it = S.begin(); it != S.end(); it++)
	{
		std::cout << it->first << " -> " << it->second << "; ";
	}
	std::cout << std::endl;

	std::cout << "st: ";
	for (std::map<int, int>::const_iterator it = Z.begin(); it != Z.end(); it++)
	{
		std::cout << it->first << " -> " << it->second << "; ";
	}
	std::cout << std::endl << std::endl;

	ft::map<int, int>::const_iterator sit = --S.end();
	std::map<int, int>::const_iterator zit = --Z.end();

	std::cout << "my: ";
	for ( ; sit != S.begin(); sit--)
		std::cout << sit->first << " -> " << sit->second << "; ";
	std::cout << sit->first << " -> " << sit->second << "; ";
	std::cout << std::endl;

	std::cout << "st: ";
	for ( ; zit != Z.begin(); zit--)
		std::cout << zit->first << " -> " << zit->second << "; ";
	std::cout << zit->first << " -> " << zit->second << "; ";
	std::cout << std::endl << std::endl;

	std::cout << "\n----CONST MAP AND CONST ITERATORS----\n";
	const ft::map<int, int> A = S;
	const std::map<int, int> B = Z;

	sit = --A.end();
	zit = --B.end();

	std::cout << "my: ";
	for ( ; sit != A.begin(); sit--)
		std::cout << sit->first << " -> " << sit->second << "; ";
	std::cout << sit->first << " -> " << sit->second << "; ";
	std::cout << std::endl;

	std::cout << "st: ";
	for ( ; zit != B.begin(); zit--)
		std::cout << zit->first << " -> " << zit->second << "; ";
	std::cout << zit->first << " -> " << zit->second << "; ";
	std::cout << std::endl << std::endl;
	
	std::cout << "\n----REVERSE ITERATOR AND CONST REVERSE ITERATOR----\n";

	std::cout << "my: ";
	for (ft::map<int, int>::reverse_iterator it = S.rbegin(); it != S.rend(); it++)
		std::cout << it->first << " -> " << it->second << "; ";
	std::cout << std::endl;

	std::cout << "st: ";
	for (std::map<int, int>::reverse_iterator it = Z.rbegin(); it != Z.rend(); it++)
		std::cout << it->first << " -> " << it->second << "; ";
	std::cout << std::endl << std::endl;

	std::cout << "my: ";
	for (ft::map<int, int>::const_reverse_iterator it = A.rbegin(); it != A.rend(); it++)
		std::cout << it->first << " -> " << it->second << "; ";
	std::cout << std::endl;

	std::cout << "st: ";
	for (std::map<int, int>::const_reverse_iterator it = B.rbegin(); it != B.rend(); it++)
		std::cout << it->first << " -> " << it->second << "; ";
	std::cout << std::endl;

	std::cout << "\n----EMPTY, SIZE AND MAX_SIZE----\n";
	ft::map<char, std::string> C;
	std::map<char, std::string> D;
	
	std::cout << "my: " << A.empty() << " " << C.empty() << " " << S.empty() << " " << A.max_size() << std::endl;
	std::cout << "st: " << B.empty() << " " << D.empty() << " " << Z.empty() << " " << B.max_size() << std::endl;

	std::cout << "my: " << A.size() << " " << C.size() << " " << S.size() << " " << S.max_size() << std::endl;
	std::cout << "st: " << B.size() << " " << D.size() << " " << Z.size() << " " << Z.max_size() << std::endl;

	std::cout << "\n----OPERATOR []----\n";
	C['a'] = "an element";
	C['b'] = "another element";
	C['c'] = C['b'];
	C['d'];

	D['a'] = "an element";
	D['b'] = "another element";
	D['c'] = D['b'];
	D['d'];
	myPrint(C);
	stPrint(D);

	C['c'] = "nice";
	D['c'] = "nice";
	myPrint(C);
	stPrint(D);

	std::cout << "\n----ERASE----\n";
	ft::map<char, std::string>::iterator it = ++C.begin();
	std::map<char, std::string>::iterator itz = ++D.begin();
	C.erase(it);
	D.erase(itz);
	myPrint(C);
	stPrint(D);
	std::cout << std::endl;

	std::cout << "My map: " << C.erase('x') << " " << C.erase('c') << std::endl;
	std::cout << "St map: " << D.erase('x') << " " << D.erase('c') << std::endl;
	std::cout << std::endl;
	
	myPrint(C);
	stPrint(D);

	S.erase(++++++S.begin(), ----S.end());
	Z.erase(++++++Z.begin(), ----Z.end());
	myPrint(S);
	stPrint(Z);
}

