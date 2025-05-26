# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 09:52:01 by vsyutkin          #+#    #+#              #
#    Updated: 2025/05/26 17:57:24 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLASSES =	Animal \
		Dog \
		Cat \
		Brain \

# # **************************************************************************** #

SRC =	main.cpp \
		$(addsuffix .cpp, $(CLASSES))
	
HEADERS =	$(addsuffix .hpp, $(CLASSES))

# **************************************************************************** #

NAME = Animals

# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g3
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