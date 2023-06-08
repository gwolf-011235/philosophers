# text effects
RESET := \033[0m
BOLD := \033[1m
BLACK := \033[30m
GREEN := \033[32m
YELLOW := \033[33m
RED := \033[31m
BLUE := \033[34m

# directories
OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)/dep

# compiling
CC := cc
CFLAGS = -Wall -Werror -Wextra -g
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
SANITIZE = -fsanitize=leak -fsanitize=address -fsanitize=undefined
COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) -c

# targets
NAME := philo

# source files
SRC :=	main.c \
		time.c \
		input.c

# objects
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

# dependencies
DEPFILES :=$(SRC:%.c=$(DEP_DIR)/%.d)

.PHONY: all, clean, fclean, re, obj, dep

all: $(NAME)
	@echo "$(GREEN)ALL DONE!$(RESET)"

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	$(CC) $(OBJS) $(SANITIZE) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation succesful$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	@printf "$(GREEN)$(BOLD)$(NAME)$(RESET) created!$(RESET)\n\n"

debug: CFLAGS = -g
debug: SANITIZE = -fsanitize=thread
debug: $(NAME)
	@echo "$(GREEN)DEBUG ready!$(RESET)"

$(OBJ_DIR)/%.o: %.c $(DEP_DIR)/%.d message | $(DEP_DIR)
	$(COMPILE) $< -o $@

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