# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smago <smago@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 15:03:14 by smago             #+#    #+#              #
#    Updated: 2021/05/14 14:27:18 by smago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRCS = main.cpp testList/testListA.cpp testList/testListB.cpp testList/testListC.cpp \
		testList/testListD.cpp testList/testListE.cpp testList/testListF.cpp \
		testList/testListG.cpp testVector/testVectorA.cpp testVector/testVectorB.cpp \
		testVector/testVectorC.cpp testVector/testVectorD.cpp testStack/testStackA.cpp \
		testQueue/testQueueA.cpp testMap/testMapA.cpp testMap/testMapB.cpp testMap/testMapC.cpp
		

FLAGS = -Wall -Wextra -Werror

all:
	clang++ $(SRCS) $(FLAGS) -std=c++98 -g -o $(NAME) 

clean:
	rm -rf $(NAME) test.dSYM