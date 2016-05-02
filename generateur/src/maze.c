/*
** maze.c for maze in /media/samuel/Home/osborn_s/rendu/init_ia/dante/mazes
** 
** Made by Samuel
** Login   <samuel@epitech.net>
** 
** Started on  Fri Apr 29 12:50:06 2016 Samuel
** Last update Mon May  2 17:35:19 2016 Samuel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"

int		main(int ac, char **av)
{
  int		width;
  int		height;
  t_maze	**maze;

  if (ac != 3)
    {
      write(2, "Usage : ./maze <width> <height>\n", 33);
      return (0);
    }
  if ((width = my_getnbr(av[1])) <= 0)
    {
      write(2, "Please enter a number larger than 0.\n", 38);
      return (1);
    }
  if ((height = my_getnbr(av[2])) <= 0)
    {
      write(2, "Please enter a number larger than 0.\n", 38);
      return (1);
    }
  maze = create_maze(width, height);
  init_maze(maze, width, height);
  carve_maze(maze, width, height);
  print_maze(maze, width, height);
  free_maze(maze, height);
  return (0);
}
