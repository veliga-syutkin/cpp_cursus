# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 00:45:14 by vsyutkin          #+#    #+#              #
#    Updated: 2025/04/04 13:39:23 by vsyutkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for the all CPP Modules.

CPP00_DIR = ./cpp0/
CPP01_DIR = ./cpp1/
# CPP02_DIR = ./cpp2/
# CPP03_DIR = ./cpp3/
# CPP04_DIR = ./cpp4/
# CPP05_DIR = ./cpp5/
# CPP06_DIR = ./cpp6/
# CPP07_DIR = ./cpp7/
# CPP08_DIR = ./cpp8/
# CPP09_DIR = ./cpp9/

DIR_CPP = $(CPP00_DIR) $(CPP01_DIR) $(CPP02_DIR) $(CPP03_DIR) $(CPP04_DIR) \
	$(CPP05_DIR) $(CPP06_DIR) $(CPP07_DIR) $(CPP08_DIR) $(CPP09_DIR)

# List of all the Makefiles in the directories
MAKEFILES = $(addprefix $(DIR_CPP), Makefile)

all: $(MAKEFILES)
	 @$(MAKE) -C $(CPP00_DIR)
	 @$(MAKE) -C $(CPP01_DIR)
#	 @$(MAKE) -C $(CPP02_DIR)
#	 @$(MAKE) -C $(CPP03_DIR)
#	 @$(MAKE) -C $(CPP04_DIR)
#	 @$(MAKE) -C $(CPP05_DIR)
#	 @$(MAKE) -C $(CPP06_DIR)
#	 @$(MAKE) -C $(CPP07_DIR)
#	 @$(MAKE) -C $(CPP08_DIR)
#	 @$(MAKE) -C $(CPP09_DIR)
	@echo "All modules compiled successfully."

clean:
	@$(MAKE) -C $(CPP00_DIR) clean
	@$(MAKE) -C $(CPP01_DIR) clean
#	@$(MAKE) -C $(CPP02_DIR) clean
#	@$(MAKE) -C $(CPP03_DIR) clean
#	@$(MAKE) -C $(CPP04_DIR) clean
#	@$(MAKE) -C $(CPP05_DIR) clean
#	@$(MAKE) -C $(CPP06_DIR) clean
#	@$(MAKE) -C $(CPP07_DIR) clean
#	@$(MAKE) -C $(CPP08_DIR) clean
#	@$(MAKE) -C $(CPP09_DIR) clean
	@echo "Cleaned all modules."

fclean:
	@$(MAKE) -C $(CPP00_DIR) fclean
	@$(MAKE) -C $(CPP01_DIR) fclean
#	@$(MAKE) -C $(CPP02_DIR) fclean
#	@$(MAKE) -C $(CPP03_DIR) fclean
#	@$(MAKE) -C $(CPP04_DIR) fclean
#	@$(MAKE) -C $(CPP05_DIR) fclean
#	@$(MAKE) -C $(CPP06_DIR) fclean
#	@$(MAKE) -C $(CPP07_DIR) fclean
#	@$(MAKE) -C $(CPP08_DIR) fclean
#	@$(MAKE) -C $(CPP09_DIR) fclean
	@echo "All modules full cleaned."

re: fclean all
	@echo "All modules recompiled successfully."

.PHONY: all clean fclean re

# ############################################################################ #
#										 # VERSIONS UPDATER AND GIT MANAGEMENT #
# ############################################################################ #

VERSIONS_DIR = ./release_notes/

# Variables
VERSIONS_NUMBER := $(shell cat $(VERSIONS_DIR)versions.txt)
COMMIT_FILE = $(VERSIONS_DIR)commits.txt
COMMIT_ARGS = $(shell cat $(VERSIONS_DIR)last_commit.txt)

# Make commands in this makefile
help: info
	@echo "Available commands: (make <command>)\n"
	@echo "help\n Display this help message.\n\n"
	@echo "checks\n Check for release notes directory and files.\n\
	If there is something missing, it will create it with defautl values.\n\n"
	@echo "git_cursus\n Use only from _CURSUS directory; \
	will push all projects to personal GitHub.\n\n"
	@echo "git_fpush\n Use only from project directory; \
	will push the project to git repo without norminette check.\n\n"
	@echo "git_push\n Use only from project directory; \
	if norminette's OK -> will push the project to git repo \
	(be it personal git OR vogsphere).\n\n"
	@echo "git_status\n Display git status.\n\n"

git: help

git_cursus: clear commit git_add git_status git_commit git_gitpush

git_push: clear git_auto

git_fpush: clear git_msg1 git_auto
#	* *	*

# Release directory and files checker
checks:
	@echo "Checking for release notes directory..."
	@echo "Checking for versions file..."
	@echo "Checking for commits file..."
	@echo "Checking for last commit file..."
ifeq ($(wildcard $(VERSIONS_DIR)),)
	@echo "Creating release notes directory..."
	@mkdir $(VERSIONS_DIR)
	@echo "Done!"
endif

ifeq ($(wildcard $(VERSIONS_DIR)versions.txt),)
	@echo "Creating versions file..."
	@echo "0" > $(VERSIONS_DIR)versions.txt
	@echo "Done!"
endif

ifeq ($(wildcard $(VERSIONS_DIR)commits.txt),)
	@echo "Creating commits file..."
	@echo "\t\t\t$(NAME) release notes:" > $(VERSIONS_DIR)commits.txt
	@echo "Done!"
endif

ifeq ($(wildcard $(VERSIONS_DIR)last_commit.txt),)
	@echo "Creating last commit file..."
	@echo "0" > $(VERSIONS_DIR)last_commit.txt
	@echo "Done!\t"
endif
#	* *	*

# utils:
ask:
	@echo "Please enter your commit message:"
	@read COMMIT_ARGS; \
	echo $$COMMIT_ARGS > $(VERSIONS_DIR)last_commit.txt

info:
	@echo "This makefile is only for managing git!"
	@echo "In _CURSUS/ directory, please use 'make git_cursus'"
	@echo "In projects directory, please use 'make git_push'"

commit: checks ask version_update
	@echo "v$$(($(VERSIONS_NUMBER) + 1))\n$(COMMIT_ARGS)\n" >> $(COMMIT_FILE)

version_update:
	@echo "Current version: $(VERSIONS_NUMBER)"
	@echo "Incrementing version"
	@echo $$(($(VERSIONS_NUMBER) + 1)) > $(VERSIONS_DIR)versions.txt
	@echo "New version: $$(($(VERSIONS_NUMBER) + 1))"
	@echo "Creating new release note"

# DO NOT USE
git_auto:	fclean commit git_add git_status git_commit git_gitpush

git_msg1:
	@echo "\n\tPushing without norminette...\n"

git_msg2:
	@echo "Pushing to _CURSUS (the personal github)..."

# ############################################################################ #
#														  # BASIC GIT COMMANDS #
git_status:
	git status

git_add:
	git add *

git_commit:
	git commit -m "v$$(($(VERSIONS_NUMBER) + 1)) $(COMMIT_ARGS)"

git_gitpush:
	git push
#																			   #
# ############################################################################ #

# ############################################################################ #
#								# PHONY #									   #
# ############################################################################ #

.PHONY: all clean fclean re bonus clear help git git_cursus git_push git_fpush \
git_status git_add git_commit git_gitpush norminette git_norminette git_auto \
git_msg1 git_msg2