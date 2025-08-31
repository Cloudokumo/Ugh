NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = pipex.c pipex_utils.c pipex_utils2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re