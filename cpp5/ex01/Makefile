# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 09:52:01 by vsyutkin          #+#    #+#              #
#    Updated: 2025/05/29 16:53:05 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLASSES =	Bureaucrat \
			ExceptionsCPP5 \
			Form \

INTERFACES =	

# # **************************************************************************** #

SRC =	main.cpp \
		$(addsuffix .cpp, $(CLASSES))
	
HEADERS =	$(addsuffix .hpp, $(CLASSES)) \
			$(addsuffix .hpp, $(INTERFACES))

# **************************************************************************** #

NAME = office

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