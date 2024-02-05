NAME = minishell

SRCS =	parsing/parsing.c\
		parsing/utils_parsing.c\
		parsing/check_parse_errors.c\
		minishell.c\
		expand/e_parsing.c\
		expand/expand_utils.c\
		signals.c\
		utils/utils.c\
		utils/utils2.c\
		utils/error_printing.c\
		utils/utils3.c\
		utils/get_env.c\
		utils/cleardata.c\
		builtins/check_builtins.c\
		builtins/cd.c\
		builtins/echo.c\
		builtins/exit.c\
		builtins/env.c\
		builtins/export.c\
		builtins/export_utils.c\
		builtins/pwd.c\
		builtins/unset.c\
		execution/exec.c\
		execution/heredoc.c\
		execution/utils_exec.c\
		execution/fds_exec.c\
		execution/exec_utils.c\
		utils/free_data.c\

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./includes

HEADERFILES = ./includes/minishell.h

LIBFT = libft.a

LIBS = -lreadline $(LIBFT)

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDES) $(LIBS) -o $(NAME) -g
	@echo "compilation OK."

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .
	$(MAKE) -C libft clean

lean:
	@echo "removing ./minishell."
	@rm -f $(NAME)

fclean:
	@echo "removing libft.a."
	@rm -f $(LIBFT)
	@echo "removing ./minishell."
	@rm -f $(NAME)

re: fclean all

r:
	$(MAKE) && clear && valgrind --leak-check=full ./$(NAME)

fd:
	$(MAKE) && clear && valgrind --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re r
