/*
** main.c for test in /home/costa_d/Documents/get_next_line/CPE_2015_getnextline
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Jan 17 18:33:50 2016 Arnaud Costa
** Last update Mon Apr 25 17:16:01 2016 Arnaud Costa
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
  int	fd;
  char	*s;

  fd = open(av[1], O_RDONLY);
  get_maze(fd);
  close(fd);
  return (0);
}
