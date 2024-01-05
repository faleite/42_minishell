###############################################################################
#                                 VARIABLES                                   #
###############################################################################

# .SILENT:
NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
SL			= src/lexer
SP			= src/parser
# FILES 		= $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
FILES 		= src/minishell.c\
			  $(SL)/cmdline_split.c $(SL)/expander.c $(SL)/handle_dollar.c\
			  $(SL)/trim_quotes.c $(SL)/lexer.c\
			  $(SP)/parser.c $(SP)/utils.c\

OBJS		= $(FILES:.c=.o)
LIBFT		= ./libft/libft.a
RDLINE		= -lreadline -lhistory
# RDLINE		= -L/usr/local/opt/readline/lib -lreadline -lhistory # for mac
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
#		@make -C libft
#		clear
		@echo "$(GREEN)Compiling of $(RED)$(NAME)...$(CLR_RESET)"
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(RDLINE) -o $(NAME)
		@echo "$(RED)$(NAME) $(GREEN)is ready!$(CLR_RESET)\n"
		@echo "$(PURPLE)====================================$(CLR_RESET)"

clean:
		$(RM) $(OBJS)
		@make clean -C libft
		clear
		@echo "$(RED)$(NAME) object $(GREEN)files have been deleted.$(CLR_RESET)\n"

fclean: clean
		$(RM) $(NAME)
#		$(RM) $(LIBFT)
		clear
		@echo "$(RED)$(NAME) $(GREEN)has been deleted.$(CLR_RESET)\n"
		@echo "$(RED)libft $(GREEN)has been deleted.$(CLR_RESET)\n"

re: fclean all
	@echo "$(RED)$(NAME) $(GREEN)has been recompiled.$(CLR_RESET)\n"
	@echo "$(PURPLE)====================================$(CLR_RESET)"

v:
	make re && valgrind --leak-check=full --suppressions="supp.supp" ./minishell

# a flag --show-leak-kinds=all 
# pode ajudar a identificar vazamentos de memória que de outra forma poderiam passar despercebidos.
vs:
	make re && valgrind --leak-check=full --show-leak-kinds=all --suppressions="supp.supp" ./minishell

fd:
	make re && valgrind  --track-fds=yes ./minishell

.PHONY: all clean fclean re