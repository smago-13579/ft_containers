/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMapC.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:06:10 by smago             #+#    #+#             */
/*   Updated: 2021/05/16 04:09:02 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testMapC()
{
	std::cout << "\n----SWAP----\n";

	ft::map<char, int> A;
	std::map<char, int> B;
	
	A.insert(std::make_pair('a', 1));
	A.insert(std::make_pair('b', 2));
	A.insert(std::make_pair('c', 3));
	A.insert(std::make_pair('d', 4));

	B.insert(std::make_pair('a', 1));
	B.insert(std::make_pair('b', 2));
	B.insert(std::make_pair('c', 3));
	B.insert(std::make_pair('d', 4));

	ft::map<char, int> C;
	std::map<char, int> D;
	C.insert(std::make_pair('x', 8));
	C.insert(std::make_pair('y', 9));

	D.insert(std::make_pair('x', 8));
	D.insert(std::make_pair('y', 9));

	A.swap(C);
	B.swap(D);
	myPrint(A);
	stPrint(B);
	myPrint(C);
	stPrint(D);

	std::cout << "\n----CLEAR----\n";
	A.clear();
	B.clear();

	myPrint(A);
	stPrint(B);
	std::cout << A.size() << " " << B.size() << std::endl;

	A['a'] = 10;
	B['a'] = 10;
	myPrint(A);
	stPrint(B);
	std::cout << A.size() << " " << B.size() << std::endl;

	std::cout << "\n----KEY_COMPARE----\n";
	ft::map<char, int>::key_compare comp = A.key_comp();
	std::cout << "Compare 'a' less than 'b': ";
	if (comp('a', 'b'))
		std::cout << "True\n";
	else 
		std::cout << "False\n";

	std::cout << "Compare 'x' less than 'b': ";
	if (comp('x', 'b'))
		std::cout << "True\n";
	else 
		std::cout << "False\n";

	std::cout << "\n----VALUE_COMPARE----\n";
	ft::map<char, int>::iterator first = C.begin();
	ft::map<char, int>::iterator last = --C.end();
	std::cout << "My map contains: \n";
	while (C.value_comp()(*first, *last))
	{
		std::cout << first->first << " -> " << first->second << std::endl;
		first++;
	}
	std::cout << first->first << " -> " << first->second << std::endl;
	
	{
		const ft::map<char, int> G = C;
		const std::map<char, int> H = D;
		ft::map<char, int>::const_iterator it = G.find('c');
		std::map<char, int>::const_iterator itz = H.find('c');
		std::cout << "\n----FIND----\n";
		std::cout << "my: " << it->first << " -> " << it->second << std::endl;
		std::cout << "st: " << itz->first << " -> " << itz->second << std::endl;
	}
	{
		ft::map<char, int>::iterator it = C.find('b');
		std::map<char, int>::iterator itz = D.find('b');
		std::cout << "my: " << it->first << " -> " << it->second << std::endl;
		std::cout << "st: " << itz->first << " -> " << itz->second << std::endl;
	}
	
	std::cout << "\n----COUNT----\n";
	std::cout << "my: " << A.count('a') << " " << A.count('b') << std::endl;
	std::cout << "st: " << B.count('a') << " " << B.count('b') << std::endl;

	const ft::map<char, int> G = C;
	const std::map<char, int> H = D;
	std::cout << "my: " << G.count('a') << " " << G.count('e') << std::endl;
	std::cout << "st: " << H.count('a') << " " << H.count('e') << std::endl;

	std::cout << "\n----LOWER_BOUND----\n";
	myPrint(C);
	stPrint(D);
	ft::map<char, int>::iterator it;
	ft::map<char, int>::const_iterator const_it;
	std::map<char, int>::iterator zit;
	std::map<char, int>::const_iterator const_zit;

	std::cout << "my: " << (C.lower_bound('b'))->first << " " << C.lower_bound('d')->first << std::endl;
	std::cout << "st: " << (D.lower_bound('b'))->first << " " << D.lower_bound('d')->first << std::endl;
	std::cout << "my: " << (G.lower_bound('A'))->first << " " << G.lower_bound('c')->first << std::endl;
	std::cout << "st: " << (H.lower_bound('A'))->first << " " << H.lower_bound('c')->first << std::endl;

	std::cout << "\n----UPPER_BOUND----\n";
	std::cout << "my: " << (C.upper_bound('b'))->first << " " << C.upper_bound('d')->first << std::endl;
	std::cout << "st: " << (D.upper_bound('b'))->first << " " << D.upper_bound('d')->first << std::endl;
	std::cout << "my: " << (G.upper_bound('A'))->first << " " << G.upper_bound('c')->first << std::endl;
	std::cout << "st: " << (H.upper_bound('A'))->first << " " << H.upper_bound('c')->first << std::endl;
	
	std::cout << "\n----EQUAL_RANGE----\n";
	std::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> retz;

	std::pair<ft::map<char, int>::const_iterator, ft::map<char, int>::const_iterator> const_ret;
	std::pair<std::map<char, int>::const_iterator, std::map<char, int>::const_iterator> const_retz;

	ret = C.equal_range('a');
	retz = D.equal_range('a');
	std::cout << "my: " << ret.first->first << " -> " << ret.first->second << std::endl;
	std::cout << "st: " << retz.first->first << " -> " << retz.first->second << std::endl;

	std::cout << "my: " << ret.second->first << " -> " << ret.second->second << std::endl;
	std::cout << "st: " << retz.second->first << " -> " << retz.second->second << std::endl;

	const_ret = G.equal_range('c');
	const_retz = H.equal_range('c');
	std::cout << "my: " << const_ret.first->first << " -> " << const_ret.first->second << std::endl;
	std::cout << "st: " << const_retz.first->first << " -> " << const_retz.first->second << std::endl;

	std::cout << "my: " << const_ret.second->first << " -> " << const_ret.second->second << std::endl;
	std::cout << "st: " << const_retz.second->first << " -> " << const_retz.second->second << std::endl;

}