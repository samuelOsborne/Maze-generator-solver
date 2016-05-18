/*
** main.c for test in /home/costa_d/Documents/get_next_line/CPE_2015_getnextline
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Sun Jan 17 18:33:50 2016 Arnaud Costa
** Last update Wed May 18 16:09:33 2016 Samuel
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "graph.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
  int	fd;

  (void)ac;
  fd = open(av[1], O_RDONLY);
  get_maze(fd);
  close(fd);
  return (0);
}
