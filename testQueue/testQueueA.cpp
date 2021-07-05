/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testQueueA.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:38:38 by smago             #+#    #+#             */
/*   Updated: 2021/05/01 14:16:16 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testQueueA()
{
	{
		std::cout << "\n----QUEUE----\n";
		std::cout << "----DEFAULT CONSTRUCTOR----\n\n";
		ft::queue<int> a;
		ft::queue<std::string> s;
		ft::queue<double> d;
		std::cout << "----NOTHING TO DISPLAY----\n\n";
	}

	std::cout << "\n----CONSTRUCTOR WITH CONTAINER----\n";
	std::deque<int> mydeque (3,100);

	std::list<int> stlist (2, 200);
	ft::list<int> mylist (2,200);
            
	ft::queue<int> A(mydeque);
	std::queue<int> B(mydeque);

	ft::queue<int, ft::list<int> > C(mylist);
	std::queue<int, std::list<int> > D(stlist);

	ft::queue<int, ft::list<int> > X; 
	std::queue<int, std::list<int> > Y;

	std::cout << "\n----TEST SIZE()----\n";

	std::cout << "size of my: " << A.size() << '\n';
	std::cout << "size of st: " << B.size() << '\n';
	std::cout << "size of my: " << C.size() << '\n';
	std::cout << "size of st: " << D.size() << "\n";
	std::cout << "size of my: " << X.size() << '\n';
	std::cout << "size of st: " << Y.size() << "\n";

	std::cout << "\n----TEST EMPTY()----\n";

	std::cout << "my: " << A.empty() << '\n';
	std::cout << "st: " << B.empty() << '\n';
	std::cout << "my: " << C.empty() << '\n';
	std::cout << "st: " << D.empty() << "\n";
	std::cout << "my: " << X.empty() << '\n';
	std::cout << "st: " << Y.empty() << "\n";

	std::cout << "\n----TEST FRONT----\n";
	std::cout << "my: " << A.front() << '\n';
	std::cout << "st: " << B.front() << '\n';
	std::cout << "my: " << C.front() << '\n';
	std::cout << "st: " << D.front() << "\n";

	std::cout << "\n----TEST BACK----\n";
	std::cout << "my: " << A.back() << '\n';
	std::cout << "st: " << B.back() << '\n';
	std::cout << "my: " << C.back() << '\n';
	std::cout << "st: " << D.back() << "\n";

	std::cout << "\n----TEST PUSH AND POP----\n";
	std::cout << "\n----ADD 9 ELEMENTS FROM 50 to 58----\n";
	for (int i = 50; i < 59; i++)
	{
		X.push(i);
		Y.push(i);
	}
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.front() << " " << X.back() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.front() << " " << Y.back() << std::endl;
	X.pop();
	Y.pop();
	
	std::cout << "\n----DELETE FIRST ELEMENT----\n";
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.front() << " " << X.back() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.front() << " " << Y.back() << std::endl;
	X.pop();
	Y.pop();

	std::cout << "\n----DELETE FIRST ELEMENT----\n";
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.front() << " " << X.back() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.front() << " " << Y.back() << std::endl;
	X.pop();
	Y.pop();

	std::cout << "\n----DELETE FIRST ELEMENT----\n";
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.front() << " " << X.back() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.front() << " " << Y.back() << std::endl;

	std::cout << "\n----USE CONST QUEUE----\n";
	const ft::queue<int> a(mydeque);
	const std::queue<int> b(mydeque);

	std::cout << "my: " << a.size() << " " << a.empty() << " " << a.front() << " " << a.back() << std::endl;
	std::cout << "st: " << b.size() << " " << b.empty() << " " << b.front() << " " << b.back() << std::endl;

	std::cout << "\n----NON-MEMBER FUNCTION OVERLOADS----\n";
	std::cout << "my: " << (C == X) << std::endl;
	std::cout << "st: " << (D == Y) << std::endl;
	std::cout << "my: " << (C != X) << std::endl;
	std::cout << "st: " << (D != Y) << std::endl;
	std::cout << "my: " << (C > X) << std::endl;
	std::cout << "st: " << (D > Y) << std::endl;
	std::cout << "my: " << (C < X) << std::endl;
	std::cout << "st: " << (D < Y) << std::endl;
	std::cout << "my: " << (C >= X) << std::endl;
	std::cout << "st: " << (D >= Y) << std::endl;
	std::cout << "my: " << (C <= X) << std::endl;
	std::cout << "st: " << (D <= Y) << std::endl;

	std::cout << "\n----MAKE THEM EQUAL AND COMPARE----\n";
	while (!X.empty() && !Y.empty())
	{
		X.pop();
		Y.pop();
	}
	for (size_t i = 0; i < 2; i++)
	{
		X.push(200);
		Y.push(200);
	}
	std::cout << "my: " << (C == X) << std::endl;
	std::cout << "st: " << (D == Y) << std::endl;
	std::cout << "my: " << (C != X) << std::endl;
	std::cout << "st: " << (D != Y) << std::endl;
	std::cout << "my: " << (C > X) << std::endl;
	std::cout << "st: " << (D > Y) << std::endl;
	std::cout << "my: " << (C < X) << std::endl;
	std::cout << "st: " << (D < Y) << std::endl;
	std::cout << "my: " << (C >= X) << std::endl;
	std::cout << "st: " << (D >= Y) << std::endl;
	std::cout << "my: " << (C <= X) << std::endl;
	std::cout << "st: " << (D <= Y) << std::endl;
}