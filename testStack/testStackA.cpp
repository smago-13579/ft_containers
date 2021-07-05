/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testStackA.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:53:13 by smago             #+#    #+#             */
/*   Updated: 2021/05/01 15:37:00 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tester.hpp"

void	testStackA()
{
	{
		std::cout << "\n----STACK----\n";
		std::cout << "----DEFAULT CONSTRUCTOR----\n\n";
		ft::stack<int> a;
		ft::stack<std::string> s;
		ft::stack<double> d;
		std::cout << "----NOTHING TO DISPLAY----\n\n";
	}

	std::cout << "\n----CONSTRUCTOR WITH CONTAINER----\n";
	std::deque<int> mydeque (3,100);         
	std::vector<int> stvector (2, 200);

	ft::vector<int> myvector (2,200);      
            
	ft::stack<int> A(mydeque);         
	std::stack<int> B(mydeque);

	ft::stack<int, ft::vector<int> > C(myvector);
	std::stack<int, std::vector<int> > D(stvector);

	ft::stack<int, ft::vector<int> > X; 
	std::stack<int, std::vector<int> > Y;

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

	std::cout << "\n----TEST TOP----\n";
	std::cout << "my: " << A.top() << '\n';
	std::cout << "st: " << B.top() << '\n';
	std::cout << "my: " << C.top() << '\n';
	std::cout << "st: " << D.top() << "\n";

	std::cout << "\n----TEST PUSH AND POP----\n";
	std::cout << "\n----ADD 9 ELEMENTS FROM 50 to 58----\n";
	for (int i = 50; i < 59; i++)
	{
		X.push(i);
		Y.push(i);
	}
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.top() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.top() << std::endl;
	X.pop();
	Y.pop();
	
	std::cout << "\n----DELETE LAST ELEMENT----\n";
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.top() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.top() << std::endl;
	X.pop();
	Y.pop();

	std::cout << "\n----DELETE LAST ELEMENT----\n";
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.top() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.top() << std::endl;
	X.pop();
	Y.pop();

	std::cout << "\n----DELETE LAST ELEMENT----\n";
	std::cout << "my: " << X.size() << " " << X.empty() << " " << X.top() << std::endl;
	std::cout << "st: " << Y.size() << " " << Y.empty() << " " << Y.top() << std::endl;

	std::cout << "\n----USE CONST STACK----\n";
	const ft::stack<int> a(mydeque);
	const std::stack<int> b(mydeque);

	std::cout << "my: " << a.size() << " " << a.empty() << " " << a.top() << std::endl;
	std::cout << "st: " << b.size() << " " << b.empty() << " " << b.top() << std::endl;

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