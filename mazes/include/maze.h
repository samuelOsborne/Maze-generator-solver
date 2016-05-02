/*
** maze.h for maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 29 13:41:18 2016 Samuel
** Last update Mon May  2 10:13:08 2016 Samuel
*/

#ifndef MAZE_H
# define MAZE_H

typedef struct	s_maze
{
  char		state;
  int		x;
  int		y;
  int		walls;
}		t_maze;

typedef struct	s_split
{
  int		r;
  int		t;
  int		i;
  int		x;
  int		d;
  int		count;
}		t_split;

t_maze		**create_maze(int width, int height);

#endif /* !MAZE_H */
