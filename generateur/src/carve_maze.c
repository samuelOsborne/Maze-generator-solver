/*
** carve_maze.c for carve_maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 29 15:02:05 2016 Samuel
** Last update Thu May 12 16:33:15 2016 Samuel
*/

#include <stdlib.h>
#include "maze.h"

void		init_split(t_split *split)
{
  split->r = 0;
  split->count = 0;
  split->r = 0;
  split->t = 0;
  split->d = 0;
  split->i = 0;
  split->x = 0;
}

void		rand_var(t_split *split, int width, int height)
{
  split->r = rand() % width;
  split->t = rand() % height;
  split->d = rand() % 4;
  split->count = 0;
}

void		split_maze(t_maze **maze, int width, int height)
{
  int		i;
  t_split	s;

  i = 0;
  init_split(&s);
  while (i < (width * height))
    {
      rand_var(&s, width, height);
      if (s.d == 0 && (s.t - 1) > 0 && (maze[s.t - 1][s.r].state != '*'))
	maze[s.t - 1][s.r].state = '*';
      if (s.d == 1 && ((s.r + 1) < width) && maze[s.t][s.r + 1].state != '*')
	maze[s.t][s.r].state = '*';
      if (s.d == 2 && ((s.t + 1) < height) && maze[s.t + 1][s.r].state != '*')
	maze[s.t][s.r].state = '*';
      if (s.d == 3 && ((s.r - 1) > 0) && maze[s.t][s.r - 1].state != '*')
	maze[s.t][s.r].state = '*';
      i++;
    }
}

void		end_line(t_maze **maze, int width, int height, int i)
{
  while (i < width)
    {
      maze[height - 1][i].state = '*';
      i++;
    }
}

void		carve_maze(t_maze **maze, int width, int height)
{
  int		x;
  int		y;
  int		r;

  x = 0;
  y = 0;
  while ((y < height - 1) && (x < width - 1))
    {
      r = rand() % 2;
      if (x == width - 2)
	while (y < height - 1)
	  maze[y++][x].state = '*';
      if (r == 0 && ((x) < width) && maze[y][x + 1].state != '*')
	maze[y][x++].state = '*';
      if (r == 1 && ((y + 1) < height) && maze[y + 1][x].state != '*')
	maze[y++][x].state = '*';
    }
  end_line(maze, width, height, x);
  split_maze(maze, width, height);
}
