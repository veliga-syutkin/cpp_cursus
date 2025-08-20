# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 09:52:01 by vsyutkin          #+#    #+#              #
#    Updated: 2025/08/20 16:05:45 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLASSES =	Date

INTERFACES =	

# # **************************************************************************** #

SRC =	main.cpp \
		$(addsuffix .cpp, $(CLASSES))
	
HEADERS =	$(addsuffix .hpp, $(CLASSES)) \
			$(addsuffix .hpp, $(INTERFACES)) \
			

# **************************************************************************** #

NAME = btc

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

# **************************************************************************** #

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re