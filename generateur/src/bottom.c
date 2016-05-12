/*
** bottom.c for bottom in /media/samuel/Home/osborn_s/rendu/init_ia/dante/generateur/src
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Wed May 11 15:12:00 2016 Samuel
** Last update Thu May 12 16:45:12 2016 Samuel
*/

#include <stdlib.h>
#include "maze.h"

void		parfait(int width, int height)
{
  t_maze	**maze;
  int		i;

  i = 0;
  srand(time(NULL));
  maze = create_maze(width, height);
  init_maze(maze, width, height);
  start_route(maze, width, height);
  while (i < width * height)
    {
      zig_lines(maze, width, height);
      i++;
    }
  print_maze(maze, width, height);
  free_maze(maze, height);
}

void		bottom(t_bot *bot, t_maze **maze, int r)
{
  int		i;

  i = 0;
  while (i <= bot->width * bot->height)
    {
      while (r - 2 > 0 && maze[bot->y][r - 2].state != '*'
	     && maze[bot->y][r - 1].state != '*')
	maze[bot->y][r--].state = '*';
      while (r + 1 < bot->width && r - 1 > 0 && bot->y - 2 > 0 &&
	     maze[bot->y - 2][r].state != '*' &&
	     maze[bot->y - 1][r + 1].state != '*' &&
	     maze[bot->y - 1][r - 1].state != '*' &&
	     bot->y > bot->tmp && maze[bot->y][r].state != '*')
	maze[bot->y--][r].state = '*';
      while (bot->y + 1 < bot->height && bot->y - 1 > 0
	     && r + 2 < bot->width && maze[bot->y][r + 2].state != '*'
	     && maze[bot->y + 1][r + 1].state != '*'
	     && maze[bot->y - 1][r + 1].state != '*'
	     && maze[bot->y][r + 1].state != '*')
	maze[bot->y][r++].state = '*';
      while (bot->y + 2 < bot->height && maze[bot->y + 2][r].state != '*')
	maze[bot->y++][r].state = '*';
      i++;
    }
}
