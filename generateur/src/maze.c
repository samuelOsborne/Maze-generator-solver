/*
** maze.c for maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 29 12:50:06 2016 Samuel
** Last update Wed May 18 13:25:43 2016 Samuel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"

int		my_strcmp(char *st1, char *st2)
{
  int		i;

  i = 0;
  while (st1[i] && st2[i] && st1[i] == st2[i])
    i++;
  return (st1[i] - st2[i]);
}

void		imparfait(int width, int height)
{
  t_maze	**maze;

  srand(time(NULL));
  maze = create_maze(width, height);
  init_maze(maze, width, height);
  carve_maze(maze, width, height);
  print_maze(maze, width, height);
  free_maze(maze, height);
}

int		main(int ac, char **av)
{
  first_check(ac, av);
  return (0);
}
