##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Fri Apr 29 12:49:46 2016 Samuel
## Last update Thu May 12 17:43:57 2016 Samuel
##

SRC	=	src/maze.c		\
		src/make_maze.c		\
		src/my_getnbr.c		\
		src/carve_maze.c	\
		src/parfait.c		\
		src/top.c		\
		src/bottom.c		\
		src/check_for_prob.c	\
		src/authorize.c		\

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	maze

CFLAGS	=	-Iinclude
CFLAGS	+=	-W -Wextra -ansi -pedantic

$(NAME)	:	$(OBJ)
		$(CC) -g -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
