/*
** maze.h for maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 29 13:41:18 2016 Samuel
** Last update Wed May 11 16:05:04 2016 Samuel
*/

#ifndef MAZE_H
# define MAZE_H

typedef struct	s_start
{
  int		x;
  int		y;
  int		r;
  int		width;
  int		height;
}		t_start;

typedef	struct	s_bot
{
  int		y;
  int		width;
  int		height;
  int		tmp;
}		t_bot;

typedef struct	s_top
{
  int		y;
  int		tmp;
  int		i;
  int		width;
  int		height;
}		t_top;

typedef struct	s_pos
{
  int		x;
  int		y;
  struct s_pos	*next;
}		t_pos;

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
