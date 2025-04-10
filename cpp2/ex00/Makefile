# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 09:52:01 by vsyutkin          #+#    #+#              #
#    Updated: 2025/04/10 12:57:09 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Fixed.cpp \
		main.cpp

HEADERS =	Fixed.hpp

NAME = Fixed

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
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