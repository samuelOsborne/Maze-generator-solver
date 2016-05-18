##
## Makefile for Makefile in /media/samuel/Home/osborn_s/rendu/init_ia/dante
## 
## Made by Samuel
## Login   <samuel@epitech.net>
## 
## Started on  Mon Apr 18 11:19:14 2016 Samuel
## Last update Wed May 18 22:32:40 2016 Arnaud Costa
##

all		:
			make -C largeur
			make -C profondeur
			make -C astar
			make -C generateur
			mkdir -p tournoi
			cp largeur/solver tournoi/solver

clean		:
			make -C largeur clean
			make -C profondeur clean
			make -C astar clean
			make -C generateur clean

fclean		:
			make -C largeur fclean
			make -C profondeur fclean
			make -C astar fclean
			make -C generateur fclean
			rm -r tournoi

re		:	fclean all

.PHONY		:	all clean fclean re
