/*
** maze.c for maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 29 12:50:06 2016 Samuel
** Last update Sun May 29 15:17:44 2016 Samuel
*/

#include <unistd.h>
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

int		imparfait(int width, int height)
{
  t_maze	**maze;

  if (width >= 100 || height >= 100)
    {
      write(2, "Height or width bigger or equal to 100.\n", 40);
      return (1);
    }
  srand(time(NULL));
  maze = create_maze(width, height);
  init_maze(maze, width, height);
  carve_maze(maze, width, height);
  print_maze(maze, width, height);
  free_maze(maze, height);
  return (0);
}

int		main(int ac, char **av)
{
  first_check(ac, av);
  return (0);
}
