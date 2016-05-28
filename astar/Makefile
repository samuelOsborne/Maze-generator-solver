##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/init_ia/dante/graphs
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Wed Apr 27 14:28:35 2016 Samuel
## Last update Sat May 28 13:31:48 2016 Arnaud Costa
##

SRC	=	src/main.c		\
		src/get_next_line.c	\
		src/my_strlen.c		\
		src/free_tab.c		\
		src/my_strcpy.c		\
		src/print_tab.c		\
		src/create_maillon.c	\
		src/get_maze.c		\
		src/map_funcs.c		\
		src/update_tab_posi.c	\
		src/memset_tab.c	\
		src/check_direction.c	\
		src/ini_close.c

NAME	=	solver

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

RM 	=	rm -f

CFLAGS	=	-W -Wall -Wextra -ansi -Iinclude

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:	
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
