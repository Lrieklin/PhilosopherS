NAME	=	philo_bonus

SRCS	=	create_struct_bonus.c\
			parser_bonus.c\
			philo_lounch.c\
			printf_bonus.c\
			utils_bonus.c\
			philo_utils_bonus.c\
			philo_bonus.c \
			
HEADER	=	philo_bonus.h

OBJ		=	$(SRCS:%.c=%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=thread

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