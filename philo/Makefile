NAME		:= philo

CC      := cc
CFLAGS  := -g3 -Wextra -Wall -Werror
HEADERS := -I ./include

SRCS_DIR := src/
SRCS     := $(addprefix $(SRCS_DIR), main.c utils.c free_and_errors.c init.c)
DIR_OBJ		:= .objs
OBJS		:= $(SRCS:$(SRCS_DIR)%.c=$(DIR_OBJ)/%.o)

VALGRIND	:= valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all
NO_PRINT	:= --no-print-directory
CYAN		:= \033[1;36m
GREEN		:= \033[1;32m
END 		:= \033[0m

all: $(NAME)

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)Done!$(END)"

clean:
	@rm -rf $(DIR_OBJ) $(DIR_OBJ_BONUS)
	@echo -n "$(GREEN)Cleaned$(END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN) all!$(END)"
	
re: fclean all

val: $(NAME)
	$(VALGRIND) ./philo 0 0 0 0 0

norm:
	@echo "\n$(CYAN)=======$(END) $(GREEN)LIBFT$(END) $(CYAN)=======$(END)"
	@norminette libraries/libft | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/libft/\x1b[1;31m&\x1b[0m/g'
	@echo "\n$(CYAN)=======$(END) $(GREEN)MANDATORY$(END) $(CYAN)=======$(END)"
	@norminette src | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/src/\x1b[1;33m&\x1b[0m/g'
	@echo "\n$(CYAN)=======$(END) $(GREEN)INCLUDES$(END) $(CYAN)=======$(END)"
	@norminette includes | sed 's/OK/\x1b[1;32m&\x1b[0m/g' | sed 's/includes/\x1b[1;36m&\x1b[0m/g'

.PHONY: all clean fclean re norm val