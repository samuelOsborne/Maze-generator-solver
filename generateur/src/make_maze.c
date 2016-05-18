/*
** make_maze.c for make_maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
** 
** Made by Samuel
** Login   <samuel@epitech.net>
**
** Started on  Fri Apr 29 14:31:42 2016 Samuel
** Last update Wed May 18 13:26:10 2016 Samuel
*/

#include <unistd.h>
#include <stdlib.h>
#include "maze.h"

void		my_putchar(char a)
{
  write(1, &a, 1);
}

t_maze		**create_maze(int width, int height)
{
  int		i;
  t_maze	**tmp;

  i = 0;
  if ((tmp = malloc(sizeof(t_maze) * (height + 1))) == NULL)
    return (NULL);
  while (i < height)
    {
      if ((tmp[i] = malloc(sizeof(t_maze) * (width) + 1)) == NULL)
        return (NULL);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}

void		print_maze(t_maze **maze, int width, int height)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
        {
	  if ((write(1, &maze[i][j].state, 1)) == -1)
	    write(2, "write error\n", 13);
	  j++;
        }
      if (i < height - 1)
	if ((write(1, "\n", 1)) == -1)
	  write(2, "write error\n", 13);
      i++;
    }
}

void		init_maze(t_maze **maze, int width, int height)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < height)
    {
      j = 0;
      while (j < width)
        {
          maze[i][j].state = 'X';
          maze[i][j].x = j;
          maze[i][j].y = i;
          maze[i][j].walls = 4;
          j++;
        }
      i++;
    }
  maze[0][0].state = '*';
  maze[height - 1][width - 1].state = '*';
  maze[height - 1][width - 2].state = '*';
}

void		free_maze(t_maze **maze, int height)
{
  int		i;

  i = 0;
  while (i <= height)
    {
      free(maze[i]);
      i++;
    }
  free(maze);
}
