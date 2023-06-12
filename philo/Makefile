# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 10:17:44 by gwolf             #+#    #+#              #
#    Updated: 2023/06/13 01:09:56 by gwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# text effects
RESET := \033[0m
BOLD := \033[1m
BLACK := \033[30m
GREEN := \033[32m
YELLOW := \033[33m
RED := \033[31m
BLUE := \033[34m

# directories
SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)/dep

# compiling
CC := cc
SANITIZE = -fsanitize=address
CPPFLAGS = -I $(INC_DIR)
CFLAGS = -Wall -Werror -Wextra -pthread -g $(SANITIZE)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE = $(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS)

# targets
NAME := philo

# source files
SRC :=	cleanup.c \
		error_msg.c \
		get.c \
		init_mutex.c \
		init.c \
		input.c \
		main.c \
		monitoring.c \
		philo_threads.c \
		print.c \
		routine.c \
		set.c \
		teardown.c \
		utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

# objects
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

# dependencies
DEPFILES :=$(SRC:%.c=$(DEP_DIR)/%.d)

.PHONY: all, clean, fclean, re, obj, dep

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	$(COMPILE) $(OBJS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation succesful$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	@printf "$(GREEN)$(BOLD)$(NAME)$(RESET) created!$(RESET)\n\n"

debug: SANITIZE = -fsanitize=thread
debug: $(NAME)
	@echo "$(GREEN)DEBUG ready!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_DIR)/%.d message | $(DEP_DIR)
	$(COMPILE) -c $< -o $@

.INTERMEDIATE: message
message:
	@printf "\n$(YELLOW)$(BOLD)compile objects$(RESET) [$(BLUE)philosophers$(RESET)]\n"

$(DEP_DIR):
	@printf "\n$(YELLOW)$(BOLD)create subdir$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	mkdir -p $@

$(DEPFILES):

clean:
	@printf "\n$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)removed subdir $(OBJ_DIR)$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)removed binary $(NAME)$(RESET)\n"

re: fclean all

include $(wildcard $(DEPFILES))