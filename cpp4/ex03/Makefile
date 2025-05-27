# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 09:52:01 by vsyutkin          #+#    #+#              #
#    Updated: 2025/05/27 14:21:52 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLASSES =	AMateria \
			Character \
			Cure \
			Ice \
			MateriaSource \

INTERFACES =	IMateriaSource \
			ICharacter \

# # **************************************************************************** #

SRC =	main.cpp \
		$(addsuffix .cpp, $(CLASSES))
	
HEADERS =	$(addsuffix .hpp, $(CLASSES)) \
			$(addsuffix .hpp, $(INTERFACES))

# **************************************************************************** #

NAME = Materia

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