/*
** parfait.c for parfait in /media/samuel/Home/osborn_s/rendu/init_ia/dante/generateur/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Tue May  3 09:21:50 2016 Samuel
** Last update Thu May 12 16:54:50 2016 Samuel
*/

#include <stdlib.h>
#include "maze.h"

int		wall_line(t_maze **maze, int y, int x, int height)
{
  while (y < height)
    maze[y++][x].state = '*';
}

void		init_str(t_start *start, int width, int height, int y)
{
  start->width = width;
  start->height = height;
  start->y = y;
}

void		start_route(t_maze **maze, int width, int height)
{
  t_start	start;

  start.x = 0;
  start.y = 0;
  start.r = 0;
  while ((start.y < height - 1) && (start.x < width - 1))
    {
      start.r = rand() % 2;
      if (start.x == width - 2 || start.x == width - 3)
	wall_line(maze, start.y, start.x, height);
      if (start.r == 0 && ((start.x) < width)
	  && maze[start.y][start.x + 1].state != '*')
	maze[start.y][start.x++].state = '*';
      if (start.r == 1 && ((start.y + 1) < height)
	  && maze[start.y + 1][start.x].state != '*')
	maze[start.y++][start.x].state = '*';
      else
	maze[start.y][start.x++].state = '*';
    }
  end_line(maze, width, height, start.x);
}

void		fill_boty(t_bot *bot, int y, int width, int height)
{
  bot->y = height - 1;
  bot->width = width;
  bot->height = height;
  bot->tmp = y;
}

int		zig_lines(t_maze **maze, int width, int height)
{
  int		r;
  int		y;
  int		d;
  t_bot		boty;

  d = rand() % 2;
  r = rand() % width;
  if (d == 1)
    {
      y = height - 1;
      if (maze[y][r].state != '*')
	{
	  while (r + 1 < width && r - 1 > 0 && maze[y][r].state != '*'
		 && maze[y][r + 1].state != '*' && maze[y][r - 1].state != '*')
	    maze[y--][r].state = '*';
	  if ((check_for_prob(maze, r, height, y)) == 1)
	    return (0);
	}
      else
	return (0);
      fill_boty(&boty, y, width, height);
      bottom(&boty, maze, r);
    }
  else if (d == 0)
    top(maze, r, width, height);
}
