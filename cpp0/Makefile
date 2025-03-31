# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 16:25:34 by vsyutkin          #+#    #+#              #
#    Updated: 2025/04/01 00:54:49 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for the entire CPP00 Module.

EX00_DIR = ./ex00/
EX01_DIR = ./ex01/
EX02_DIR = ./ex02/

DIR_EX = $(EX00_DIR) $(EX01_DIR) $(EX02_DIR)

# List of all the Makefiles in the directories
MAKEFILES = $(addprefix $(DIR_EX), Makefile)

all: $(MAKEFILES)
	@$(MAKE) -C $(EX00_DIR)
	@$(MAKE) -C $(EX01_DIR)
	@$(MAKE) -C $(EX02_DIR)
	@echo "All exercices compiled successfully."

clean:
	@$(MAKE) -C $(EX00_DIR) clean
	@$(MAKE) -C $(EX01_DIR) clean
	@$(MAKE) -C $(EX02_DIR) clean
	@echo "Cleaned all exercices."

fclean:
	@$(MAKE) -C $(EX00_DIR) fclean
	@$(MAKE) -C $(EX01_DIR) fclean
	@$(MAKE) -C $(EX02_DIR) fclean
	@echo "All exercices full cleaned."

re: fclean all
	@echo "All exercices recompiled successfully."

.PHONY: all clean fclean re

# **************************************************************************** #

# ex00:
# 	@$(MAKE) -C $(EX00_DIR)
# 	@echo "ex00 module compiled successfully."

# ex01:
# 	@$(MAKE) -C $(EX01_DIR)
# 	@echo "ex01 module compiled successfully."

# ex02:
# 	@$(MAKE) -C $(EX02_DIR)
# 	@echo "ex02 module compiled successfully."

# .PHONY: ex00 ex01 ex02
# **************************************************************************** #

