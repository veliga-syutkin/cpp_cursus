# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 00:17:29 by vsyutkin          #+#    #+#              #
#    Updated: 2025/04/01 00:43:25 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Account.cpp \
		tests.cpp \

NAME = StolenJob.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f last.log

re: fclean all

run: $(NAME) 
	./$(NAME) > ./last.log

.PHONY: all clean fclean re