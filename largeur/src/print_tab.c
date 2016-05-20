/*
** print_tab.c for test in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 13:46:00 2016 Arnaud Costa
** Last update Fri May 20 13:30:27 2016 Arnaud Costa
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
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

  i = 0;
  while (tab[i] != NULL)
    {
      write(1, tab[i], m_str(tab[i]));
      write(1, "\n", 1);
      i++;
    }
}
