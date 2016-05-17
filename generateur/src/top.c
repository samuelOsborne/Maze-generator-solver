/*
** top.c for top in /media/samuel/Home/osborn_s/rendu/init_ia/dante/generateur/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Wed May 11 14:42:47 2016 Samuel
** Last update Tue May 17 10:29:40 2016 Samuel
*/

#include "maze.h"

void	init_top(t_top *up, int width, int height)
{
  up->y = 0;
  up->i = 0;
  up->width = width;
  up->height = height;
}

void	rep(t_top *up, int y)
{
  up->tmp = y;
  up->y = 0;
}

int	liner(t_maze **maze, t_top *up, int r)
{
  while (r - 1 > 0
	 && r + 1 < up->width
	 && maze[up->y][r].state != '*'
	 && maze[up->y][r - 1].state != '*'
	 && maze[up->y][r + 1].state != '*')
    maze[up->y++][r].state = '*';
  if (maze[up->y][r].state == 'X')
    {
      while (up->y > 0)
	maze[up->y--][r].state = 'X';
      return (1);
    }
  return (0);
}

void	top_draw(t_maze **maze, int r, t_top *up)
{
  int	i;

  i = 0;
  while (i <= up->width + up->height)
    {
      while (up->y + 2 < up->height && r + 2 < up->width
	     && maze[up->y][r + 2].state != '*' && maze[up->y][r + 1].state != '*')
        maze[up->y][r++].state = '*';
      while (r < up->width && up->y + 2 < up->height && r - 1 > 0
	     && maze[up->y + 2][r].state != '*'
	     && maze[up->y + 2][r - 1].state != '*'
	     && up->y < up->tmp && maze[up->y][r + 1].state != '*'
             && maze[up->y + 1][r + 1].state != '*')
        maze[up->y++][r].state = '*';
      while (r - 2 > 0 && up->y + 1 < up->height
	     && maze[up->y][r - 2].state != '*' && maze[up->y][r - 1].state != '*'
             && maze[up->y + 1][r - 1].state != '*'
	     && maze[up->y][r].state != '*')
        maze[up->y][r--].state = '*';
      while (up->y - 2 > 0 && maze[up->y - 2][r].state != '*'
	     && maze[up->y - 1][r].state != '*' && maze[up->y][r].state != '*'
             && maze[up->y][r - 1].state != '*')
        maze[up->y--][r].state = '*';
      i++;
    }
}

int	top(t_maze **maze, int r, int width, int height)
{
  t_top	up;
  int	i;

  i = 0;
  init_top(&up, width, height);
  if (maze[up.y][r].state != '*')
    if ((liner(maze, &up, r)) == 1)
      return (0);
  rep(&up, up.y);
  top_draw(maze, r, &up);
}
