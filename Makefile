##
## Makefile for  in /home/quach_a/Lab/philo
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Mon Feb 16 22:23:44 2015 Jonathan Quach
## Last update Sun Mar  1 22:43:18 2015 Jonathan Quach
##

SRCS =  action.c \
	init.c \
	main.c

OBJS =	$(SRCS:.c=.o)

NAME =	philo

CC = 	gcc

RM = 	rm -f

CFLAGS = -W -Wall -Werror -Wextra

LDFLAG = -pthread

all: 	 $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAG)

clean:
	 $(RM) $(OBJS)

fclean:  clean
	 $(RM) $(NAME)

re:	 fclean all

.PHONY:  all clean fclean re
