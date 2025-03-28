# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 16:25:34 by vsyutkin          #+#    #+#              #
#    Updated: 2025/03/28 17:34:54 by vsyutkin         ###   ########.fr        #
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
	@echo "All modules compiled successfully."

clean:
	@$(MAKE) -C $(EX00_DIR) clean
	@$(MAKE) -C $(EX01_DIR) clean
	@$(MAKE) -C $(EX02_DIR) clean
	@echo "Cleaned all modules."

fclean: clean
	@$(MAKE) -C $(EX00_DIR) fclean
	@$(MAKE) -C $(EX01_DIR) fclean
	@$(MAKE) -C $(EX02_DIR) fclean
	@echo "All modules cleaned."

re: fclean all
	@echo "All modules recompiled successfully."

.PHONY: all clean fclean re

# **************************************************************************** #

ex00:
	@$(MAKE) -C $(EX00_DIR)
	@echo "ex00 module compiled successfully."
