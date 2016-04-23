##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/init_ia/dante/gen_lab
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Fri Apr 22 17:18:40 2016 Samuel
## Last update Fri Apr 22 17:26:45 2016 Samuel
##

SRC	=	src/gen_laby.c	\
		src/my_getnbr.c	\

NAME	=	gen_and_solve

CFLAGS	=	-Iinclude
CFLAGS	+=	-Wall -W -Wextra -pedantic

CC	=	gcc

RM	=	rm -rf

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
