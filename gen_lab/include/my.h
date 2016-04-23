/*
** my.h for my in /media/samuel/Home/osborn_s/rendu/init_ia/dante/gen_lab
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 22 11:28:35 2016 Samuel
** Last update Fri Apr 22 17:25:19 2016 Samuel
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_maze
{
  int		x1;
  int		y1;
  int		x2;
  int		y2;
  int		dx;
  int		dy;
  int		dir;
  int		count;
}		t_maze;

typedef struct	s_solve
{
  int		dir;
  int		count;
  int		x;
  int		y;
  int		dx;
  int		dy;
  int		forward;
}		t_solve;

int		my_getnbr(char *);

#endif /* !MY_H */
