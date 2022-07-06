NAME	=	philo

SRCS	=	create_struct.c\
			parser.c\
			philo.c\
			utils.c\
			threads.c \
			printf.c\
			mutex_init.c\
			philo_utils.c\
			free_struct.c\
			
HEADER	=	philo.h

OBJ		=	$(SRCS:%.c=%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	cc $(CFLAGS) $(OBJ)  -o $(NAME) 

%.o		:	%.c $(HEADER) $(HEADERLIBFT) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all