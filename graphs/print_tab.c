/*
** print_tab.c for test in /home/costa_d/Documents/IA/dante/graphs
**
** Made by Arnaud Costa
** Login   <costa_d@epitech.net>
**
** Started on  Tue Apr 26 13:46:00 2016 Arnaud Costa
** Last update Wed Apr 27 17:45:32 2016 Samuel
*/

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
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
