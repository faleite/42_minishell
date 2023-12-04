###############################################################################
#                                 VARIABLES                                   #
###############################################################################

# .SILENT:
NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
SRC_DIR		= src
FILES 		= $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS		= $(FILES:.c=.o)
LIBFT		= ./libft/libft.a
RM			= rm -f

.c.o:
	$(CC) -c $< -o $@

################################################################################
#                                 COLORS                                       #
################################################################################

CLR_RESET	= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
PURPLE 		= \033[0;35m

###############################################################################
#                                 SCRIPT                                      #
###############################################################################

all: $(NAME)

$(NAME): $(OBJS)
		@make -C libft
		clear
		@echo "$(GREEN)Compiling of $(RED)$(NAME)...$(CLR_RESET)"
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		@echo "$(RED)$(NAME) $(GREEN)is ready!$(CLR_RESET)\n"
		@echo "$(PURPLE)====================================$(CLR_RESET)"

clean:
		$(RM) $(OBJS)
		@make clean -C libft
		clear
		@echo "$(RED)$(NAME) object $(GREEN)files have been deleted.$(CLR_RESET)\n"

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT)
		clear
		@echo "$(RED)$(NAME) $(GREEN)has been deleted.$(CLR_RESET)\n"
		@echo "$(RED)libft $(GREEN)has been deleted.$(CLR_RESET)\n"

re: fclean all
	@echo "$(RED)$(NAME) $(GREEN)has been recompiled.$(CLR_RESET)\n"
	@echo "$(PURPLE)====================================$(CLR_RESET)"


v:
	make re && clear && valgrind --leak-check=full --show-leak-kinds=all ./minishell

.PHONY: all clean fclean re