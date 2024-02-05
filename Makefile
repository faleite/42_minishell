###############################################################################
#                                 VARIABLES                                   #
###############################################################################

# .SILENT:
NAME		= minishell
INC			= includes/executor.h includes/parser.h src/builtins/builtins.h
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
SRC_DIR		= src/
SL			= src/lexer
SP			= src/parser
SE			= src/errors
SEC			= src/executor
SB			= src/builtins
SH			= src/heredoc
# FILES 		= $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
FILES 		= $(SRC_DIR)parser.c $(SRC_DIR)exit.c\
			  $(SL)/cmdline_split.c $(SL)/expander.c $(SL)/handle_dollar.c\
			  $(SL)/trim_quotes.c $(SL)/lexer.c\
			  $(SP)/parser_redirect.c $(SP)/utils.c $(SP)/parser_args.c\
			  $(SP)/free_data.c $(SP)/parser_prompt.c $(SP)/debugs.c\
			  $(SE)/handle_errors.c $(SE)/handle_data.c $(SE)/sintax_errors.c\
			  $(SH)/heredoc.c $(SH)/expander_hd.c $(SH)/heredoc_utils.c\
			  $(SEC)/envp.c $(SEC)/execve.c $(SEC)/fd.c $(SEC)/path.c\
			  $(SEC)/init_executor.c $(SB)/builtins.c $(SB)/echo.c\
			  $(SB)/pwd.c $(SB)/cd.c $(SB)/unset.c $(SB)/envp_utils.c\
			  $(SB)/builtin_utils.c $(SB)/exit.c $(SB)/env_export.c

OBJS		= $(FILES:.c=.o)
LIBFT		= ./libft/libft.a
RDLINE		= -lreadline -lhistory
# RDLINE		= -L/usr/local/opt/readline/lib -lreadline -lhistory # for mac
RM			= rm -f

.c.o:
	$(CC) -c $< -o $@ -g

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
		@echo "$(GREEN)Compiling of $(REminishell.c:25D)$(NAME)...$(CLR_RESET)"
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
		$(RM) $(LIBFT)
		clear
		@echo "$(RED)$(NAME) $(GREEN)has been deleted.$(CLR_RESET)\n"
		@echo "$(RED)libft $(GREEN)has been deleted.$(CLR_RESET)\n"

re: fclean all
	@echo "$(RED)$(NAME) $(GREEN)has been recompiled.$(CLR_RESET)\n"
	@echo "$(PURPLE)====================================$(CLR_RESET)"

v:
	make re && valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

# a flag --show-leak-kinds=all 
# pode ajudar a identificar vazamentos de memória que de outra forma poderiam passar despercebidos.
vs:
	make re && valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell

fd:
	make re && valgrind  --track-fds=yes ./minishell

.PHONY: all clean fclean re
