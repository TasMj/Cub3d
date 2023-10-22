CC	= gcc

RM	= rm -f

NAME	= libft.a

SRCS = 	ft_memset.c\
		ft_substr.c\
		ft_strdup.c\
		ft_memcpy.c\
		ft_strlen.c\
		ft_calloc.c\
		ft_atoi.c\
		ft_strcmp.c\
		ft_bzero.c\
		ft_printf.c\
		ft_isdigit.c\
		ft_parse.c\
		ft_basics_utils.c\
		ft_utils.c\
		ft_convert.c\
		ft_convert_xxup.c\

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -g -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
