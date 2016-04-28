/*
** print_tab.c for test in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 13:46:00 2016 Arnaud Costa
** Last update Thu Apr 28 10:21:21 2016 Samuel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "graph.h"

void	my_putchar(char a)
{
  write(1, &a, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

void	print_tab(char **tab)
{
  int	i;
  int	op;

  i = 0;
  if ((op = open("solved", O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
    {
      write(2, "Could not create solution file!\n", 33);
      return ;
    }
  while (tab[i] != NULL)
    {
      write(op, tab[i], my_strlen(tab[i]));
      write(op, "\n", 1);
      i++;
    }
  close(op);
}
