NAME = libft.a

AR = ar
ARFLAGS = crs

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

CC = cc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES = ./libft.h

SRC_PART1 = \
	./ft_memset.c\
	./ft_bzero.c\
	./ft_memcpy.c\
	./ft_memmove.c\
	./ft_memchr.c\
	./ft_memcmp.c\
	./ft_calloc.c\
	./ft_strlen.c\
	./ft_strlcpy.c\
	./ft_strlcat.c\
	./ft_strchr.c\
	./ft_strrchr.c\
	./ft_strncmp.c\
	./ft_strnstr.c\
	./ft_strdup.c\
	./ft_isdigit.c\
	./ft_atoi.c\
	./ft_atof.c\
	./ft_isalpha.c\
	./ft_isalnum.c\
	./ft_isascii.c\
	./ft_isprint.c\
	./ft_toupper.c\
	./ft_tolower.c

SRC_PART2 = \
	./ft_substr.c\
	./ft_strjoin.c\
	./ft_strtrim.c\
	./ft_split.c\
	./ft_itoa.c\
	./ft_strmapi.c\
	./ft_striteri.c\
	./ft_putchar_fd.c\
	./ft_putstr_fd.c\
	./ft_putendl_fd.c\
	./ft_putnbr_fd.c

SRCS_BONUS	=	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c


SRCS = \
	$(SRC_PART1)\
	$(SRC_PART2)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)


all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all


$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS) 

.PHONY: all clean fclean re bonus