### Variables ###
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_strlen.c ft_strncmp.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_strdup.c \
		ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_calloc.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
		ft_strmapi.c ft_itoa.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c
OBJS = $(FILES:.c=.o) # generates the same FILES list whith the .o extension 

BNUS_FLES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
OBJS_BNUS = $(BNUS_FLES:.c=.o)

### Script ###
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

$(OBJS): $(FILES)
	$(CC) $(CFLAGS) -c $(FILES)

bonus:	$(OBJS_BNUS)
	ar -rcs $(NAME) $(OBJS_BNUS)

$(OBJS_BNUS): $(BNUS_FLES)
	$(CC) $(CFLAGS) -c $(BNUS_FLES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re