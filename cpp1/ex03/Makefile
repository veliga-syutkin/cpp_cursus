# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 13:31:49 by vsyutkin          #+#    #+#              #
#    Updated: 2025/04/07 01:26:07 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Human.cpp \
		HumanA.cpp \
		HumanB.cpp \
		main.cpp \
		Weapon.cpp

HEADERS =	Human.hpp \
			HumanA.hpp \
			HumanB.hpp \
			Weapon.hpp

NAME = Human_and_Weapon

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re