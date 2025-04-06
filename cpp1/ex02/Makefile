# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 13:31:49 by vsyutkin          #+#    #+#              #
#    Updated: 2025/04/04 17:53:40 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp
BONUS_SRC = man_ptr_ref.cpp

HEADERS = 

NAME = brain
NAME_BONUS = man_ptr_ref

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:.cpp=.o)
OBJS_BONUS = $(BONUS_SRC:.cpp=.o)

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CXX) $(CXXFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

.PHONY: all clean fclean re