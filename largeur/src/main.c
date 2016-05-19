/*
** main.c for test in /home/costa_d/Documents/get_next_line/CPE_2015_getnextline
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Jan 17 18:33:50 2016 Arnaud Costa
** Last update Thu May 19 11:26:07 2016 Samuel
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
  int	fd;

  if (ac == 1)
    {
      if ((write(2, "Please pass a maze file as an argument.\n", 41)) == -1)
	return (1);
      return (1);
    }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      if ((write(2, "File not available.\n", 20)) == -1)
	return (1);
      return (1);
    }
  get_maze(fd);
  close(fd);
  return (0);
}
